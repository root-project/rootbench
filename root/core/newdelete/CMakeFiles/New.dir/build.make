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
include core/newdelete/CMakeFiles/New.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/newdelete/CMakeFiles/New.dir/compiler_depend.make

# Include the progress variables for this target.
include core/newdelete/CMakeFiles/New.dir/progress.make

# Include the compile flags for this target's objects.
include core/newdelete/CMakeFiles/New.dir/flags.make

core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.o: core/newdelete/CMakeFiles/New.dir/flags.make
core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.o: /Users/abhiacherjee/Documents/root_src/core/newdelete/src/NewDelete.cxx
core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.o: core/newdelete/CMakeFiles/New.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/newdelete && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.o -MF CMakeFiles/New.dir/src/NewDelete.cxx.o.d -o CMakeFiles/New.dir/src/NewDelete.cxx.o -c /Users/abhiacherjee/Documents/root_src/core/newdelete/src/NewDelete.cxx

core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/New.dir/src/NewDelete.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/newdelete && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/core/newdelete/src/NewDelete.cxx > CMakeFiles/New.dir/src/NewDelete.cxx.i

core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/New.dir/src/NewDelete.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/newdelete && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/core/newdelete/src/NewDelete.cxx -o CMakeFiles/New.dir/src/NewDelete.cxx.s

# Object files for target New
New_OBJECTS = \
"CMakeFiles/New.dir/src/NewDelete.cxx.o"

# External object files for target New
New_EXTERNAL_OBJECTS =

lib/libNew.so: core/newdelete/CMakeFiles/New.dir/src/NewDelete.cxx.o
lib/libNew.so: core/newdelete/CMakeFiles/New.dir/build.make
lib/libNew.so: lib/libCore.so
lib/libNew.so: core/newdelete/CMakeFiles/New.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libNew.so"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/newdelete && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/New.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/newdelete/CMakeFiles/New.dir/build: lib/libNew.so
.PHONY : core/newdelete/CMakeFiles/New.dir/build

core/newdelete/CMakeFiles/New.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/core/newdelete && $(CMAKE_COMMAND) -P CMakeFiles/New.dir/cmake_clean.cmake
.PHONY : core/newdelete/CMakeFiles/New.dir/clean

core/newdelete/CMakeFiles/New.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/core/newdelete /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/core/newdelete /Users/abhiacherjee/Documents/rootbench/root/core/newdelete/CMakeFiles/New.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : core/newdelete/CMakeFiles/New.dir/depend

