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
include geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/compiler_depend.make

# Include the progress variables for this target.
include geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/progress.make

# Include the compile flags for this target's objects.
include geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/flags.make

geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/LinkDef.h
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeomData.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeomHierarchy.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeomViewer.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeoPainter.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeomData.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeomHierarchy.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeomViewer.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/ROOT/RGeoPainter.hxx
geom/webviewer/G__ROOTGeomViewer.cxx: /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/LinkDef.h
geom/webviewer/G__ROOTGeomViewer.cxx: bin/rootcling
geom/webviewer/G__ROOTGeomViewer.cxx: lib/libCore.so
geom/webviewer/G__ROOTGeomViewer.cxx: lib/libGeom.so
geom/webviewer/G__ROOTGeomViewer.cxx: lib/libRCsg.so
geom/webviewer/G__ROOTGeomViewer.cxx: lib/libROOTWebDisplay.so
geom/webviewer/G__ROOTGeomViewer.cxx: lib/libROOTBrowserv7.so
geom/webviewer/G__ROOTGeomViewer.cxx: include/module.modulemap
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating G__ROOTGeomViewer.cxx, ../../lib/ROOTGeomViewer.pcm"
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E env LD_LIBRARY_PATH=/Users/abhiacherjee/Documents/rootbench/root/lib: ROOTIGNOREPREFIX=1 /Users/abhiacherjee/Documents/rootbench/root/bin/rootcling -rootbuild -v2 -f G__ROOTGeomViewer.cxx -cxxmodule -s /Users/abhiacherjee/Documents/rootbench/root/lib/libROOTGeomViewer.so -m Core.pcm -m Geom.pcm -m RCsg.pcm -m ROOTWebDisplay.pcm -m ROOTBrowserv7.pcm -excludePath /Users/abhiacherjee/Documents/root_src -excludePath /Users/abhiacherjee/Documents/rootbench/root/ginclude -excludePath /Users/abhiacherjee/Documents/rootbench/root/externals -excludePath /Users/abhiacherjee/Documents/rootbench/root/builtins -DNO_SSL -DHTTP_WITHOUT_FASTCGI -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1 -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Users/abhiacherjee/Documents/rootbench/root/include -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/geom/webviewer/inc -I/Users/abhiacherjee/Documents/root_src/core/unix/../clib/res -I/Users/abhiacherjee/Documents/root_src/core/unix/inc -I/Users/abhiacherjee/Documents/root_src/core/macosx/inc -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/core/zstd/inc -I/Users/abhiacherjee/Documents/root_src/core/lz4/inc -I/Users/abhiacherjee/Documents/root_src/core/lzma/inc -I/Users/abhiacherjee/Documents/root_src/core/zip/inc -I/Users/abhiacherjee/Documents/root_src/core/thread/inc -I/Users/abhiacherjee/Documents/root_src/core/textinput/src -I/Users/abhiacherjee/Documents/root_src/core/textinput/inc -I/Users/abhiacherjee/Documents/root_src/core/rint/inc -I/Users/abhiacherjee/Documents/root_src/core/meta/inc -I/Users/abhiacherjee/Documents/root_src/core/gui/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/res -I/Users/abhiacherjee/Documents/root_src/core/foundation/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/inc -I/Users/abhiacherjee/Documents/root_src/core/cont/inc -I/Users/abhiacherjee/Documents/root_src/core/clingutils/res -I/Users/abhiacherjee/Documents/root_src/core/clingutils/inc -I/Users/abhiacherjee/Documents/root_src/core/clib/inc -I/Users/abhiacherjee/Documents/root_src/core/base/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/base/inc -I/Users/abhiacherjee/Documents/rootbench/root/ginclude -I/Users/abhiacherjee/Documents/root_src/geom/geom/inc -I/Users/abhiacherjee/Documents/root_src/io/io/v7/inc -I/Users/abhiacherjee/Documents/root_src/io/io/inc -I/Users/abhiacherjee/Documents/root_src/core/clib/res -I/Users/abhiacherjee/Documents/root_src/math/mathcore/v7/inc -I/Users/abhiacherjee/Documents/root_src/math/mathcore/inc -I/Users/abhiacherjee/Documents/root_src/core/imt/inc -I/Users/abhiacherjee/Documents/root_src/hist/hist/inc -I/Users/abhiacherjee/Documents/root_src/math/matrix/inc -I/Users/abhiacherjee/Documents/root_src/graf3d/csg/inc -I/Users/abhiacherjee/Documents/root_src/gui/webdisplay/inc -I/Users/abhiacherjee/Documents/root_src/net/http/inc -I/Users/abhiacherjee/Documents/root_src/net/net/inc -I/Users/abhiacherjee/Documents/root_src/gui/browserv7/inc -I/Users/abhiacherjee/Documents/root_src/gui/browsable/inc -I/Users/abhiacherjee/Documents/root_src/core/multiproc/inc ROOT/RGeomData.hxx ROOT/RGeomHierarchy.hxx ROOT/RGeomViewer.hxx ROOT/RGeoPainter.hxx /Users/abhiacherjee/Documents/root_src/geom/webviewer/inc/LinkDef.h

lib/ROOTGeomViewer.pcm: geom/webviewer/G__ROOTGeomViewer.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate lib/ROOTGeomViewer.pcm

geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o: geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/flags.make
geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o: geom/webviewer/G__ROOTGeomViewer.cxx
geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o: geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o -MF CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o.d -o CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o -c /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer/G__ROOTGeomViewer.cxx

geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer/G__ROOTGeomViewer.cxx > CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.i

geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer/G__ROOTGeomViewer.cxx -o CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.s

G__ROOTGeomViewer: geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/G__ROOTGeomViewer.cxx.o
G__ROOTGeomViewer: geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/build.make
.PHONY : G__ROOTGeomViewer

# Rule to build all files generated by this target.
geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/build: G__ROOTGeomViewer
.PHONY : geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/build

geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer && $(CMAKE_COMMAND) -P CMakeFiles/G__ROOTGeomViewer.dir/cmake_clean.cmake
.PHONY : geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/clean

geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/depend: geom/webviewer/G__ROOTGeomViewer.cxx
geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/depend: lib/ROOTGeomViewer.pcm
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/geom/webviewer /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer /Users/abhiacherjee/Documents/rootbench/root/geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : geom/webviewer/CMakeFiles/G__ROOTGeomViewer.dir/depend

