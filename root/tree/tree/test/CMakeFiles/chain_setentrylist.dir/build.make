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
include tree/tree/test/CMakeFiles/chain_setentrylist.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tree/tree/test/CMakeFiles/chain_setentrylist.dir/compiler_depend.make

# Include the progress variables for this target.
include tree/tree/test/CMakeFiles/chain_setentrylist.dir/progress.make

# Include the compile flags for this target's objects.
include tree/tree/test/CMakeFiles/chain_setentrylist.dir/flags.make

tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o: tree/tree/test/CMakeFiles/chain_setentrylist.dir/flags.make
tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o: /Users/abhiacherjee/Documents/root_src/tree/tree/test/chain_setentrylist.cxx
tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o: tree/tree/test/CMakeFiles/chain_setentrylist.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/tree/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o -MF CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o.d -o CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o -c /Users/abhiacherjee/Documents/root_src/tree/tree/test/chain_setentrylist.cxx

tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/tree/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/tree/tree/test/chain_setentrylist.cxx > CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.i

tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/tree/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/tree/tree/test/chain_setentrylist.cxx -o CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.s

# Object files for target chain_setentrylist
chain_setentrylist_OBJECTS = \
"CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o"

# External object files for target chain_setentrylist
chain_setentrylist_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

tree/tree/test/chain_setentrylist: tree/tree/test/CMakeFiles/chain_setentrylist.dir/chain_setentrylist.cxx.o
tree/tree/test/chain_setentrylist: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
tree/tree/test/chain_setentrylist: tree/tree/test/CMakeFiles/chain_setentrylist.dir/build.make
tree/tree/test/chain_setentrylist: lib/libTree.so
tree/tree/test/chain_setentrylist: googletest-prefix/src/googletest-build/lib//libgtest_main.a
tree/tree/test/chain_setentrylist: googletest-prefix/src/googletest-build/lib//libgmock.a
tree/tree/test/chain_setentrylist: googletest-prefix/src/googletest-build/lib//libgmock_main.a
tree/tree/test/chain_setentrylist: lib/libMathCore.so
tree/tree/test/chain_setentrylist: lib/libImt.so
tree/tree/test/chain_setentrylist: lib/libMultiProc.so
tree/tree/test/chain_setentrylist: lib/libNet.so
tree/tree/test/chain_setentrylist: lib/libRIO.so
tree/tree/test/chain_setentrylist: lib/libThread.so
tree/tree/test/chain_setentrylist: lib/libCore.so
tree/tree/test/chain_setentrylist: googletest-prefix/src/googletest-build/lib//libgtest.a
tree/tree/test/chain_setentrylist: tree/tree/test/CMakeFiles/chain_setentrylist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chain_setentrylist"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/tree/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chain_setentrylist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tree/tree/test/CMakeFiles/chain_setentrylist.dir/build: tree/tree/test/chain_setentrylist
.PHONY : tree/tree/test/CMakeFiles/chain_setentrylist.dir/build

tree/tree/test/CMakeFiles/chain_setentrylist.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/tree/test && $(CMAKE_COMMAND) -P CMakeFiles/chain_setentrylist.dir/cmake_clean.cmake
.PHONY : tree/tree/test/CMakeFiles/chain_setentrylist.dir/clean

tree/tree/test/CMakeFiles/chain_setentrylist.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/tree/tree/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/tree/tree/test /Users/abhiacherjee/Documents/rootbench/root/tree/tree/test/CMakeFiles/chain_setentrylist.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tree/tree/test/CMakeFiles/chain_setentrylist.dir/depend

