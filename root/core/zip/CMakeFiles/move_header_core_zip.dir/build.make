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

# Utility rule file for move_header_core_zip.

# Include any custom commands dependencies for this target.
include core/zip/CMakeFiles/move_header_core_zip.dir/compiler_depend.make

# Include the progress variables for this target.
include core/zip/CMakeFiles/move_header_core_zip.dir/progress.make

core/zip/CMakeFiles/move_header_core_zip: include/Compression.h
core/zip/CMakeFiles/move_header_core_zip: include/RZip.h

include/Compression.h: /Users/abhiacherjee/Documents/root_src/core/zip/inc/Compression.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying header /Users/abhiacherjee/Documents/root_src/core/zip/inc/Compression.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/zip && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/core/zip/inc/Compression.h /Users/abhiacherjee/Documents/rootbench/root/include/Compression.h

include/RZip.h: /Users/abhiacherjee/Documents/root_src/core/zip/inc/RZip.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Copying header /Users/abhiacherjee/Documents/root_src/core/zip/inc/RZip.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/zip && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/core/zip/inc/RZip.h /Users/abhiacherjee/Documents/rootbench/root/include/RZip.h

move_header_core_zip: core/zip/CMakeFiles/move_header_core_zip
move_header_core_zip: include/Compression.h
move_header_core_zip: include/RZip.h
move_header_core_zip: core/zip/CMakeFiles/move_header_core_zip.dir/build.make
.PHONY : move_header_core_zip

# Rule to build all files generated by this target.
core/zip/CMakeFiles/move_header_core_zip.dir/build: move_header_core_zip
.PHONY : core/zip/CMakeFiles/move_header_core_zip.dir/build

core/zip/CMakeFiles/move_header_core_zip.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/core/zip && $(CMAKE_COMMAND) -P CMakeFiles/move_header_core_zip.dir/cmake_clean.cmake
.PHONY : core/zip/CMakeFiles/move_header_core_zip.dir/clean

core/zip/CMakeFiles/move_header_core_zip.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/core/zip /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/core/zip /Users/abhiacherjee/Documents/rootbench/root/core/zip/CMakeFiles/move_header_core_zip.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : core/zip/CMakeFiles/move_header_core_zip.dir/depend

