RB_ADD_GBENCHMARK(RoofitBenchmarks
  RooFitBinnedBenchmarks.cxx
  LIBRARIES
  RooFit
  RooFitCore
  HistFactory)

 add_test(NAME rootbench-RoofitBenchmarks
		COMMAND RoofitBenchmarks --benchmark_out_format=json)
