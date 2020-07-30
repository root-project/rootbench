if(ROOT_dataframe_FOUND)
  RB_ADD_GBENCHMARK(TTreeBenchmarks
    TTreeBenchmarks.cxx
    TTreeSumBenchmarks.cxx
    LABEL short
    LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)
endif(ROOT_dataframe_FOUND)

if(ROOT_root7_FOUND AND rootbench-datafiles AND ROOT_dataframe_FOUND)
  RB_GENERATE_DICTIONARY(h1event ${CMAKE_CURRENT_SOURCE_DIR}/include/h1event.h
                            LINKDEF h1linkdef.h)

  RB_ADD_TOOL(gen_h1 ${CMAKE_CURRENT_SOURCE_DIR}/gen_h1.cxx
            LIBRARIES Core Hist Imt RIO Tree TreePlayer
            ROOTDataFrame ROOTVecOps ROOTNTuple
            DEPENDS libh1event
  )

  RB_ADD_TOOL(gen_atlas ${CMAKE_CURRENT_SOURCE_DIR}/gen_atlas.cxx
            LIBRARIES Core Hist Imt RIO Tree TreePlayer
            ROOTDataFrame ROOTVecOps ROOTNTuple
            DEPENDS libh1event
  )

  RB_ADD_GBENCHMARK(RNTupleH1Benchmarks
    RNTupleH1Benchmarks.cxx
    LABEL short
    LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
    DOWNLOAD_DATAFILES h1dst-lzma.root
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c zlib ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c lzma ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c lz4 ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c zstd ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_h1 -o ${RB_DATASETDIR} -c none ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${RB_HADD_EXECUTABLE} -f101 ${RB_DATASETDIR}/h1dst-zlib.root ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${RB_HADD_EXECUTABLE} -f404 ${RB_DATASETDIR}/h1dst-lz4.root ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${RB_HADD_EXECUTABLE} -f506 ${RB_DATASETDIR}/h1dst-zstd.root ${RB_DATASETDIR}/h1dst-lzma.root"
    SETUP "${RB_HADD_EXECUTABLE} -f0 ${RB_DATASETDIR}/h1dst-none.root ${RB_DATASETDIR}/h1dst-lzma.root")

  RB_ADD_GBENCHMARK(RNTupleATLASBenchmarks
    RNTupleATLASBenchmarks.cxx
    LABEL short
    LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
    DOWNLOAD_DATAFILES gg_data-zstd.root
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_atlas -i ${RB_DATASETDIR}/gg_data-zstd.root -o ${RB_DATASETDIR} -c zlib"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_atlas -i ${RB_DATASETDIR}/gg_data-zstd.root -o ${RB_DATASETDIR} -c lzma"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_atlas -i ${RB_DATASETDIR}/gg_data-zstd.root -o ${RB_DATASETDIR} -c lz4"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_atlas -i ${RB_DATASETDIR}/gg_data-zstd.root -o ${RB_DATASETDIR} -c zstd"
    SETUP "${CMAKE_CURRENT_BINARY_DIR}/gen_atlas -i ${RB_DATASETDIR}/gg_data-zstd.root -o ${RB_DATASETDIR} -c none")
endif(ROOT_root7_FOUND AND rootbench-datafiles AND ROOT_dataframe_FOUND)

if(ROOT_root7_FOUND AND rootbench-datafiles)
  RB_ADD_GBENCHMARK(RNTupleLHCBBenchmarks
   RNTupleLHCBBenchmarks.cxx
   LABEL short
   LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
   DOWNLOAD_DATAFILES B2HHH~none.rc2.ntuple)
endif(ROOT_root7_FOUND AND rootbench-datafiles)
