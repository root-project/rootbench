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

# Utility rule file for DAVIX.

# Include any custom commands dependencies for this target.
include builtins/davix/CMakeFiles/DAVIX.dir/compiler_depend.make

# Include the progress variables for this target.
include builtins/davix/CMakeFiles/DAVIX.dir/progress.make

builtins/davix/CMakeFiles/DAVIX: builtins/davix/CMakeFiles/DAVIX-complete

builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-install
builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-mkdir
builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download
builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-update
builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-patch
builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure
builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-build
builtins/davix/CMakeFiles/DAVIX-complete: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E make_directory /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/CMakeFiles
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/CMakeFiles/DAVIX-complete
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-done

builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-build: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -Dmake=$(MAKE) -P /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-build-RelWithDebInfo.cmake
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-build

builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure: builtins/davix/DAVIX-prefix/tmp/DAVIX-cfgcmd.txt
builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure: builtins/davix/DAVIX-prefix/tmp/DAVIX-cache-RelWithDebInfo.cmake
builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -P /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure-RelWithDebInfo.cmake
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure

builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/download-DAVIX.cmake
builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-urlinfo.txt
builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -P /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download-RelWithDebInfo.cmake
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download

builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-install: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing install step for 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -Dmake=$(MAKE) -P /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-install-RelWithDebInfo.cmake
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-install

builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -Dcfgdir= -P /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/tmp/DAVIX-mkdirs.cmake
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-mkdir

builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-patch: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-patch-info.txt
builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-patch: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E echo_append
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-patch

builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-update: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-update-info.txt
builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-update: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'DAVIX'"
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E echo_append
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-update

DAVIX: builtins/davix/CMakeFiles/DAVIX
DAVIX: builtins/davix/CMakeFiles/DAVIX-complete
DAVIX: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-build
DAVIX: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-configure
DAVIX: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-download
DAVIX: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-install
DAVIX: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-mkdir
DAVIX: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-patch
DAVIX: builtins/davix/DAVIX-prefix/src/DAVIX-stamp/DAVIX-update
DAVIX: builtins/davix/CMakeFiles/DAVIX.dir/build.make
.PHONY : DAVIX

# Rule to build all files generated by this target.
builtins/davix/CMakeFiles/DAVIX.dir/build: DAVIX
.PHONY : builtins/davix/CMakeFiles/DAVIX.dir/build

builtins/davix/CMakeFiles/DAVIX.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/builtins/davix && $(CMAKE_COMMAND) -P CMakeFiles/DAVIX.dir/cmake_clean.cmake
.PHONY : builtins/davix/CMakeFiles/DAVIX.dir/clean

builtins/davix/CMakeFiles/DAVIX.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/builtins/davix /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/builtins/davix /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/CMakeFiles/DAVIX.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : builtins/davix/CMakeFiles/DAVIX.dir/depend

