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
include core/clingutils/CMakeFiles/G__multimapDict.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/clingutils/CMakeFiles/G__multimapDict.dir/compiler_depend.make

# Include the progress variables for this target.
include core/clingutils/CMakeFiles/G__multimapDict.dir/progress.make

# Include the compile flags for this target's objects.
include core/clingutils/CMakeFiles/G__multimapDict.dir/flags.make

core/clingutils/G__multimapDict.cxx: /Users/abhiacherjee/Documents/root_src/core/clingutils/src/multimapLinkdef.h
core/clingutils/G__multimapDict.cxx: /Users/abhiacherjee/Documents/root_src/core/clingutils/src/multimapLinkdef.h
core/clingutils/G__multimapDict.cxx: lib/libCore.so
core/clingutils/G__multimapDict.cxx: include/module.modulemap
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating G__multimapDict.cxx, ../../lib/libmultimapDict.rootmap"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E env LD_LIBRARY_PATH=/Users/abhiacherjee/Documents/rootbench/root/lib: /Users/abhiacherjee/Documents/rootbench/root/core/rootcling_stage1/src/rootcling_stage1 -v2 -f G__multimapDict.cxx -s /Users/abhiacherjee/Documents/rootbench/root/lib/libmultimapDict.so -m Core.pcm -excludePath /Users/abhiacherjee/Documents/root_src -excludePath /Users/abhiacherjee/Documents/rootbench/root/ginclude -excludePath /Users/abhiacherjee/Documents/rootbench/root/externals -excludePath /Users/abhiacherjee/Documents/rootbench/root/builtins -rml libmultimapDict.so -rmf /Users/abhiacherjee/Documents/rootbench/root/lib/libmultimapDict.rootmap --noIncludePaths -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1 -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Users/abhiacherjee/Documents/rootbench/root/include -I/Users/abhiacherjee/Documents/root_src/core/clingutils/inc -I/Users/abhiacherjee/Documents/root_src/core/clingutils/res -I/Users/abhiacherjee/Documents/root_src/core/clib/inc -I/Users/abhiacherjee/Documents/root_src/core/base/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/base/inc -I/Users/abhiacherjee/Documents/rootbench/root/ginclude -I/Users/abhiacherjee/Documents/root_src/interpreter/cling/include/cling/cint -I/Users/abhiacherjee/Documents/root_src/core/cont/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/gui/inc -I/Users/abhiacherjee/Documents/root_src/core/meta/inc -I/Users/abhiacherjee/Documents/root_src/core/textinput/inc -I/Users/abhiacherjee/Documents/root_src/core/thread/inc -I/Users/abhiacherjee/Documents/root_src/core/zip/inc -I/Users/abhiacherjee/Documents/root_src/core/lzma/inc -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/core/lz4/inc -I/Users/abhiacherjee/Documents/root_src/core/zstd/inc map /Users/abhiacherjee/Documents/root_src/core/clingutils/src/multimapLinkdef.h

lib/libmultimapDict.rootmap: core/clingutils/G__multimapDict.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libmultimapDict.rootmap

core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o: core/clingutils/CMakeFiles/G__multimapDict.dir/flags.make
core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o: core/clingutils/G__multimapDict.cxx
core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o: core/clingutils/CMakeFiles/G__multimapDict.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o -MF CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o.d -o CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o -c /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/G__multimapDict.cxx

core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/G__multimapDict.cxx > CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.i

core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/G__multimapDict.cxx -o CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.s

G__multimapDict: core/clingutils/CMakeFiles/G__multimapDict.dir/G__multimapDict.cxx.o
G__multimapDict: core/clingutils/CMakeFiles/G__multimapDict.dir/build.make
.PHONY : G__multimapDict

# Rule to build all files generated by this target.
core/clingutils/CMakeFiles/G__multimapDict.dir/build: G__multimapDict
.PHONY : core/clingutils/CMakeFiles/G__multimapDict.dir/build

core/clingutils/CMakeFiles/G__multimapDict.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/core/clingutils && $(CMAKE_COMMAND) -P CMakeFiles/G__multimapDict.dir/cmake_clean.cmake
.PHONY : core/clingutils/CMakeFiles/G__multimapDict.dir/clean

core/clingutils/CMakeFiles/G__multimapDict.dir/depend: core/clingutils/G__multimapDict.cxx
core/clingutils/CMakeFiles/G__multimapDict.dir/depend: lib/libmultimapDict.rootmap
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/core/clingutils /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/core/clingutils /Users/abhiacherjee/Documents/rootbench/root/core/clingutils/CMakeFiles/G__multimapDict.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : core/clingutils/CMakeFiles/G__multimapDict.dir/depend

