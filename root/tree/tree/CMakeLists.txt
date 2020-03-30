include_directories(${PROJECT_SOURCE_DIR}/root/tree/dataframe)

RB_ADD_GBENCHMARK(TTreeBenchmarks
  TTreeBenchmarks.cxx
  TTreeSumBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

if(ROOT_root7_FOUND AND rootbench-datafiles)

  # Generate fresh RNTuples files (since format is still not stable, we will generate files each time)
  add_custom_target(h1-rntuple-generation ALL DEPENDS 
    ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-zlib.ntuple 
    ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-lzma.ntuple
    ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-lz4.ntuple
    ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-zstd.ntuple
    ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-none.ntuple
  )
  # Generate fresh RNTuples files (since format is still not stable, we will generate files each time)

  add_custom_command(OUTPUT  ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-zlib.ntuple
    COMMAND ${PROJECT_BINARY_DIR}/tools/datafile-generators/gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c zlib h1dst-zlib.root
    POST_COMMAND 
      COMMAND ${CMAKE_COMMAND} -E
        copy_if_different
        ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-zlib.ntuple
        ${CMAKE_CURRENT_BINARY_DIR}/h1dst-zlib.ntuple
    DEPENDS gen_h1
  )
  # Generate fresh RNTuples files (since format is still not stable, we will generate files each time)
  add_custom_command(OUTPUT  ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-lzma.ntuple
    COMMAND ${PROJECT_BINARY_DIR}/tools/datafile-generators/gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c lzma h1dst-lzma.root
    POST_COMMAND 
      COMMAND ${CMAKE_COMMAND} -E
          copy_if_different
          ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-lzma.ntuple
          ${CMAKE_CURRENT_BINARY_DIR}/h1dst-lzma.ntuple
    DEPENDS gen_h1
  )
  # Generate fresh RNTuples files (since format is still not stable, we will generate files each time)
  add_custom_command(OUTPUT  ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-lz4.ntuple
    COMMAND ${PROJECT_BINARY_DIR}/tools/datafile-generators/gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c lz4 h1dst-lz4.root
    POST_COMMAND 
    COMMAND ${CMAKE_COMMAND} -E
      copy_if_different
      ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-lz4.ntuple
      ${CMAKE_CURRENT_BINARY_DIR}/h1dst-lz4.ntuple
    DEPENDS gen_h1
  )
  # Generate fresh RNTuples files (since format is still not stable, we will generate files each time)
  add_custom_command(OUTPUT  ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-zstd.ntuple
    COMMAND ${PROJECT_BINARY_DIR}/tools/datafile-generators/gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c zstd h1dst-zstd.root
    POST_COMMAND 
    COMMAND ${CMAKE_COMMAND} -E
      copy_if_different
      ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-zstd.ntuple
      ${CMAKE_CURRENT_BINARY_DIR}/h1dst-zstd.ntuple
    DEPENDS gen_h1
  )
  # Generate fresh RNTuples files (since format is still not stable, we will generate files each time)
  add_custom_command(OUTPUT  ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-none.ntuple
    COMMAND ${PROJECT_BINARY_DIR}/tools/datafile-generators/gen_h1 -o ${PROJECT_BINARY_DIR}/rootbench-datafiles -c none h1dst-none.root
    POST_COMMAND 
    COMMAND ${CMAKE_COMMAND} -E
      copy_if_different
      ${PROJECT_BINARY_DIR}/rootbench-datafiles/h1dst-none.ntuple
      ${CMAKE_CURRENT_BINARY_DIR}/h1dst-none.ntuple
    DEPENDS gen_h1
  )

  RB_ADD_GBENCHMARK(RNTupleAnalysisBenchmarks
    RNTupleH1Benchmarks.cxx
    LABEL short
    LIBRARIES Core Hist MathCore RIO Tree ROOTNTuple
    DEPENDS h1-rntuple-generation
    DOWNLOAD_DATAFILES h1dst-lz4.root
              h1dst-lzma.root
              h1dst-none.root
              h1dst-zlib.root
              h1dst-zstd.root
    )
endif()