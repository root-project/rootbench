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

# Utility rule file for webassembly-resource-headers.

# Include any custom commands dependencies for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/progress.make

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/wasm_simd128.h

interpreter/llvm-project/llvm/lib/clang/16/include/wasm_simd128.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/wasm_simd128.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying clang's wasm_simd128.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/wasm_simd128.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/wasm_simd128.h

webassembly-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/wasm_simd128.h
webassembly-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers
webassembly-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/build.make
.PHONY : webassembly-resource-headers

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/build: webassembly-resource-headers
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/build

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && $(CMAKE_COMMAND) -P CMakeFiles/webassembly-resource-headers.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/clean

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/webassembly-resource-headers.dir/depend

