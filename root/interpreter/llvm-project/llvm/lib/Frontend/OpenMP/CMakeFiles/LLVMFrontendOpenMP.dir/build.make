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
include interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/progress.make

# Include the compile flags for this target's objects.
include interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/flags.make

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/flags.make
interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMP.cpp
interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o -MF CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o.d -o CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMP.cpp

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMP.cpp > CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.i

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMP.cpp -o CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.s

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/flags.make
interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPContext.cpp
interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o -MF CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o.d -o CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPContext.cpp

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPContext.cpp > CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.i

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPContext.cpp -o CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.s

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/flags.make
interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPIRBuilder.cpp
interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o -MF CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o.d -o CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPIRBuilder.cpp

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPIRBuilder.cpp > CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.i

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/OMPIRBuilder.cpp -o CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.s

# Object files for target LLVMFrontendOpenMP
LLVMFrontendOpenMP_OBJECTS = \
"CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o" \
"CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o" \
"CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o"

# External object files for target LLVMFrontendOpenMP
LLVMFrontendOpenMP_EXTERNAL_OBJECTS =

interpreter/llvm-project/llvm/lib/libLLVMFrontendOpenMP.a: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMP.cpp.o
interpreter/llvm-project/llvm/lib/libLLVMFrontendOpenMP.a: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPContext.cpp.o
interpreter/llvm-project/llvm/lib/libLLVMFrontendOpenMP.a: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/OMPIRBuilder.cpp.o
interpreter/llvm-project/llvm/lib/libLLVMFrontendOpenMP.a: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/build.make
interpreter/llvm-project/llvm/lib/libLLVMFrontendOpenMP.a: interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../libLLVMFrontendOpenMP.a"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && $(CMAKE_COMMAND) -P CMakeFiles/LLVMFrontendOpenMP.dir/cmake_clean_target.cmake
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMFrontendOpenMP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/build: interpreter/llvm-project/llvm/lib/libLLVMFrontendOpenMP.a
.PHONY : interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/build

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP && $(CMAKE_COMMAND) -P CMakeFiles/LLVMFrontendOpenMP.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/clean

interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Frontend/OpenMP /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/lib/Frontend/OpenMP/CMakeFiles/LLVMFrontendOpenMP.dir/depend

