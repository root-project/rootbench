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
include math/mathcore/test/CMakeFiles/GradientUnit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include math/mathcore/test/CMakeFiles/GradientUnit.dir/compiler_depend.make

# Include the progress variables for this target.
include math/mathcore/test/CMakeFiles/GradientUnit.dir/progress.make

# Include the compile flags for this target's objects.
include math/mathcore/test/CMakeFiles/GradientUnit.dir/flags.make

math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.o: math/mathcore/test/CMakeFiles/GradientUnit.dir/flags.make
math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.o: /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testGradient.cxx
math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.o: math/mathcore/test/CMakeFiles/GradientUnit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.o -MF CMakeFiles/GradientUnit.dir/testGradient.cxx.o.d -o CMakeFiles/GradientUnit.dir/testGradient.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testGradient.cxx

math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GradientUnit.dir/testGradient.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testGradient.cxx > CMakeFiles/GradientUnit.dir/testGradient.cxx.i

math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GradientUnit.dir/testGradient.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/mathcore/test/testGradient.cxx -o CMakeFiles/GradientUnit.dir/testGradient.cxx.s

# Object files for target GradientUnit
GradientUnit_OBJECTS = \
"CMakeFiles/GradientUnit.dir/testGradient.cxx.o"

# External object files for target GradientUnit
GradientUnit_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

math/mathcore/test/GradientUnit: math/mathcore/test/CMakeFiles/GradientUnit.dir/testGradient.cxx.o
math/mathcore/test/GradientUnit: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
math/mathcore/test/GradientUnit: math/mathcore/test/CMakeFiles/GradientUnit.dir/build.make
math/mathcore/test/GradientUnit: lib/libHist.so
math/mathcore/test/GradientUnit: googletest-prefix/src/googletest-build/lib//libgtest_main.a
math/mathcore/test/GradientUnit: googletest-prefix/src/googletest-build/lib//libgmock.a
math/mathcore/test/GradientUnit: googletest-prefix/src/googletest-build/lib//libgmock_main.a
math/mathcore/test/GradientUnit: lib/libMatrix.so
math/mathcore/test/GradientUnit: lib/libMathCore.so
math/mathcore/test/GradientUnit: lib/libImt.so
math/mathcore/test/GradientUnit: lib/libMultiProc.so
math/mathcore/test/GradientUnit: lib/libNet.so
math/mathcore/test/GradientUnit: lib/libRIO.so
math/mathcore/test/GradientUnit: lib/libThread.so
math/mathcore/test/GradientUnit: lib/libCore.so
math/mathcore/test/GradientUnit: googletest-prefix/src/googletest-build/lib//libgtest.a
math/mathcore/test/GradientUnit: math/mathcore/test/CMakeFiles/GradientUnit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GradientUnit"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GradientUnit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/mathcore/test/CMakeFiles/GradientUnit.dir/build: math/mathcore/test/GradientUnit
.PHONY : math/mathcore/test/CMakeFiles/GradientUnit.dir/build

math/mathcore/test/CMakeFiles/GradientUnit.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test && $(CMAKE_COMMAND) -P CMakeFiles/GradientUnit.dir/cmake_clean.cmake
.PHONY : math/mathcore/test/CMakeFiles/GradientUnit.dir/clean

math/mathcore/test/CMakeFiles/GradientUnit.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/mathcore/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test /Users/abhiacherjee/Documents/rootbench/root/math/mathcore/test/CMakeFiles/GradientUnit.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/mathcore/test/CMakeFiles/GradientUnit.dir/depend

