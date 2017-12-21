//Comment the following line to use the C interface, uncomment to use the c++ interface
#define OPENCV_CPP_INTERFACE

#ifndef OPENCV_CPP_INTERFACE
#include "opencv/cv.h"
#include "opencv/highgui.h"
#else
#include <iostream>
#include "opencv2/opencv.hpp"
#endif

#include <cstdio>
#include <math.h>

#ifndef OPENCV_CPP_INTERFACE
//WORK HERE FOR THE C INTERFACE

void convolution(IplImage * input, IplImage * output, float * kernel, int kernel_side){
	//=====================EXERCISE 1==========================
	//apply the convolutional operation on each pixel of input using the passed kernel, save the result in output
	return;
}

void TwoFrameDifference(IplImage*current_frame, IplImage*previous_frame, IplImage * output, int threshold){
	//=====================EXERCISE 2==========================
	//Compute two frame difference between current and previous, save the difference mask in output
	return;
}

int main(int argc, char**argv){
	//====================Exercise 0.a========================:
	//Open a video stream either from file or from your webcam
	//=======================================================

	//create placeholder for original and modified frame
	IplImage * previous_frame = NULL;
	IplImage * current_frame = NULL;
	IplImage * frame_converted = NULL;
	
	int kernel_side = 3;
	//uncomment only one filter at a time

	//edge detector filter
	//float kernel_filter[9] = { -1, -1, -1, -1, 8, -1, -1, -1, -1 };

	//gaussian blur filter
	//float kernel_filter[9] = { 1.0f / 16, 2.0f / 16, 1.0f / 16, 2.0f / 16, 4.0f / 16, 2.0f / 16, 1.0f / 16, 2.0f / 16, 1.0f / 16 };
	
	//mean filter
	float kernel_filter[9] = { 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9 };

	//====================Exercise 0.b========================
	//write a while loop to iterate over all the frame in the video sequence, store each frame in current_frame
	//=======================================================
	while (){
		
		//=============================EXERCISE 1===============================
		//implement convolution function and try out different kernels on current_frame

		//convolution(current_frame,frame_converted,kernel_filter,kernel_side);

		//=====================================================================


		//=============================EXERCISE 2===============================
		//Implement two frame difference function and try it out on a video sequence

		//TwoFrameDifference(current_frame,previous_frame, frame_converted, 30);

		//when the difference mask is computed at the end of the iteration copy current frame in previous frame fro teh next iteration
		//======================================================================

		//Visualize orignal frame 
		cvShowImage("Original", current_frame);
		//uncomment the following line to display frame_converted
		//cvShowImage("Elaborated", frame_converted);
		cvWaitKey(1);

		
	}

	//====================Exercise 0.c========================
	//when done close the video stream
	//=======================================================

	cvReleaseImage(&previous_frame);
	cvReleaseImage(&current_frame);
	cvReleaseImage(&frame_converted);
}

#else
//WORK HERE FOR THE C++ INTERFACE

void convolution(const cv::Mat & input, cv::Mat & output, const std::vector<float> & kernel, const int kernel_side){
	//=====================EXERCISE 1==========================
	//apply the convolutional operation on each pixel of input using the passed kernel, save the result in output
	int sum=0;
	int k = (kernel_side - 1) /2;

	for (int i = 0; i < input.rows; i++)
		for (int j = 0; j < input.cols; j++)
			output.at<uchar>(i,j) = 0;

	for (int i = k; i < input.rows-k; i++)
	{
		for (int j = k; j < input.cols-k; j++)
		{
			for (int m = -k; m <= k; m++) 
				for (int n = -k; n <= k; n++)
						sum += kernel[(n+k)*kernel_side+(m+k)] * input.at<uchar>(i-n, j-m);
			if (sum > 255)
				sum = 255;
			if (sum < 0)
				sum = 0;
			output.at<uchar>(i, j) = sum;
			sum = 0;
		}
	}
	cv::imshow("Convolution", output);
	return;
}

void two_frame_difference(const cv::Mat & current, const cv::Mat & previous, cv::Mat & output, const int threshold){
	//=====================EXERCISE 2==========================
	//Compute two frame difference between current and previous, save the difference mask in output
	cv::Mat diff = abs(current-previous);
	for (int i = 0; i < diff.rows; i++)
	{
		for (int j = 0; j < diff.cols; j++)
		{
			if(diff.at<uchar>(i,j) >threshold){
				output.at<uchar>(i, j)=255;
			}
			else{
				output.at<uchar>(i, j)=0;
			}
		}
	}
	return;
}

void three_frame_difference(const cv::Mat & current, const cv::Mat & previous, const cv::Mat & pre_previous, cv::Mat & output, const int threshold) {
	//=====================EXERCISE 3==========================
	//Compute two frame difference between current and previous, save the difference mask in output
	cv::Mat output1 = current.clone();
	cv::Mat output2 = current.clone();
	two_frame_difference(current, previous, output1, threshold);
	two_frame_difference(previous, pre_previous, output2, threshold);

	output = output1 & output2;
	return;
}

