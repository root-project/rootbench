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
include interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/progress.make

# Include the compile flags for this target's objects.
include interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/flags.make

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/flags.make
interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/ErrorCollector.cpp
interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o -MF CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o.d -o CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/ErrorCollector.cpp

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/ErrorCollector.cpp > CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.i

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/ErrorCollector.cpp -o CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.s

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/flags.make
interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs.cpp
interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o -MF CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o.d -o CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs.cpp

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs.cpp > CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.i

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs.cpp -o CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.s

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/flags.make
interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o: interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs-driver.cpp
interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o -MF CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o.d -o CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o -c /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs-driver.cpp

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs-driver.cpp > CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.i

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs/llvm-ifs-driver.cpp -o CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.s

# Object files for target llvm-ifs
llvm__ifs_OBJECTS = \
"CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o" \
"CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o" \
"CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o"

# External object files for target llvm-ifs
llvm__ifs_EXTERNAL_OBJECTS =

interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/ErrorCollector.cpp.o
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs.cpp.o
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/llvm-ifs-driver.cpp.o
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/build.make
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMBinaryFormat.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMInterfaceStub.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMObject.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMSupport.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMTargetParser.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMTextAPI.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMObjectYAML.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMOption.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMObject.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMTextAPI.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMIRReader.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMBitReader.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMAsmParser.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMCore.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMRemarks.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMBitstreamReader.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMMCParser.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMMC.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMBinaryFormat.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMTargetParser.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMDebugInfoCodeView.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMSupport.a
interpreter/llvm-project/llvm/bin/llvm-ifs: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/lib/libz.tbd
interpreter/llvm-project/llvm/bin/llvm-ifs: /opt/homebrew/lib/libzstd.dylib
interpreter/llvm-project/llvm/bin/llvm-ifs: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/lib/libcurses.tbd
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/lib/libLLVMDemangle.a
interpreter/llvm-project/llvm/bin/llvm-ifs: interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../bin/llvm-ifs"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/llvm-ifs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/build: interpreter/llvm-project/llvm/bin/llvm-ifs
.PHONY : interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/build

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs && $(CMAKE_COMMAND) -P CMakeFiles/llvm-ifs.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/clean

interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/tools/llvm-ifs /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/tools/llvm-ifs/CMakeFiles/llvm-ifs.dir/depend

