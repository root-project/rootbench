#include "InterpreterTest.h"

#include "benchmark/benchmark.h"

BENCHMARK_CAPTURE(TestTutorial, Test_startup, "", "")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hsimple, "tutorials/", "hsimple.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_TMVAGAexample, "tutorials/", "tmva/TMVAGAexample.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_TMVAGAexample2, "tutorials/", "tmva/TMVAGAexample2.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hvector, "tutorials/", "tree/hvector.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hinvertMatrix, "tutorials/", "matrix/invertMatrix.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_fitLinear, "tutorials/", "fit/fitLinear.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit103, "tutorials/", "roofit/rf103_interprfuncs.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit105, "tutorials/", "roofit/rf105_funcbinding.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit109, "tutorials/", "roofit/rf109_chi2residpull.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit110, "tutorials/", "roofit/rf110_normintegration.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit204, "tutorials/", "roofit/rf204_extrangefit.C")->Unit(benchmark::kMicrosecond)->UseManualTime();

BENCHMARK_MAIN();
