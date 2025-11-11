#include <RooAbsData.h>
#include <RooAbsPdf.h>
#include <RooAddPdf.h>
#include <RooAddition.h>
#include <RooCategory.h>
#include <RooChebychev.h>
#include <RooConstVar.h>
#include <RooDataHist.h>
#include <RooDataSet.h>
#include <RooExponential.h>
#include <RooFitResult.h>
#include <RooGaussian.h>
#include <RooMinimizer.h>
#include <RooProduct.h>
#include <RooRandom.h>
#include <RooRealVar.h>
#include <RooSimultaneous.h>

#include <Math/Factory.h>
#include <Math/Minimizer.h>

#include <TMath.h>
#include <TROOT.h>
#include <TSystem.h>

#include "BenchmarkUtils.h"

#include "benchmark/benchmark.h"

#include <limits>
#include <memory>

static int counter = 0;

std::unique_ptr<RooAbsPdf> createModel(RooRealVar &x, std::string const &channelName)
{
   using namespace RooFit;

   auto prefix = [&](const char *name) { return name + std::string("_") + channelName; };

   RooRealVar c(prefix("c").c_str(), "c", -0.5, -0.8, 0.2);

   RooExponential expo(prefix("expo").c_str(), "expo", x, c);

   // Create two Gaussian PDFs g1(x,mean1,sigma) anf g2(x,mean2,sigma) and their parameters
   RooRealVar mean1(prefix("mean1").c_str(), "mean of gaussians", 3, 0, 5);
   RooRealVar sigma1(prefix("sigma1").c_str(), "width of gaussians", 0.8, .01, 3.0);
   RooRealVar mean2(prefix("mean2").c_str(), "mean of gaussians", 6, 5, 10);
   RooRealVar sigma2(prefix("sigma2").c_str(), "width of gaussians", 1.0, .01, 3.0);

   RooGaussian sig1(prefix("sig1").c_str(), "Signal component 1", x, mean1, sigma1);
   RooGaussian sig2(prefix("sig2").c_str(), "Signal component 2", x, mean2, sigma2);

   // Sum the signal components
   RooRealVar sig1frac(prefix("sig1frac").c_str(), "fraction of signal 1", 0.5, 0.0, 1.0);
   RooAddPdf sig(prefix("sig").c_str(), "g1+g2", {sig1, sig2}, {sig1frac});

   // Sum the composite signal and background
   RooRealVar sigfrac(prefix("sigfrac").c_str(), "fraction of signal", 0.4, 0.0, 1.0);
   RooAddPdf model(prefix("model").c_str(), "g1+g2+a", {sig, expo}, {sigfrac});

   return std::unique_ptr<RooAbsPdf>{static_cast<RooAbsPdf *>(model.cloneTree())};
}

enum backend {
   Reference,
   BatchMode,
   CodeSquashNumDiff,
   CodeSquashAD
};

