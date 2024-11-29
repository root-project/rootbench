RB_ADD_GBENCHMARK(InterpreterBenchmarks
  RunInterpreter.cxx
  LABEL short)

RB_ADD_GBENCHMARK(InterpreterBenchmarksNoPCH
  RunInterpreterNoPCH.cxx
  LABEL short)

RB_ADD_MEM_GBENCHMARK(InterpreterLookupHelperBenchmarks
  LookupHelper.cxx LIBRARIES Core
  LABEL short)
