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
include main/CMakeFiles/xpdtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include main/CMakeFiles/xpdtest.dir/compiler_depend.make

# Include the progress variables for this target.
include main/CMakeFiles/xpdtest.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/xpdtest.dir/flags.make

main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o: main/CMakeFiles/xpdtest.dir/flags.make
main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o: /Users/abhiacherjee/Documents/root_src/main/src/xpdtest.cxx
main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o: main/CMakeFiles/xpdtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o -MF CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o.d -o CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o -c /Users/abhiacherjee/Documents/root_src/main/src/xpdtest.cxx

main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/xpdtest.dir/src/xpdtest.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/main/src/xpdtest.cxx > CMakeFiles/xpdtest.dir/src/xpdtest.cxx.i

main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/xpdtest.dir/src/xpdtest.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/main/src/xpdtest.cxx -o CMakeFiles/xpdtest.dir/src/xpdtest.cxx.s

# Object files for target xpdtest
xpdtest_OBJECTS = \
"CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o"

# External object files for target xpdtest
xpdtest_EXTERNAL_OBJECTS =

bin/xpdtest: main/CMakeFiles/xpdtest.dir/src/xpdtest.cxx.o
bin/xpdtest: main/CMakeFiles/xpdtest.dir/build.make
bin/xpdtest: lib/libProof.so
bin/xpdtest: lib/libTree.so
bin/xpdtest: lib/libHist.so
bin/xpdtest: lib/libMatrix.so
bin/xpdtest: lib/libMathCore.so
bin/xpdtest: lib/libImt.so
bin/xpdtest: lib/libMultiProc.so
bin/xpdtest: lib/libNet.so
bin/xpdtest: lib/libRIO.so
bin/xpdtest: lib/libThread.so
bin/xpdtest: lib/libCore.so
bin/xpdtest: main/CMakeFiles/xpdtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/xpdtest"
	cd /Users/abhiacherjee/Documents/rootbench/root/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xpdtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/xpdtest.dir/build: bin/xpdtest
.PHONY : main/CMakeFiles/xpdtest.dir/build

main/CMakeFiles/xpdtest.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/main && $(CMAKE_COMMAND) -P CMakeFiles/xpdtest.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/xpdtest.dir/clean

main/CMakeFiles/xpdtest.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/main /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/main /Users/abhiacherjee/Documents/rootbench/root/main/CMakeFiles/xpdtest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : main/CMakeFiles/xpdtest.dir/depend

