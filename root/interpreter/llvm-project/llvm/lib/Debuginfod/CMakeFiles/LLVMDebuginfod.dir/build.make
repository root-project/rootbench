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
include interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/progress.make

# Include the compile flags for this target's objects.
include interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/flags.make

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/flags.make
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/BuildIDFetcher.cpp
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o -MF CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o.d -o CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/BuildIDFetcher.cpp

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/BuildIDFetcher.cpp > CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.i

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/BuildIDFetcher.cpp -o CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.s

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/flags.make
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/Debuginfod.cpp
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o -MF CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o.d -o CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/Debuginfod.cpp

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/Debuginfod.cpp > CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.i

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/Debuginfod.cpp -o CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.s

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/flags.make
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPClient.cpp
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o -MF CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o.d -o CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPClient.cpp

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPClient.cpp > CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.i

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPClient.cpp -o CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.s

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/flags.make
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPServer.cpp
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o -MF CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o.d -o CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPServer.cpp

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPServer.cpp > CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.i

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod/HTTPServer.cpp -o CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.s

# Object files for target LLVMDebuginfod
LLVMDebuginfod_OBJECTS = \
"CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o" \
"CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o" \
"CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o" \
"CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o"

# External object files for target LLVMDebuginfod
LLVMDebuginfod_EXTERNAL_OBJECTS =

interpreter/llvm-project/llvm/lib/libLLVMDebuginfod.a: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/BuildIDFetcher.cpp.o
interpreter/llvm-project/llvm/lib/libLLVMDebuginfod.a: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/Debuginfod.cpp.o
interpreter/llvm-project/llvm/lib/libLLVMDebuginfod.a: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPClient.cpp.o
interpreter/llvm-project/llvm/lib/libLLVMDebuginfod.a: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/HTTPServer.cpp.o
interpreter/llvm-project/llvm/lib/libLLVMDebuginfod.a: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/build.make
interpreter/llvm-project/llvm/lib/libLLVMDebuginfod.a: interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library ../libLLVMDebuginfod.a"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && $(CMAKE_COMMAND) -P CMakeFiles/LLVMDebuginfod.dir/cmake_clean_target.cmake
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMDebuginfod.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/build: interpreter/llvm-project/llvm/lib/libLLVMDebuginfod.a
.PHONY : interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/build

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod && $(CMAKE_COMMAND) -P CMakeFiles/LLVMDebuginfod.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/clean

interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib/Debuginfod /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/lib/Debuginfod/CMakeFiles/LLVMDebuginfod.dir/depend

