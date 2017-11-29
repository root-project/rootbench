#include "InterpreterTest.h"

#include "benchmark/benchmark.h"

BENCHMARK_CAPTURE(TestTutorial, Test_nopch_minuit2, "tutorials/", "fit/minuit2FitBench.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_minuit2Gaus, "tutorials/", "fit/minuit2GausFit.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_quadp, "tutorials/", "quadp/portfolio.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_foam, "tutorials/", "foam/foam_demo.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_fftw, "tutorials/", "fft/FFT.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_higgs, "tutorials/", "mlp/mlpHiggs.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_regression, "tutorials/", "mlp/mlpRegression.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_higgs, "tutorials/", "mlp/mlpHiggs.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mlp_regression, "tutorials/", "mlp/mlpRegression.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_assembly, "tutorials/", "geom/assembly.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_na49, "tutorials/", "geom/na49.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_geomAlice, "tutorials/", "geom/geomAlice.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_geomAtlas, "tutorials/", "geom/geomAtlas.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_mp3player, "tutorials/", "geom/mp3player.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_geamD0, "tutorials/", "geom/geomD0.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_radionucl, "tutorials/", "geom/RadioNuclides.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_rootgeom, "tutorials/", "geom/rootgeom.C")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(TestTutorial, Test_nopch_geodemo, "tutorials/", "geom/geodemo.C")->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
