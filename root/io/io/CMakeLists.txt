RB_ADD_GBENCHMARK(IOBenchmarks
  TBufferMergerBenchmarks.cxx
  LIBRARIES
  Core RIO Tree TreePlayer
  )
 
 add_test(NAME rootbench-IOBenchmarks
		COMMAND IOBenchmarks --benchmark_out_format=json)