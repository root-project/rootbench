# CMake generated Testfile for 
# Source directory: /Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/GRU
# Build directory: /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/GRU
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[TMVA-DNN-GRU-Forward-Cpu]=] "/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake" "-DCMD=/Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/GRU/testGRUForwardPassCpu" "-DSYS=/Users/abhiacherjee/Documents/rootbench/root" "-P" "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootTestDriver.cmake")
set_tests_properties([=[TMVA-DNN-GRU-Forward-Cpu]=] PROPERTIES  ENVIRONMENT "ROOT_HIST=0" _BACKTRACE_TRIPLES "/Users/abhiacherjee/Documents/rootbench/root/RootMacros.cmake;1696;add_test;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/GRU/CMakeLists.txt;37;ROOT_ADD_TEST;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/GRU/CMakeLists.txt;0;")
add_test([=[TMVA-DNN-GRU-Backward-Cpu]=] "/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake" "-DCMD=/Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/GRU/testGRUBackpropagationCpu" "-DSYS=/Users/abhiacherjee/Documents/rootbench/root" "-P" "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootTestDriver.cmake")
set_tests_properties([=[TMVA-DNN-GRU-Backward-Cpu]=] PROPERTIES  ENVIRONMENT "ROOT_HIST=0" _BACKTRACE_TRIPLES "/Users/abhiacherjee/Documents/rootbench/root/RootMacros.cmake;1696;add_test;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/GRU/CMakeLists.txt;41;ROOT_ADD_TEST;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/GRU/CMakeLists.txt;0;")
add_test([=[TMVA-DNN-GRU-Full-Cpu]=] "/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake" "-DCMD=/Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/GRU/testFullGRUCpu" "-DSYS=/Users/abhiacherjee/Documents/rootbench/root" "-P" "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootTestDriver.cmake")
set_tests_properties([=[TMVA-DNN-GRU-Full-Cpu]=] PROPERTIES  ENVIRONMENT "ROOT_HIST=0" _BACKTRACE_TRIPLES "/Users/abhiacherjee/Documents/rootbench/root/RootMacros.cmake;1696;add_test;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/GRU/CMakeLists.txt;45;ROOT_ADD_TEST;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/GRU/CMakeLists.txt;0;")
