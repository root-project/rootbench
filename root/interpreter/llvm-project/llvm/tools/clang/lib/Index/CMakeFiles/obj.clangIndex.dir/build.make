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
include interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.make

# Include the progress variables for this target.
include interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/progress.make

# Include the compile flags for this target's objects.
include interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/CommentToXML.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o -MF CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/CommentToXML.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/CommentToXML.cpp > CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/CommentToXML.cpp -o CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/FileIndexRecord.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o -MF CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/FileIndexRecord.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/FileIndexRecord.cpp > CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/FileIndexRecord.cpp -o CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexBody.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o -MF CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexBody.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexBody.cpp > CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexBody.cpp -o CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexDecl.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o -MF CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexDecl.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexDecl.cpp > CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexDecl.cpp -o CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingAction.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o -MF CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingAction.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingAction.cpp > CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingAction.cpp -o CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingContext.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o -MF CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingContext.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingContext.cpp > CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexingContext.cpp -o CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexSymbol.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o -MF CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexSymbol.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexSymbol.cpp > CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexSymbol.cpp -o CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexTypeSourceInfo.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o -MF CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexTypeSourceInfo.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexTypeSourceInfo.cpp > CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/IndexTypeSourceInfo.cpp -o CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.s

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/flags.make
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/USRGeneration.cpp
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o -MF CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o.d -o CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o -c /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/USRGeneration.cpp

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/USRGeneration.cpp > CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.i

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index/USRGeneration.cpp -o CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.s

obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/CommentToXML.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/FileIndexRecord.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexBody.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexDecl.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingAction.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexingContext.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexSymbol.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/IndexTypeSourceInfo.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/USRGeneration.cpp.o
obj.clangIndex: interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/build.make
.PHONY : obj.clangIndex

# Rule to build all files generated by this target.
interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/build: obj.clangIndex
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/build

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index && $(CMAKE_COMMAND) -P CMakeFiles/obj.clangIndex.dir/cmake_clean.cmake
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/clean

interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/lib/Index /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index /Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : interpreter/llvm-project/llvm/tools/clang/lib/Index/CMakeFiles/obj.clangIndex.dir/depend

