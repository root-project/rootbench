if(NOT CMAKE_SYSTEM_NAME MATCHES Darwin)
  RB_ADD_GBENCHMARK(InterpreterBenchmarks
    RunInterpreter.cxx
    LABEL short)

  RB_ADD_GBENCHMARK(InterpreterBenchmarksNoPCH
    RunInterpreterNoPCH.cxx
    LABEL short)
endif()
