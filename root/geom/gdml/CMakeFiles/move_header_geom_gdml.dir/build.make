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

# Utility rule file for move_header_geom_gdml.

# Include any custom commands dependencies for this target.
include geom/gdml/CMakeFiles/move_header_geom_gdml.dir/compiler_depend.make

# Include the progress variables for this target.
include geom/gdml/CMakeFiles/move_header_geom_gdml.dir/progress.make

geom/gdml/CMakeFiles/move_header_geom_gdml: include/TGDMLParse.h
geom/gdml/CMakeFiles/move_header_geom_gdml: include/TGDMLWrite.h

include/TGDMLParse.h: /Users/abhiacherjee/Documents/root_src/geom/gdml/inc/TGDMLParse.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying header /Users/abhiacherjee/Documents/root_src/geom/gdml/inc/TGDMLParse.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/gdml && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/geom/gdml/inc/TGDMLParse.h /Users/abhiacherjee/Documents/rootbench/root/include/TGDMLParse.h

include/TGDMLWrite.h: /Users/abhiacherjee/Documents/root_src/geom/gdml/inc/TGDMLWrite.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Copying header /Users/abhiacherjee/Documents/root_src/geom/gdml/inc/TGDMLWrite.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/gdml && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/geom/gdml/inc/TGDMLWrite.h /Users/abhiacherjee/Documents/rootbench/root/include/TGDMLWrite.h

move_header_geom_gdml: geom/gdml/CMakeFiles/move_header_geom_gdml
move_header_geom_gdml: include/TGDMLParse.h
move_header_geom_gdml: include/TGDMLWrite.h
move_header_geom_gdml: geom/gdml/CMakeFiles/move_header_geom_gdml.dir/build.make
.PHONY : move_header_geom_gdml

# Rule to build all files generated by this target.
geom/gdml/CMakeFiles/move_header_geom_gdml.dir/build: move_header_geom_gdml
.PHONY : geom/gdml/CMakeFiles/move_header_geom_gdml.dir/build

geom/gdml/CMakeFiles/move_header_geom_gdml.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/gdml && $(CMAKE_COMMAND) -P CMakeFiles/move_header_geom_gdml.dir/cmake_clean.cmake
.PHONY : geom/gdml/CMakeFiles/move_header_geom_gdml.dir/clean

geom/gdml/CMakeFiles/move_header_geom_gdml.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/geom/gdml /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/geom/gdml /Users/abhiacherjee/Documents/rootbench/root/geom/gdml/CMakeFiles/move_header_geom_gdml.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : geom/gdml/CMakeFiles/move_header_geom_gdml.dir/depend

