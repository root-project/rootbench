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
include math/vecops/test/CMakeFiles/vecops_rvec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include math/vecops/test/CMakeFiles/vecops_rvec.dir/compiler_depend.make

# Include the progress variables for this target.
include math/vecops/test/CMakeFiles/vecops_rvec.dir/progress.make

# Include the compile flags for this target's objects.
include math/vecops/test/CMakeFiles/vecops_rvec.dir/flags.make

math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o: math/vecops/test/CMakeFiles/vecops_rvec.dir/flags.make
math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o: /Users/abhiacherjee/Documents/root_src/math/vecops/test/vecops_rvec.cxx
math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o: math/vecops/test/CMakeFiles/vecops_rvec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/vecops/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o -MF CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o.d -o CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/vecops/test/vecops_rvec.cxx

math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/vecops/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/vecops/test/vecops_rvec.cxx > CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.i

math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/vecops/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/vecops/test/vecops_rvec.cxx -o CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.s

# Object files for target vecops_rvec
vecops_rvec_OBJECTS = \
"CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o"

# External object files for target vecops_rvec
vecops_rvec_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

math/vecops/test/vecops_rvec: math/vecops/test/CMakeFiles/vecops_rvec.dir/vecops_rvec.cxx.o
math/vecops/test/vecops_rvec: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
math/vecops/test/vecops_rvec: math/vecops/test/CMakeFiles/vecops_rvec.dir/build.make
math/vecops/test/vecops_rvec: lib/libPhysics.so
math/vecops/test/vecops_rvec: lib/libROOTVecOps.so
math/vecops/test/vecops_rvec: lib/libGenVector.so
math/vecops/test/vecops_rvec: lib/libTree.so
math/vecops/test/vecops_rvec: googletest-prefix/src/googletest-build/lib//libgtest_main.a
math/vecops/test/vecops_rvec: googletest-prefix/src/googletest-build/lib//libgmock.a
math/vecops/test/vecops_rvec: googletest-prefix/src/googletest-build/lib//libgmock_main.a
math/vecops/test/vecops_rvec: lib/libMatrix.so
math/vecops/test/vecops_rvec: /Users/abhiacherjee/Documents/install_root/lib/libvdt.dylib
math/vecops/test/vecops_rvec: lib/libMathCore.so
math/vecops/test/vecops_rvec: lib/libImt.so
math/vecops/test/vecops_rvec: lib/libMultiProc.so
math/vecops/test/vecops_rvec: lib/libNet.so
math/vecops/test/vecops_rvec: lib/libRIO.so
math/vecops/test/vecops_rvec: lib/libThread.so
math/vecops/test/vecops_rvec: lib/libCore.so
math/vecops/test/vecops_rvec: googletest-prefix/src/googletest-build/lib//libgtest.a
math/vecops/test/vecops_rvec: math/vecops/test/CMakeFiles/vecops_rvec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vecops_rvec"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/vecops/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vecops_rvec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/vecops/test/CMakeFiles/vecops_rvec.dir/build: math/vecops/test/vecops_rvec
.PHONY : math/vecops/test/CMakeFiles/vecops_rvec.dir/build

math/vecops/test/CMakeFiles/vecops_rvec.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/vecops/test && $(CMAKE_COMMAND) -P CMakeFiles/vecops_rvec.dir/cmake_clean.cmake
.PHONY : math/vecops/test/CMakeFiles/vecops_rvec.dir/clean

math/vecops/test/CMakeFiles/vecops_rvec.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/vecops/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/vecops/test /Users/abhiacherjee/Documents/rootbench/root/math/vecops/test/CMakeFiles/vecops_rvec.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/vecops/test/CMakeFiles/vecops_rvec.dir/depend

