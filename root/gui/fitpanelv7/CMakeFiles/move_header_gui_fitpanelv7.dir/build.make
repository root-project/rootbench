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

# Utility rule file for move_header_gui_fitpanelv7.

# Include any custom commands dependencies for this target.
include gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/compiler_depend.make

# Include the progress variables for this target.
include gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/progress.make

gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7: include/ROOT/RFitPanel.hxx
gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7: include/ROOT/RFitPanelModel.hxx

include/ROOT/RFitPanel.hxx: /Users/abhiacherjee/Documents/root_src/gui/fitpanelv7/inc/ROOT/RFitPanel.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying header /Users/abhiacherjee/Documents/root_src/gui/fitpanelv7/inc/ROOT/RFitPanel.hxx to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/fitpanelv7 && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/gui/fitpanelv7/inc/ROOT/RFitPanel.hxx /Users/abhiacherjee/Documents/rootbench/root/include/ROOT/RFitPanel.hxx

include/ROOT/RFitPanelModel.hxx: /Users/abhiacherjee/Documents/root_src/gui/fitpanelv7/inc/ROOT/RFitPanelModel.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Copying header /Users/abhiacherjee/Documents/root_src/gui/fitpanelv7/inc/ROOT/RFitPanelModel.hxx to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/fitpanelv7 && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/gui/fitpanelv7/inc/ROOT/RFitPanelModel.hxx /Users/abhiacherjee/Documents/rootbench/root/include/ROOT/RFitPanelModel.hxx

move_header_gui_fitpanelv7: gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7
move_header_gui_fitpanelv7: include/ROOT/RFitPanel.hxx
move_header_gui_fitpanelv7: include/ROOT/RFitPanelModel.hxx
move_header_gui_fitpanelv7: gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/build.make
.PHONY : move_header_gui_fitpanelv7

# Rule to build all files generated by this target.
gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/build: move_header_gui_fitpanelv7
.PHONY : gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/build

gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/gui/fitpanelv7 && $(CMAKE_COMMAND) -P CMakeFiles/move_header_gui_fitpanelv7.dir/cmake_clean.cmake
.PHONY : gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/clean

gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/gui/fitpanelv7 /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/gui/fitpanelv7 /Users/abhiacherjee/Documents/rootbench/root/gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : gui/fitpanelv7/CMakeFiles/move_header_gui_fitpanelv7.dir/depend

