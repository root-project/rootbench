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

# Utility rule file for install-LLVMInstrumentation.

# Include any custom commands dependencies for this target.
include interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/progress.make

interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Transforms/Instrumentation && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -DCMAKE_INSTALL_COMPONENT="LLVMInstrumentation" -P /Users/abhiacherjee/Documents/rootbench/root/cmake_install.cmake

install-LLVMInstrumentation: interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation
install-LLVMInstrumentation: interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/build.make
.PHONY : install-LLVMInstrumentation

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/build: install-LLVMInstrumentation
.PHONY : interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/build

interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Transforms/Instrumentation && $(CMAKE_COMMAND) -P CMakeFiles/install-LLVMInstrumentation.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/clean

interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Transforms/Instrumentation /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Transforms/Instrumentation /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/lib/Transforms/Instrumentation/CMakeFiles/install-LLVMInstrumentation.dir/depend

