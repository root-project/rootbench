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
include roofit/hs3/CMakeFiles/G__RooFitHS3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include roofit/hs3/CMakeFiles/G__RooFitHS3.dir/compiler_depend.make

# Include the progress variables for this target.
include roofit/hs3/CMakeFiles/G__RooFitHS3.dir/progress.make

# Include the compile flags for this target's objects.
include roofit/hs3/CMakeFiles/G__RooFitHS3.dir/flags.make

roofit/hs3/G__RooFitHS3.cxx: /Users/abhiacherjee/Documents/root_src/roofit/hs3/LinkDef.h
roofit/hs3/G__RooFitHS3.cxx: /Users/abhiacherjee/Documents/root_src/roofit/hs3/inc/RooFitHS3/JSONIO.h
roofit/hs3/G__RooFitHS3.cxx: /Users/abhiacherjee/Documents/root_src/roofit/hs3/inc/RooFitHS3/RooJSONFactoryWSTool.h
roofit/hs3/G__RooFitHS3.cxx: /Users/abhiacherjee/Documents/root_src/roofit/hs3/inc/RooFitHS3/JSONIO.h
roofit/hs3/G__RooFitHS3.cxx: /Users/abhiacherjee/Documents/root_src/roofit/hs3/inc/RooFitHS3/RooJSONFactoryWSTool.h
roofit/hs3/G__RooFitHS3.cxx: /Users/abhiacherjee/Documents/root_src/roofit/hs3/LinkDef.h
roofit/hs3/G__RooFitHS3.cxx: bin/rootcling
roofit/hs3/G__RooFitHS3.cxx: lib/libRooFitCore.so
roofit/hs3/G__RooFitHS3.cxx: lib/libRooFitJSONInterface.so
roofit/hs3/G__RooFitHS3.cxx: include/module.modulemap
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating G__RooFitHS3.cxx, ../../lib/RooFitHS3.pcm"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3 && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E env LD_LIBRARY_PATH=/Users/abhiacherjee/Documents/rootbench/root/lib: ROOTIGNOREPREFIX=1 /Users/abhiacherjee/Documents/rootbench/root/bin/rootcling -rootbuild -v2 -f G__RooFitHS3.cxx -cxxmodule -s /Users/abhiacherjee/Documents/rootbench/root/lib/libRooFitHS3.so -m RooFitCore.pcm -m RooFitJSONInterface.pcm -excludePath /Users/abhiacherjee/Documents/root_src -excludePath /Users/abhiacherjee/Documents/rootbench/root/ginclude -excludePath /Users/abhiacherjee/Documents/rootbench/root/externals -excludePath /Users/abhiacherjee/Documents/rootbench/root/builtins -writeEmptyRootPCM -DROOFIT_LEGACY_EVAL_BACKEND -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1 -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Users/abhiacherjee/Documents/rootbench/root/include -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/libxml2 -I/Users/abhiacherjee/Documents/root_src/roofit/hs3/inc -I/Users/abhiacherjee/Documents/root_src/core/unix/../clib/res -I/Users/abhiacherjee/Documents/root_src/core/unix/inc -I/Users/abhiacherjee/Documents/root_src/core/macosx/inc -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/core/zstd/inc -I/Users/abhiacherjee/Documents/root_src/core/lz4/inc -I/Users/abhiacherjee/Documents/root_src/core/lzma/inc -I/Users/abhiacherjee/Documents/root_src/core/zip/inc -I/Users/abhiacherjee/Documents/root_src/core/thread/inc -I/Users/abhiacherjee/Documents/root_src/core/textinput/src -I/Users/abhiacherjee/Documents/root_src/core/textinput/inc -I/Users/abhiacherjee/Documents/root_src/core/rint/inc -I/Users/abhiacherjee/Documents/root_src/core/meta/inc -I/Users/abhiacherjee/Documents/root_src/core/gui/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/res -I/Users/abhiacherjee/Documents/root_src/core/foundation/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/inc -I/Users/abhiacherjee/Documents/root_src/core/cont/inc -I/Users/abhiacherjee/Documents/root_src/core/clingutils/res -I/Users/abhiacherjee/Documents/root_src/core/clingutils/inc -I/Users/abhiacherjee/Documents/root_src/core/clib/inc -I/Users/abhiacherjee/Documents/root_src/core/base/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/base/inc -I/Users/abhiacherjee/Documents/rootbench/root/ginclude -I/Users/abhiacherjee/Documents/root_src/roofit/roofitcore/inc -I/Users/abhiacherjee/Documents/root_src/roofit/roofitcore/res -I/Users/abhiacherjee/Documents/root_src/hist/hist/inc -I/Users/abhiacherjee/Documents/root_src/math/mathcore/v7/inc -I/Users/abhiacherjee/Documents/root_src/math/mathcore/inc -I/Users/abhiacherjee/Documents/root_src/core/imt/inc -I/Users/abhiacherjee/Documents/root_src/math/matrix/inc -I/Users/abhiacherjee/Documents/root_src/graf2d/graf/inc -I/Users/abhiacherjee/Documents/root_src/io/io/v7/inc -I/Users/abhiacherjee/Documents/root_src/io/io/inc -I/Users/abhiacherjee/Documents/root_src/core/clib/res -I/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE/include -I/Users/abhiacherjee/Documents/root_src/tree/tree/inc -I/Users/abhiacherjee/Documents/root_src/math/minuit/inc -I/Users/abhiacherjee/Documents/root_src/math/foam/inc -I/Users/abhiacherjee/Documents/root_src/math/smatrix/inc -I/Users/abhiacherjee/Documents/root_src/roofit/batchcompute/res -I/Users/abhiacherjee/Documents/root_src/roofit/jsoninterface/inc -I/Users/abhiacherjee/Documents/root_src/roofit/roofit/inc -I/Users/abhiacherjee/Documents/root_src/roofit/histfactory/inc -I/Users/abhiacherjee/Documents/root_src/graf2d/gpad/inc -I/Users/abhiacherjee/Documents/root_src/roofit/roostats/inc -I/Users/abhiacherjee/Documents/root_src/io/xmlparser/inc -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/libxml2 -I/Users/abhiacherjee/Documents/root_src/core/multiproc/inc -I/Users/abhiacherjee/Documents/root_src/net/net/inc RooFitHS3/JSONIO.h RooFitHS3/RooJSONFactoryWSTool.h /Users/abhiacherjee/Documents/root_src/roofit/hs3/LinkDef.h

