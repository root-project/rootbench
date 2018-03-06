#include "PyROOTTest.h"

#include "benchmark/benchmark.h"

BENCHMARK_CAPTURE(TestTutorial, Test_hsimple, "tutorials/pyroot/", "hsimple.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_framework, "tutorials/pyroot/", "framework.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hsum, "tutorials/pyroot/", "hsum.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_formula1, "tutorials/pyroot/", "formula1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_fillrandom, "tutorials/pyroot/", "fillrandom.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_fit1, "tutorials/pyroot/", "fit1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_h1draw, "tutorials/pyroot/", "h1draw.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_graph, "tutorials/pyroot/", "graph.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_gerrors, "tutorials/pyroot/", "gerrors.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_tornado, "tutorials/pyroot/", "tornado.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_surfaces, "tutorials/pyroot/", "surfaces.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_zdemo, "tutorials/pyroot/", "zdemo.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_geometry, "tutorials/pyroot/", "geometry.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_na49view, "tutorials/pyroot/", "na49view.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_file, "tutorials/pyroot/", "file.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_ntuple1, "tutorials/pyroot/", "ntuple1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_rootmarks, "tutorials/pyroot/", "rootmarks.py")->Unit(benchmark::kMicrosecond)->UseManualTime();

BENCHMARK_MAIN();
