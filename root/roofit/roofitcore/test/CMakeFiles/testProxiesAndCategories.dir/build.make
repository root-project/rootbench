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
include roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/compiler_depend.make

# Include the progress variables for this target.
include roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/progress.make

# Include the compile flags for this target's objects.
include roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/flags.make

roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o: roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/flags.make
roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o: /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/testProxiesAndCategories.cxx
roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o: roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o -MF CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o.d -o CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o -c /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/testProxiesAndCategories.cxx

roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/testProxiesAndCategories.cxx > CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.i

roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test/testProxiesAndCategories.cxx -o CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.s

# Object files for target testProxiesAndCategories
testProxiesAndCategories_OBJECTS = \
"CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o"

# External object files for target testProxiesAndCategories
testProxiesAndCategories_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

roofit/roofitcore/test/testProxiesAndCategories: roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/testProxiesAndCategories.cxx.o
roofit/roofitcore/test/testProxiesAndCategories: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
roofit/roofitcore/test/testProxiesAndCategories: roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/build.make
roofit/roofitcore/test/testProxiesAndCategories: lib/libRooFitCore.so
roofit/roofitcore/test/testProxiesAndCategories: googletest-prefix/src/googletest-build/lib//libgtest_main.a
roofit/roofitcore/test/testProxiesAndCategories: googletest-prefix/src/googletest-build/lib//libgmock.a
roofit/roofitcore/test/testProxiesAndCategories: googletest-prefix/src/googletest-build/lib//libgmock_main.a
roofit/roofitcore/test/testProxiesAndCategories: lib/libTree.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libMinuit.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libGraf.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libFoam.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libHist.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libMatrix.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libSmatrix.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libMathCore.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libImt.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libMultiProc.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libNet.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libRIO.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libThread.so
roofit/roofitcore/test/testProxiesAndCategories: lib/libCore.so
roofit/roofitcore/test/testProxiesAndCategories: googletest-prefix/src/googletest-build/lib//libgtest.a
roofit/roofitcore/test/testProxiesAndCategories: roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testProxiesAndCategories"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testProxiesAndCategories.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/build: roofit/roofitcore/test/testProxiesAndCategories
.PHONY : roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/build

roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test && $(CMAKE_COMMAND) -P CMakeFiles/testProxiesAndCategories.dir/cmake_clean.cmake
.PHONY : roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/clean

roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/roofit/roofitcore/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test /Users/abhiacherjee/Documents/rootbench/root/roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : roofit/roofitcore/test/CMakeFiles/testProxiesAndCategories.dir/depend

