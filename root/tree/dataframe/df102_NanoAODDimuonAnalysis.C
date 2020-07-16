// This test is an adaption of the RDataFrame tutorial df102

#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "TCanvas.h"
#include "TH1D.h"
#include "TLatex.h"
#include "Math/Vector4D.h"
#include "TStyle.h"

#include <vector>
#include <string>

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"


using namespace ROOT::VecOps;

static const std::vector<std::string> files = {RB::GetDataDir() + "/Run2012B_DoubleMuParked.root",
                                               RB::GetDataDir() + "/Run2012C_DoubleMuParked.root"};

void payload(const std::vector<std::string>& files, unsigned int nthreads)
{
#ifdef R__USE_IMT
   // Enable multi-threading
   if (nthreads) {
      ROOT::EnableImplicitMT(nthreads);
   } else {
      ROOT::DisableImplicitMT();
   }
#endif // R__USE_IMT

   // Create dataframe from NanoAOD files
   ROOT::RDataFrame df("Events", files);

   // For simplicity, select only events with exactly two muons and require opposite charge
   auto df_2mu = df.Filter("nMuon == 2", "Events with exactly two muons");
   auto df_os = df_2mu.Filter("Muon_charge[0] != Muon_charge[1]", "Muons with opposite charge");

   // Compute invariant mass of the dimuon system
   auto df_mass = df_os.Define("Dimuon_mass", InvariantMass<float>, {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass"});

   // Make histogram of dimuon mass spectrum
   auto h = df_mass.Histo1D({"Dimuon_mass", "Dimuon_mass", 30000, 0.25, 300}, "Dimuon_mass");

   // Request cut-flow report
   auto report = df_mass.Report();

   // Produce plot
   gStyle->SetOptStat(0); gStyle->SetTextFont(42);
   auto c = new TCanvas("c", "", 800, 700);
   c->SetLogx(); c->SetLogy();

   h->SetTitle("");
   h->GetXaxis()->SetTitle("m_{#mu#mu} (GeV)"); h->GetXaxis()->SetTitleSize(0.04);
   h->GetYaxis()->SetTitle("N_{Events}"); h->GetYaxis()->SetTitleSize(0.04);
   h->DrawClone();

   TLatex label; label.SetNDC(true);
   label.DrawLatex(0.175, 0.740, "#eta");
   label.DrawLatex(0.205, 0.775, "#rho,#omega");
   label.DrawLatex(0.270, 0.740, "#phi");
   label.DrawLatex(0.400, 0.800, "J/#psi");
   label.DrawLatex(0.415, 0.670, "#psi'");
   label.DrawLatex(0.485, 0.700, "Y(1,2,3S)");
   label.DrawLatex(0.755, 0.680, "Z");
   label.SetTextSize(0.040); label.DrawLatex(0.100, 0.920, "#bf{CMS Open Data}");
   label.SetTextSize(0.030); label.DrawLatex(0.630, 0.920, "#sqrt{s} = 8 TeV, L_{int} = 11.6 fb^{-1}");

   c->SaveAs("dimuon_spectrum.pdf");

   // Print cut-flow report
   report->Print();
}

static void df102_NanoAODDimuonAnalysis_noimt(benchmark::State &state)
{
   for (auto _ : state)
      payload(files, 0);
}

static void df102_NanoAODDimuonAnalysis_imt(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      payload(files, nthreads);
   }
}

BENCHMARK(df102_NanoAODDimuonAnalysis_noimt)->Repetitions(1);
BENCHMARK(df102_NanoAODDimuonAnalysis_imt)->Repetitions(1)->Arg(8);
BENCHMARK_MAIN();
