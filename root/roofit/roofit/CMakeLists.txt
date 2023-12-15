RB_ADD_GBENCHMARK(benchRooFitBinned
  RooFitBinnedBenchmarks.cxx
  LABEL long
  LIBRARIES Core Hist MathCore RIO RooFit RooStats RooFitCore HistFactory)

RB_ADD_GBENCHMARK(benchRooFitUnbinned
  RooFitUnBinnedBenchmarks.cxx
  LABEL long
  LIBRARIES Core Hist MathCore RIO RooFit RooStats RooFitCore HistFactory)

RB_ADD_GBENCHMARK(benchRooFitBackends
  benchRooFitBackends.cxx
  LABEL long
  LIBRARIES Core MathCore RooFitCore RooFit)

if(cuda)
  target_compile_definitions(benchRooFitUnbinned PRIVATE DO_BENCH_ROOFIT_CUDA)
  target_compile_definitions(benchRooFitBackends PRIVATE DO_BENCH_ROOFIT_CUDA)
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/benchRooFitBackends_make_plot.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

RB_ADD_GBENCHMARK(benchCodeSquashAD
  benchCodeSquashAD.cxx
  LABEL long
  LIBRARIES Core MathCore RooFit RooStats RooFitCore)
