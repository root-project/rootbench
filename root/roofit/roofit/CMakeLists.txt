configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.rootrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
RB_ADD_GBENCHMARK(RoofitBinnedBenchmark
  RooFitBinnedBenchmarks.cxx
  LABEL long
  LIBRARIES Core Hist MathCore RIO RooFit RooStats RooFitCore HistFactory)

RB_ADD_GBENCHMARK(RoofitUnBinnedBenchmark
  RooFitUnBinnedBenchmarks.cxx
  LABEL long
  LIBRARIES Core Hist MathCore RIO RooFit RooStats RooFitCore HistFactory)

