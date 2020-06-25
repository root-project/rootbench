include_directories(${PROJECT_SOURCE_DIR}/root/tree/dataframe)
include_directories(${PROJECT_SOURCE_DIR}/root/tree/tree/inc)

RB_ADD_GBENCHMARK(TTreeBenchmarks
  TTreeBenchmarks.cxx
  TTreeSumBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)


# Generation of datafiles for RNTuple benchmarks is moved in fixtures
if(ROOT_root7_FOUND)
  RB_GENERATE_DICTIONARY(libh1event ${CMAKE_CURRENT_SOURCE_DIR}/inc/h1event.h
                            LINKDEF inc/h1LinkDef.h)

  add_custom_command(TARGET libh1eventlibgen POST_BUILD
                            COMMAND ${CMAKE_COMMAND} -E copy
                                ${CMAKE_CURRENT_BINARY_DIR}/libh1event.so
				${CMAKE_BINARY_DIR}/lib/libh1event.so)
			
  RB_ADD_TOOL(gen_h1 ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_h1.cxx
            LIBRARIES Core Hist Imt RIO Tree TreePlayer 
            ROOTDataFrame ROOTVecOps ROOTNTuple h1event
            DEPENDENCIES libh1eventlibgen
)
endif()

if(ROOT_root7_FOUND AND rootbench-datafiles)
  RB_ADD_GBENCHMARK(RNTupleAnalysisBenchmarks
    RNTupleH1Benchmarks.cxx
    LABEL short
    LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
    FIXTURES_DOWNLOAD h1dst-none.root h1dst-zstd.root h1dst-lz4.root h1dst-lzma.root h1dst-zlib.root
    FIXTURES_SETUP "./gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c none ${PROJECT_BINARY_DIR}/rootbench-data/h1dst-none.root"
    FIXTURES_SETUP "./gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c zstd ${PROJECT_BINARY_DIR}/rootbench-data/h1dst-zstd.root"
    FIXTURES_SETUP "./gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c lz4 ${PROJECT_BINARY_DIR}/rootbench-data/h1dst-lz4.root"
    FIXTURES_SETUP "./gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c lzma ${PROJECT_BINARY_DIR}/rootbench-data/h1dst-lzma.root"
    FIXTURES_SETUP "./gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c zlib ${PROJECT_BINARY_DIR}/rootbench-data/h1dst-zlib.root"
    DOWNLOAD_DATAFILES h1dst-lz4.root
              h1dst-lzma.root
              h1dst-none.root
              h1dst-zlib.root
              h1dst-zstd.root
    )
endif()