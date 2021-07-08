#include "RooWorkspace.h"
#include "RooAddPdf.h"
#include "RooRealVar.h"
#include "RooMinimizer.h"
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
} // namespace

Sample addVariations(Sample asample, int nnps, bool channel_crosstalk, int channel)
{
   for (int nuis = 0; nuis < nnps; ++nuis) {
      TRandom *R = new TRandom(channel * nuis / nnps);
      Double_t random = R->Rndm();
      double uncertainty_up = (1 + random) / sqrt(100);
      double uncertainty_down = (1 - random) / sqrt(100);
      if(verbose) {
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

Channel makeChannel(int channel, int nbins, int nnps)
{
   std::string channel_name = "Region" + std::to_string(channel);
   Channel chan(channel_name);
   gDirectory = nullptr;
   auto Signal_Hist = new TH1F("Signal", "Signal", nbins, 0, nbins);
   auto Background_Hist = new TH1F("Background", "Background", nbins, 0, nbins);
   auto Data_Hist = new TH1F("Data", "Data", nbins, 0, nbins);
   for (Int_t bin = 1; bin <= nbins; ++bin) {
      for (Int_t i = 0; i <= bin; ++i) {
         Signal_Hist->Fill(bin + 0.5);
         Data_Hist->Fill(bin + 0.5);
      }
      for (Int_t i = 0; i <= nbins; ++i) {
         Background_Hist->Fill(bin + 0.5);
         Data_Hist->Fill(bin + 0.5);
      }
   }
   chan.SetData(Data_Hist);
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
   chan.AddSample(background);
   chan.AddSample(signal);
   return chan;
}

void buildBinnedTest(int n_channels = 1, int nbins = 10, int nnps = 1, const char *name_rootfile = "")
{
   if(verbose) {
     std::cout << "in build binned test with output" << name_rootfile << std::endl;
   }
   Measurement meas("meas", "meas");
   meas.SetPOI("SignalStrength");
   meas.SetLumi(1.0);
   meas.SetLumiRelErr(0.10);
   meas.AddConstantParam("Lumi");
   Channel chan;
   for (int channel = 0; channel < n_channels; ++channel) {
      chan = makeChannel(channel, nbins, nnps);
      meas.AddChannel(chan);
   }
   HistoToWorkspaceFactoryFast hist2workspace(meas);
   RooWorkspace *ws;
   if (n_channels < 2) {
      ws = hist2workspace.MakeSingleChannelModel(meas, chan);
   } else {
      ws = hist2workspace.MakeCombinedModel(meas);
   }
   RooFIter iter = ws->components().fwdIterator();
   RooAbsArg *arg;
   while ((arg = iter.next())) {
      if (arg->IsA() == RooRealSumPdf::Class()) {
         arg->setAttribute("BinnedLikelihood");
         if(verbose) std::cout << "component " << arg->GetName() << " is a binned likelihood" << std::endl;
      }
   }
   ws->SetName("BinnedWorkspace");
   ws->writeToFile(name_rootfile);
}

//############## End of Base Algorithms ##############################
//####################################################################
//############## Start Of #Channel tests #############################

static void BM_RooFit_BinnedTestMigrad_NChannel(benchmark::State &state)
{
   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);
   int chan = state.range(0);
   int cpu = state.range(1);
   TFile *infile = new TFile("workspace.root", "RECREATE");
   //   if (infile->IsZombie()) {
   buildBinnedTest(chan, 10, 2, "workspace.root");
   if(verbose) std::cout << "Workspace for tests was created!" << std::endl;
   //}
   infile = TFile::Open("workspace.root");
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig *>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(cpu, 0));
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(0);
   m.setLogFile("benchmigradnchannellog");
   for (auto _ : state) {
      m.migrad();
   }
   delete data;
   delete infile;
   delete mc;
   delete pdf;
   delete nll;
}

static void BM_RooFit_BinnedTestHesse_NChannel(benchmark::State &state)
{

   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);
   int chan = state.range(0);
   int cpu = state.range(1);
   TFile *infile = new TFile("workspace.root");
   //   if (infile->IsZombie()) {
   buildBinnedTest(chan, 10, 2, "workspace.root");
   if(verbose) std::cout << "Workspace for tests was created!" << std::endl;
   //   }
   infile = TFile::Open("workspace.root");
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig *>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(cpu, 0));
   RooArgSet *params = (RooArgSet *)pdf->getParameters(data);
   w->saveSnapshot("no_fit", *params, kTRUE);
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(0);
   m.setLogFile("benchhessenchannellog");
   m.migrad();
   w->loadSnapshot("no_fit");
   for (auto _ : state) {
      m.hesse();
   }
   delete data;
   delete infile;
   delete mc;
   delete pdf;
   delete nll;
}

