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
include tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/compiler_depend.make

# Include the progress variables for this target.
include tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/progress.make

# Include the compile flags for this target's objects.
include tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/flags.make

tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o: tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/flags.make
tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o: /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/CustomStruct.cxx
tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o: tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o -MF CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o.d -o CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o -c /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/CustomStruct.cxx

tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CustomStruct.dir/CustomStruct.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/CustomStruct.cxx > CMakeFiles/CustomStruct.dir/CustomStruct.cxx.i

tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CustomStruct.dir/CustomStruct.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/CustomStruct.cxx -o CMakeFiles/CustomStruct.dir/CustomStruct.cxx.s

# Object files for target CustomStruct
CustomStruct_OBJECTS = \
"CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o"

# External object files for target CustomStruct
CustomStruct_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test/CMakeFiles/G__CustomStruct.dir/G__CustomStruct.cxx.o"

tree/ntuple/v7/test/libCustomStruct.so: tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/CustomStruct.cxx.o
tree/ntuple/v7/test/libCustomStruct.so: tree/ntuple/v7/test/CMakeFiles/G__CustomStruct.dir/G__CustomStruct.cxx.o
tree/ntuple/v7/test/libCustomStruct.so: tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/build.make
tree/ntuple/v7/test/libCustomStruct.so: lib/libRIO.so
tree/ntuple/v7/test/libCustomStruct.so: lib/libThread.so
tree/ntuple/v7/test/libCustomStruct.so: lib/libCore.so
tree/ntuple/v7/test/libCustomStruct.so: tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libCustomStruct.so"
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CustomStruct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/build: tree/ntuple/v7/test/libCustomStruct.so
.PHONY : tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/build

tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test && $(CMAKE_COMMAND) -P CMakeFiles/CustomStruct.dir/cmake_clean.cmake
.PHONY : tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/clean

tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test /Users/abhiacherjee/Documents/rootbench/root/tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tree/ntuple/v7/test/CMakeFiles/CustomStruct.dir/depend

