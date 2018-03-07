#include "PyROOTTest.h"

#include "benchmark/benchmark.h"

BENCHMARK_CAPTURE(TestTutorial, Test_hsimple_py, "tutorials/pyroot/", "hsimple.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_framework_py, "tutorials/pyroot/", "framework.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_hsum_py, "tutorials/pyroot/", "hsum.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_formula1_py, "tutorials/pyroot/", "formula1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_fillrandom_py, "tutorials/pyroot/", "fillrandom.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_fit1_py, "tutorials/pyroot/", "fit1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_h1draw_py, "tutorials/pyroot/", "h1draw.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_graph_py, "tutorials/pyroot/", "graph.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_gerrors_py, "tutorials/pyroot/", "gerrors.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_tornado_py, "tutorials/pyroot/", "tornado.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_surfaces_py, "tutorials/pyroot/", "surfaces.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_zdemo_py, "tutorials/pyroot/", "zdemo.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_geometry_py, "tutorials/pyroot/", "geometry.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_na49view_py, "tutorials/pyroot/", "na49view.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_file_py, "tutorials/pyroot/", "file.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_ntuple1_py, "tutorials/pyroot/", "ntuple1.py")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_rootmarks_py, "tutorials/pyroot/", "rootmarks.py")->Unit(benchmark::kMicrosecond)->UseManualTime();

BENCHMARK_MAIN();
