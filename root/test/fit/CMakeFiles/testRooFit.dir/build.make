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
include test/fit/CMakeFiles/testRooFit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/fit/CMakeFiles/testRooFit.dir/compiler_depend.make

# Include the progress variables for this target.
include test/fit/CMakeFiles/testRooFit.dir/progress.make

# Include the compile flags for this target's objects.
include test/fit/CMakeFiles/testRooFit.dir/flags.make

test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.o: test/fit/CMakeFiles/testRooFit.dir/flags.make
test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.o: /Users/abhiacherjee/Documents/root_src/test/fit/testRooFit.cxx
test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.o: test/fit/CMakeFiles/testRooFit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/test/fit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.o -MF CMakeFiles/testRooFit.dir/testRooFit.cxx.o.d -o CMakeFiles/testRooFit.dir/testRooFit.cxx.o -c /Users/abhiacherjee/Documents/root_src/test/fit/testRooFit.cxx

test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testRooFit.dir/testRooFit.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/test/fit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/test/fit/testRooFit.cxx > CMakeFiles/testRooFit.dir/testRooFit.cxx.i

test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testRooFit.dir/testRooFit.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/test/fit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/test/fit/testRooFit.cxx -o CMakeFiles/testRooFit.dir/testRooFit.cxx.s

# Object files for target testRooFit
testRooFit_OBJECTS = \
"CMakeFiles/testRooFit.dir/testRooFit.cxx.o"

# External object files for target testRooFit
testRooFit_EXTERNAL_OBJECTS =

test/fit/testRooFit: test/fit/CMakeFiles/testRooFit.dir/testRooFit.cxx.o
test/fit/testRooFit: test/fit/CMakeFiles/testRooFit.dir/build.make
test/fit/testRooFit: lib/libRooFit.so
test/fit/testRooFit: lib/libRooFitCore.so
test/fit/testRooFit: lib/libMinuit.so
test/fit/testRooFit: lib/libGraf.so
test/fit/testRooFit: lib/libFoam.so
test/fit/testRooFit: lib/libHist.so
test/fit/testRooFit: lib/libSmatrix.so
test/fit/testRooFit: lib/libMatrix.so
test/fit/testRooFit: lib/libTree.so
test/fit/testRooFit: lib/libMathCore.so
test/fit/testRooFit: lib/libImt.so
test/fit/testRooFit: lib/libMultiProc.so
test/fit/testRooFit: lib/libNet.so
test/fit/testRooFit: lib/libRIO.so
test/fit/testRooFit: lib/libThread.so
test/fit/testRooFit: lib/libCore.so
test/fit/testRooFit: test/fit/CMakeFiles/testRooFit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testRooFit"
	cd /Users/abhiacherjee/Documents/rootbench/root/test/fit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testRooFit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/fit/CMakeFiles/testRooFit.dir/build: test/fit/testRooFit
.PHONY : test/fit/CMakeFiles/testRooFit.dir/build

test/fit/CMakeFiles/testRooFit.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/test/fit && $(CMAKE_COMMAND) -P CMakeFiles/testRooFit.dir/cmake_clean.cmake
.PHONY : test/fit/CMakeFiles/testRooFit.dir/clean

test/fit/CMakeFiles/testRooFit.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/test/fit /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/test/fit /Users/abhiacherjee/Documents/rootbench/root/test/fit/CMakeFiles/testRooFit.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/fit/CMakeFiles/testRooFit.dir/depend

