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
CMAKE_SOURCE_DIR = /Users/Nicola/Downloads/CV/Lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Nicola/Downloads/CV/Lab4/build

# Include any dependencies generated for this target.
include CMakeFiles/Lab4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab4.dir/flags.make

CMakeFiles/Lab4.dir/Local_Feature.o: CMakeFiles/Lab4.dir/flags.make
CMakeFiles/Lab4.dir/Local_Feature.o: ../Local_Feature.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Nicola/Downloads/CV/Lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab4.dir/Local_Feature.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab4.dir/Local_Feature.o -c /Users/Nicola/Downloads/CV/Lab4/Local_Feature.cpp

CMakeFiles/Lab4.dir/Local_Feature.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab4.dir/Local_Feature.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Nicola/Downloads/CV/Lab4/Local_Feature.cpp > CMakeFiles/Lab4.dir/Local_Feature.i

CMakeFiles/Lab4.dir/Local_Feature.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab4.dir/Local_Feature.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Nicola/Downloads/CV/Lab4/Local_Feature.cpp -o CMakeFiles/Lab4.dir/Local_Feature.s

CMakeFiles/Lab4.dir/Local_Feature.o.requires:

.PHONY : CMakeFiles/Lab4.dir/Local_Feature.o.requires

CMakeFiles/Lab4.dir/Local_Feature.o.provides: CMakeFiles/Lab4.dir/Local_Feature.o.requires
	$(MAKE) -f CMakeFiles/Lab4.dir/build.make CMakeFiles/Lab4.dir/Local_Feature.o.provides.build
.PHONY : CMakeFiles/Lab4.dir/Local_Feature.o.provides

CMakeFiles/Lab4.dir/Local_Feature.o.provides.build: CMakeFiles/Lab4.dir/Local_Feature.o


# Object files for target Lab4
Lab4_OBJECTS = \
"CMakeFiles/Lab4.dir/Local_Feature.o"

# External object files for target Lab4
Lab4_EXTERNAL_OBJECTS =

Lab4: CMakeFiles/Lab4.dir/Local_Feature.o
Lab4: CMakeFiles/Lab4.dir/build.make
Lab4: /usr/local/lib/libopencv_videostab.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_ts.a
Lab4: /usr/local/lib/libopencv_superres.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_stitching.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_contrib.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_nonfree.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_ocl.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_gpu.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_photo.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_objdetect.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_legacy.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_video.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_ml.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_calib3d.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_features2d.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_highgui.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_imgproc.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_flann.2.4.13.dylib
Lab4: /usr/local/lib/libopencv_core.2.4.13.dylib
Lab4: CMakeFiles/Lab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Nicola/Downloads/CV/Lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab4.dir/build: Lab4

.PHONY : CMakeFiles/Lab4.dir/build

CMakeFiles/Lab4.dir/requires: CMakeFiles/Lab4.dir/Local_Feature.o.requires

.PHONY : CMakeFiles/Lab4.dir/requires

CMakeFiles/Lab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab4.dir/clean

CMakeFiles/Lab4.dir/depend:
	cd /Users/Nicola/Downloads/CV/Lab4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Nicola/Downloads/CV/Lab4 /Users/Nicola/Downloads/CV/Lab4 /Users/Nicola/Downloads/CV/Lab4/build /Users/Nicola/Downloads/CV/Lab4/build /Users/Nicola/Downloads/CV/Lab4/build/CMakeFiles/Lab4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab4.dir/depend
