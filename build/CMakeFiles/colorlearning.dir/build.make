# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jfasola/fuerte_workspace/sandbox/colortrack_ros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/build

# Include any dependencies generated for this target.
include CMakeFiles/colorlearning.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/colorlearning.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/colorlearning.dir/flags.make

CMakeFiles/colorlearning.dir/src/colorlearning.o: CMakeFiles/colorlearning.dir/flags.make
CMakeFiles/colorlearning.dir/src/colorlearning.o: ../src/colorlearning.cpp
CMakeFiles/colorlearning.dir/src/colorlearning.o: ../manifest.xml
CMakeFiles/colorlearning.dir/src/colorlearning.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/colorlearning.dir/src/colorlearning.o: /opt/ros/fuerte/share/roscpp/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/colorlearning.dir/src/colorlearning.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/colorlearning.dir/src/colorlearning.o -c /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/src/colorlearning.cpp

CMakeFiles/colorlearning.dir/src/colorlearning.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colorlearning.dir/src/colorlearning.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/src/colorlearning.cpp > CMakeFiles/colorlearning.dir/src/colorlearning.i

CMakeFiles/colorlearning.dir/src/colorlearning.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colorlearning.dir/src/colorlearning.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/src/colorlearning.cpp -o CMakeFiles/colorlearning.dir/src/colorlearning.s

CMakeFiles/colorlearning.dir/src/colorlearning.o.requires:
.PHONY : CMakeFiles/colorlearning.dir/src/colorlearning.o.requires

CMakeFiles/colorlearning.dir/src/colorlearning.o.provides: CMakeFiles/colorlearning.dir/src/colorlearning.o.requires
	$(MAKE) -f CMakeFiles/colorlearning.dir/build.make CMakeFiles/colorlearning.dir/src/colorlearning.o.provides.build
.PHONY : CMakeFiles/colorlearning.dir/src/colorlearning.o.provides

CMakeFiles/colorlearning.dir/src/colorlearning.o.provides.build: CMakeFiles/colorlearning.dir/src/colorlearning.o

# Object files for target colorlearning
colorlearning_OBJECTS = \
"CMakeFiles/colorlearning.dir/src/colorlearning.o"

# External object files for target colorlearning
colorlearning_EXTERNAL_OBJECTS =

../bin/colorlearning: CMakeFiles/colorlearning.dir/src/colorlearning.o
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_calib3d.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_contrib.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_core.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_features2d.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_flann.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_gpu.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_highgui.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_imgproc.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_legacy.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_ml.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_nonfree.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_objdetect.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_photo.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_stitching.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_ts.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_video.so
../bin/colorlearning: /opt/ros/fuerte/lib/libopencv_videostab.so
../bin/colorlearning: CMakeFiles/colorlearning.dir/build.make
../bin/colorlearning: CMakeFiles/colorlearning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/colorlearning"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/colorlearning.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/colorlearning.dir/build: ../bin/colorlearning
.PHONY : CMakeFiles/colorlearning.dir/build

CMakeFiles/colorlearning.dir/requires: CMakeFiles/colorlearning.dir/src/colorlearning.o.requires
.PHONY : CMakeFiles/colorlearning.dir/requires

CMakeFiles/colorlearning.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/colorlearning.dir/cmake_clean.cmake
.PHONY : CMakeFiles/colorlearning.dir/clean

CMakeFiles/colorlearning.dir/depend:
	cd /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jfasola/fuerte_workspace/sandbox/colortrack_ros /home/jfasola/fuerte_workspace/sandbox/colortrack_ros /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/build /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/build /home/jfasola/fuerte_workspace/sandbox/colortrack_ros/build/CMakeFiles/colorlearning.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/colorlearning.dir/depend
