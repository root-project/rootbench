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
include roofit/roofit/test/CMakeFiles/testRooJohnson.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include roofit/roofit/test/CMakeFiles/testRooJohnson.dir/compiler_depend.make

# Include the progress variables for this target.
include roofit/roofit/test/CMakeFiles/testRooJohnson.dir/progress.make

# Include the compile flags for this target's objects.
include roofit/roofit/test/CMakeFiles/testRooJohnson.dir/flags.make

roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o: roofit/roofit/test/CMakeFiles/testRooJohnson.dir/flags.make
roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o: /Users/abhiacherjee/Documents/root_src/roofit/roofit/test/testRooJohnson.cxx
roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o: roofit/roofit/test/CMakeFiles/testRooJohnson.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofit/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o -MF CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o.d -o CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o -c /Users/abhiacherjee/Documents/root_src/roofit/roofit/test/testRooJohnson.cxx

roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofit/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/roofit/roofit/test/testRooJohnson.cxx > CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.i

roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofit/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/roofit/roofit/test/testRooJohnson.cxx -o CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.s

# Object files for target testRooJohnson
testRooJohnson_OBJECTS = \
"CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o"

# External object files for target testRooJohnson
testRooJohnson_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

roofit/roofit/test/testRooJohnson: roofit/roofit/test/CMakeFiles/testRooJohnson.dir/testRooJohnson.cxx.o
roofit/roofit/test/testRooJohnson: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
roofit/roofit/test/testRooJohnson: roofit/roofit/test/CMakeFiles/testRooJohnson.dir/build.make
roofit/roofit/test/testRooJohnson: lib/libGpad.so
roofit/roofit/test/testRooJohnson: lib/libRooFit.so
roofit/roofit/test/testRooJohnson: googletest-prefix/src/googletest-build/lib//libgtest_main.a
roofit/roofit/test/testRooJohnson: googletest-prefix/src/googletest-build/lib//libgmock.a
roofit/roofit/test/testRooJohnson: googletest-prefix/src/googletest-build/lib//libgmock_main.a
roofit/roofit/test/testRooJohnson: lib/libRooFitCore.so
roofit/roofit/test/testRooJohnson: lib/libMinuit.so
roofit/roofit/test/testRooJohnson: lib/libGraf.so
roofit/roofit/test/testRooJohnson: lib/libFoam.so
roofit/roofit/test/testRooJohnson: lib/libHist.so
roofit/roofit/test/testRooJohnson: lib/libSmatrix.so
roofit/roofit/test/testRooJohnson: lib/libTree.so
roofit/roofit/test/testRooJohnson: lib/libMatrix.so
roofit/roofit/test/testRooJohnson: lib/libMathCore.so
roofit/roofit/test/testRooJohnson: lib/libImt.so
roofit/roofit/test/testRooJohnson: lib/libMultiProc.so
roofit/roofit/test/testRooJohnson: lib/libNet.so
roofit/roofit/test/testRooJohnson: lib/libRIO.so
roofit/roofit/test/testRooJohnson: lib/libThread.so
roofit/roofit/test/testRooJohnson: lib/libCore.so
roofit/roofit/test/testRooJohnson: googletest-prefix/src/googletest-build/lib//libgtest.a
roofit/roofit/test/testRooJohnson: roofit/roofit/test/CMakeFiles/testRooJohnson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testRooJohnson"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofit/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testRooJohnson.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
roofit/roofit/test/CMakeFiles/testRooJohnson.dir/build: roofit/roofit/test/testRooJohnson
.PHONY : roofit/roofit/test/CMakeFiles/testRooJohnson.dir/build

roofit/roofit/test/CMakeFiles/testRooJohnson.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofit/test && $(CMAKE_COMMAND) -P CMakeFiles/testRooJohnson.dir/cmake_clean.cmake
.PHONY : roofit/roofit/test/CMakeFiles/testRooJohnson.dir/clean

roofit/roofit/test/CMakeFiles/testRooJohnson.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/roofit/roofit/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/roofit/roofit/test /Users/abhiacherjee/Documents/rootbench/root/roofit/roofit/test/CMakeFiles/testRooJohnson.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : roofit/roofit/test/CMakeFiles/testRooJohnson.dir/depend

