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
include roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/compiler_depend.make

# Include the progress variables for this target.
include roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/progress.make

# Include the compile flags for this target's objects.
include roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/flags.make

roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o: roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/flags.make
roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o: /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/TestStatistics/testRooAbsL.cxx
roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o: roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o -MF CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o.d -o CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o -c /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/TestStatistics/testRooAbsL.cxx

roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/TestStatistics/testRooAbsL.cxx > CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.i

roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/TestStatistics/testRooAbsL.cxx -o CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.s

# Object files for target testRooAbsL
testRooAbsL_OBJECTS = \
"CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o"

# External object files for target testRooAbsL
testRooAbsL_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

roofit/roofitcore/test/testRooAbsL: roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/TestStatistics/testRooAbsL.cxx.o
roofit/roofitcore/test/testRooAbsL: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
roofit/roofitcore/test/testRooAbsL: roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/build.make
roofit/roofitcore/test/testRooAbsL: lib/libRooFitCore.so
roofit/roofitcore/test/testRooAbsL: googletest-prefix/src/googletest-build/lib//libgtest_main.a
roofit/roofitcore/test/testRooAbsL: googletest-prefix/src/googletest-build/lib//libgmock.a
roofit/roofitcore/test/testRooAbsL: googletest-prefix/src/googletest-build/lib//libgmock_main.a
roofit/roofitcore/test/testRooAbsL: lib/libTree.so
roofit/roofitcore/test/testRooAbsL: lib/libMinuit.so
roofit/roofitcore/test/testRooAbsL: lib/libGraf.so
roofit/roofitcore/test/testRooAbsL: lib/libFoam.so
roofit/roofitcore/test/testRooAbsL: lib/libHist.so
roofit/roofitcore/test/testRooAbsL: lib/libMatrix.so
roofit/roofitcore/test/testRooAbsL: lib/libSmatrix.so
roofit/roofitcore/test/testRooAbsL: lib/libMathCore.so
roofit/roofitcore/test/testRooAbsL: lib/libImt.so
roofit/roofitcore/test/testRooAbsL: lib/libMultiProc.so
roofit/roofitcore/test/testRooAbsL: lib/libNet.so
roofit/roofitcore/test/testRooAbsL: lib/libRIO.so
roofit/roofitcore/test/testRooAbsL: lib/libThread.so
roofit/roofitcore/test/testRooAbsL: lib/libCore.so
roofit/roofitcore/test/testRooAbsL: googletest-prefix/src/googletest-build/lib//libgtest.a
roofit/roofitcore/test/testRooAbsL: roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testRooAbsL"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testRooAbsL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/build: roofit/roofitcore/test/testRooAbsL
.PHONY : roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/build

roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && $(CMAKE_COMMAND) -P CMakeFiles/testRooAbsL.dir/cmake_clean.cmake
.PHONY : roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/clean

roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : roofit/roofitcore/test/CMakeFiles/testRooAbsL.dir/depend

