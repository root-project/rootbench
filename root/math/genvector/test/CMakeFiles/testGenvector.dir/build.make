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
include math/genvector/test/CMakeFiles/testGenvector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include math/genvector/test/CMakeFiles/testGenvector.dir/compiler_depend.make

# Include the progress variables for this target.
include math/genvector/test/CMakeFiles/testGenvector.dir/progress.make

# Include the compile flags for this target's objects.
include math/genvector/test/CMakeFiles/testGenvector.dir/flags.make

math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.o: math/genvector/test/CMakeFiles/testGenvector.dir/flags.make
math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.o: /Users/abhiacherjee/Documents/root_src/math/genvector/test/testGenVector.cxx
math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.o: math/genvector/test/CMakeFiles/testGenvector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/genvector/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.o -MF CMakeFiles/testGenvector.dir/testGenVector.cxx.o.d -o CMakeFiles/testGenvector.dir/testGenVector.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/genvector/test/testGenVector.cxx

math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testGenvector.dir/testGenVector.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/genvector/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/genvector/test/testGenVector.cxx > CMakeFiles/testGenvector.dir/testGenVector.cxx.i

math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testGenvector.dir/testGenVector.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/genvector/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/genvector/test/testGenVector.cxx -o CMakeFiles/testGenvector.dir/testGenVector.cxx.s

# Object files for target testGenvector
testGenvector_OBJECTS = \
"CMakeFiles/testGenvector.dir/testGenVector.cxx.o"

# External object files for target testGenvector
testGenvector_EXTERNAL_OBJECTS =

math/genvector/test/testGenvector: math/genvector/test/CMakeFiles/testGenvector.dir/testGenVector.cxx.o
math/genvector/test/testGenvector: math/genvector/test/CMakeFiles/testGenvector.dir/build.make
math/genvector/test/testGenvector: lib/libGenVector.so
math/genvector/test/testGenvector: lib/libHist.so
math/genvector/test/testGenvector: lib/libSmatrix.so
math/genvector/test/testGenvector: lib/libMatrix.so
math/genvector/test/testGenvector: lib/libMathCore.so
math/genvector/test/testGenvector: lib/libImt.so
math/genvector/test/testGenvector: lib/libMultiProc.so
math/genvector/test/testGenvector: lib/libNet.so
math/genvector/test/testGenvector: lib/libRIO.so
math/genvector/test/testGenvector: lib/libThread.so
math/genvector/test/testGenvector: lib/libCore.so
math/genvector/test/testGenvector: math/genvector/test/CMakeFiles/testGenvector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testGenvector"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/genvector/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testGenvector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/genvector/test/CMakeFiles/testGenvector.dir/build: math/genvector/test/testGenvector
.PHONY : math/genvector/test/CMakeFiles/testGenvector.dir/build

math/genvector/test/CMakeFiles/testGenvector.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/genvector/test && $(CMAKE_COMMAND) -P CMakeFiles/testGenvector.dir/cmake_clean.cmake
.PHONY : math/genvector/test/CMakeFiles/testGenvector.dir/clean

math/genvector/test/CMakeFiles/testGenvector.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/genvector/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/genvector/test /Users/abhiacherjee/Documents/rootbench/root/math/genvector/test/CMakeFiles/testGenvector.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/genvector/test/CMakeFiles/testGenvector.dir/depend

