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
include tree/readspeed/test/CMakeFiles/readspeed_general.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tree/readspeed/test/CMakeFiles/readspeed_general.dir/compiler_depend.make

# Include the progress variables for this target.
include tree/readspeed/test/CMakeFiles/readspeed_general.dir/progress.make

# Include the compile flags for this target's objects.
include tree/readspeed/test/CMakeFiles/readspeed_general.dir/flags.make

tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o: tree/readspeed/test/CMakeFiles/readspeed_general.dir/flags.make
tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o: /Users/abhiacherjee/Documents/root_src/tree/readspeed/test/readspeed_general.cxx
tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o: tree/readspeed/test/CMakeFiles/readspeed_general.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o -MF CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o.d -o CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o -c /Users/abhiacherjee/Documents/root_src/tree/readspeed/test/readspeed_general.cxx

tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/readspeed_general.dir/readspeed_general.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/tree/readspeed/test/readspeed_general.cxx > CMakeFiles/readspeed_general.dir/readspeed_general.cxx.i

tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/readspeed_general.dir/readspeed_general.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/tree/readspeed/test/readspeed_general.cxx -o CMakeFiles/readspeed_general.dir/readspeed_general.cxx.s

# Object files for target readspeed_general
readspeed_general_OBJECTS = \
"CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o"

# External object files for target readspeed_general
readspeed_general_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/CMakeFiles/ReadSpeed.dir/src/ReadSpeed.cxx.o" \
"/Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/CMakeFiles/ReadSpeed.dir/src/ReadSpeedCLI.cxx.o" \
"/Users/abhiacherjee/Documents/rootbench/root/core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o"

tree/readspeed/test/readspeed_general: tree/readspeed/test/CMakeFiles/readspeed_general.dir/readspeed_general.cxx.o
tree/readspeed/test/readspeed_general: tree/readspeed/CMakeFiles/ReadSpeed.dir/src/ReadSpeed.cxx.o
tree/readspeed/test/readspeed_general: tree/readspeed/CMakeFiles/ReadSpeed.dir/src/ReadSpeedCLI.cxx.o
tree/readspeed/test/readspeed_general: core/testsupport/CMakeFiles/TestSupport.dir/src/TestSupport.cxx.o
tree/readspeed/test/readspeed_general: tree/readspeed/test/CMakeFiles/readspeed_general.dir/build.make
tree/readspeed/test/readspeed_general: lib/libTreePlayer.so
tree/readspeed/test/readspeed_general: googletest-prefix/src/googletest-build/lib//libgtest_main.a
tree/readspeed/test/readspeed_general: googletest-prefix/src/googletest-build/lib//libgmock.a
tree/readspeed/test/readspeed_general: googletest-prefix/src/googletest-build/lib//libgmock_main.a
tree/readspeed/test/readspeed_general: lib/libTree.so
tree/readspeed/test/readspeed_general: lib/libGraf3d.so
tree/readspeed/test/readspeed_general: lib/libGpad.so
tree/readspeed/test/readspeed_general: lib/libGraf.so
tree/readspeed/test/readspeed_general: lib/libHist.so
tree/readspeed/test/readspeed_general: lib/libMatrix.so
tree/readspeed/test/readspeed_general: lib/libMathCore.so
tree/readspeed/test/readspeed_general: lib/libImt.so
tree/readspeed/test/readspeed_general: lib/libMultiProc.so
tree/readspeed/test/readspeed_general: lib/libNet.so
tree/readspeed/test/readspeed_general: lib/libRIO.so
tree/readspeed/test/readspeed_general: lib/libThread.so
tree/readspeed/test/readspeed_general: lib/libCore.so
tree/readspeed/test/readspeed_general: googletest-prefix/src/googletest-build/lib//libgtest.a
tree/readspeed/test/readspeed_general: tree/readspeed/test/CMakeFiles/readspeed_general.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable readspeed_general"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/readspeed_general.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tree/readspeed/test/CMakeFiles/readspeed_general.dir/build: tree/readspeed/test/readspeed_general
.PHONY : tree/readspeed/test/CMakeFiles/readspeed_general.dir/build

tree/readspeed/test/CMakeFiles/readspeed_general.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/test && $(CMAKE_COMMAND) -P CMakeFiles/readspeed_general.dir/cmake_clean.cmake
.PHONY : tree/readspeed/test/CMakeFiles/readspeed_general.dir/clean

tree/readspeed/test/CMakeFiles/readspeed_general.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/tree/readspeed/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/test /Users/abhiacherjee/Documents/rootbench/root/tree/readspeed/test/CMakeFiles/readspeed_general.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tree/readspeed/test/CMakeFiles/readspeed_general.dir/depend

