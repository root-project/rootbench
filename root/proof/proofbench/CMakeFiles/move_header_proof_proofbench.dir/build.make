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

# Utility rule file for move_header_proof_proofbench.

# Include any custom commands dependencies for this target.
include proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/compiler_depend.make

# Include the progress variables for this target.
include proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/progress.make

proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofBench.h
proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofBenchDataSet.h
proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofBenchRun.h
proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofBenchRunCPU.h
proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofBenchRunDataRead.h
proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofBenchTypes.h
proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofNodes.h
proof/proofbench/CMakeFiles/move_header_proof_proofbench: include/TProofPerfAnalysis.h

include/TProofBench.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBench.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBench.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBench.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofBench.h

include/TProofBenchDataSet.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchDataSet.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchDataSet.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchDataSet.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofBenchDataSet.h

include/TProofBenchRun.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRun.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRun.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRun.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofBenchRun.h

include/TProofBenchRunCPU.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRunCPU.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRunCPU.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRunCPU.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofBenchRunCPU.h

include/TProofBenchRunDataRead.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRunDataRead.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRunDataRead.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchRunDataRead.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofBenchRunDataRead.h

include/TProofBenchTypes.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchTypes.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchTypes.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofBenchTypes.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofBenchTypes.h

include/TProofNodes.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofNodes.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofNodes.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofNodes.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofNodes.h

include/TProofPerfAnalysis.h: /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofPerfAnalysis.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Copying header /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofPerfAnalysis.h to /Users/abhiacherjee/Documents/rootbench/root/include"
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy /Users/abhiacherjee/Documents/root_src/proof/proofbench/inc/TProofPerfAnalysis.h /Users/abhiacherjee/Documents/rootbench/root/include/TProofPerfAnalysis.h

move_header_proof_proofbench: include/TProofBench.h
move_header_proof_proofbench: include/TProofBenchDataSet.h
move_header_proof_proofbench: include/TProofBenchRun.h
move_header_proof_proofbench: include/TProofBenchRunCPU.h
move_header_proof_proofbench: include/TProofBenchRunDataRead.h
move_header_proof_proofbench: include/TProofBenchTypes.h
move_header_proof_proofbench: include/TProofNodes.h
move_header_proof_proofbench: include/TProofPerfAnalysis.h
move_header_proof_proofbench: proof/proofbench/CMakeFiles/move_header_proof_proofbench
move_header_proof_proofbench: proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/build.make
.PHONY : move_header_proof_proofbench

# Rule to build all files generated by this target.
proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/build: move_header_proof_proofbench
.PHONY : proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/build

proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench && $(CMAKE_COMMAND) -P CMakeFiles/move_header_proof_proofbench.dir/cmake_clean.cmake
.PHONY : proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/clean

proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/proof/proofbench /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench /Users/abhiacherjee/Documents/rootbench/root/proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : proof/proofbench/CMakeFiles/move_header_proof_proofbench.dir/depend

