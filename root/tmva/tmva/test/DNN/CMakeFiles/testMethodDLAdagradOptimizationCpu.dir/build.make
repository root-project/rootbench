# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/abhiacherjee/Documents/root_src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/abhiacherjee/Documents/rootbench/root

# Include any dependencies generated for this target.
include tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/compiler_depend.make

# Include the progress variables for this target.
include tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/progress.make

# Include the compile flags for this target's objects.
include tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/flags.make

tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o: tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/flags.make
tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o: /Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/TestMethodDLAdagradOptimizationCpu.cxx
tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o: tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o -MF CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o.d -o CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o -c /Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/TestMethodDLAdagradOptimizationCpu.cxx

tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/TestMethodDLAdagradOptimizationCpu.cxx > CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.i

tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/TestMethodDLAdagradOptimizationCpu.cxx -o CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.s

# Object files for target testMethodDLAdagradOptimizationCpu
testMethodDLAdagradOptimizationCpu_OBJECTS = \
"CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o"

# External object files for target testMethodDLAdagradOptimizationCpu
testMethodDLAdagradOptimizationCpu_EXTERNAL_OBJECTS =

tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/TestMethodDLAdagradOptimizationCpu.cxx.o
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/build.make
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libTMVA.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libMinuit.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libMLP.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libTreePlayer.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libGraf3d.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libTree.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libGpad.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libGraf.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libHist.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libMatrix.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libMathCore.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libXMLIO.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libImt.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libMultiProc.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libNet.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libRIO.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libThread.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: lib/libCore.so
tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu: tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testMethodDLAdagradOptimizationCpu"
	cd /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/build: tmva/tmva/test/DNN/testMethodDLAdagradOptimizationCpu
.PHONY : tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/build

tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN && $(CMAKE_COMMAND) -P CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/cmake_clean.cmake
.PHONY : tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/clean

tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tmva/tmva/test/DNN/CMakeFiles/testMethodDLAdagradOptimizationCpu.dir/depend

