#include "InterpreterTest.h"

#include "benchmark/benchmark.h"

BENCHMARK_CAPTURE(TestTutorial, Test_startup, "", "")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hsimple, "tutorials", "hsimple.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_TMVAGAexample, "tutorials", "machine_learning/TMVAGAexample.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_TMVAGAexample2, "tutorials", "machine_learning/TMVAGAexample2.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hvector, "tutorials", "io/tree/tree121_hvector.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hinvertMatrix, "tutorials", "math/matrix/invertMatrix.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_fitLinear, "tutorials", "math/fit/fitLinear.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit103, "tutorials", "roofit/roofit/rf103_interprfuncs.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit105, "tutorials", "roofit/roofit/rf105_funcbinding.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit109, "tutorials", "roofit/roofit/rf109_chi2residpull.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit110, "tutorials", "roofit/roofit/rf110_normintegration.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_roofit204, "tutorials", "roofit/roofit/rf204a_extendedLikelihood.C")->Unit(benchmark::kMicrosecond)->UseManualTime();

BENCHMARK_MAIN();
