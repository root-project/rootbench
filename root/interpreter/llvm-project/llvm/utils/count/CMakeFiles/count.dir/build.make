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
include interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/progress.make

# Include the compile flags for this target's objects.
include interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/flags.make

interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.o: interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/flags.make
interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/utils/count/count.c
interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.o: interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.o -MF CMakeFiles/count.dir/count.c.o.d -o CMakeFiles/count.dir/count.c.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/utils/count/count.c

interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/count.dir/count.c.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/utils/count/count.c > CMakeFiles/count.dir/count.c.i

interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/count.dir/count.c.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/utils/count/count.c -o CMakeFiles/count.dir/count.c.s

# Object files for target count
count_OBJECTS = \
"CMakeFiles/count.dir/count.c.o"

# External object files for target count
count_EXTERNAL_OBJECTS =

interpreter/llvm-project/llvm/bin/count: interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/count.c.o
interpreter/llvm-project/llvm/bin/count: interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/build.make
interpreter/llvm-project/llvm/bin/count: interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/count"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/count.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/build: interpreter/llvm-project/llvm/bin/count
.PHONY : interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/build

interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count && $(CMAKE_COMMAND) -P CMakeFiles/count.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/clean

interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/utils/count /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/utils/count/CMakeFiles/count.dir/depend

