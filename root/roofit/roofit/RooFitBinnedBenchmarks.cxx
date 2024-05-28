#include "RooWorkspace.h"
#include "RooAddPdf.h"
#include "RooRealVar.h"
#include "RooMinimizer.h"
#include "RooFuncWrapper.h"
#include "TFile.h"
#include "TH1.h"
#include "TRandom.h"
#include "TError.h"
#include "RooStats/HistFactory/Measurement.h"
#include "RooStats/HistFactory/HistoToWorkspaceFactoryFast.h"
#include "RooStats/ModelConfig.h"
#include "RooLinkedListIter.h"
#include "RooRealSumPdf.h"

#include "benchmark/benchmark.h"

using namespace RooFit;
using namespace RooStats;
using namespace HistFactory;

namespace {
constexpr bool verbose = false;

// test matrix configuration
//const std::vector<int> nChannelsVector = {1, 2, 3};
const std::vector<int> nChannelsVector = {2};
const std::vector<int> nBinsVector{5, 10, 15};
const int nBinsForChannelScan = 2;
const int nChannelsForBinScan = 1;
const std::vector<int> nCPUVector{1};

////default evaluation backend
std::string evalBackend = "cpu";

//default value for seeding step:
bool seeding_only = false;

auto const timeUnit = benchmark::kMillisecond;

void setupRooMsgService()
{
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);
}

TRandom *tRandom = nullptr;

} // namespace

Sample addVariations(Sample asample, int nnps, bool channel_crosstalk, int channel)
{
   for (int nuis = 0; nuis < nnps; ++nuis) {
      TRandom *R = new TRandom(channel * nuis / nnps);
      Double_t random = R->Rndm();
      double uncertainty_up = (1 + random) / sqrt(100);
      double uncertainty_down = (1 - random) / sqrt(100);
      if (verbose) {
         std::cout << "in channel " << channel << "nuisance +/- [" << uncertainty_up << "," << uncertainty_down << "]"
                   << std::endl;
      }
      std::string nuis_name = "norm_uncertainty_" + std::to_string(nuis);
      if (!channel_crosstalk) {
         nuis_name = nuis_name + "_channel_" + std::to_string(channel);
      }
      asample.AddOverallSys(nuis_name, uncertainty_up, uncertainty_down);
   }
   return asample;
}

std::unique_ptr<RooStats::HistFactory::Channel> makeChannel(int channel, int nbins, int nnps)
{
   std::string channel_name = "Region" + std::to_string(channel);
   auto chan = std::make_unique<RooStats::HistFactory::Channel>(channel_name);
   gDirectory = nullptr;
   auto Signal_Hist = new TH1F("Signal", "Signal", nbins, 0, nbins);
   auto Background_Hist = new TH1F("Background", "Background", nbins, 0, nbins);
   auto Data_Hist = new TH1F("Data", "Data", nbins, 0, nbins);
   //for (Int_t bin = 1; bin <= nbins; ++bin) {
      //for (Int_t i = 0; i <= bin; ++i) {
         //Signal_Hist->Fill(bin + 0.5);
         //Data_Hist->Fill(bin + 0.5);
      //}
      //for (Int_t i = 0; i <= nbins; ++i) {
         //Background_Hist->Fill(bin + 0.5);
         //Data_Hist->Fill(bin + 0.5);
      //}
   //}
   for (Int_t bin = 1; bin <= nbins; ++bin) {
      for (Int_t i = 1; i < bin; ++i) {
         double randomSig = tRandom->Rndm();
         Signal_Hist->SetBinContent(i, 10 * randomSig);
         double randomBkg = tRandom->Rndm();
         Background_Hist->SetBinContent(i, 100 * randomBkg);
         Data_Hist->SetBinContent(i, tRandom->Poisson(10 * randomSig + 100 * randomBkg));
      }
   }

   chan->SetData(Data_Hist);
   Sample background("background");
   background.SetNormalizeByTheory(false);
   background.SetHisto(Background_Hist);
   background.ActivateStatError();
   Sample signal("signal");
   signal.SetNormalizeByTheory(false);
   signal.SetHisto(Signal_Hist);
   signal.ActivateStatError();
   signal.AddNormFactor("SignalStrength", 1, 0, 3);

   if (nnps > 0) {
      signal = addVariations(signal, nnps, true, channel);
      background = addVariations(background, nnps, false, channel);
   }
   chan->AddSample(background);
   chan->AddSample(signal);
   return chan;
}

void buildBinnedTest(int n_channels = 1, int nbins = 10, int nnps = 1, const char *name_rootfile = "")
{
   if (verbose) {
      std::cout << "in build binned test with output" << name_rootfile << std::endl;
   }
   Measurement meas("meas", "meas");
   meas.SetPOI("SignalStrength");
   meas.SetLumi(1.0);
   meas.SetLumiRelErr(0.10);
   meas.AddConstantParam("Lumi");
   std::unique_ptr<RooStats::HistFactory::Channel> chan;
   for (int channel = 0; channel < n_channels; ++channel) {
      chan = makeChannel(channel, nbins, nnps);
      meas.AddChannel(*chan);
   }
   HistoToWorkspaceFactoryFast hist2workspace(meas);
   std::unique_ptr<RooWorkspace> ws;
   if (n_channels < 2) {
      ws = std::unique_ptr<RooWorkspace>{hist2workspace.MakeSingleChannelModel(meas, *chan)};
   } else {
      ws = std::unique_ptr<RooWorkspace>{hist2workspace.MakeCombinedModel(meas)};
   }
   for (RooAbsArg *arg : ws->components()) {
      if (arg->IsA() == RooRealSumPdf::Class()) {
         arg->setAttribute("BinnedLikelihood");
         if (verbose)
            std::cout << "component " << arg->GetName() << " is a binned likelihood" << std::endl;
      }
   }
   ws->SetName("BinnedWorkspace");
   ws->writeToFile(name_rootfile);
}

