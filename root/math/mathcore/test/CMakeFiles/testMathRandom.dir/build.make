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
include math/mathcore/test/CMakeFiles/testMathRandom.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include math/mathcore/test/CMakeFiles/testMathRandom.dir/compiler_depend.make

# Include the progress variables for this target.
include math/mathcore/test/CMakeFiles/testMathRandom.dir/progress.make

# Include the compile flags for this target's objects.
include math/mathcore/test/CMakeFiles/testMathRandom.dir/flags.make

math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o: math/mathcore/test/CMakeFiles/testMathRandom.dir/flags.make
math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o: /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testMathRandom.cxx
math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o: math/mathcore/test/CMakeFiles/testMathRandom.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o -MF CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o.d -o CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testMathRandom.cxx

math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testMathRandom.dir/testMathRandom.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testMathRandom.cxx > CMakeFiles/testMathRandom.dir/testMathRandom.cxx.i

math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testMathRandom.dir/testMathRandom.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testMathRandom.cxx -o CMakeFiles/testMathRandom.dir/testMathRandom.cxx.s

# Object files for target testMathRandom
testMathRandom_OBJECTS = \
"CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o"

# External object files for target testMathRandom
testMathRandom_EXTERNAL_OBJECTS =

math/mathcore/test/testMathRandom: math/mathcore/test/CMakeFiles/testMathRandom.dir/testMathRandom.cxx.o
math/mathcore/test/testMathRandom: math/mathcore/test/CMakeFiles/testMathRandom.dir/build.make
math/mathcore/test/testMathRandom: lib/libGraf3d.so
math/mathcore/test/testMathRandom: lib/libGpad.so
math/mathcore/test/testMathRandom: lib/libTree.so
math/mathcore/test/testMathRandom: lib/libMinuit2.so
math/mathcore/test/testMathRandom: lib/libRint.so
math/mathcore/test/testMathRandom: lib/libPostscript.so
math/mathcore/test/testMathRandom: lib/libPhysics.so
math/mathcore/test/testMathRandom: lib/libGraf.so
math/mathcore/test/testMathRandom: lib/libHist.so
math/mathcore/test/testMathRandom: lib/libMatrix.so
math/mathcore/test/testMathRandom: lib/libGenVector.so
math/mathcore/test/testMathRandom: lib/libMathCore.so
math/mathcore/test/testMathRandom: lib/libImt.so
math/mathcore/test/testMathRandom: lib/libMultiProc.so
math/mathcore/test/testMathRandom: lib/libNet.so
math/mathcore/test/testMathRandom: lib/libRIO.so
math/mathcore/test/testMathRandom: lib/libThread.so
math/mathcore/test/testMathRandom: lib/libCore.so
math/mathcore/test/testMathRandom: math/mathcore/test/CMakeFiles/testMathRandom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testMathRandom"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testMathRandom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/mathcore/test/CMakeFiles/testMathRandom.dir/build: math/mathcore/test/testMathRandom
.PHONY : math/mathcore/test/CMakeFiles/testMathRandom.dir/build

math/mathcore/test/CMakeFiles/testMathRandom.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && $(CMAKE_COMMAND) -P CMakeFiles/testMathRandom.dir/cmake_clean.cmake
.PHONY : math/mathcore/test/CMakeFiles/testMathRandom.dir/clean

math/mathcore/test/CMakeFiles/testMathRandom.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/mathcore/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test/CMakeFiles/testMathRandom.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/mathcore/test/CMakeFiles/testMathRandom.dir/depend

