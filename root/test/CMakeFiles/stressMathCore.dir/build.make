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
include test/CMakeFiles/stressMathCore.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/stressMathCore.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/stressMathCore.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/stressMathCore.dir/flags.make

test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o: test/CMakeFiles/stressMathCore.dir/flags.make
test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o: /Users/abhiacherjee/Documents/root_src/test/stressMathCore.cxx
test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o: test/CMakeFiles/stressMathCore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o -MF CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o.d -o CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o -c /Users/abhiacherjee/Documents/root_src/test/stressMathCore.cxx

test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/stressMathCore.dir/stressMathCore.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/test/stressMathCore.cxx > CMakeFiles/stressMathCore.dir/stressMathCore.cxx.i

test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/stressMathCore.dir/stressMathCore.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/test/stressMathCore.cxx -o CMakeFiles/stressMathCore.dir/stressMathCore.cxx.s

# Object files for target stressMathCore
stressMathCore_OBJECTS = \
"CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o"

# External object files for target stressMathCore
stressMathCore_EXTERNAL_OBJECTS =

test/stressMathCore: test/CMakeFiles/stressMathCore.dir/stressMathCore.cxx.o
test/stressMathCore: test/CMakeFiles/stressMathCore.dir/build.make
test/stressMathCore: lib/libHist.so
test/stressMathCore: lib/libTree.so
test/stressMathCore: lib/libGenVector.so
test/stressMathCore: lib/libMatrix.so
test/stressMathCore: lib/libMathCore.so
test/stressMathCore: lib/libImt.so
test/stressMathCore: lib/libMultiProc.so
test/stressMathCore: lib/libNet.so
test/stressMathCore: lib/libRIO.so
test/stressMathCore: lib/libThread.so
test/stressMathCore: lib/libCore.so
test/stressMathCore: test/CMakeFiles/stressMathCore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stressMathCore"
	cd /Users/abhiacherjee/Documents/rootbench/root/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stressMathCore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/stressMathCore.dir/build: test/stressMathCore
.PHONY : test/CMakeFiles/stressMathCore.dir/build

test/CMakeFiles/stressMathCore.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/test && $(CMAKE_COMMAND) -P CMakeFiles/stressMathCore.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/stressMathCore.dir/clean

test/CMakeFiles/stressMathCore.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/test /Users/abhiacherjee/Documents/rootbench/root/test/CMakeFiles/stressMathCore.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/stressMathCore.dir/depend

