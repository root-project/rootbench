#include "TFormula.h"

#include "benchmark/benchmark.h"

class TFormulaTests : public TFormula {
public:
  TFormulaTests(TString name, TString formula): TFormula(name,formula){}
   virtual     ~TFormulaTests(){}
   Bool_t      ParserNew();
   Bool_t      GetVarVal();
   Bool_t      GetParVal();
   Bool_t      AddVar();
   Bool_t      SetVar();
   Bool_t      AddVars();
   Bool_t      SetVars();
   Bool_t      SetPar1();
   Bool_t      SetPar2();
   Bool_t      SetPars1();
   Bool_t      SetPars2();
   Bool_t      Eval();
   Bool_t      Stress(Int_t n = 10000);
   Bool_t      Parser();
   Bool_t      Vectorize();
};

static void BM_TFormula_CreateEmpty(benchmark::State &state)
{
   for (auto _ : state) {
     TFormulaTests f();
   }
}
BENCHMARK(BM_TFormula_CreateEmpty);

static void BM_TFormula_Math_Sin(benchmark::State &state) {
  TString testFormula;
  for (auto _ : state) {
    testFormula = "x- [test]^(TMath::Sin(pi*var*TMath::DegToRad())) - var1pol2(0) + gausn(0)*landau(0)+expo(10)";

    TFormulaTests * test = new TFormulaTests("TFtests","");
    test->AddVariable("var",0);
    test->AddVariable("var1",0);
    test->Compile(testFormula);
  }
}
BENCHMARK(BM_TFormula_Math_Sin);

static void BM_TFormula_Pow(benchmark::State &state) {
  TString testFormula;
  for (auto _ : state) {
    testFormula = "pow(5.7, 2.4)";

    TFormulaTests * test = new TFormulaTests("TFtests","");
    test->Compile(testFormula);
  }
}
BENCHMARK(BM_TFormula_Pow);

static void BM_TFormula_Std_Pow(benchmark::State &state) {
  TString testFormula;
  for (auto _ : state) {
    testFormula = "std::pow(5.7, 2.4)";

    TFormulaTests * test = new TFormulaTests("TFtests","");
    test->Compile(testFormula);
  }
}
BENCHMARK(BM_TFormula_Std_Pow);

// Define our main.
BENCHMARK_MAIN();
