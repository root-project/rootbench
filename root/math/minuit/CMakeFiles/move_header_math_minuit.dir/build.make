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

# Utility rule file for move_header_math_minuit.

# Include any custom commands dependencies for this target.
include math/minuit/CMakeFiles/move_header_math_minuit.dir/compiler_depend.make

# Include the progress variables for this target.
include math/minuit/CMakeFiles/move_header_math_minuit.dir/progress.make

math/minuit/CMakeFiles/move_header_math_minuit: include/TFitter.h
math/minuit/CMakeFiles/move_header_math_minuit: include/TLinearFitter.h
math/minuit/CMakeFiles/move_header_math_minuit: include/TLinearMinimizer.h
math/minuit/CMakeFiles/move_header_math_minuit: include/TMinuit.h
math/minuit/CMakeFiles/move_header_math_minuit: include/TMinuitMinimizer.h

include/TFitter.h: /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TFitter.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying header /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TFitter.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TFitter.h /Users/abhiacherjee/Documents/rootbench/root/include/TFitter.h

include/TLinearFitter.h: /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TLinearFitter.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Copying header /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TLinearFitter.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TLinearFitter.h /Users/abhiacherjee/Documents/rootbench/root/include/TLinearFitter.h

include/TLinearMinimizer.h: /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TLinearMinimizer.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Copying header /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TLinearMinimizer.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TLinearMinimizer.h /Users/abhiacherjee/Documents/rootbench/root/include/TLinearMinimizer.h

include/TMinuit.h: /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TMinuit.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Copying header /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TMinuit.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TMinuit.h /Users/abhiacherjee/Documents/rootbench/root/include/TMinuit.h

include/TMinuitMinimizer.h: /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TMinuitMinimizer.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Copying header /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TMinuitMinimizer.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/math/minuit/inc/TMinuitMinimizer.h /Users/abhiacherjee/Documents/rootbench/root/include/TMinuitMinimizer.h

move_header_math_minuit: include/TFitter.h
move_header_math_minuit: include/TLinearFitter.h
move_header_math_minuit: include/TLinearMinimizer.h
move_header_math_minuit: include/TMinuit.h
move_header_math_minuit: include/TMinuitMinimizer.h
move_header_math_minuit: math/minuit/CMakeFiles/move_header_math_minuit
move_header_math_minuit: math/minuit/CMakeFiles/move_header_math_minuit.dir/build.make
.PHONY : move_header_math_minuit

# Rule to build all files generated by this target.
math/minuit/CMakeFiles/move_header_math_minuit.dir/build: move_header_math_minuit
.PHONY : math/minuit/CMakeFiles/move_header_math_minuit.dir/build

math/minuit/CMakeFiles/move_header_math_minuit.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && $(CMAKE_COMMAND) -P CMakeFiles/move_header_math_minuit.dir/cmake_clean.cmake
.PHONY : math/minuit/CMakeFiles/move_header_math_minuit.dir/clean

math/minuit/CMakeFiles/move_header_math_minuit.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/minuit /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/minuit /Users/abhiacherjee/Documents/rootbench/root/math/minuit/CMakeFiles/move_header_math_minuit.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/minuit/CMakeFiles/move_header_math_minuit.dir/depend