// ############## End of Base Algorithms ##############################
// ####################################################################
// ############## Start Of # Tests #############################

static void BM_RooFit_BinnedTestMigrad(benchmark::State &state)
{
   gErrorIgnoreLevel = kInfo;
   setupRooMsgService();
   int chan = state.range(0);
   int nbins = state.range(1);
   int cpu = state.range(2);
   auto infile = std::make_unique<TFile>("workspace.root", "RECREATE");
   //   if (infile->IsZombie()) {
   buildBinnedTest(chan, nbins, 2, "workspace.root");
   if (verbose)
      std::cout << "Workspace for tests was created!" << std::endl;
   //}
   infile.reset(TFile::Open("workspace.root"));
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   std::unique_ptr<RooAbsData> data{w->data("obsData")};
   std::unique_ptr<ModelConfig> mc{static_cast<ModelConfig *>(w->genobj("ModelConfig"))};
   std::unique_ptr<RooAbsPdf> pdf{w->pdf(mc->GetPdf()->GetName())};
   std::unique_ptr<RooAbsReal> nll{pdf->createNLL(*data, NumCPU(cpu, 0), EvalBackend(evalBackend))};
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(false);
   m.setLogFile("benchmigradnchannellog");
   for (auto _ : state) {
      m.migrad();
   }
}   

static void BM_RooFit_BinnedTestHesse(benchmark::State &state)
{

   gErrorIgnoreLevel = kInfo;
   setupRooMsgService();
   int chan = state.range(0);
   int nbins = state.range(1);
   int cpu = state.range(2);
   TFile *infile = new TFile("workspace.root");
   //   if (infile->IsZombie()) {
   buildBinnedTest(chan, nbins, 2, "workspace.root");
   if (verbose)
      std::cout << "Workspace for tests was created!" << std::endl;
   //   }
   infile = TFile::Open("workspace.root");
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig *>(w->genobj("ModelConfig"));
   std::unique_ptr<RooAbsPdf> pdf{w->pdf(mc->GetPdf()->GetName())};
   std::unique_ptr<RooAbsReal> nll{pdf->createNLL(*data, NumCPU(cpu, 0), EvalBackend(evalBackend))};
   RooArgSet params;
   pdf->getParameters(data->get(), params);
   w->saveSnapshot("no_fit", params, true);
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(false);
   m.setLogFile("benchhessenchannellog");
   m.migrad();
   w->loadSnapshot("no_fit");
   for (auto _ : state) {
      m.hesse();
   }
   delete data;
   delete infile;
   delete mc;
}

static void BM_RooFit_BinnedTestMinos(benchmark::State &state)
{

   gErrorIgnoreLevel = kInfo;
   setupRooMsgService();
   int chan = state.range(0);
   int nbins = state.range(1);
   int cpu = state.range(2);
   auto infile = std::make_unique<TFile>("workspace.root");
   //   if (infile->IsZombie()) {
   buildBinnedTest(chan, nbins, 2, "workspace.root");
   if (verbose)
      std::cout << "Workspace for tests was created!" << std::endl;
   //}
   infile.reset(TFile::Open("workspace.root"));
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   std::unique_ptr<RooAbsData> data{w->data("obsData")};
   std::unique_ptr<ModelConfig> mc{static_cast<ModelConfig *>(w->genobj("ModelConfig"))};
   std::unique_ptr<RooAbsPdf> pdf{w->pdf(mc->GetPdf()->GetName())};
   std::unique_ptr<RooAbsReal> nll{pdf->createNLL(*data, NumCPU(cpu, 0), EvalBackend(evalBackend))};
   RooArgSet params;
   pdf->getParameters(data->get(), params);
   w->saveSnapshot("no_fit", params, true);
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(false);
   m.setLogFile("benchhessenchannellog");
   m.migrad();
   m.hesse();
   w->loadSnapshot("no_fit");
   for (auto _ : state) {
      m.minos();
   }
}

// ############## Run # Tests ###############################

static void ChanArguments(benchmark::internal::Benchmark *b)
{
   // channel scan
   for (int nChannels : nChannelsVector) {
      for (int nCPU : nCPUVector) {
         b->Args({nChannels, nBinsForChannelScan, nCPU});
      }
   }

   // bin scan
   //for (int nBins : nBinsVector) {
      //for (int nCPU : nCPUVector) {
         //b->Args({nChannelsForBinScan, nBins, nCPU});
      //}
   //}
}

BENCHMARK(BM_RooFit_BinnedTestMigrad)->Apply(ChanArguments)->UseRealTime()->Unit(timeUnit)->Iterations(1);
//BENCHMARK(BM_RooFit_BinnedTestHesse)->Apply(ChanArguments)->UseRealTime()->Unit(timeUnit)->Iterations(1);
//BENCHMARK(BM_RooFit_BinnedTestMinos)->Apply(ChanArguments)->UseRealTime()->Unit(timeUnit)->Iterations(1);

// ############## End Of Tests ########################################
// ####################################################################
// ############## RUN #################################################

int main(int argc, char **argv)
{

   benchmark::Initialize(&argc, argv);

   tRandom = new TRandom(1337);

   for (int i = 1; i < argc; ++i) {
      if (std::string(argv[i]) == "-b") {
         if (i + 1 < argc) {
            // Set the evalBackend value from the next command-line argument
            evalBackend = argv[i + 1];
         }
         if (i + 2 < argc) {
            // Set the evalBackend value from the next command-line argument
            evalBackend = argv[i + 1];
            seeding_only = argv[i + 2];
         }
      }
   }
   benchmark::RunSpecifiedBenchmarks();
}
