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
include io/xmlparser/CMakeFiles/G__XMLParser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include io/xmlparser/CMakeFiles/G__XMLParser.dir/compiler_depend.make

# Include the progress variables for this target.
include io/xmlparser/CMakeFiles/G__XMLParser.dir/progress.make

# Include the compile flags for this target's objects.
include io/xmlparser/CMakeFiles/G__XMLParser.dir/flags.make

io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/LinkDef.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TDOMParser.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TSAXParser.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLAttr.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLDocument.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLNode.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLParser.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TDOMParser.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TSAXParser.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLAttr.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLDocument.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLNode.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/TXMLParser.h
io/xmlparser/G__XMLParser.cxx: /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/LinkDef.h
io/xmlparser/G__XMLParser.cxx: bin/rootcling
io/xmlparser/G__XMLParser.cxx: lib/libCore.so
io/xmlparser/G__XMLParser.cxx: include/module.modulemap
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating G__XMLParser.cxx, ../../lib/XMLParser.pcm"
	cd /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser && /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E env LD_LIBRARY_PATH=/Users/abhiacherjee/Documents/rootbench/root/lib: ROOTIGNOREPREFIX=1 /Users/abhiacherjee/Documents/rootbench/root/bin/rootcling -rootbuild -v2 -f G__XMLParser.cxx -cxxmodule -s /Users/abhiacherjee/Documents/rootbench/root/lib/libXMLParser.so -m Core.pcm -excludePath /Users/abhiacherjee/Documents/root_src -excludePath /Users/abhiacherjee/Documents/rootbench/root/ginclude -excludePath /Users/abhiacherjee/Documents/rootbench/root/externals -excludePath /Users/abhiacherjee/Documents/rootbench/root/builtins -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/c++/v1 -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/15.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Users/abhiacherjee/Documents/rootbench/root/include -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/io/xmlparser/inc -I/Users/abhiacherjee/Documents/root_src/core/unix/../clib/res -I/Users/abhiacherjee/Documents/root_src/core/unix/inc -I/Users/abhiacherjee/Documents/root_src/core/macosx/inc -I/opt/homebrew/include -I/Users/abhiacherjee/Documents/root_src/core/zstd/inc -I/Users/abhiacherjee/Documents/root_src/core/lz4/inc -I/Users/abhiacherjee/Documents/root_src/core/lzma/inc -I/Users/abhiacherjee/Documents/root_src/core/zip/inc -I/Users/abhiacherjee/Documents/root_src/core/thread/inc -I/Users/abhiacherjee/Documents/root_src/core/textinput/src -I/Users/abhiacherjee/Documents/root_src/core/textinput/inc -I/Users/abhiacherjee/Documents/root_src/core/rint/inc -I/Users/abhiacherjee/Documents/root_src/core/meta/inc -I/Users/abhiacherjee/Documents/root_src/core/gui/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/res -I/Users/abhiacherjee/Documents/root_src/core/foundation/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/foundation/inc -I/Users/abhiacherjee/Documents/root_src/core/cont/inc -I/Users/abhiacherjee/Documents/root_src/core/clingutils/res -I/Users/abhiacherjee/Documents/root_src/core/clingutils/inc -I/Users/abhiacherjee/Documents/root_src/core/clib/inc -I/Users/abhiacherjee/Documents/root_src/core/base/v7/inc -I/Users/abhiacherjee/Documents/root_src/core/base/inc -I/Users/abhiacherjee/Documents/rootbench/root/ginclude -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.2.sdk/usr/include/libxml2 TDOMParser.h TSAXParser.h TXMLAttr.h TXMLDocument.h TXMLNode.h TXMLParser.h /Users/abhiacherjee/Documents/root_src/io/xmlparser/inc/LinkDef.h

lib/XMLParser.pcm: io/xmlparser/G__XMLParser.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate lib/XMLParser.pcm

io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o: io/xmlparser/CMakeFiles/G__XMLParser.dir/flags.make
io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o: io/xmlparser/G__XMLParser.cxx
io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o: io/xmlparser/CMakeFiles/G__XMLParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o -MF CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o.d -o CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o -c /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser/G__XMLParser.cxx

io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser/G__XMLParser.cxx > CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.i

io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser/G__XMLParser.cxx -o CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.s

G__XMLParser: io/xmlparser/CMakeFiles/G__XMLParser.dir/G__XMLParser.cxx.o
G__XMLParser: io/xmlparser/CMakeFiles/G__XMLParser.dir/build.make
.PHONY : G__XMLParser

# Rule to build all files generated by this target.
io/xmlparser/CMakeFiles/G__XMLParser.dir/build: G__XMLParser
.PHONY : io/xmlparser/CMakeFiles/G__XMLParser.dir/build

io/xmlparser/CMakeFiles/G__XMLParser.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser && $(CMAKE_COMMAND) -P CMakeFiles/G__XMLParser.dir/cmake_clean.cmake
.PHONY : io/xmlparser/CMakeFiles/G__XMLParser.dir/clean

io/xmlparser/CMakeFiles/G__XMLParser.dir/depend: io/xmlparser/G__XMLParser.cxx
io/xmlparser/CMakeFiles/G__XMLParser.dir/depend: lib/XMLParser.pcm
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/io/xmlparser /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser /Users/abhiacherjee/Documents/rootbench/root/io/xmlparser/CMakeFiles/G__XMLParser.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : io/xmlparser/CMakeFiles/G__XMLParser.dir/depend

