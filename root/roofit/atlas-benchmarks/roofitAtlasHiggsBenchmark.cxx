#include <RooCategory.h>
#include <RooWorkspace.h>
#include <RooRealVar.h>
#include <RooRandom.h>
#include <RooSimultaneous.h>
#include <RooUniform.h>
#include <RooMinimizer.h>
#include <RooStats/ModelConfig.h>

#include <TFile.h>
#include <TRandom.h>
#include <TError.h>

#include <benchmark/benchmark.h>

using namespace RooFit;
using namespace benchmark;

void kickValues(RooArgSet const &vars, bool kickAll = true)
{
   auto random = RooRandom::randomGenerator();
   auto kick = [&](RooRealVar &var) {
      double val = var.getVal();
      var.setVal(val + (random->Uniform() - 0.5) * 0.01 * val);
   };
   if (kickAll) {
      for (auto *var : static_range_cast<RooRealVar *>(vars)) {
         kick(*var);
      }
   } else {
      kick(*static_cast<RooRealVar *>(vars[random->Integer(vars.size())]));
   }
}

struct BenchmarkData {

   std::unique_ptr<TFile> tfile;
   RooWorkspace *ws = nullptr;
   RooAbsPdf *pdf = nullptr;
   std::unique_ptr<RooAbsPdf> ownedPdf;
   RooAbsData *data = nullptr;
   std::unique_ptr<RooAbsReal> nll;
   std::unique_ptr<RooAbsReal> batchedNll;
   std::unique_ptr<RooAbsReal> codegenNll;
};

BenchmarkData &bmdata()
{
   static BenchmarkData data;
   return data;
}

static void benchCreateNLL(benchmark::State &state)
{
   const std::string evalBackend = state.range(0) == 2 ? "codegen" : (state.range(0) == 1 ? "cpu" : "legacy");
   auto &nllPtr =
      state.range(0) == 2 ? bmdata().codegenNll : (state.range(0) == 1 ? bmdata().batchedNll : bmdata().nll);

   auto mc = static_cast<RooStats::ModelConfig *>(bmdata().ws->obj("ModelConfig"));
   RooArgSet const *globObs = mc->GetGlobalObservables();
   bmdata().data = bmdata().ws->data("toyData");

   for (auto _ : state) {
      nllPtr = std::unique_ptr<RooAbsReal>{bmdata().pdf->createNLL(
         *bmdata().data, GlobalObservables(*globObs), Offset(true), Optimize(2), EvalBackend(evalBackend))};
   }

   double val = nllPtr->getVal();

   std::cout.precision(17);
   std::cout << "Initial value: " << std::fixed << val << std::endl;
}

static void benchEvaluateNLL(benchmark::State &state)
{
   bool kickAllParameters = state.range(0);
   auto &nllPtr =
      state.range(1) == 2 ? bmdata().codegenNll : (state.range(1) == 1 ? bmdata().batchedNll : bmdata().nll);

   RooArgSet parameters;
   nllPtr->getParameters(nullptr, parameters);
   RooArgSet initialParams;
   parameters.snapshot(initialParams);

   RooRandom::randomGenerator()->SetSeed(999);

   nllPtr->getVal();

   for (auto _ : state) {
      kickValues(parameters, kickAllParameters);
      nllPtr->getVal();
   }

   parameters.assign(initialParams);
}

static void benchMinimizeNLL(benchmark::State &state)
{
   auto &nllPtr =
      state.range(0) == 2 ? bmdata().codegenNll : (state.range(0) == 1 ? bmdata().batchedNll : bmdata().nll);

   RooArgSet parameters;
   nllPtr->getParameters(nullptr, parameters);
   RooArgSet initialParams;
   parameters.snapshot(initialParams);

   nllPtr->getVal();
   RooMinimizer minim{*nllPtr};
   minim.setStrategy(0);

   for (auto _ : state) {
      minim.minimize("Minuit2", "MIGRAD");
   }

   parameters.assign(initialParams);
}

// BENCHMARK(benchCreateNLL)->Name("createNLL")->Args({0})->Unit(kSecond)->Iterations(1);
// BENCHMARK(benchCreateNLL)->Name("createNLL_CPU")->Args({1})->Unit(kSecond)->Iterations(1);
BENCHMARK(benchCreateNLL)->Name("createNLL_CodeGenAD")->Args({2})->Unit(kSecond)->Iterations(1);
// BENCHMARK(benchEvaluateNLL)->Name("evaluateNLL")->Args({1, 0})->Unit(kMillisecond);
// BENCHMARK(benchEvaluateNLL)->Name("evaluateNLL_CPU")->Args({1, 1})->Unit(kMillisecond);
// BENCHMARK(benchEvaluateNLL)->Name("evaluateNLL_CodeGenAD")->Args({1, 2})->Unit(kMillisecond);
// BENCHMARK(benchEvaluateNLL)->Name("evaluateNLL_SingleKick")->Args({0, 0})->Unit(kMillisecond);
// BENCHMARK(benchEvaluateNLL)->Name("evaluateNLL_CPU_SingleKick")->Args({0, 1})->Unit(kMillisecond);
// BENCHMARK(benchEvaluateNLL)->Name("evaluateNLL_CodeGenAD_SingleKick")->Args({0, 2})->Unit(kMillisecond);
// BENCHMARK(benchMinimizeNLL)->Name("minimizeNLL")->Args({0})->Unit(kSecond)->Iterations(1);
// BENCHMARK(benchMinimizeNLL)->Name("minimizeNLL_CPU")->Args({1})->Unit(kSecond)->Iterations(1);
BENCHMARK(benchMinimizeNLL)->Name("minimizeNLL_CodeGenAD")->Args({2})->Unit(kSecond)->Iterations(1);

