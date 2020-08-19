RB_ADD_GBENCHMARK(IOBenchmarks
  TBufferMergerBenchmarks.cxx
  LABEL short
  LIBRARIES Core RIO Tree TreePlayer)

RB_ADD_GBENCHMARK(TFile_RDFSnapshot
  TFile_RDFSnapshot.cxx
  LABEL short
LIBRARIES Core RIO ROOTDataFrame Tree TreePlayer MathCore)

if(rootbench-datafiles)
  RB_ADD_GBENCHMARK(CompressionBenchmarks_MainEvent
    TFile_CompressionBenchmarks_MainEvent.cxx
    LABEL short
    LIBRARIES Core RIO
    DOWNLOAD_DATAFILES Event0-sample.root)

  RB_ADD_GBENCHMARK(CompressionBenchmarks_LHCb
    TFile_LHCb_Benchmarks.cxx
    LABEL short
    LIBRARIES Core RIO
    DOWNLOAD_DATAFILES lhcb_B2ppKK2011_md_noPIDstrip.root)

  RB_ADD_GBENCHMARK(CompressionBenchmarks_NanoAOD
    TFile_NanoAOD_Benchmarks.cxx
    LABEL short
    LIBRARIES Core RIO
    DOWNLOAD_DATAFILES Run2012B_DoubleElectron.root)

  RB_ADD_GBENCHMARK(CompressionBenchmarks_ATLAS
    TFile_ATLAS_Benchmarks.cxx
    LABEL short
    LIBRARIES Core RIO
    DOWNLOAD_DATAFILES atlasopendata_mc_117050.ttbar_lep.root atlasopendata_DataMuons.root)
endif()