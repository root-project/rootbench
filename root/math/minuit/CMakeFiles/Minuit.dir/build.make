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
include math/minuit/CMakeFiles/Minuit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include math/minuit/CMakeFiles/Minuit.dir/compiler_depend.make

# Include the progress variables for this target.
include math/minuit/CMakeFiles/Minuit.dir/progress.make

# Include the compile flags for this target's objects.
include math/minuit/CMakeFiles/Minuit.dir/flags.make

math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.o: math/minuit/CMakeFiles/Minuit.dir/flags.make
math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.o: /Users/abhiacherjee/Documents/root_src/math/minuit/src/TFitter.cxx
math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.o: math/minuit/CMakeFiles/Minuit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.o -MF CMakeFiles/Minuit.dir/src/TFitter.cxx.o.d -o CMakeFiles/Minuit.dir/src/TFitter.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/minuit/src/TFitter.cxx

math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minuit.dir/src/TFitter.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/minuit/src/TFitter.cxx > CMakeFiles/Minuit.dir/src/TFitter.cxx.i

math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minuit.dir/src/TFitter.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/minuit/src/TFitter.cxx -o CMakeFiles/Minuit.dir/src/TFitter.cxx.s

math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o: math/minuit/CMakeFiles/Minuit.dir/flags.make
math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o: /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearFitter.cxx
math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o: math/minuit/CMakeFiles/Minuit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o -MF CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o.d -o CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearFitter.cxx

math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearFitter.cxx > CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.i

math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearFitter.cxx -o CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.s

math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o: math/minuit/CMakeFiles/Minuit.dir/flags.make
math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o: /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearMinimizer.cxx
math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o: math/minuit/CMakeFiles/Minuit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o -MF CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o.d -o CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearMinimizer.cxx

math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearMinimizer.cxx > CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.i

math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/minuit/src/TLinearMinimizer.cxx -o CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.s

math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.o: math/minuit/CMakeFiles/Minuit.dir/flags.make
math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.o: /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuit.cxx
math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.o: math/minuit/CMakeFiles/Minuit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.o -MF CMakeFiles/Minuit.dir/src/TMinuit.cxx.o.d -o CMakeFiles/Minuit.dir/src/TMinuit.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuit.cxx

math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minuit.dir/src/TMinuit.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuit.cxx > CMakeFiles/Minuit.dir/src/TMinuit.cxx.i

math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minuit.dir/src/TMinuit.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuit.cxx -o CMakeFiles/Minuit.dir/src/TMinuit.cxx.s

math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o: math/minuit/CMakeFiles/Minuit.dir/flags.make
math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o: /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuitMinimizer.cxx
math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o: math/minuit/CMakeFiles/Minuit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o -MF CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o.d -o CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o -c /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuitMinimizer.cxx

math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.i"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuitMinimizer.cxx > CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.i

math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.s"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/abhiacherjee/Documents/root_src/math/minuit/src/TMinuitMinimizer.cxx -o CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.s

# Object files for target Minuit
Minuit_OBJECTS = \
"CMakeFiles/Minuit.dir/src/TFitter.cxx.o" \
"CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o" \
"CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o" \
"CMakeFiles/Minuit.dir/src/TMinuit.cxx.o" \
"CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o"

# External object files for target Minuit
Minuit_EXTERNAL_OBJECTS = \
"/Users/abhiacherjee/Documents/rootbench/root/math/minuit/CMakeFiles/G__Minuit.dir/G__Minuit.cxx.o"

lib/libMinuit.so: math/minuit/CMakeFiles/Minuit.dir/src/TFitter.cxx.o
lib/libMinuit.so: math/minuit/CMakeFiles/Minuit.dir/src/TLinearFitter.cxx.o
lib/libMinuit.so: math/minuit/CMakeFiles/Minuit.dir/src/TLinearMinimizer.cxx.o
lib/libMinuit.so: math/minuit/CMakeFiles/Minuit.dir/src/TMinuit.cxx.o
lib/libMinuit.so: math/minuit/CMakeFiles/Minuit.dir/src/TMinuitMinimizer.cxx.o
lib/libMinuit.so: math/minuit/CMakeFiles/G__Minuit.dir/G__Minuit.cxx.o
lib/libMinuit.so: math/minuit/CMakeFiles/Minuit.dir/build.make
lib/libMinuit.so: lib/libGraf.so
lib/libMinuit.so: lib/libHist.so
lib/libMinuit.so: lib/libMatrix.so
lib/libMinuit.so: lib/libMathCore.so
lib/libMinuit.so: lib/libImt.so
lib/libMinuit.so: lib/libMultiProc.so
lib/libMinuit.so: lib/libNet.so
lib/libMinuit.so: lib/libRIO.so
lib/libMinuit.so: lib/libThread.so
lib/libMinuit.so: lib/libCore.so
lib/libMinuit.so: math/minuit/CMakeFiles/Minuit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/abhiacherjee/Documents/rootbench/root/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../../lib/libMinuit.so"
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Minuit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/minuit/CMakeFiles/Minuit.dir/build: lib/libMinuit.so
.PHONY : math/minuit/CMakeFiles/Minuit.dir/build

math/minuit/CMakeFiles/Minuit.dir/clean:
	cd /Users/abhiacherjee/Documents/rootbench/root/math/minuit && $(CMAKE_COMMAND) -P CMakeFiles/Minuit.dir/cmake_clean.cmake
.PHONY : math/minuit/CMakeFiles/Minuit.dir/clean

math/minuit/CMakeFiles/Minuit.dir/depend:
	cd /Users/abhiacherjee/Documents/rootbench/root && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abhiacherjee/Documents/root_src /Users/abhiacherjee/Documents/root_src/math/minuit /Users/abhiacherjee/Documents/rootbench/root /Users/abhiacherjee/Documents/rootbench/root/math/minuit /Users/abhiacherjee/Documents/rootbench/root/math/minuit/CMakeFiles/Minuit.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : math/minuit/CMakeFiles/Minuit.dir/depend

