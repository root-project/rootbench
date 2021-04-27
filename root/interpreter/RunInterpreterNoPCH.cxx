#include "InterpreterTest.h"

#include "benchmark/benchmark.h"

BENCHMARK_CAPTURE(TestTutorial, Test_nopch_minuit2, "tutorials/", "fit/minuit2FitBench.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_minuit2Gaus, "tutorials/", "fit/minuit2GausFit.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_quadp, "tutorials/", "quadp/portfolio.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_foam, "tutorials/", "foam/foam_demo.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_fftw, "tutorials/", "fft/FFT.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_higgs, "tutorials/", "mlp/mlpHiggs.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_regression, "tutorials/", "mlp/mlpRegression.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_higgs, "tutorials/", "mlp/mlpHiggs.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_regression, "tutorials/", "mlp/mlpRegression.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_assembly, "tutorials/", "geom/assembly.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_na49, "tutorials/", "geom/na49.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_rootgeom, "tutorials/", "geom/rootgeom.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_parallel_world, "tutorials/", "geom/parallel_world.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mp3player, "tutorials/", "geom/mp3player.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_geometry, "tutorials/", "geom/geometry.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_radionucl, "tutorials/", "geom/RadioNuclides.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_rootgeom, "tutorials/", "geom/rootgeom.C")->Unit(benchmark::kMicrosecond)->UseManualTime();
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_xtruSamples, "tutorials/", "geom/xtruSamples.C")->Unit(benchmark::kMicrosecond)->UseManualTime();

BENCHMARK_MAIN();
