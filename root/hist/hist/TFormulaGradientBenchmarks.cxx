#include <TFormula.h>
#include <TF1.h>
#include <TFitResult.h>

#include <benchmark/benchmark.h>

// Generate clad gradient function and evaluate it.
inline static void clad_eval(TF1*, TFormula* f, Double_t* x, Double_t* result) {
  f->GradientPar(x, result);
}

// Evaluate gradient via numerical method.
inline static void numerical_eval(TF1* h, TFormula*, Double_t* x, Double_t* result) {
  h->GradientPar(x, result);
}

// Benchmark for the formula with given name.
// EVAL is either clad_eval to benchmark clad or numerical_eval to benchmark
// numerical method.
template <typename F>
static void BM_TFormulaPerf(benchmark::State &state, const char* formula, F&& eval, bool useClad = false) {
  auto h = new TF1("f1", formula);
  int Npar = h->GetNpar();
  double* p = new double[Npar];
  for (int i = 0; i < Npar; i++) p[i] = std::rand() % 100;
  h->SetParameters(p);
  int Ndim = h->GetNdim();
  double* x = new double[Ndim]{};
  for (int i = 0; i < Ndim; i++) x[i] = std::rand() % 100;
  TFormula::CladStorage result(Npar);
  TFormula *f = nullptr;
  if (useClad) {
     f = h->GetFormula();
     f->GenerateGradientPar();
  }

  for (auto _ : state)
    eval(h, f, x, result.data());
  delete[] p;
  delete[] x;
}

#define DEFINE_BM_TFormulaPerf_CLAD(formula) \
   BENCHMARK_CAPTURE(BM_TFormulaPerf, formula##_Clad, #formula, clad_eval, true);

#define DEFINE_BM_TFormulaPerf_NUMERICAL(formula) \
  BENCHMARK_CAPTURE(BM_TFormulaPerf, formula##_Numerical, #formula, numerical_eval);

#define DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(formula) \
  DEFINE_BM_TFormulaPerf_CLAD(formula) \
  DEFINE_BM_TFormulaPerf_NUMERICAL(formula)

DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(gaus)

DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(expo)

//DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(crystalball)

DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(breitwigner)

DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(cheb0)
DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(cheb1)
DEFINE_BM_TFormulaPerf_CLAD_AND_NUMERICAL(cheb2)

