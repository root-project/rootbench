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
include tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/compiler_depend.make

# Include the progress variables for this target.
include tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/progress.make

# Include the compile flags for this target's objects.
include tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/flags.make

tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o: tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/flags.make
tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o: /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/ntuple_endian.cxx
tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o: tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o -MF CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o.d -o CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o -c /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/ntuple_endian.cxx

tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/ntuple_endian.cxx > CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.i

tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/ntuple_endian.cxx -o CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.s

# Object files for target ntuple_endian
ntuple_endian_OBJECTS = \
"CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o"

# External object files for target ntuple_endian
ntuple_endian_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

tree/ntuple/v7/test/ntuple_endian: tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/ntuple_endian.cxx.o
tree/ntuple/v7/test/ntuple_endian: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
tree/ntuple/v7/test/ntuple_endian: tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/build.make
tree/ntuple/v7/test/ntuple_endian: lib/libROOTNTuple.so
tree/ntuple/v7/test/ntuple_endian: googletest-prefix/src/googletest-build/lib//libgtest_main.a
tree/ntuple/v7/test/ntuple_endian: googletest-prefix/src/googletest-build/lib//libgmock.a
tree/ntuple/v7/test/ntuple_endian: googletest-prefix/src/googletest-build/lib//libgmock_main.a
tree/ntuple/v7/test/ntuple_endian: lib/libImt.so
tree/ntuple/v7/test/ntuple_endian: lib/libMultiProc.so
tree/ntuple/v7/test/ntuple_endian: lib/libNet.so
tree/ntuple/v7/test/ntuple_endian: lib/libRIO.so
tree/ntuple/v7/test/ntuple_endian: lib/libThread.so
tree/ntuple/v7/test/ntuple_endian: lib/libROOTVecOps.so
tree/ntuple/v7/test/ntuple_endian: /Users/abhiacherjee/Documents/install_root/lib/libvdt.dylib
tree/ntuple/v7/test/ntuple_endian: lib/libCore.so
tree/ntuple/v7/test/ntuple_endian: googletest-prefix/src/googletest-build/lib//libgtest.a
tree/ntuple/v7/test/ntuple_endian: tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ntuple_endian"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ntuple_endian.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/build: tree/ntuple/v7/test/ntuple_endian
.PHONY : tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/build

tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && $(CMAKE_COMMAND) -P CMakeFiles/ntuple_endian.dir/cmake_clean.cmake
.PHONY : tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/clean

tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tree/ntuple/v7/test/CMakeFiles/ntuple_endian.dir/depend

