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
include gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/compiler_depend.make

# Include the progress variables for this target.
include gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/progress.make

# Include the compile flags for this target's objects.
include gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/flags.make

gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o: gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/flags.make
gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o: /Users/abhiacherjee/Documents/root_src/gui/browsable/src/TLeafDraw6Provider.cxx
gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o: gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/browsable && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o -MF CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o.d -o CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o -c /Users/abhiacherjee/Documents/root_src/gui/browsable/src/TLeafDraw6Provider.cxx

gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/browsable && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/gui/browsable/src/TLeafDraw6Provider.cxx > CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.i

gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/browsable && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/gui/browsable/src/TLeafDraw6Provider.cxx -o CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.s

# Object files for target ROOTLeafDraw6Provider
ROOTLeafDraw6Provider_OBJECTS = \
"CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o"

# External object files for target ROOTLeafDraw6Provider
ROOTLeafDraw6Provider_EXTERNAL_OBJECTS =

lib/libROOTLeafDraw6Provider.so: gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/src/TLeafDraw6Provider.cxx.o
lib/libROOTLeafDraw6Provider.so: gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/build.make
lib/libROOTLeafDraw6Provider.so: lib/libROOTBrowsable.so
lib/libROOTLeafDraw6Provider.so: lib/libTree.so
lib/libROOTLeafDraw6Provider.so: lib/libGpad.so
lib/libROOTLeafDraw6Provider.so: lib/libGraf.so
lib/libROOTLeafDraw6Provider.so: lib/libHist.so
lib/libROOTLeafDraw6Provider.so: lib/libMatrix.so
lib/libROOTLeafDraw6Provider.so: lib/libMathCore.so
lib/libROOTLeafDraw6Provider.so: lib/libImt.so
lib/libROOTLeafDraw6Provider.so: lib/libMultiProc.so
lib/libROOTLeafDraw6Provider.so: lib/libNet.so
lib/libROOTLeafDraw6Provider.so: lib/libRIO.so
lib/libROOTLeafDraw6Provider.so: lib/libThread.so
lib/libROOTLeafDraw6Provider.so: lib/libCore.so
lib/libROOTLeafDraw6Provider.so: gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libROOTLeafDraw6Provider.so"
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/browsable && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ROOTLeafDraw6Provider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/build: lib/libROOTLeafDraw6Provider.so
.PHONY : gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/build

gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/browsable && $(CMAKE_COMMAND) -P CMakeFiles/ROOTLeafDraw6Provider.dir/cmake_clean.cmake
.PHONY : gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/clean

gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/gui/browsable /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/gui/browsable /Users/abhiacherjee/Documents/rootbench/root/gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : gui/browsable/CMakeFiles/ROOTLeafDraw6Provider.dir/depend

