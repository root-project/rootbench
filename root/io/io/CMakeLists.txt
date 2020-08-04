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

  # FIXME: too long benchmarks, needs to be optimised
  #RB_ADD_GBENCHMARK(CompressionBenchmarks_LHCb
  #  TFile_LHCb_Benchmarks.cxx
  #  LABEL short
  #  LIBRARIES Core RIO
  #  DOWNLOAD_DATAFILES lhcb_B2ppKK2011_md_noPIDstrip.root)

  #RB_ADD_GBENCHMARK(CompressionBenchmarks_NanoAOD
  #  TFile_NanoAOD_Benchmarks.cxx
  #  LABEL short
  #  LIBRARIES Core RIO
  #  DOWNLOAD_DATAFILES Run2012B_DoubleMuParked.root)

  #RB_ADD_GBENCHMARK(CompressionBenchmarks_ATLAS
  #  TFile_ATLAS_Benchmarks.cxx
  #  LABEL short
  #  LIBRARIES Core RIO
  #  DOWNLOAD_DATAFILES gg_data-zstd.root)
endif()
