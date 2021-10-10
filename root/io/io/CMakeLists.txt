RB_ADD_GBENCHMARK(IOBenchmarks
  TBufferMergerBenchmarks.cxx
  LABEL short
  LIBRARIES Core RIO Tree TreePlayer)

if(ROOT_dataframe_FOUND AND ROOT_root7_FOUND) # using ROOT_root7_FOUND as a proxy for "c++ standard >= 14"
  RB_ADD_GBENCHMARK(TFile_RDFSnapshot
    TFile_RDFSnapshot.cxx
    LABEL short
  LIBRARIES Core RIO ROOTDataFrame Tree TreePlayer MathCore)
endif()

if(rootbench-datafiles)
  # FIXME:Compression tests needs to have libEvent.so which is a part of ROOT build
  # Preloading doesn't help...
  #if(TARGET Event)
  #  RB_ADD_GBENCHMARK(CompressionBenchmarks_MainEvent
  #    TFile_CompressionBenchmarks_MainEvent.cxx
  #    LABEL short
  #    LIBRARIES Core RIO
  #    DOWNLOAD_DATAFILES Event0-sample.root)
  #endif()

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