// The channels 221 to 231 inclusive of the full combination workspace are
// unfortunately corrupt. They contain RooAddPdfs that are affected by the
// notorious server-proxy-desyncing that can happen if the RooFit frameworks do
// the wrong thing. Th new the EvalBackend uses the client-server links to build
// the computation graph for evaluation, and the old RooFit uses the proxies
// (the client-server links are only used to the dirty flag propagation in the
// old RooFit). As the servers and proxies are out of sync in some channels, we
// have no idea what is actually correct and hence these channels are
// unsuitable for validation and benchmarking. They are replaced here by
// uniform pdfs.
void maskBrokenChannels()
{
   auto ws = bmdata().ws;
   auto *simPdf = static_cast<RooSimultaneous *>(bmdata().pdf);

   bmdata().ownedPdf = std::make_unique<RooSimultaneous>("fixedSimPdf", "fixedSimPdf",
                                                         const_cast<RooAbsCategoryLValue &>(simPdf->indexCat()));
   bmdata().pdf = bmdata().ownedPdf.get();
   RooSimultaneous *fixedSimPdf = static_cast<RooSimultaneous *>(bmdata().pdf);
   RooArgSet observables{*ws->data("toyData")->get()};

   std::size_t iChannel = 0;
   for (auto const &item : simPdf->indexCat()) {
      if (!(iChannel > 220 && iChannel < 231)) {
         fixedSimPdf->addPdf(*simPdf->getPdf(item.first.c_str()), item.first.c_str());
      } else {
         const std::string name = item.first + "_uniform";
         auto uniform = std::make_unique<RooUniform>(name.c_str(), name.c_str(), observables);
         fixedSimPdf->addPdf(*uniform, item.first.c_str());
         fixedSimPdf->addOwnedComponents(std::move(uniform));
      }
      ++iChannel;
   }
}

RooAbsPdf *createSimPdfSubset(RooWorkspace &ws, std::string newPdfName, int begin, int end)
{
   std::stringstream ss;
   ss << "SIMUL::" << newPdfName << "( channelCat, ";
   std::vector<std::string> channelNames;
   for (auto state : *ws.cat("channelCat")) {
      channelNames.push_back(state.first);
   }
   for (std::size_t iChannel = begin; iChannel < end; ++iChannel) {
      ss << channelNames[iChannel] << "=" << channelNames[iChannel] << "_model";
      if (iChannel == end - 1) {
         ss << ")";
      } else {
         ss << ",";
      }
   }
   ws.factory(ss.str());

   return ws.pdf(newPdfName);
}

int main(int argc, char **argv)
{
   std::size_t iWorkspace = 1;

   // Parse command line arguments
   for (Int_t i = 1; i < argc; i++) {
      std::string arg = argv[i];
      iWorkspace = std::stoi(arg);
   }

   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);

   std::vector<std::string> workspaceFiles{
      "WS-VHbb-STXS_mu_toy.root", "WS-VHbb-STXS_mu_toy_new.root",   "WS-Comb-STXS_toy.root",
      "WS-HGam-STXS_xs_toy.root", "WS-boostedHbb-glob_xs_toy.root",
   };

   std::vector<std::string> workspaceNames{
      "combined", "combined", "combWS", "combWS", "combWS",
   };

   bmdata().tfile = std::unique_ptr<TFile>{TFile::Open(workspaceFiles[iWorkspace].c_str())};
   bmdata().ws = bmdata().tfile->Get<RooWorkspace>(workspaceNames[iWorkspace].c_str());
   auto mc = static_cast<RooStats::ModelConfig *>(bmdata().ws->obj("ModelConfig"));

   bmdata().pdf = mc->GetPdf();
   // Use this instead to create a new simultaneous pdf that only includes a
   // subset of the channels:
   // bmdata().pdf = createSimPdfSubset(*bmdata().ws, "simPdfSubset", 0, 5);

   // Mask broken channels of the full Higgs combination workspace.
   if (iWorkspace == 2) {
      maskBrokenChannels();
   }

   benchmark::Initialize(&argc, argv);
   benchmark::RunSpecifiedBenchmarks();

   // If there is any owned pdf, it has to be deleted before the workspace goes
   // out of scope. Otherwise, it would have dangling pointers.
   bmdata().ownedPdf.reset();
}
