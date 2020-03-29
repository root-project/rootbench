RB_ADD_GBENCHMARK(IOBenchmarks
  TBufferMergerBenchmarks.cxx
  LABEL short
  LIBRARIES Core RIO Tree TreePlayer)

RB_ADD_GBENCHMARK(TFile_RDFSnapshot
  TFile_RDFSnapshot.cxx
  LABEL short
  LIBRARIES Core RIO ROOTDataFrame MathCore) 

if(rootbench-datafiles)
  RB_ADD_GBENCHMARK(CompressionBenchmarks_MainEvent
    TFile_CompressionBenchmarks_MainEvent.cxx
    LABEL short
    LIBRARIES Core RIO
    DOWNLOAD_DATAFILES Event0-sample.root)
endif()