static void BM_RooFit_BinnedTestMinos_NChannel(benchmark::State &state)
{

   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);
   int chan = state.range(0);
   int cpu = state.range(1);
   TFile *infile = new TFile("workspace.root");
   //   if (infile->IsZombie()) {
   buildBinnedTest(chan, 10, 2, "workspace.root");
   if(verbose) std::cout << "Workspace for tests was created!" << std::endl;
   //}
   infile = TFile::Open("workspace.root");
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig *>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(cpu, 0));
   RooArgSet *params = (RooArgSet *)pdf->getParameters(data);
   w->saveSnapshot("no_fit", *params, kTRUE);
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(0);
   m.setLogFile("benchhessenchannellog");
   m.migrad();
   m.hesse();
   w->loadSnapshot("no_fit");
   for (auto _ : state) {
      m.minos();
   }
   delete data;
   delete infile;
   delete mc;
   delete pdf;
   delete nll;
}

//############## Run # Channel Tests ###############################

static void ChanArguments(benchmark::internal::Benchmark *b)
{
   for (int i = 1; i <= 4; ++i)
      for (int j = 1; j <= 3; ++j)
         b->Args({i, j});
}

BENCHMARK(BM_RooFit_BinnedTestMigrad_NChannel)
   ->Apply(ChanArguments)
   ->UseRealTime()
   ->Unit(benchmark::kMicrosecond)
   ->Iterations(1);
BENCHMARK(BM_RooFit_BinnedTestHesse_NChannel)
   ->Apply(ChanArguments)
   ->UseRealTime()
   ->Unit(benchmark::kMicrosecond)
   ->Iterations(1);
BENCHMARK(BM_RooFit_BinnedTestMinos_NChannel)
   ->Apply(ChanArguments)
   ->UseRealTime()
   ->Unit(benchmark::kMicrosecond)
   ->Iterations(1);

//############## End Of #ChannelTtests ###############################
//####################################################################
//############## Start Of #Bin Tests #################################

static void BM_RooFit_BinnedTestMigrad_NBin(benchmark::State &state)
{
   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);
   int bin = state.range(0);
   int cpu = state.range(1);
   TFile *infile = new TFile("workspace.root", "RECREATE");
   //   if (infile->IsZombie()) {
   buildBinnedTest(1, bin, 2, "workspace.root");
   if(verbose) std::cout << "Workspace for tests was created!" << std::endl;
   //}
   infile = TFile::Open("workspace.root");
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig *>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(cpu, 0));
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(0);
   m.setLogFile("benchmigradnbinlog");
   for (auto _ : state) {
      m.migrad();
   }
   delete data;
   delete infile;
   delete mc;
   delete pdf;
   delete nll;
}

static void BM_RooFit_BinnedTestHesse_NBin(benchmark::State &state)
{
   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);
   int bin = state.range(0);
   int cpu = state.range(1);
   TFile *infile = new TFile("workspace.root");
   //   if (infile->IsZombie()) {
   buildBinnedTest(1, bin, 2, "workspace.root");
   if(verbose) std::cout << "Workspace for tests was created!" << std::endl;
   //}
   infile = TFile::Open("workspace.root");
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig *>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(cpu, 0));
   RooArgSet *params = (RooArgSet *)pdf->getParameters(data);
   w->saveSnapshot("no_fit", *params, kTRUE);
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(0);
   m.setLogFile("benchhessenbinlog");
   m.migrad();
   w->loadSnapshot("no_fit");
   for (auto _ : state) {
      m.hesse();
   }
   delete data;
   delete infile;
   delete mc;
   delete pdf;
   delete nll;
}

static void BM_RooFit_BinnedTestMinos_NBin(benchmark::State &state)
{

   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);
   int bin = state.range(0);
   int cpu = state.range(1);
   TFile *infile = new TFile("workspace.root");
   //   if (infile->IsZombie()) {
   buildBinnedTest(1, bin, 2, "workspace.root");
   if(verbose) std::cout << "Workspace for tests was created!" << std::endl;
   //   }
   infile = TFile::Open("workspace.root");
   RooWorkspace *w = static_cast<RooWorkspace *>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig *>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(cpu, 0));
   RooArgSet *params = (RooArgSet *)pdf->getParameters(data);
   w->saveSnapshot("no_fit", *params, kTRUE);
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setProfile(0);
   m.setLogFile("benchhessenbinlog");
   m.migrad();
   m.hesse();
   w->loadSnapshot("no_fit");
   for (auto _ : state) {
      m.minos();
   }
   delete data;
   delete infile;
   delete mc;
   delete pdf;
   delete nll;
}

//############## Run # Bin Tests ####################################

static void BinArguments(benchmark::internal::Benchmark *b)
{
   for (int i = 1; i <= 4; ++i) {
      for (int j = 1; j <= 3; ++j) {
         b->Args({i * 5, j});
      }
   }
}

BENCHMARK(BM_RooFit_BinnedTestMigrad_NBin)
   ->Apply(BinArguments)
   ->UseRealTime()
   ->Unit(benchmark::kMicrosecond)
   ->Iterations(1);
BENCHMARK(BM_RooFit_BinnedTestHesse_NBin)
   ->Apply(BinArguments)
   ->UseRealTime()
   ->Unit(benchmark::kMicrosecond)
   ->Iterations(1);
BENCHMARK(BM_RooFit_BinnedTestMinos_NBin)
   ->Apply(BinArguments)
   ->UseRealTime()
   ->Unit(benchmark::kMicrosecond)
   ->Iterations(1);

//############## End Of Tests ########################################
//####################################################################
//############## RUN #################################################

BENCHMARK_MAIN();
