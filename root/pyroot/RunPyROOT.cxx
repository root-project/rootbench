#include "PyROOTTest.h"

#include "benchmark/benchmark.h"

// The Python tutorials that no longer exist in ROOT (framework.py, hsum.py,
// fillrandom.py, h1draw.py, graph.py, gerrors.py, zdemo.py, file.py and
// rootmarks.py) were dropped from the benchmarks, as well as geometry.py and
// na49view.py, which cannot run standalone because they depend on a geometry
// that needs to be created by other macros first.
BENCHMARK_CAPTURE(TestTutorial, Test_hsimple_py, "tutorials", "hsimple.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_formula1_py, "tutorials", "visualisation/graphics/formula1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_fit1_py, "tutorials", "math/fit/fit1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_tornado_py, "tutorials", "visualisation/graphics/tornado.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_surfaces_py, "tutorials", "visualisation/graphics/surfaces.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_ntuple1_py, "tutorials", "io/tree/ntuple1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();

BENCHMARK_MAIN();
