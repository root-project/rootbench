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
include core/foundation/test/CMakeFiles/testStringUtils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/foundation/test/CMakeFiles/testStringUtils.dir/compiler_depend.make

# Include the progress variables for this target.
include core/foundation/test/CMakeFiles/testStringUtils.dir/progress.make

# Include the compile flags for this target's objects.
include core/foundation/test/CMakeFiles/testStringUtils.dir/flags.make

core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o: core/foundation/test/CMakeFiles/testStringUtils.dir/flags.make
core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o: /Users/abhiacherjee/Documents/root_src/core/foundation/test/testStringUtils.cxx
core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o: core/foundation/test/CMakeFiles/testStringUtils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o -MF CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o.d -o CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o -c /Users/abhiacherjee/Documents/root_src/core/foundation/test/testStringUtils.cxx

core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testStringUtils.dir/testStringUtils.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/core/foundation/test/testStringUtils.cxx > CMakeFiles/testStringUtils.dir/testStringUtils.cxx.i

core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testStringUtils.dir/testStringUtils.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/core/foundation/test/testStringUtils.cxx -o CMakeFiles/testStringUtils.dir/testStringUtils.cxx.s

# Object files for target testStringUtils
testStringUtils_OBJECTS = \
"CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o"

# External object files for target testStringUtils
testStringUtils_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

core/foundation/test/testStringUtils: core/foundation/test/CMakeFiles/testStringUtils.dir/testStringUtils.cxx.o
core/foundation/test/testStringUtils: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
core/foundation/test/testStringUtils: core/foundation/test/CMakeFiles/testStringUtils.dir/build.make
core/foundation/test/testStringUtils: googletest-prefix/src/googletest-build/lib//libgtest_main.a
core/foundation/test/testStringUtils: googletest-prefix/src/googletest-build/lib//libgmock.a
core/foundation/test/testStringUtils: googletest-prefix/src/googletest-build/lib//libgmock_main.a
core/foundation/test/testStringUtils: lib/libCore.so
core/foundation/test/testStringUtils: googletest-prefix/src/googletest-build/lib//libgtest.a
core/foundation/test/testStringUtils: core/foundation/test/CMakeFiles/testStringUtils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testStringUtils"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testStringUtils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/foundation/test/CMakeFiles/testStringUtils.dir/build: core/foundation/test/testStringUtils
.PHONY : core/foundation/test/CMakeFiles/testStringUtils.dir/build

core/foundation/test/CMakeFiles/testStringUtils.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test && $(CMAKE_COMMAND) -P CMakeFiles/testStringUtils.dir/cmake_clean.cmake
.PHONY : core/foundation/test/CMakeFiles/testStringUtils.dir/clean

core/foundation/test/CMakeFiles/testStringUtils.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/core/foundation/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test /Users/abhiacherjee/Documents/rootbench/root/core/foundation/test/CMakeFiles/testStringUtils.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : core/foundation/test/CMakeFiles/testStringUtils.dir/depend

