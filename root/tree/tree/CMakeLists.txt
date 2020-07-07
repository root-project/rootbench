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
    DOWNLOAD_DATAFILES h1dst-lz4.root h1dst-lzma.root h1dst-none.root h1dst-zlib.root h1dst-zstd.root
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c zlib ${RB_DATASETDIR}/h1dst-zlib.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c lzma ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c lz4 ${RB_DATASETDIR}/h1dst-lz4.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c zstd ${RB_DATASETDIR}/h1dst-zstd.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c none ${RB_DATASETDIR}/h1dst-none.root")
endif()
