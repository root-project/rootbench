#include <TFormula.h>
#include <TF1.h>
#include <TFitResult.h>
#include <TH1.h>
#include <TRandom3.h>
#include <TStopwatch.h>
#include <Math/MinimizerOptions.h>

#include <benchmark/benchmark.h>

static void BM_TFormula_GausFit_Clad(benchmark::State &state) {
  auto f1 = new TF1("f1", "gaus");
  auto h1 = new TH1D("h1", "h1", 1000, -5, 5);
  double p1[] = {1, 0, 1.5};
  f1->SetParameters(p1);
  h1->FillRandom("f1", 100000);
  double p2[] = {100, 1, 3};
  f1->SetParameters(p2);
  // enable Clad in TFormula
  f1->GetFormula()->GenerateGradientPar();

  for (auto _ : state) {
    auto r2 = h1->Fit(f1, "S G Q N"); // clad
    if (r2->Status() != 0) Error("GausFit_Clad","Error fitting histogram");
  }
  delete f1;
  delete h1;
}

BENCHMARK(BM_TFormula_GausFit_Clad)->Unit(benchmark::kMillisecond);

static void BM_TFormula_GausFit_Numerical(benchmark::State &state) {
  auto f1 = new TF1("f1", "gaus");
  auto h1 = new TH1D("h1", "h1", 1000, -5, 5);
  double p1[] = {1, 0, 1.5};
  f1->SetParameters(p1);
  h1->FillRandom("f1", 100000);
  double p2[] = {100, 1, 3};
  f1->SetParameters(p2);

  for (auto _ : state) {
    auto r1 = h1->Fit(f1, "S Q N"); // numerical
    if (r1->Status() != 0) Error("GausFit_Numerical","Error fitting histogram");
  }
  delete f1;
  delete h1;
}

BENCHMARK(BM_TFormula_GausFit_Numerical)->Unit(benchmark::kMillisecond);

// test class for building fit with many parameters (many gaussian + polynomial)
class ManyGausFit {

private:
   TF1 *fitFunc = nullptr;
   TH1 *h1 = nullptr;
   std::vector<double> initParams;
   std::vector<double> stepSizes;
   int debug = 0;
   bool useCLAD = false;

public:
   ManyGausFit(int ng = 30, int nbins = 1000, bool clad = false, bool debLevel = false, int seed = 1111)
   {
      useCLAD = clad;
      debug = debLevel;

      if (debug) std::cout << "Create histogram and function for fitting " << std::endl;

      double xmax = 10;
      int nevts = 1.E6;
      double sigFrac = 0.3;

      h1 = new TH1D("h1", "h1", nbins, 0, xmax);

      // create the gaussians
      double dmu = xmax / double(ng + 1);

      std::vector<double> mu(ng);
      std::vector<double> sig(ng);
      std::vector<double> a(ng);

      for (int i = 0; i < ng; ++i) {
         mu[i] = dmu * (i + 1);
         sig[i] = dmu / 5;
         a[i] = sigFrac * (nevts / ng) * h1->GetBinWidth(1);
      }

      // generate events
      TRandom3 rng(seed);  // use same seed to be reproducible
      auto fpol = new TF1("fpol", "pol2", 0, 10);
      std::vector<double> p0{1.0, 1.0, -0.1};
      fpol->SetParameters(p0.data());
      h1->FillRandom("fpol", (1. - sigFrac) * nevts, &rng);

      for (int i = 0; i < sigFrac * nevts / ng; ++i) {
         for (int j = 0; j < ng; ++j)
            h1->Fill(rng.Gaus(mu[j], sig[j]));
      }


      // build now the Gaussian functions
      TF1 *fbkg = new TF1("fbkg", "[0]+[1]*x+[2]*x*x", 0, 10);

      // now the gaussians
      std::vector<TF1 *> fgaus(ng);
      TString funcFormula = fbkg->GetName();
      for (int i = 0; i < ng; i++) {
         //      fgaus[i] = new TF1(TString::Format("fgaus%d",i),
         //      TString::Format("[A%i]*ROOT::Math::normal_pdf(x,[sig%d],[mu%d])",i,i,i), 0, 10);
         fgaus[i] = new TF1(TString::Format("fgaus%d", i), "gausn", 0, 10);
         fgaus[i]->SetParName(0, TString::Format("A%d", i));
         fgaus[i]->SetParName(1, TString::Format("mu%d", i));
         fgaus[i]->SetParName(2, TString::Format("sig%d", i));
         funcFormula += TString::Format("+%s", fgaus[i]->GetName());
      }
      //std::cout << funcFormula << std::endl;

      fitFunc = new TF1("fitFunc", funcFormula, 0, 10);

      double *p = fpol->GetParameters();
      double polInteg = xmax * fpol->GetParameter(0) + 0.5 * xmax * xmax * fpol->GetParameter(1) +
                        1. / 3 * std::pow(xmax, 3) * fpol->GetParameter(2);
      double scaleFact = (1. - sigFrac) * nevts * h1->GetBinWidth(1) / polInteg;
      fitFunc->SetParameter("p0", p[0] * scaleFact);
      fitFunc->SetParameter("p1", p[1] * scaleFact);
      fitFunc->SetParameter("p2", p[2] * scaleFact);

      // step sizes for polynomials
      stepSizes = std::vector<double>(fitFunc->GetNpar());
      for (int i = 0; i <3; ++i)
        stepSizes[i] = 0.01*std::abs(fitFunc->GetParameter(i));

      // set gaussians parameters
      for (int i = 0; i < ng; ++i) {
         fitFunc->SetParameter(TString::Format("A%d", i), a[i]);
         fitFunc->SetParameter(TString::Format("mu%d", i), mu[i]);
         fitFunc->SetParameter(TString::Format("sig%d", i), sig[i]);
         stepSizes[3 + 3*i] = 0.01*std::abs(a[i]);
         stepSizes[3 + 3*i + 1] = h1->GetBinWidth(1);
         stepSizes[3 + 3*i + 2] = 0.1*h1->GetBinWidth(1);
      }

      if (debug>1)
         fitFunc->Print("V");

      // fitFunc->Draw();
      if (debug>1)
         fitFunc->SetNpx(5 * nbins);

      if (useCLAD)
         fitFunc->GetFormula()->GenerateGradientPar();

      initParams = std::vector<double>(fitFunc->GetParameters(), fitFunc->GetParameters() + fitFunc->GetNpar());

      // avoid computing Hessian at end of minimization
      // Support for second derivatives using Clad is not there yet
      ROOT::Math::MinimizerOptions::SetDefaultStrategy(0);
      // try using Minuit whenever possible
      ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2");
   }