lib/RooFitHS3.pcm: roofit/hs3/G__RooFitHS3.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate lib/RooFitHS3.pcm

roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o: roofit/hs3/CMakeFiles/G__RooFitHS3.dir/flags.make
roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o: roofit/hs3/G__RooFitHS3.cxx
roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o: roofit/hs3/CMakeFiles/G__RooFitHS3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o -MF CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o.d -o CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o -c /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3/G__RooFitHS3.cxx

roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3/G__RooFitHS3.cxx > CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.i

roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3/G__RooFitHS3.cxx -o CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.s

G__RooFitHS3: roofit/hs3/CMakeFiles/G__RooFitHS3.dir/G__RooFitHS3.cxx.o
G__RooFitHS3: roofit/hs3/CMakeFiles/G__RooFitHS3.dir/build.make
.PHONY : G__RooFitHS3

# Rule to build all files generated by this target.
roofit/hs3/CMakeFiles/G__RooFitHS3.dir/build: G__RooFitHS3
.PHONY : roofit/hs3/CMakeFiles/G__RooFitHS3.dir/build

roofit/hs3/CMakeFiles/G__RooFitHS3.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3 && $(CMAKE_COMMAND) -P CMakeFiles/G__RooFitHS3.dir/cmake_clean.cmake
.PHONY : roofit/hs3/CMakeFiles/G__RooFitHS3.dir/clean

roofit/hs3/CMakeFiles/G__RooFitHS3.dir/depend: lib/RooFitHS3.pcm
roofit/hs3/CMakeFiles/G__RooFitHS3.dir/depend: roofit/hs3/G__RooFitHS3.cxx
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/roofit/hs3 /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3 /Users/abhiacherjee/Documents/rootbench/root/roofit/hs3/CMakeFiles/G__RooFitHS3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : roofit/hs3/CMakeFiles/G__RooFitHS3.dir/depend

