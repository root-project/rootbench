# CMake generated Testfile for 
# Source directory: /Users/abhiacherjee/Documents/root_src/gui/webdisplay/test
# Build directory: /Users/abhiacherjee/Documents/rootbench/root/gui/webdisplay/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test-webgui-ping]=] "/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake" "-DCMD=/Users/abhiacherjee/Documents/rootbench/root/bin/root.exe^-b^-q^-l^ping.cxx" "-DSYS=/Users/abhiacherjee/Documents/rootbench/root" "-DCOPY=/Users/abhiacherjee/Documents/root_src/tutorials/webgui/ping/ping.cxx^/Users/abhiacherjee/Documents/root_src/tutorials/webgui/ping/ping.html" "-P" "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootTestDriver.cmake")
set_tests_properties([=[test-webgui-ping]=] PROPERTIES  ENVIRONMENT "ROOT_HIST=0" PASS_REGULAR_EXPRESSION "PING-PONG TEST COMPLETED" RUN_SERIAL "true" _BACKTRACE_TRIPLES "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootMacros.cmake;1696;add_test;/Users/abhiacherjee/Documents/root_src/gui/webdisplay/test/CMakeLists.txt;14;ROOT_ADD_TEST;/Users/abhiacherjee/Documents/root_src/gui/webdisplay/test/CMakeLists.txt;0;")
