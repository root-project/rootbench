#include "RooWorkspace.h"
#include "RooAddPdf.h"
#include "RooRealVar.h"
#include "RooMinimizer.h"
#include "TFile.h"
#include "TH1.h"
#include "TError.h"
#include "RooStats/HistFactory/Measurement.h"
#include "RooStats/HistFactory/HistoToWorkspaceFactoryFast.h"
#include "RooStats/ModelConfig.h"

#include "benchmark/benchmark.h"

using namespace RooFit;
using namespace RooStats;
using namespace HistFactory;

void buildBinnedTest()
{
   Measurement meas("meas","meas");
   meas.SetPOI( "SignalStrength" );
   meas.SetLumi( 1.0 );
   meas.SetLumiRelErr( 0.10 );
   meas.AddConstantParam("Lumi");
   Channel chan( "Region0" );
   auto Signal_Hist = new TH1F("Signal","Signal",100,0,100);
   auto Background_Hist = new TH1F("Background","Background",100,0,100);
   auto Data_Hist = new TH1F("Data","Data",100,0,100);
   int nbins = Signal_Hist->GetXaxis()->GetNbins();
   for (int bin = 1; bin <= nbins; ++bin ){
      for (int i = 0; i <= bin; ++i ){
         Signal_Hist->Fill(bin + 0.5);
         Data_Hist->Fill(bin + 0.5);
      }
     for (int i = 0; i <= 100; ++i ){
        Background_Hist->Fill(bin + 0.5);
        Data_Hist->Fill(bin + 0.5);
       }
   }
   chan.SetData( Data_Hist );
   Sample background("background");
   background.SetNormalizeByTheory(false);
   background.SetHisto( Background_Hist );
   Sample signal("signal");
   signal.SetNormalizeByTheory(false);
   signal.SetHisto(Signal_Hist);
   signal.AddNormFactor("SignalStrength",1,0,3);
   chan.AddSample(background);
   chan.AddSample(signal);
   meas.AddChannel(chan);
   HistoToWorkspaceFactoryFast hist2workspace(meas);
   RooWorkspace *ws = hist2workspace.MakeSingleChannelModel(meas, chan);
   ws->SetName("BinnedWorkspace");
   ws->writeToFile("workspace.root");
}

static void BM_RooFit_BinnedTestMigrad(benchmark::State &state)
{  
   RooMsgService::instance().setGlobalKillBelow(RooFit::INFO);
   gErrorIgnoreLevel = kWarning;
   int cpu = state.range(0);
   TFile *infile = TFile::Open("workspace.root");
   if(!infile->IsOpen()){
     buildBinnedTest();
     std::cout << "Workspace for tests was created!" << std::endl;
     infile->TFile::Open("workspace.root");
   }
   RooWorkspace *w = static_cast<RooWorkspace*>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig*>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(cpu,0));
   RooMinimizer m(*nll);
   m.setStrategy(0);
   m.setProfile(1);
   while (state.KeepRunning()){
      m.migrad();
   }
}

BENCHMARK(BM_RooFit_BinnedTestMigrad)->Unit(benchmark::kMicrosecond)->Arg(2);
//BENCHMARK(BM_RooFit_BinnedTestMigrad)->Unit(benchmark::kMicrosecond)->Arg(2)->UseRealTime()->ThreadPerCpu();
//BENCHMARK(BM_RooFit_BinnedTestMigrad)->Unit(benchmark::kMicrosecond)->Range(1, 5)->UseRealTime()->ThreadRange(1, 256);
//BENCHMARK(BM_RooFit_BinnedTestMigrad)->Unit(benchmark::kMicrosecond)->Ranges({{32, 128}, {1, 5}})->UseRealTime()->ThreadRange(1, 256);

static void BM_RooFit_BinnedTestHesse(benchmark::State &state)
{  
   RooMsgService::instance().setGlobalKillBelow(RooFit::INFO);
   gErrorIgnoreLevel = kWarning;
   TFile *infile = TFile::Open("workspace.root");
   if(!infile->IsOpen()){
      buildBinnedTest();
      std::cout << "Workspace for tests was created!" << std::endl;
      infile->TFile::Open("workspace.root");
   }
   RooWorkspace *w = static_cast<RooWorkspace*>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig*>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(2,0));
   RooMinimizer m(*nll);
   m.setStrategy(0);
   m.setProfile(1);
   m.migrad();
   while (state.KeepRunning())
      m.hesse();
}
BENCHMARK(BM_RooFit_BinnedTestHesse)->Unit(benchmark::kMicrosecond);

static void BM_RooFit_BinnedTestMinos(benchmark::State &state)
{  
   RooMsgService::instance().setGlobalKillBelow(RooFit::INFO);
   gErrorIgnoreLevel = kWarning;
   TFile *infile = TFile::Open("workspace.root");
   if(!infile->IsOpen()){
      buildBinnedTest();
      std::cout << "Workspace for tests was created!" << std::endl;
      infile->TFile::Open("workspace.root");
   }
   RooWorkspace *w = static_cast<RooWorkspace*>(infile->Get("BinnedWorkspace"));
   RooAbsData *data = w->data("obsData");
   ModelConfig *mc = static_cast<ModelConfig*>(w->genobj("ModelConfig"));
   RooAbsPdf *pdf = w->pdf(mc->GetPdf()->GetName());
   RooAbsReal *nll = pdf->createNLL(*data, NumCPU(2,0));
   RooMinimizer m(*nll);
   m.setStrategy(0);
   m.setProfile(1);
   m.migrad();
   while (state.KeepRunning())
      m.minos();
}

BENCHMARK(BM_RooFit_BinnedTestMinos)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