void visualizeHistogram(const std::vector<unsigned int> & histogram) {
	int outMargin = 30;
	int binw = 4;
	int binh = 3;
	int wout = (255 * binw) + (outMargin * 2);
	int hout = (100 * binh) + (outMargin * 2);
	cv::Size size;
	size.width = wout;
	size.height = hout;
	cv::Mat image_out = cv::Mat(size, CV_8UC3);
	image_out = cv::Scalar(255, 255, 255);

	//draw axes
	cv::line(image_out, cv::Point(outMargin, outMargin), cv::Point(outMargin, hout - outMargin), cv::Scalar(0, 0, 0), 2);
	cv::line(image_out, cv::Point(wout - outMargin, hout - outMargin), cv::Point(outMargin, hout - outMargin), cv::Scalar(0, 0, 0), 2);

	//draw histogram bin
	unsigned int max = 0;
	for (int i = 0; i<255; i++) {
		if (histogram[i]>max)max = histogram[i];
	}
	for (int i = 0; i < 256; i++) {
		if (histogram[i] > 0) {
			cv::Point pt1(outMargin + (i*binw), hout - outMargin);
			cv::Point pt2(pt1.x + binw, pt1.y - ((histogram[i] * 100 / max)*binh));
			cv::rectangle(image_out, pt1, pt2, cv::Scalar(255 - i, i / 3, i), CV_FILLED);
		}
	}

	//add notes
	std::string left = "0";
	std::string right = "255";
	cv::putText(image_out, left, cv::Point(outMargin, hout - (outMargin / 2)), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 2);
	cv::putText(image_out, right, cv::Point(wout - (1.5*outMargin), hout - (outMargin / 2)), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 2);
	cv::imshow("Histogram", image_out);
}

void buildHistogram(const cv::Mat& input, std::vector<unsigned int> & histogram) {
	unsigned int pixelvalue;
	for (int x = 0; x < input.rows; x++) {
		for (int y = 0; y < input.cols; y++) {
			pixelvalue = input.at<uchar>(x, y);
			histogram[pixelvalue] ++;
		}
	}
	visualizeHistogram(histogram);
	for (int i = 0; i < histogram.size(); i++) {
		histogram[i]=0;
	}
}

int main(int argc, char**argv){
	//====================Exercise 0.a========================:
	//Open a video stream either from file or from your webcam
	//=======================================================
	std::string filename = "../../videos/seq.avi";
    cv::VideoCapture stream;
    stream.open(0);
    if (!stream.isOpened()) {
        std::cout << "Unable to open stream"<< std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		getchar();
		return -1;
    }
    
	//create placeholder for original and modified frame
	cv::Mat previous_frame;
	cv::Mat pre_previous_frame;
	cv::Mat current_frame;
	cv::Mat frame_converted;

	//Windows size
	cv::namedWindow("Original", CV_WINDOW_NORMAL);
	cv::namedWindow("Convolution", CV_WINDOW_NORMAL);
	cv::namedWindow("Motion detection", CV_WINDOW_NORMAL);
	cv::namedWindow("Histogram", CV_WINDOW_NORMAL);
	cv::resizeWindow("Original",620,340);
	cv::resizeWindow("Convolution",620,340);
	cv::resizeWindow("Motion detection",620,340);
	cv::resizeWindow("Histogram", 620, 340);
	cv::moveWindow("Original", 0, 0);
	cv::moveWindow("Convolution", 640, 0);
	cv::moveWindow("Motion detection", 0, 380);
	cv::moveWindow("Histogram", 640, 380);

	int kernel_side = 3;
	int threshold =30;
	int first_read=0;
	std::vector<float> kernel_filter(kernel_side*kernel_side);
	std::vector<unsigned int> histogram(256, 0);
	//uncomment only one filter at a time
	
	//edge detector filter
	float k[9] = { -1, -1, -1, -1, 8, -1, -1, -1, -1 };
	
	//gaussian blur filter
	//float k[9] = { 1.0f / 16, 2.0f / 16, 1.0f / 16, 2.0f / 16, 4.0f / 16, 2.0f / 16, 1.0f / 16, 2.0f / 16, 1.0f / 16 };
	
	//mean filter
	//float k[9] = { 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9, 1.0f / 9 };
	kernel_filter.assign(k,k+9);

	//====================Exercise 0.b========================
	//write a while loop to iterate over all the frame in the video sequence, store each frame in current_frame
	//=======================================================
	
	while (stream.read(current_frame)){
		
		//=============================EXERCISE 1===============================
		//implement convolution function and try out different kernels on current_frame

		//Visualize orignal frame 
		cv::imshow("Original", current_frame);

		cvtColor(current_frame,current_frame,CV_RGB2GRAY);
		frame_converted = current_frame.clone();

		//Histogram View
		buildHistogram(current_frame, histogram);

		//Convolution View
		convolution(current_frame,frame_converted,kernel_filter,kernel_side); // decommenta per eseguire matrice di convoluzione

		//Motion Detection View
		//two_frame_difference(current_frame,previous_frame, frame_converted, threshold); 
		//current_frame.copyTo(previous_frame);											  
		
		//when the difference mask is computed at the end of the iteration copy current frame in previous frame fro teh next iteration
		//======================================================================

		//=============================EXERCISE 3===============================
		//Implement two frame difference function and try it out on a video sequence

		three_frame_difference(current_frame, previous_frame, pre_previous_frame, frame_converted, threshold);  
		previous_frame.copyTo(pre_previous_frame);																
		current_frame.copyTo(previous_frame);																	

		//when the difference mask is computed at the end of the iteration copy current frame in previous frame fro teh next iteration
		//======================================================================

		//uncomment the following line to display frame_converted
		cv::imshow("Motion detection", frame_converted);
		cv::waitKey(1);

		

	}
	
	//====================Exercise 0.c========================
	//when done close the video stream
	//=======================================================
	stream.release();
	std::cout << "All frames in the video elaborated..." << std::endl;
	std::cout << "Ending execution" << std::endl;
	return 0;
}
#endif