static void BM_RooFuncWrapper_ManyParams_Minimization(benchmark::State &state)
{
   using namespace RooFit;

   counter++;

   // gInterpreter->ProcessLine("gErrorIgnoreLevel = 2001;");
   // auto &msg = RooMsgService::instance();
   // msg.setGlobalKillBelow(RooFit::WARNING);

   // Generate the same dataset for all backends.
   RooRandom::randomGenerator()->SetSeed(100);

   std::size_t nEvents = 1000;

   RooCategory channelCat{"channel_cat", ""};

   std::map<std::string, RooAbsPdf *> pdfMap;
   std::map<std::string, std::unique_ptr<RooAbsData>> dataMap;

   RooArgSet observables;
   RooArgSet models;

   auto nChannels = state.range(1);

   for (int iChannel = 0; iChannel < nChannels; ++iChannel) {
      std::string suffix = "_" + std::to_string(iChannel + 1);
      auto obsName = "x" + suffix;
      auto x = std::make_unique<RooRealVar>(obsName.c_str(), obsName.c_str(), 0, 10.);
      x->setBins(20);

      std::unique_ptr<RooAbsPdf> model{createModel(*x, std::to_string(iChannel + 1))};

      pdfMap.insert({"channel" + suffix, model.get()});
      channelCat.defineType("channel" + suffix, iChannel);
      dataMap.insert({"channel" + suffix, std::unique_ptr<RooAbsData>{model->generateBinned(*x, nEvents)}});

      observables.addOwned(std::move(x));
      models.addOwned(std::move(model));
   }

   RooSimultaneous model{"model", "model", pdfMap, channelCat};

   // Generate the same dataset for all backends.
   RooDataSet data{"data", "data", {observables, channelCat}, Index(channelCat), Import(dataMap)};

   // Save the original parameter values and errors to reset after minimization
   RooArgSet params;
   model.getParameters(&observables, params);

   RooFitADBenchmarksUtils::randomizeParameters(params);

   RooArgSet origParams;
   params.snapshot(origParams);

   std::cout << "nparams: " << params.size() << std::endl;

   std::unique_ptr<RooAbsReal> nllRef{model.createNLL(data, EvalBackend::Legacy(), Offset("initial"))};
   std::unique_ptr<RooAbsReal> nllRefBatch{model.createNLL(data, EvalBackend::Cpu(), Offset("initial"))};
   std::unique_ptr<RooAbsReal> nllFunc{model.createNLL(data, EvalBackend::Codegen(), Offset("initial"))};
   std::unique_ptr<RooAbsReal> nllFuncNoGrad{model.createNLL(data, EvalBackend::CodegenNoGrad(), Offset("initial"))};

   std::unique_ptr<RooMinimizer> m = nullptr;

   int code = state.range(0);
   if (code == backend::Reference) {
      m = std::make_unique<RooMinimizer>(*nllRef);
   } else if (code == backend::CodeSquashNumDiff) {
      m = std::make_unique<RooMinimizer>(*nllFuncNoGrad);
   } else if (code == backend::BatchMode) {
      m = std::make_unique<RooMinimizer>(*nllRefBatch);
   } else if (code == backend::CodeSquashAD) {
      m = std::make_unique<RooMinimizer>(*nllFunc);
   }

   for (auto _ : state) {
      // m->setPrintLevel(-1);
      m->setStrategy(0);
      params.assign(origParams);

      m->minimize("Minuit2");
   }
}

int main(int argc, char **argv)
{
   std::vector<long int> rangeLow{1, 2, 3, 4, 5, 6, 7, 8, 12, 17, 23, 28, 33, 38, 43, 49, 54, 59};
   std::vector<long int> rangeHigh{64,  70,  75,  80,  85,  90,  96,  100, 110, 120, 130, 140,
                                   150, 160, 170, 180, 190, 200, 225, 250, 275, 300, 325};
   std::vector<long int> range;
   range.insert(range.end(), rangeLow.begin(), rangeLow.end());
   range.insert(range.end(), rangeHigh.begin(), rangeHigh.end());

   // Run the minimization with the reference NLL
   RooFitADBenchmarksUtils::doBenchmarks("NllReferenceMinimization", Reference,
                                         BM_RooFuncWrapper_ManyParams_Minimization, range, 1);

   // Run the minimization with the reference NLL (BatchMode)
   RooFitADBenchmarksUtils::doBenchmarks("NllBatchModeMinimization", BatchMode,
                                         BM_RooFuncWrapper_ManyParams_Minimization, range, 1);

   // Run the minimization with the code-squashed version with AD.
   RooFitADBenchmarksUtils::doBenchmarks("NllCodeSquash_AD", CodeSquashAD, BM_RooFuncWrapper_ManyParams_Minimization,
                                         range, 1);
   // RooFitADBenchmarksUtils::doBenchmarks("NllCodeSquash_AD", CodeSquashAD,
   // BM_RooFuncWrapper_ManyParams_Minimization, {250}, 1);

   // Run the minimization with the code-squashed version with numerical-diff.
   // We can't go to more than 59 channels here, because since offsetting is
   // not supported, the fit will not converge anymore if the number of bins is
   // sufficiently high.
   RooFitADBenchmarksUtils::doBenchmarks("NllCodeSquash_NumDiff", CodeSquashNumDiff,
                                         BM_RooFuncWrapper_ManyParams_Minimization, rangeLow, 1);

   benchmark::Initialize(&argc, argv);
   benchmark::RunSpecifiedBenchmarks();
   benchmark::Shutdown();
}
