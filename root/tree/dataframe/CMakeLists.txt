RB_ADD_GBENCHMARK(RDFBenchmarks
  RDataFrameBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

RB_ADD_GBENCHMARK(DFBenchmarks
  RDataFrame_vs_Tree.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

