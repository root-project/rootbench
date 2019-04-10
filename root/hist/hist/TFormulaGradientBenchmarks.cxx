#include <TFormula.h>
#include <TF1.h>
#include <TFitResult.h>
#include <TH1.h>

#include <benchmark/benchmark.h>

static void BM_TFormula_GausTFormulaPerf_Clad(benchmark::State &state) {
  auto h = new TF1("f1", "gaus");
  double p[] = {3, 1, 2};
  h->SetParameters(p);
  double x[] = {0};
  TFormula::GradientStorage result_clad(3);
  TFormula *f = h->GetFormula();

  for (auto _ : state) {
    f->GenerateGradientPar();
    f->GradientPar(x, result_clad.data());
  }
}

BENCHMARK(BM_TFormula_GausTFormulaPerf_Clad);

static void BM_TFormula_GausTFormulaPerf_Numerical(benchmark::State &state) {
  auto h = new TF1("f1", "gaus");
  double p[] = {3, 1, 2};
  h->SetParameters(p);
  double x[] = {0};
  TFormula::GradientStorage result_num(3);

  for (auto _ : state) {
    h->GradientPar(x, result_num.data());
  }
}

BENCHMARK(BM_TFormula_GausTFormulaPerf_Numerical);

static void BM_TFormula_GausPerf_Clad(benchmark::State &state) {
  auto f1 = new TF1("f1", "gaus");
  auto h1 = new TH1D("h1", "h1", 1000000, -5, 5);
  double p1[] = {1, 0, 1.5};
  f1->SetParameters(p1);
  h1->FillRandom("f1", 100000);
  double p2[] = {100, 1, 3};
  f1->SetParameters(p2);
  auto r1 = h1->Fit(f1, "S"); // numerical
  f1->GetFormula()->GenerateGradientPar(); // makes it om par

  for (auto _ : state) {
    auto r2 = h1->Fit(f1, "S G"); // clad
  }
}

BENCHMARK(BM_TFormula_GausPerf_Clad);

static void BM_TFormula_GausPerf_Numerical(benchmark::State &state) {
  auto f1 = new TF1("f1", "gaus");
  auto h1 = new TH1D("h1", "h1", 1000000, -5, 5);
  double p1[] = {1, 0, 1.5};
  f1->SetParameters(p1);
  h1->FillRandom("f1", 100000);
  double p2[] = {100, 1, 3};
  f1->SetParameters(p2);

  for (auto _ : state) {
    auto r1 = h1->Fit(f1, "S"); // numerical
  }
}

BENCHMARK(BM_TFormula_GausPerf_Numerical);
