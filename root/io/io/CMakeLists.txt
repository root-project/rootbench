RB_ADD_GBENCHMARK(IOBenchmarks
  TBufferMergerBenchmarks.cxx
  LABEL short
  LIBRARIES Core RIO Tree TreePlayer)

RB_ADD_GBENCHMARK(TFile_RDFSnapshot
  TFile_RDFSnapshot.cxx
  LABEL short
  LIBRARIES Core RIO ROOTDataFrame MathCore) 

RB_ADD_GBENCHMARK(TFile_MainEvent
  TFile_MainEvent.cxx
  LABEL short
  LIBRARIES Core RIO) 