#include "opencv2/opencv.hpp"

#if (defined(CV_VERSION_EPOCH) && CV_VERSION_EPOCH == 2) //opencv version 2.4.x
#include "opencv2/nonfree/nonfree.hpp"
#else //opencv version 3.x
//compile with xfeatures2d module to use SIFT or SURF :(
#endif

int main(int argc, char**argv){
#if (defined(CV_VERSION_EPOCH) && CV_VERSION_EPOCH == 2)
	cv::initModule_nonfree();
#endif
	bool visualize_everything = false;
	cv::Mat model;
	cv::Mat scene;
	cv::VideoCapture camera(0);
	int ratio_th = 70;
	std::string model_path;

	bool loaded = false;
	while (!loaded){
		std::cout << "Please insert the path to the model image: " << std::endl;
		std::cin >> model_path;
		model = cv::imread(model_path);
		if (model.data == NULL){
			std::cout << " Unable to load image " << std::endl;
		}
		else{
			loaded = true;
		}
	}
	std::cout << "Model Image loaded..." << std::endl;
	
	std::string detector_name = "SIFT";
	int det_index = 0;
#if (defined(CV_VERSION_EPOCH) && CV_VERSION_EPOCH == 2)
	std::cout << "Choose algorithm to use: 1-->SIFT, 2-->SURF, 3-->ORB, 4-->BRISK" << std::endl;
#else
	std::cout << "Choose algorithm to use: 3--> ORB, 4-->BRISK" << std::endl;
#endif
	std::cin >> det_index;

	switch (det_index){
#if (defined(CV_VERSION_EPOCH) && CV_VERSION_EPOCH == 2)
		case 1:
			detector_name = "SIFT";
			break;
		case 2:
			detector_name = "SURF";
			break;
#endif
		case 3:
			detector_name = "ORB";
			break;
		case 4:
			detector_name = "BRISK";
			break;
		default:
			std::cout << "Unrecognized option aborting..." << std::endl;
			std::exit(1);
	}

	std::cout << "Detector choosen: " << detector_name << std::endl;
#if (defined(CV_VERSION_EPOCH) && CV_VERSION_EPOCH == 2)
	cv::Ptr<cv::Feature2D> detector = cv::Feature2D::create(detector_name);
	cv::Ptr<cv::Feature2D> descriptor = cv::Feature2D::create(detector_name);
#else
	cv::Ptr<cv::Feature2D> detector;
	cv::Ptr<cv::Feature2D> descriptor;
	if (det_index == 3){
		detector = cv::ORB::create(2000);
		descriptor = cv::ORB::create(2000);
	}
	else {
		detector = cv::BRISK::create();
		descriptor = cv::BRISK::create();
	}
#endif

	std::vector<cv::KeyPoint> keypoints_model, keypoints_scene;

	//model detection
	detector->detect(model, keypoints_model);
	std::cout << keypoints_model.size() << " Keypoints found on model" << std::endl;

	//STEP 2: Keypoint description
	//create descriptors
	cv::Mat descriptor_model, descriptor_scene;
	descriptor->compute(model, keypoints_model, descriptor_model);

	//STEP 3: Building FLANN
	//create matcher
	cv::Ptr<cv::DescriptorMatcher> matcher;
	if (det_index<3)
		matcher = cv::DescriptorMatcher::create("FlannBased");
	else
		matcher = cv::makePtr<cv::FlannBasedMatcher>(new cv::flann::LshIndexParams(10, 20, 2));
	
	std::vector<cv::Mat> models_descriptors;
	models_descriptors.push_back(descriptor_model);
	//add model descriptor
	matcher->add(models_descriptors);

	cv::namedWindow("params", CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("ratio_th*100", "params", &ratio_th, 100, NULL);

	std::cout << "Everything ready, starting..." << std::endl;

	//loop on frame coming from camera
	while (camera.read(scene)){

		//scene detection
		detector->detect(scene, keypoints_scene);
		
		//scene descriptor
		descriptor->compute(scene, keypoints_scene, descriptor_scene);

		//matching
		std::vector<std::vector<cv::DMatch> > matches;
		matcher->knnMatch(descriptor_scene, matches, 2);

		//ratio test to discard bad matches
		std::vector<cv::DMatch> filtered_match;

		float rth = ratio_th / 100.0;
		for (int i = 0; i < matches.size(); i++){
			std::vector<cv::DMatch> current_match = matches[i];
			if (current_match.size() == 2){
				if ((current_match[0].distance / current_match[1].distance) < rth){
					filtered_match.push_back(current_match[0]);
				}
			}
		}

		//STEP 4: Estimate Homograpy with RANSAC
		//extract pair of matching keypoints
		std::vector<cv::Point2d> model_points;
		std::vector<cv::Point2d> scene_points;
		for (int j = 0; j < filtered_match.size(); j++){
			cv::DMatch current = filtered_match[j];
			model_points.push_back(keypoints_model[current.trainIdx].pt);
			scene_points.push_back(keypoints_scene[current.queryIdx].pt);
		}

		cv::Mat bounding_box;
		scene.copyTo(bounding_box);
		//estimate homography using ransac
		if (model_points.size() > 5){
			cv::Mat homography = cv::findHomography(model_points, scene_points, CV_RANSAC);

			if (homography.rows == 3 && homography.cols == 3){ //check if the homography is valid
				//compute scene bounding box corner using the homography computed right now
				std::vector<cv::Point2f> obj_corners(4);
				obj_corners[0] = cv::Point(0, 0);
				obj_corners[1] = cv::Point(model.cols, 0);
				obj_corners[2] = cv::Point(model.cols, model.rows);
				obj_corners[3] = cv::Point(0, model.rows);
				std::vector<cv::Point2f> scene_corners(4);
				perspectiveTransform(obj_corners, scene_corners, homography);
				//draw the bounding box
				cv::line(bounding_box, scene_corners[0], scene_corners[1], cv::Scalar(0, 255, 0), 2);
				cv::line(bounding_box, scene_corners[1], scene_corners[2], cv::Scalar(255, 0, 0), 2);
				cv::line(bounding_box, scene_corners[2], scene_corners[3], cv::Scalar(0, 0, 255), 2);
				cv::line(bounding_box, scene_corners[3], scene_corners[0], cv::Scalar(0, 255, 255), 2);
			}
		}

		cv::imshow("Camera", bounding_box);
		cv::waitKey(160);
	}
}
