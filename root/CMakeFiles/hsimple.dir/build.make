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

# Utility rule file for hsimple.

# Include any custom commands dependencies for this target.
include CMakeFiles/hsimple.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hsimple.dir/progress.make

CMakeFiles/hsimple: tutorials/hsimple.root

tutorials/hsimple.root: bin/root
tutorials/hsimple.root: lib/libCling.so
tutorials/hsimple.root: lib/libHist.so
tutorials/hsimple.root: lib/libTree.so
tutorials/hsimple.root: lib/libGpad.so
tutorials/hsimple.root: lib/libGraf.so
tutorials/hsimple.root: lib/libHistPainter.so
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating tutorials/hsimple.root"
	cd /Users/abhiacherjee/Documents/rootbench/root/tutorials && DYLD_LIBRARY_PATH=/Users/abhiacherjee/Documents/rootbench/root/lib: ROOTIGNOREPREFIX=1 ROOT_HIST=0 /Users/abhiacherjee/Documents/rootbench/root/bin/root.exe -l -q -b -n -x hsimple.C -e return

hsimple: CMakeFiles/hsimple
hsimple: tutorials/hsimple.root
hsimple: CMakeFiles/hsimple.dir/build.make
.PHONY : hsimple

# Rule to build all files generated by this target.
CMakeFiles/hsimple.dir/build: hsimple
.PHONY : CMakeFiles/hsimple.dir/build

CMakeFiles/hsimple.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hsimple.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hsimple.dir/clean

CMakeFiles/hsimple.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/CMakeFiles/hsimple.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hsimple.dir/depend

