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
include hist/hist/test/CMakeFiles/test_TF123_Moments.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include hist/hist/test/CMakeFiles/test_TF123_Moments.dir/compiler_depend.make

# Include the progress variables for this target.
include hist/hist/test/CMakeFiles/test_TF123_Moments.dir/progress.make

# Include the compile flags for this target's objects.
include hist/hist/test/CMakeFiles/test_TF123_Moments.dir/flags.make

hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o: hist/hist/test/CMakeFiles/test_TF123_Moments.dir/flags.make
hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o: /Users/abhiacherjee/Documents/root_src/hist/hist/test/test_TF123_Moments.cxx
hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o: hist/hist/test/CMakeFiles/test_TF123_Moments.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/hist/hist/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o -MF CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o.d -o CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o -c /Users/abhiacherjee/Documents/root_src/hist/hist/test/test_TF123_Moments.cxx

hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/hist/hist/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/hist/hist/test/test_TF123_Moments.cxx > CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.i

hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/hist/hist/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/hist/hist/test/test_TF123_Moments.cxx -o CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.s

# Object files for target test_TF123_Moments
test_TF123_Moments_OBJECTS = \
"CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o"

# External object files for target test_TF123_Moments
test_TF123_Moments_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

hist/hist/test/test_TF123_Moments: hist/hist/test/CMakeFiles/test_TF123_Moments.dir/test_TF123_Moments.cxx.o
hist/hist/test/test_TF123_Moments: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
hist/hist/test/test_TF123_Moments: hist/hist/test/CMakeFiles/test_TF123_Moments.dir/build.make
hist/hist/test/test_TF123_Moments: lib/libHist.so
hist/hist/test/test_TF123_Moments: googletest-prefix/src/googletest-build/lib//libgtest_main.a
hist/hist/test/test_TF123_Moments: googletest-prefix/src/googletest-build/lib//libgmock.a
hist/hist/test/test_TF123_Moments: googletest-prefix/src/googletest-build/lib//libgmock_main.a
hist/hist/test/test_TF123_Moments: lib/libMatrix.so
hist/hist/test/test_TF123_Moments: lib/libMathCore.so
hist/hist/test/test_TF123_Moments: lib/libImt.so
hist/hist/test/test_TF123_Moments: lib/libMultiProc.so
hist/hist/test/test_TF123_Moments: lib/libNet.so
hist/hist/test/test_TF123_Moments: lib/libRIO.so
hist/hist/test/test_TF123_Moments: lib/libThread.so
hist/hist/test/test_TF123_Moments: lib/libCore.so
hist/hist/test/test_TF123_Moments: googletest-prefix/src/googletest-build/lib//libgtest.a
hist/hist/test/test_TF123_Moments: hist/hist/test/CMakeFiles/test_TF123_Moments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_TF123_Moments"
	cd /Users/abhiacherjee/Documents/rootbench/root/hist/hist/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_TF123_Moments.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hist/hist/test/CMakeFiles/test_TF123_Moments.dir/build: hist/hist/test/test_TF123_Moments
.PHONY : hist/hist/test/CMakeFiles/test_TF123_Moments.dir/build

hist/hist/test/CMakeFiles/test_TF123_Moments.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/hist/hist/test && $(CMAKE_COMMAND) -P CMakeFiles/test_TF123_Moments.dir/cmake_clean.cmake
.PHONY : hist/hist/test/CMakeFiles/test_TF123_Moments.dir/clean

hist/hist/test/CMakeFiles/test_TF123_Moments.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/hist/hist/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/hist/hist/test /Users/abhiacherjee/Documents/rootbench/root/hist/hist/test/CMakeFiles/test_TF123_Moments.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : hist/hist/test/CMakeFiles/test_TF123_Moments.dir/depend

