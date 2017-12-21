cmake_minimum_required(VERSION 2.0)
project( Lab5 )
find_package( OpenCV REQUIRED )
add_executable( Local_Feature Local_Feature.cpp)
target_link_libraries( Local_Feature ${OpenCV_LIBS})

add_executable( Camera_track Camera_track.cpp)
target_link_libraries( Camera_track ${OpenCV_LIBS})