# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.8.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.8.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Nicola/Downloads/CV/Lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Nicola/Downloads/CV/Lab5/build

# Include any dependencies generated for this target.
include CMakeFiles/Camera_track.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Camera_track.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Camera_track.dir/flags.make

CMakeFiles/Camera_track.dir/Camera_track.o: CMakeFiles/Camera_track.dir/flags.make
CMakeFiles/Camera_track.dir/Camera_track.o: ../Camera_track.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Nicola/Downloads/CV/Lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Camera_track.dir/Camera_track.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Camera_track.dir/Camera_track.o -c /Users/Nicola/Downloads/CV/Lab5/Camera_track.cpp

CMakeFiles/Camera_track.dir/Camera_track.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Camera_track.dir/Camera_track.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Nicola/Downloads/CV/Lab5/Camera_track.cpp > CMakeFiles/Camera_track.dir/Camera_track.i

CMakeFiles/Camera_track.dir/Camera_track.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Camera_track.dir/Camera_track.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Nicola/Downloads/CV/Lab5/Camera_track.cpp -o CMakeFiles/Camera_track.dir/Camera_track.s

CMakeFiles/Camera_track.dir/Camera_track.o.requires:

.PHONY : CMakeFiles/Camera_track.dir/Camera_track.o.requires

CMakeFiles/Camera_track.dir/Camera_track.o.provides: CMakeFiles/Camera_track.dir/Camera_track.o.requires
	$(MAKE) -f CMakeFiles/Camera_track.dir/build.make CMakeFiles/Camera_track.dir/Camera_track.o.provides.build
.PHONY : CMakeFiles/Camera_track.dir/Camera_track.o.provides

CMakeFiles/Camera_track.dir/Camera_track.o.provides.build: CMakeFiles/Camera_track.dir/Camera_track.o


# Object files for target Camera_track
Camera_track_OBJECTS = \
"CMakeFiles/Camera_track.dir/Camera_track.o"

# External object files for target Camera_track
Camera_track_EXTERNAL_OBJECTS =

Camera_track: CMakeFiles/Camera_track.dir/Camera_track.o
Camera_track: CMakeFiles/Camera_track.dir/build.make
Camera_track: /usr/local/lib/libopencv_videostab.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_ts.a
Camera_track: /usr/local/lib/libopencv_superres.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_stitching.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_contrib.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_nonfree.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_ocl.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_gpu.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_photo.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_objdetect.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_legacy.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_video.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_ml.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_calib3d.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_features2d.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_highgui.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_imgproc.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_flann.2.4.13.dylib
Camera_track: /usr/local/lib/libopencv_core.2.4.13.dylib
Camera_track: CMakeFiles/Camera_track.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Nicola/Downloads/CV/Lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Camera_track"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Camera_track.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Camera_track.dir/build: Camera_track

.PHONY : CMakeFiles/Camera_track.dir/build

CMakeFiles/Camera_track.dir/requires: CMakeFiles/Camera_track.dir/Camera_track.o.requires

.PHONY : CMakeFiles/Camera_track.dir/requires

CMakeFiles/Camera_track.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Camera_track.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Camera_track.dir/clean

CMakeFiles/Camera_track.dir/depend:
	cd /Users/Nicola/Downloads/CV/Lab5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Nicola/Downloads/CV/Lab5 /Users/Nicola/Downloads/CV/Lab5 /Users/Nicola/Downloads/CV/Lab5/build /Users/Nicola/Downloads/CV/Lab5/build /Users/Nicola/Downloads/CV/Lab5/build/CMakeFiles/Camera_track.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Camera_track.dir/depend

