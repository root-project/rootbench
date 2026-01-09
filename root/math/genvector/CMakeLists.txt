if(NOT CMAKE_SYSTEM_NAME MATCHES Darwin)
  RB_ADD_GBENCHMARK(GenVectorBenchmarks
    Cartesian3DBenchmarks.cxx
    LABEL short
    LIBRARIES GenVector MathCore)
endif()