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
include math/smatrix/CMakeFiles/G__Smatrix32.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include math/smatrix/CMakeFiles/G__Smatrix32.dir/compiler_depend.make

# Include the progress variables for this target.
include math/smatrix/CMakeFiles/G__Smatrix32.dir/progress.make

# Include the compile flags for this target's objects.
include math/smatrix/CMakeFiles/G__Smatrix32.dir/flags.make

math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/LinkDefD32.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SMatrix.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SMatrixDfwd.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SMatrixFfwd.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SVector.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SMatrix.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SMatrixDfwd.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SMatrixFfwd.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/Math/SVector.h
math/smatrix/G__Smatrix32.cxx: /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/LinkDefD32.h
math/smatrix/G__Smatrix32.cxx: bin/rootcling
math/smatrix/G__Smatrix32.cxx: lib/libCore.so
math/smatrix/G__Smatrix32.cxx: lib/libMathCore.so
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating G__Smatrix32.cxx, ../../lib/libSmatrix32.rootmap"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/smatrix && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E env LD_LIBRARY_PATH=/Users/abhiacherjee/Documents/rootbench/root/lib: ROOTIGNOREPREFIX=1 /Users/abhiacherjee/Documents/rootbench/root/bin/rootcling -rootbuild -v2 -f G__Smatrix32.cxx -s /Users/abhiacherjee/Documents/rootbench/root/lib/libSmatrix.so -multiDict -m Core.pcm -m MathCore.pcm -excludePath /Users/abhiacherjee/Documents/root_src -excludePath /Users/abhiacherjee/Documents/rootbench/root/ginclude -excludePath /Users/abhiacherjee/Documents/rootbench/root/externals -excludePath /Users/abhiacherjee/Documents/rootbench/root/builtins -rml libSmatrix.so -rmf /Users/abhiacherjee/Documents/rootbench/root/lib/libSmatrix32.rootmap -writeEmptyRootPCM -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1 -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Users/abhiacherjee/Documents/rootbench/root/include -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/math/smatrix/inc -I/Users/abhiacherjee/Documents/root_src/core/unix/../clib/res -I/Users/abhiacherjee/Documents/root_src/core/unix/inc -I/Users/abhiacherjee/Documents/root_src/core/macosx/inc -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/core/zstd/inc -I/Users/abhiacherjee/Documents/root_src/core/lz4/inc -I/Users/abhiacherjee/Documents/root_src/core/lzma/inc -I/Users/abhiacherjee/Documents/root_src/core/zip/inc -I/Users/abhiacherjee/Documents/root_src/core/thread/inc -I/Users/abhiacherjee/Documents/root_src/core/textinput/src -I/Users/abhiacherjee/Documents/root_src/core/textinput/inc -I/Users/abhiacherjee/Documents/root_src/core/rint/inc -I/Users/abhiacherjee/Documents/root_src/core/meta/inc -I/Users/abhiacherjee/Documents/root_src/core/gui/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/res -I/Users/abhiacherjee/Documents/root_src/core/foundation/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/inc -I/Users/abhiacherjee/Documents/root_src/core/cont/inc -I/Users/abhiacherjee/Documents/root_src/core/clingutils/res -I/Users/abhiacherjee/Documents/root_src/core/clingutils/inc -I/Users/abhiacherjee/Documents/root_src/core/clib/inc -I/Users/abhiacherjee/Documents/root_src/core/base/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/base/inc -I/Users/abhiacherjee/Documents/rootbench/root/ginclude -I/Users/abhiacherjee/Documents/root_src/math/mathcore/v7/inc -I/Users/abhiacherjee/Documents/root_src/math/mathcore/inc -I/Users/abhiacherjee/Documents/root_src/core/imt/inc -I/Users/abhiacherjee/Documents/root_src/core/multiproc/inc -I/Users/abhiacherjee/Documents/root_src/net/net/inc -I/Users/abhiacherjee/Documents/root_src/io/io/v7/inc -I/Users/abhiacherjee/Documents/root_src/io/io/inc Math/SMatrix.h Math/SMatrixDfwd.h Math/SMatrixFfwd.h Math/SVector.h /Users/abhiacherjee/Documents/root_src/math/smatrix/inc/LinkDefD32.h

lib/libSmatrix32.rootmap: math/smatrix/G__Smatrix32.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libSmatrix32.rootmap

math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o: math/smatrix/CMakeFiles/G__Smatrix32.dir/flags.make
math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o: math/smatrix/G__Smatrix32.cxx
math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o: math/smatrix/CMakeFiles/G__Smatrix32.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/smatrix && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o -MF CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o.d -o CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o -c /Users/abhiacherjee/Documents/rootbench/root/math/smatrix/G__Smatrix32.cxx

math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/smatrix && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/rootbench/root/math/smatrix/G__Smatrix32.cxx > CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.i

math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/smatrix && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/rootbench/root/math/smatrix/G__Smatrix32.cxx -o CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.s

G__Smatrix32: math/smatrix/CMakeFiles/G__Smatrix32.dir/G__Smatrix32.cxx.o
G__Smatrix32: math/smatrix/CMakeFiles/G__Smatrix32.dir/build.make
.PHONY : G__Smatrix32

# Rule to build all files generated by this target.
math/smatrix/CMakeFiles/G__Smatrix32.dir/build: G__Smatrix32
.PHONY : math/smatrix/CMakeFiles/G__Smatrix32.dir/build

math/smatrix/CMakeFiles/G__Smatrix32.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/smatrix && $(CMAKE_COMMAND) -P CMakeFiles/G__Smatrix32.dir/cmake_clean.cmake
.PHONY : math/smatrix/CMakeFiles/G__Smatrix32.dir/clean

math/smatrix/CMakeFiles/G__Smatrix32.dir/depend: lib/libSmatrix32.rootmap
math/smatrix/CMakeFiles/G__Smatrix32.dir/depend: math/smatrix/G__Smatrix32.cxx
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/smatrix /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/smatrix /Users/abhiacherjee/Documents/rootbench/root/math/smatrix/CMakeFiles/G__Smatrix32.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/smatrix/CMakeFiles/G__Smatrix32.dir/depend

