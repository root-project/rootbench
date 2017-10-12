RB_ADD_GBENCHMARK(RoofitBenchmarks
  RooFitBinnedBenchmarks.cxx
  LIBRARIES
  Core
  Hist
  MathCore
  RIO
  RooFit
  RooStats
  RooFitCore
  HistFactory)

 add_test(NAME rootbench-RoofitBenchmarks
		COMMAND RoofitBenchmarks --benchmark_out_format=json)
