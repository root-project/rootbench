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

# Utility rule file for arm-resource-headers.

# Include any custom commands dependencies for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/progress.make

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/arm_cmse.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/armintr.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h

interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: interpreter/llvm-project/llvm/bin/clang-tblgen
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: interpreter/llvm-project/llvm/bin/clang-tblgen
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/CodeGen/SDNodeProperties.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/CodeGen/ValueTypes.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Frontend/Directive/DirectiveBase.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Frontend/OpenACC/ACC.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Frontend/OpenMP/OMP.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/Attributes.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/Intrinsics.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsAArch64.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsAMDGPU.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsARM.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsBPF.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsDirectX.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsHexagon.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsHexagonDep.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsLoongArch.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsMips.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsNVVM.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsPowerPC.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsRISCV.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsRISCVXTHead.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsSPIRV.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsSystemZ.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsVE.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsVEVL.gen.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsWebAssembly.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsX86.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsXCore.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Option/OptParser.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/TableGen/Automaton.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/TableGen/SearchableTable.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GenericOpcodes.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/Combine.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/RegisterBank.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/SelectionDAGCompat.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/Target.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/Target.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetCallingConv.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetInstrPredicate.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetItinerary.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetPfmCounters.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetSchedule.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetSelectionDAG.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include/clang/Basic/arm_cde.td
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building arm_cde.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && ../../../../bin/clang-tblgen -gen-arm-cde-header -I /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include/clang/Basic/ -I /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers -I/Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include -I/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include -I/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/include -I/Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include -no-warn-on-unused-template-args /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include/clang/Basic/arm_cde.td --write-if-changed -o /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h

interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: interpreter/llvm-project/llvm/bin/clang-tblgen
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: interpreter/llvm-project/llvm/bin/clang-tblgen
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/CodeGen/SDNodeProperties.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/CodeGen/ValueTypes.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Frontend/Directive/DirectiveBase.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Frontend/OpenACC/ACC.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Frontend/OpenMP/OMP.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/Attributes.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/Intrinsics.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsAArch64.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsAMDGPU.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsARM.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsBPF.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsDirectX.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsHexagon.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsHexagonDep.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsLoongArch.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsMips.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsNVVM.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsPowerPC.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsRISCV.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsRISCVXTHead.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsSPIRV.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsSystemZ.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsVE.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsVEVL.gen.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsWebAssembly.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsX86.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/IR/IntrinsicsXCore.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Option/OptParser.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/TableGen/Automaton.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/TableGen/SearchableTable.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GenericOpcodes.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/Combine.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/RegisterBank.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/SelectionDAGCompat.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/GlobalISel/Target.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/Target.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetCallingConv.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetInstrPredicate.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetItinerary.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetPfmCounters.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetSchedule.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm/Target/TargetSelectionDAG.td
interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include/clang/Basic/arm_mve.td
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building arm_mve.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && ../../../../bin/clang-tblgen -gen-arm-mve-header -I /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include/clang/Basic/ -I /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers -I/Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include -I/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include -I/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/include -I/Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include -no-warn-on-unused-template-args /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include/clang/Basic/arm_mve.td --write-if-changed -o /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h

interpreter/llvm-project/llvm/lib/clang/16/include/arm_cmse.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/arm_cmse.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Copying clang's arm_cmse.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/arm_cmse.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/arm_cmse.h

interpreter/llvm-project/llvm/lib/clang/16/include/armintr.h: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/armintr.h
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Copying clang's armintr.h..."
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E copy_if_different /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers/armintr.h /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/clang/16/include/armintr.h

arm-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/arm_cmse.h
arm-resource-headers: interpreter/llvm-project/llvm/lib/clang/16/include/armintr.h
arm-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers
arm-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_cde.h
arm-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/arm_mve.h
arm-resource-headers: interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/build.make
.PHONY : arm-resource-headers

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/build: arm-resource-headers
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/build

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers && $(CMAKE_COMMAND) -P CMakeFiles/arm-resource-headers.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/clean

interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Headers /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Headers/CMakeFiles/arm-resource-headers.dir/depend

