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
include net/rpdutils/CMakeFiles/SrvAuth.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include net/rpdutils/CMakeFiles/SrvAuth.dir/compiler_depend.make

# Include the progress variables for this target.
include net/rpdutils/CMakeFiles/SrvAuth.dir/progress.make

# Include the compile flags for this target's objects.
include net/rpdutils/CMakeFiles/SrvAuth.dir/flags.make

net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o: net/rpdutils/CMakeFiles/SrvAuth.dir/flags.make
net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o: /Users/abhiacherjee/Documents/root_src/net/rpdutils/src/rpdutils.cxx
net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o: net/rpdutils/CMakeFiles/SrvAuth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/net/rpdutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-deprecated-declarations -MD -MT net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o -MF CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o.d -o CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o -c /Users/abhiacherjee/Documents/root_src/net/rpdutils/src/rpdutils.cxx

net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/net/rpdutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-deprecated-declarations -E /Users/abhiacherjee/Documents/root_src/net/rpdutils/src/rpdutils.cxx > CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.i

net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/net/rpdutils && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-deprecated-declarations -S /Users/abhiacherjee/Documents/root_src/net/rpdutils/src/rpdutils.cxx -o CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.s

# Object files for target SrvAuth
SrvAuth_OBJECTS = \
"CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o"

# External object files for target SrvAuth
SrvAuth_EXTERNAL_OBJECTS =

lib/libSrvAuth.so: net/rpdutils/CMakeFiles/SrvAuth.dir/src/rpdutils.cxx.o
lib/libSrvAuth.so: net/rpdutils/CMakeFiles/SrvAuth.dir/build.make
lib/libSrvAuth.so: /opt/homebrew/lib/libssl.dylib
lib/libSrvAuth.so: /opt/homebrew/lib/libcrypto.dylib
lib/libSrvAuth.so: lib/librpdutil.a
lib/libSrvAuth.so: lib/librsa.a
lib/libSrvAuth.so: lib/libNet.so
lib/libSrvAuth.so: lib/libRIO.so
lib/libSrvAuth.so: lib/libThread.so
lib/libSrvAuth.so: lib/libCore.so
lib/libSrvAuth.so: net/rpdutils/CMakeFiles/SrvAuth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libSrvAuth.so"
	cd /Users/abhiacherjee/Documents/rootbench/root/net/rpdutils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SrvAuth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
net/rpdutils/CMakeFiles/SrvAuth.dir/build: lib/libSrvAuth.so
.PHONY : net/rpdutils/CMakeFiles/SrvAuth.dir/build

net/rpdutils/CMakeFiles/SrvAuth.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/net/rpdutils && $(CMAKE_COMMAND) -P CMakeFiles/SrvAuth.dir/cmake_clean.cmake
.PHONY : net/rpdutils/CMakeFiles/SrvAuth.dir/clean

net/rpdutils/CMakeFiles/SrvAuth.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/net/rpdutils /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/net/rpdutils /Users/abhiacherjee/Documents/rootbench/root/net/rpdutils/CMakeFiles/SrvAuth.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : net/rpdutils/CMakeFiles/SrvAuth.dir/depend

