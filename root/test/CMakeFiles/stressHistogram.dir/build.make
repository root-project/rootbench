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
include test/CMakeFiles/stressHistogram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/stressHistogram.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/stressHistogram.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/stressHistogram.dir/flags.make

test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o: test/CMakeFiles/stressHistogram.dir/flags.make
test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o: /Users/abhiacherjee/Documents/root_src/test/stressHistogram.cxx
test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o: test/CMakeFiles/stressHistogram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o -MF CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o.d -o CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o -c /Users/abhiacherjee/Documents/root_src/test/stressHistogram.cxx

test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/stressHistogram.dir/stressHistogram.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/test/stressHistogram.cxx > CMakeFiles/stressHistogram.dir/stressHistogram.cxx.i

test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/stressHistogram.dir/stressHistogram.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/test/stressHistogram.cxx -o CMakeFiles/stressHistogram.dir/stressHistogram.cxx.s

# Object files for target stressHistogram
stressHistogram_OBJECTS = \
"CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o"

# External object files for target stressHistogram
stressHistogram_EXTERNAL_OBJECTS =

test/stressHistogram: test/CMakeFiles/stressHistogram.dir/stressHistogram.cxx.o
test/stressHistogram: test/CMakeFiles/stressHistogram.dir/build.make
test/stressHistogram: lib/libHist.so
test/stressHistogram: lib/libMatrix.so
test/stressHistogram: lib/libMathCore.so
test/stressHistogram: lib/libImt.so
test/stressHistogram: lib/libMultiProc.so
test/stressHistogram: lib/libNet.so
test/stressHistogram: lib/libRIO.so
test/stressHistogram: lib/libThread.so
test/stressHistogram: lib/libCore.so
test/stressHistogram: test/CMakeFiles/stressHistogram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stressHistogram"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stressHistogram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/stressHistogram.dir/build: test/stressHistogram
.PHONY : test/CMakeFiles/stressHistogram.dir/build

test/CMakeFiles/stressHistogram.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/test && $(CMAKE_COMMAND) -P CMakeFiles/stressHistogram.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/stressHistogram.dir/clean

test/CMakeFiles/stressHistogram.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/test /Users/abhiacherjee/Documents/rootbench/root/test/CMakeFiles/stressHistogram.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/stressHistogram.dir/depend

