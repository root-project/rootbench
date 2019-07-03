include_directories(${PROJECT_SOURCE_DIR}/root/tree/dataframe)

RB_ADD_GBENCHMARK(TTreeBenchmarks
  TTreeBenchmarks.cxx
  TTreeSumBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)
