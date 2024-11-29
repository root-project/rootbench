# CMake generated Testfile for 
# Source directory: /Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/LSTM
# Build directory: /Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/LSTM
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[TMVA-DNN-LSTM-Forward-Cpu]=] "/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake" "-DCMD=/Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/LSTM/testLSTMForwardPassCpu" "-DSYS=/Users/abhiacherjee/Documents/rootbench/root" "-P" "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootTestDriver.cmake")
set_tests_properties([=[TMVA-DNN-LSTM-Forward-Cpu]=] PROPERTIES  ENVIRONMENT "ROOT_HIST=0" _BACKTRACE_TRIPLES "/Users/abhiacherjee/Documents/rootbench/root/RootMacros.cmake;1696;add_test;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/LSTM/CMakeLists.txt;48;ROOT_ADD_TEST;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/LSTM/CMakeLists.txt;0;")
add_test([=[TMVA-DNN-LSTM-Backward-Cpu]=] "/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake" "-DCMD=/Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/LSTM/testLSTMBackpropagationCpu" "-DSYS=/Users/abhiacherjee/Documents/rootbench/root" "-P" "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootTestDriver.cmake")
set_tests_properties([=[TMVA-DNN-LSTM-Backward-Cpu]=] PROPERTIES  ENVIRONMENT "ROOT_HIST=0" _BACKTRACE_TRIPLES "/Users/abhiacherjee/Documents/rootbench/root/RootMacros.cmake;1696;add_test;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/LSTM/CMakeLists.txt;52;ROOT_ADD_TEST;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/LSTM/CMakeLists.txt;0;")
add_test([=[TMVA-DNN-LSTM-Full-Cpu]=] "/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake" "-DCMD=/Users/abhiacherjee/Documents/rootbench/root/tmva/tmva/test/DNN/LSTM/testFullLSTMCpu" "-DSYS=/Users/abhiacherjee/Documents/rootbench/root" "-P" "/Users/abhiacherjee/Documents/root_src/cmake/modules/RootTestDriver.cmake")
set_tests_properties([=[TMVA-DNN-LSTM-Full-Cpu]=] PROPERTIES  ENVIRONMENT "ROOT_HIST=0" _BACKTRACE_TRIPLES "/Users/abhiacherjee/Documents/rootbench/root/RootMacros.cmake;1696;add_test;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/LSTM/CMakeLists.txt;56;ROOT_ADD_TEST;/Users/abhiacherjee/Documents/root_src/tmva/tmva/test/DNN/LSTM/CMakeLists.txt;0;")
