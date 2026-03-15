#include "InterpreterTest.h"

#include "benchmark/benchmark.h"

BENCHMARK_CAPTURE(TestTutorial, Test_nopch_minuit2, "tutorials", "math/fit/minuit2FitBench.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_minuit2Gaus, "tutorials", "math/fit/minuit2GausFit.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_quadp, "tutorials", "math/quadp/portfolio.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_foam, "tutorials", "math/foam/foam_demo.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_fftw, "tutorials", "math/fft/FFT.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_higgs, "tutorials", "legacy/mlp/mlpHiggs.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_regression, "tutorials", "legacy/mlp/mlpRegression.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_assembly, "tutorials", "geom/assembly.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_na49, "tutorials", "legacy/g3d/na49.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_rootgeom, "tutorials", "visualisation/geom/rootgeom.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_parallel_world, "tutorials", "visualisation/geom/parallel_world.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mp3player, "tutorials", "visualisation/geom/mp3player.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_geometry, "tutorials", "legacy/g3d/geometry.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_radionucl, "tutorials", "visualisation/geom/RadioNuclides.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_xtruSamples, "tutorials", "legacy/g3d/xtruSamples.C")->Unit(benchmark::kMicrosecond)->UseManualTime();

BENCHMARK_MAIN();
