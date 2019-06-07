RB_ADD_GBENCHMARK(RDFBenchmarks
  RDataFrameBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

RB_ADD_GBENCHMARK(DFBenchmarks
  df_vs_tree.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)
