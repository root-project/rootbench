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
include math/minuit2/test/CMakeFiles/PaulTest3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include math/minuit2/test/CMakeFiles/PaulTest3.dir/compiler_depend.make

# Include the progress variables for this target.
include math/minuit2/test/CMakeFiles/PaulTest3.dir/progress.make

# Include the compile flags for this target's objects.
include math/minuit2/test/CMakeFiles/PaulTest3.dir/flags.make

math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o: math/minuit2/test/CMakeFiles/PaulTest3.dir/flags.make
math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o: /Users/abhiacherjee/Documents/root_src/math/minuit2/test/MnSim/PaulTest3.cxx
math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o: math/minuit2/test/CMakeFiles/PaulTest3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit2/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o -MF CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o.d -o CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/minuit2/test/MnSim/PaulTest3.cxx

math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit2/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/minuit2/test/MnSim/PaulTest3.cxx > CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.i

math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit2/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/minuit2/test/MnSim/PaulTest3.cxx -o CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.s

# Object files for target PaulTest3
PaulTest3_OBJECTS = \
"CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o"

# External object files for target PaulTest3
PaulTest3_EXTERNAL_OBJECTS =

math/minuit2/test/PaulTest3: math/minuit2/test/CMakeFiles/PaulTest3.dir/MnSim/PaulTest3.cxx.o
math/minuit2/test/PaulTest3: math/minuit2/test/CMakeFiles/PaulTest3.dir/build.make
math/minuit2/test/PaulTest3: math/minuit2/test/libMinuit2TestMnSim.so
math/minuit2/test/PaulTest3: lib/libMinuit2.so
math/minuit2/test/PaulTest3: lib/libHist.so
math/minuit2/test/PaulTest3: lib/libMatrix.so
math/minuit2/test/PaulTest3: lib/libMathCore.so
math/minuit2/test/PaulTest3: lib/libImt.so
math/minuit2/test/PaulTest3: lib/libMultiProc.so
math/minuit2/test/PaulTest3: lib/libNet.so
math/minuit2/test/PaulTest3: lib/libRIO.so
math/minuit2/test/PaulTest3: lib/libThread.so
math/minuit2/test/PaulTest3: lib/libCore.so
math/minuit2/test/PaulTest3: math/minuit2/test/CMakeFiles/PaulTest3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PaulTest3"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit2/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PaulTest3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/minuit2/test/CMakeFiles/PaulTest3.dir/build: math/minuit2/test/PaulTest3
.PHONY : math/minuit2/test/CMakeFiles/PaulTest3.dir/build

math/minuit2/test/CMakeFiles/PaulTest3.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit2/test && $(CMAKE_COMMAND) -P CMakeFiles/PaulTest3.dir/cmake_clean.cmake
.PHONY : math/minuit2/test/CMakeFiles/PaulTest3.dir/clean

math/minuit2/test/CMakeFiles/PaulTest3.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/minuit2/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/minuit2/test /Users/abhiacherjee/Documents/rootbench/root/math/minuit2/test/CMakeFiles/PaulTest3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/minuit2/test/CMakeFiles/PaulTest3.dir/depend

