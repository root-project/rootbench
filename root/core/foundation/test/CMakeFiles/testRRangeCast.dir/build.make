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
include core/foundation/test/CMakeFiles/testRRangeCast.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/foundation/test/CMakeFiles/testRRangeCast.dir/compiler_depend.make

# Include the progress variables for this target.
include core/foundation/test/CMakeFiles/testRRangeCast.dir/progress.make

# Include the compile flags for this target's objects.
include core/foundation/test/CMakeFiles/testRRangeCast.dir/flags.make

core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o: core/foundation/test/CMakeFiles/testRRangeCast.dir/flags.make
core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o: /Users/abhiacherjee/Documents/root_src/core/foundation/test/testRRangeCast.cxx
core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o: core/foundation/test/CMakeFiles/testRRangeCast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o -MF CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o.d -o CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o -c /Users/abhiacherjee/Documents/root_src/core/foundation/test/testRRangeCast.cxx

core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/core/foundation/test/testRRangeCast.cxx > CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.i

core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/core/foundation/test/testRRangeCast.cxx -o CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.s

# Object files for target testRRangeCast
testRRangeCast_OBJECTS = \
"CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o"

# External object files for target testRRangeCast
testRRangeCast_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

core/foundation/test/testRRangeCast: core/foundation/test/CMakeFiles/testRRangeCast.dir/testRRangeCast.cxx.o
core/foundation/test/testRRangeCast: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
core/foundation/test/testRRangeCast: core/foundation/test/CMakeFiles/testRRangeCast.dir/build.make
core/foundation/test/testRRangeCast: googletest-prefix/src/googletest-build/lib//libgtest_main.a
core/foundation/test/testRRangeCast: googletest-prefix/src/googletest-build/lib//libgmock.a
core/foundation/test/testRRangeCast: googletest-prefix/src/googletest-build/lib//libgmock_main.a
core/foundation/test/testRRangeCast: lib/libCore.so
core/foundation/test/testRRangeCast: googletest-prefix/src/googletest-build/lib//libgtest.a
core/foundation/test/testRRangeCast: core/foundation/test/CMakeFiles/testRRangeCast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testRRangeCast"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testRRangeCast.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/foundation/test/CMakeFiles/testRRangeCast.dir/build: core/foundation/test/testRRangeCast
.PHONY : core/foundation/test/CMakeFiles/testRRangeCast.dir/build

core/foundation/test/CMakeFiles/testRRangeCast.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && $(CMAKE_COMMAND) -P CMakeFiles/testRRangeCast.dir/cmake_clean.cmake
.PHONY : core/foundation/test/CMakeFiles/testRRangeCast.dir/clean

core/foundation/test/CMakeFiles/testRRangeCast.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/core/foundation/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test/CMakeFiles/testRRangeCast.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : core/foundation/test/CMakeFiles/testRRangeCast.dir/depend

