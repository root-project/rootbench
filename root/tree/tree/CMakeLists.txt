include_directories(${PROJECT_SOURCE_DIR}/root/tree/dataframe)

RB_ADD_GBENCHMARK(TTreeBenchmarks
  TTreeBenchmarks.cxx
  TTreeSumBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

if(ROOT_root7_FOUND)
  RB_GENERATE_DICTIONARY(h1event ${CMAKE_CURRENT_SOURCE_DIR}/include/h1event.h
                            LINKDEF h1linkdef.h)

  RB_ADD_TOOL(gen_h1 ${CMAKE_CURRENT_SOURCE_DIR}/gen_h1.cxx
            LIBRARIES Core Hist Imt RIO Tree TreePlayer
            ROOTDataFrame ROOTVecOps ROOTNTuple
            DEPENDS libh1event
  )
endif()

if(ROOT_root7_FOUND AND rootbench-datafiles)
  RB_ADD_GBENCHMARK(RNTupleAnalysisBenchmarks
    RNTupleH1Benchmarks.cxx
    LABEL short
    LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
    DOWNLOAD_DATAFILES h1dst-lzma.root
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c zlib ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c lzma ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c lz4 ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c zstd ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c none ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "hadd -f101 ${RB_DATASETDIR}/h1dst-zlib.root ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "hadd -f404 ${RB_DATASETDIR}/h1dst-lz4.root ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "hadd -f506 ${RB_DATASETDIR}/h1dst-zstd.root ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "hadd -f0 ${RB_DATASETDIR}/h1dst-none.root ${RB_DATASETDIR}/h1dst-lzma.root")

  RB_ADD_GBENCHMARK(RNTupleLHCBBenchmarks
   RNTupleLHCBBenchmarks.cxx
   LABEL short
   LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
   DOWNLOAD_DATAFILES B2HHH~none.ntuple)
endif()
