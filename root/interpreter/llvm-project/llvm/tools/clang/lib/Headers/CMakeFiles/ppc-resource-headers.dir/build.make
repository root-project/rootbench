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

# Utility rule file for ppc-resource-headers.

# Include any custom commands dependencies for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/progress.make

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/altivec.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/mmintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/xmmintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/mm_malloc.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/emmintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/pmmintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/tmmintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/smmintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/bmiintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/bmi2intrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/immintrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/x86intrin.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/x86gprintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/altivec.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/altivec.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying clang's altivec.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/altivec.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/altivec.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/bmi2intrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/bmi2intrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Copying clang's ppc_wrappers/bmi2intrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/bmi2intrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/bmi2intrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/bmiintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/bmiintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Copying clang's ppc_wrappers/bmiintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/bmiintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/bmiintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/emmintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/emmintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Copying clang's ppc_wrappers/emmintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/emmintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/emmintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/immintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/immintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Copying clang's ppc_wrappers/immintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/immintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/immintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/mm_malloc.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/mm_malloc.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Copying clang's ppc_wrappers/mm_malloc.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/mm_malloc.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/mm_malloc.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/mmintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/mmintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Copying clang's ppc_wrappers/mmintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/mmintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/mmintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/pmmintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/pmmintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Copying clang's ppc_wrappers/pmmintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/pmmintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/pmmintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/smmintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/smmintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Copying clang's ppc_wrappers/smmintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/smmintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/smmintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/tmmintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/tmmintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Copying clang's ppc_wrappers/tmmintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/tmmintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/tmmintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/x86gprintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/x86gprintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Copying clang's ppc_wrappers/x86gprintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/x86gprintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/x86gprintrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/x86intrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/x86intrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Copying clang's ppc_wrappers/x86intrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/x86intrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/x86intrin.h

interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/xmmintrin.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/xmmintrin.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Copying clang's ppc_wrappers/xmmintrin.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/ppc_wrappers/xmmintrin.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/ppc_wrappers/xmmintrin.h

ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/altivec.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/bmi2intrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/bmiintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/emmintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/immintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/mm_malloc.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/mmintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/pmmintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/smmintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/tmmintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/x86gprintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/x86intrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/ppc_wrappers/xmmintrin.h
ppc-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers
ppc-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/build.make
.PHONY : ppc-resource-headers

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/build: ppc-resource-headers
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/build

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && $(CMAKE_COMMAND) -P CMakeFiles/ppc-resource-headers.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/clean

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/ppc-resource-headers.dir/depend

