include_directories(${PROJECT_SOURCE_DIR}/root/tree/dataframe)

RB_ADD_GBENCHMARK(TTreeBenchmarks
  TTreeBenchmarks.cxx
  TTreeSumBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

if(ROOT_root7_FOUND)
  RB_ADD_GBENCHMARK(RNTupleGenericBenchmarks
    RNTupleGenericBenchmarks.cxx
    LABEL short
    LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple)
endif()

if(ROOT_root7_FOUND AND rootbench_datafiles)
  RB_ADD_GBENCHMARK(RNTupleAnalysisBenchmarks
    RNTupleH1Benchmarks.cxx
    LABEL short
    LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
    DATAFILES h1ds-lz4.root
              h1ds-lzma.root
              h1ds-none.root
              h1ds-zlib.root
              h1ds-zstd.root
    )
endif()