   bool Fit()
   {
      TString fitOpt = "S  0 ";
      if (debug<2)
         fitOpt += TString(" Q ");
      else
         fitOpt += TString(" V ");
      if (useCLAD)
         fitOpt += TString(" G");
      // need to set initial parameters and step size to make all fits equivalent
      // when using AD is quite important having good step sizes for having a good MnSeed
      fitFunc->SetParameters(initParams.data());
      std::vector<double> emptyStepSizes(fitFunc->GetNpar());
      // need to set step size to have fits
      fitFunc->SetParErrors(emptyStepSizes.data());
      TString type = (useCLAD) ? "Clad" : "numerical";

      TStopwatch w;
      if (debug)  w.Start();
      auto res = h1->Fit(fitFunc, fitOpt);

    if (debug) {
      std::cout << "Using " << type << " differentiations : ncalls " << res->NCalls() << " elapsed time : ";
      w.Print();
    }


    if (debug>1)
         res->Print();

      bool ok = (res->Status() == 0);
      if (!ok)
         Error("ManyGausFit", "Error fitting with many gaussians, return status is %d", res->Status());

      return ok;
   }

   ~ManyGausFit()
   {
      delete fitFunc;
      delete h1;
   }
};

int printLevel = 0;
// nbins should be at least > 10 * max(ngaussians) or the fits will start failing
unsigned nbins = 2000;   // 5000 is ok of max gaussian is 64

static void BM_TFormula_ManyGausFit_Clad(benchmark::State &state)
{
   unsigned ngaussians = state.range(0);
   ManyGausFit test(ngaussians, nbins, true,  printLevel);
   for (auto _ : state) {
      test.Fit();
   }
}
// iterate ngaussian from 2 to 64 : 2, 4, 8, ....,64
BENCHMARK(BM_TFormula_ManyGausFit_Clad)->Unit(benchmark::kMillisecond)->RangeMultiplier(2)->Range(2, 64);

static void BM_TFormula_ManyGausFit_Numerical(benchmark::State &state)
{
   unsigned ngaussians = state.range(0);
   ManyGausFit test(ngaussians, nbins, false, printLevel);
   for (auto _ : state) {
      test.Fit();
   }
}

BENCHMARK(BM_TFormula_ManyGausFit_Numerical)->Unit(benchmark::kMillisecond)->RangeMultiplier(2)->Range(2, 64);

// Define our main.
//BENCHMARK_MAIN();

// define main to pass some conveninent command line parameters
int main(int argc, char **argv) {

   // Parse command line arguments
   for (Int_t i = 1; i < argc; i++) {
      std::string arg = argv[i];
      if (arg == "-v") {
         std::cout << "---running in verbose mode" << std::endl;
         printLevel = 1;
      } else if (arg == "-vv") {
        std::cout << "---running in very verbose mode" << std::endl;
        printLevel = 2;
      }
   }


  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();

}
