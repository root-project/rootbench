RB_ADD_GBENCHMARK(IOBenchmarks
  TBufferMergerBenchmarks.cxx
  LABEL short
  LIBRARIES Core RIO Tree TreePlayer)

RB_ADD_GBENCHMARK(CompressBenchmarks
  TFileBenchmarks.cxx
  LABEL short
  LIBRARIES Core RIO ROOTDataFrame MathCore) 