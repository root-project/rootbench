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
include core/clingutils/CMakeFiles/complexDict.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/clingutils/CMakeFiles/complexDict.dir/compiler_depend.make

# Include the progress variables for this target.
include core/clingutils/CMakeFiles/complexDict.dir/progress.make

# Include the compile flags for this target's objects.
include core/clingutils/CMakeFiles/complexDict.dir/flags.make

core/clingutils/dummy.cxx:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating dummy.cxx"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E touch dummy.cxx

core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.o: core/clingutils/CMakeFiles/complexDict.dir/flags.make
core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.o: core/clingutils/dummy.cxx
core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.o: core/clingutils/CMakeFiles/complexDict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.o -MF CMakeFiles/complexDict.dir/dummy.cxx.o.d -o CMakeFiles/complexDict.dir/dummy.cxx.o -c /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/dummy.cxx

core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/complexDict.dir/dummy.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/dummy.cxx > CMakeFiles/complexDict.dir/dummy.cxx.i

core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/complexDict.dir/dummy.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/dummy.cxx -o CMakeFiles/complexDict.dir/dummy.cxx.s

# Object files for target complexDict
complexDict_OBJECTS = \
"CMakeFiles/complexDict.dir/dummy.cxx.o"

# External object files for target complexDict
complexDict_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/core/clingutils/CMakeFiles/G__complexDict.dir/G__complexDict.cxx.o"

lib/libcomplexDict.so: core/clingutils/CMakeFiles/complexDict.dir/dummy.cxx.o
lib/libcomplexDict.so: core/clingutils/CMakeFiles/G__complexDict.dir/G__complexDict.cxx.o
lib/libcomplexDict.so: core/clingutils/CMakeFiles/complexDict.dir/build.make
lib/libcomplexDict.so: lib/libCore.so
lib/libcomplexDict.so: core/clingutils/CMakeFiles/complexDict.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../lib/libcomplexDict.so"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/complexDict.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/clingutils/CMakeFiles/complexDict.dir/build: lib/libcomplexDict.so
.PHONY : core/clingutils/CMakeFiles/complexDict.dir/build

core/clingutils/CMakeFiles/complexDict.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && $(CMAKE_COMMAND) -P CMakeFiles/complexDict.dir/cmake_clean.cmake
.PHONY : core/clingutils/CMakeFiles/complexDict.dir/clean

core/clingutils/CMakeFiles/complexDict.dir/depend: core/clingutils/dummy.cxx
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/core/clingutils /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/core/clingutils /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/CMakeFiles/complexDict.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : core/clingutils/CMakeFiles/complexDict.dir/depend

