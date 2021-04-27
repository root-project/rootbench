#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "RConfigure.h" // for R__USE_IMT
#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"
#include "Math/Vector4D.h"
#include "TCanvas.h"

/*
 * The original benchmark code and also the original input file can be found here:
 * https://github.com/stwunsch/opendata-benchmarks
 */

static const std::string filepath1M = RB::GetDataDir() + "/Run2012B_SingleMu_1M.root";
static const std::string filepath10M = RB::GetDataDir() + "/Run2012B_SingleMu_10M.root";

void set_nthreads(unsigned int nthreads)
{
#ifdef R__USE_IMT
   if (nthreads) {
      ROOT::EnableImplicitMT(nthreads);
   } else {
      ROOT::DisableImplicitMT();
   }
#else
   Warn("ROOT was built without IMT support, all tests will be run on a single thread.");
#endif // R__USE_IMT
}

// Benchmark 1

void benchmark1_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Histo1D({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark1_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark1_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark1_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark1_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark1_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Histo1D<float>({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark1_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark1_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark1_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark1_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

// Benchmark 2

void benchmark2_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Histo1D({"", ";Jet p_{T} (GeV);N_{Events}", 100, 15, 60}, "Jet_pt");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark2_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark2_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark2_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark2_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark2_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Histo1D<ROOT::RVec<float>>({"", ";Jet p_{T} (GeV);N_{Events}", 100, 15, 60}, "Jet_pt");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark2_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark2_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark2_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark2_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

// Benchmark 3

void benchmark3_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Define("goodJet_pt", "Jet_pt[Jet_eta > 1.0]")
               .Histo1D({"", ";Jet p_{T} (GeV);N_{Events}", 100, 15, 60}, "goodJet_pt");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark3_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark3_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark3_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark3_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark3_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto goodJetPt = [](const ROOT::RVec<float> &pt, const ROOT::RVec<float> &eta) { return pt[eta > 1.0]; };
   auto h = df.Define("goodJet_pt", goodJetPt, {"Jet_pt", "Jet_eta"})
               .Histo1D<ROOT::RVec<float>>({"", ";Jet p_{T} (GeV);N_{Events}", 100, 15, 60}, "goodJet_pt");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark3_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark3_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark3_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark3_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

// Benchmark 4

void benchmark4_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Filter("Sum(Jet_pt > 40 && abs(Jet_eta) < 1.0) > 1", "More than one jet with pt > 40 and abs(eta) < 1.0")
               .Histo1D({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark4_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark4_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark4_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark4_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark4_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   using VecF = const ROOT::RVec<float> &;
   auto filter = [](VecF pt, VecF eta) {
      return Sum(pt > 40 && abs(eta) < 1.0) > 1;
   };
   auto h = df.Filter(filter, {"Jet_pt", "Jet_eta"}, "More than one jet with pt > 40 and abs(eta) < 1.0")
               .Histo1D<float>({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark4_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark4_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark4_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark4_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

// Benchmark 5

ROOT::RVec<float> benchmark5_compute_dimuon_masses(const ROOT::RVec<float> &pt, const ROOT::RVec<float> &eta,
                                                   const ROOT::RVec<float> &phi, const ROOT::RVec<float> &mass,
                                                   const ROOT::RVec<int> &charge)
{
   ROOT::RVec<float> masses;
   const auto c = ROOT::VecOps::Combinations(pt.size(), 2);
   for (auto i = 0; i < int(pt.size()); i++) {
      const auto i1 = c[0][i];
      const auto i2 = c[1][i];
      if (charge[i1] == charge[i2])
         continue;
      const ROOT::Math::PtEtaPhiMVector p1(pt[i1], eta[i1], phi[i1], mass[i1]);
      const ROOT::Math::PtEtaPhiMVector p2(pt[i2], eta[i2], phi[i2], mass[i2]);
      masses.push_back((p1 + p2).mass());
   }
   return masses;
}

void benchmark5_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Filter("nMuon >= 2", "At least two muons")
               .Define("Dimuon_mass", benchmark5_compute_dimuon_masses,
                       {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass", "Muon_charge"})
               .Filter("Sum(Dimuon_mass > 60 && Dimuon_mass < 100) > 0",
                       "At least one dimuon system with mass in range [60, 100]")
               .Histo1D({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark5_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark5_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark5_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark5_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark5_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto h = df.Filter([](unsigned int n) { return n >= 2; }, {"nMuon"}, "At least two muons")
               .Define("Dimuon_mass", benchmark5_compute_dimuon_masses,
                       {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass", "Muon_charge"})
               .Filter([](const ROOT::RVec<float> &mass) { return Sum(mass > 60 && mass < 100) > 0; }, {"Dimuon_mass"},
                       "At least one dimuon system with mass in range [60, 100]")
               .Histo1D<float>({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark5_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark5_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark5_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark5_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

// Benchmark 6

ROOT::RVec<std::size_t> benchmark6_find_trijet(const ROOT::RVec<float> &pt, const ROOT::RVec<float> &eta,
                                               const ROOT::RVec<float> &phi, const ROOT::RVec<float> &mass)
{
   const auto c = ROOT::VecOps::Combinations(pt, 3);
   const auto make_p4 = [&](std::size_t idx) {
      return ROOT::Math::PtEtaPhiMVector(pt[idx], eta[idx], phi[idx], mass[idx]);
   };

   float distance = 1e9;
   const auto top_mass = 172.5;
   std::size_t idx = 0;
   for (auto i = 0u; i < c[0].size(); i++) {
      auto p1 = make_p4(c[0][i]);
      auto p2 = make_p4(c[1][i]);
      auto p3 = make_p4(c[2][i]);
      const auto tmp_mass = (p1 + p2 + p3).mass();
      const auto tmp_distance = std::abs(tmp_mass - top_mass);
      if (tmp_distance < distance) {
         distance = tmp_distance;
         idx = i;
      }
   }

   return {c[0][idx], c[1][idx], c[2][idx]};
}

void benchmark6_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath1M);
   auto df2 = df.Filter("nJet >= 3", "At least three jets")
                 .Define("Trijet_idx", benchmark6_find_trijet, {"Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass"});
   auto h1 = df2.Define("Trijet_pt", "Take(Jet_pt, Trijet_idx)")
                .Histo1D({"", ";Trijet pt (GeV);N_{Events}", 100, 15, 40}, "Trijet_pt");
   auto h2 = df2.Define("Trijet_leadingBtag", "Max(Take(Jet_btag, Trijet_idx))")
                .Histo1D({"", ";Trijet leading b-tag;N_{Events}", 100, 0, 1}, "Trijet_leadingBtag");
   *h1;
   *h2;
#ifndef NDEBUG
   TCanvas c;
   c.Divide(2, 1);
   c.cd(1);
   h1->Draw();
   c.cd(2);
   h2->Draw();
   c.SaveAs("benchmark6_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark6_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark6_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark6_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark6_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath1M);
   auto df2 = df.Filter([](unsigned int n) { return n >= 3; }, {"nJet"}, "At least three jets")
                 .Define("Trijet_idx", benchmark6_find_trijet, {"Jet_pt", "Jet_eta", "Jet_phi", "Jet_mass"});
   auto h1 = df2.Define("Trijet_pt",
                        [](const ROOT::RVec<float> &pt, const ROOT::RVec<std::size_t> &idx) { return Take(pt, idx); },
                        {"Jet_pt", "Trijet_idx"})
                .Histo1D<ROOT::RVec<float>>({"", ";Trijet pt (GeV);N_{Events}", 100, 15, 40}, "Trijet_pt");
   auto h2 =
      df2.Define("Trijet_leadingBtag",
                 [](const ROOT::RVec<float> &btag, const ROOT::RVec<std::size_t> &idx) { return Max(Take(btag, idx)); },
                 {"Jet_btag", "Trijet_idx"})
         .Histo1D<float>({"", ";Trijet leading b-tag;N_{Events}", 100, 0, 1}, "Trijet_leadingBtag");
   *h1;
   *h2;
#ifndef NDEBUG
   TCanvas c;
   c.Divide(2, 1);
   c.cd(1);
   h1->Draw();
   c.cd(2);
   h2->Draw();
   c.SaveAs("benchmark6_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark6_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark6_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark6_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

// Benchmark 7

ROOT::RVec<int> benchmark7_good_jets(const ROOT::RVec<float> &eta1, const ROOT::RVec<float> &phi1,
                                     const ROOT::RVec<float> &pt2, const ROOT::RVec<float> &eta2,
                                     const ROOT::RVec<float> &phi2)
{
   ROOT::RVec<int> mask(eta1.size(), 1);
   if (eta2.size() == 0) {
      return mask;
   }

   const auto eta3 = eta2[pt2 > 10];
   const auto phi3 = phi2[pt2 > 10];
   if (eta3.size() == 0) {
      return mask;
   }

   const auto c = ROOT::VecOps::Combinations(eta1, eta3);
   for (auto i = 0u; i < c[0].size(); i++) {
      const auto i1 = c[0][i];
      const auto i2 = c[1][i];
      const auto dr = ROOT::VecOps::DeltaR(eta1[i1], phi1[i1], eta2[i2], phi2[i2]);
      if (dr < 0.4)
         mask[i1] = 0;
   }
   return mask;
}

void benchmark7_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath1M);
   auto h =
      df.Filter("nJet > 0", "At least one jet")
         .Define("goodJet_antiMuon", benchmark7_good_jets, {"Jet_eta", "Jet_phi", "Muon_pt", "Muon_eta", "Muon_phi"})
         .Define("goodJet_antiElectron", benchmark7_good_jets,
                 {"Jet_eta", "Jet_phi", "Electron_pt", "Electron_eta", "Electron_phi"})
         .Define("goodJet", "goodJet_antiMuon || goodJet_antiElectron")
         .Filter("Sum(goodJet) > 0")
         .Define("goodJet_sumPt", "Sum(Jet_pt[goodJet])")
         .Histo1D({"", ";Jet p_{T} sum (GeV);N_{Events}", 100, 15, 200}, "goodJet_sumPt");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark7_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark7_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark7_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark7_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark7_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath1M);
   auto h =
      df.Filter([](unsigned int n) { return n > 0; }, {"nJet"}, "At least one jet")
         .Define("goodJet_antiMuon", benchmark7_good_jets, {"Jet_eta", "Jet_phi", "Muon_pt", "Muon_eta", "Muon_phi"})
         .Define("goodJet_antiElectron", benchmark7_good_jets,
                 {"Jet_eta", "Jet_phi", "Electron_pt", "Electron_eta", "Electron_phi"})
         .Define("goodJet",
                 [](const ROOT::RVec<int> &muon, const ROOT::RVec<int> &electron) { return muon || electron; },
                 {"goodJet_antiMuon", "goodJet_antiElectron"})
         .Filter([](const ROOT::RVec<int> &good) { return Sum(good) > 0; }, {"goodJet"})
         .Define("goodJet_sumPt",
                 [](const ROOT::RVec<int> &good, const ROOT::RVec<float> &pt) { return Sum(pt[good]); },
                 {"goodJet", "Jet_pt"})
         .Histo1D<float>({"", ";Jet p_{T} sum (GeV);N_{Events}", 100, 15, 200}, "goodJet_sumPt");
   *h;
#ifndef NDEBUG
   TCanvas c;
   h->Draw();
   c.SaveAs("benchmark7_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark7_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark7_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark7_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

// Benchmark 8

float benchmark8_additional_lepton_pt(const ROOT::RVec<float> &pt, const ROOT::RVec<float> &eta,
                                      const ROOT::RVec<float> &phi, const ROOT::RVec<float> &mass,
                                      const ROOT::RVec<int> &charge, const ROOT::RVec<int> &flavour)
{
   const auto c = Combinations(pt, 2);
   float lep_pt = -999;
   float best_mass = 99999;
   int best_i1 = -1;
   int best_i2 = -1;
   const auto z_mass = 91.2;
   const auto make_p4 = [&](std::size_t idx) {
      return ROOT::Math::PtEtaPhiMVector(pt[idx], eta[idx], phi[idx], mass[idx]);
   };

   for (auto i = 0u; i < c[0].size(); i++) {
      const auto i1 = c[0][i];
      const auto i2 = c[1][i];
      if (charge[i1] == charge[i2])
         continue;
      if (flavour[i1] != flavour[i2])
         continue;
      const auto p1 = make_p4(i1);
      const auto p2 = make_p4(i2);
      const auto tmp_mass = (p1 + p2).mass();
      if (std::abs(tmp_mass - z_mass) < std::abs(best_mass - z_mass)) {
         best_mass = tmp_mass;
         best_i1 = i1;
         best_i2 = i2;
      }
   }

   if (best_i1 == -1)
      return lep_pt;

   for (auto i = 0; i < int(pt.size()); i++) {
      if (i != best_i1 && i != best_i2 && pt[i] > lep_pt)
         lep_pt = pt[i];
   }

   return lep_pt;
}

void benchmark8_jitted(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto df2 = df.Filter("nElectron + nMuon > 2", "At least three leptons")
                 .Define("Lepton_pt", "Concatenate(Muon_pt, Electron_pt)")
                 .Define("Lepton_eta", "Concatenate(Muon_eta, Electron_eta)")
                 .Define("Lepton_phi", "Concatenate(Muon_phi, Electron_phi)")
                 .Define("Lepton_mass", "Concatenate(Muon_mass, Electron_mass)")
                 .Define("Lepton_charge", "Concatenate(Muon_charge, Electron_charge)")
                 .Define("Lepton_flavour", "Concatenate(ROOT::RVec<int>(nMuon, 0), ROOT::RVec<int>(nElectron, 1))")
                 .Define("AdditionalLepton_pt", benchmark8_additional_lepton_pt,
                         {"Lepton_pt", "Lepton_eta", "Lepton_phi", "Lepton_mass", "Lepton_charge", "Lepton_flavour"})
                 .Filter("AdditionalLepton_pt != -999", "No valid lepton pair found.");
   auto h1 = df2.Histo1D({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   auto h2 = df2.Histo1D({"", ";Lepton p_{T} (GeV);N_{Events}", 100, 15, 60}, "AdditionalLepton_pt");
   *h1;
   *h2;
#ifndef NDEBUG
   TCanvas c;
   c.Divide(2, 1);
   c.cd(1);
   h1->Draw();
   c.cd(2);
   h2->Draw();
   c.SaveAs("benchmark8_jitted.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark8_jitted(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark8_jitted(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark8_jitted)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

void benchmark8_compiled(unsigned int nthreads)
{
   set_nthreads(nthreads);
   ROOT::RDataFrame df("Events", filepath10M);
   auto concatF = [](const ROOT::RVec<float> &a, const ROOT::RVec<float> &b) { return Concatenate(a, b); };
   auto concatI = [](const ROOT::RVec<int> &a, const ROOT::RVec<int> &b) { return Concatenate(a, b); };
   auto df2 = df.Filter([](unsigned int nElectron, unsigned int nMuon) { return nElectron + nMuon > 2; },
                        {"nElectron", "nMuon"}, "At least three leptons")
                 .Define("Lepton_pt", concatF, {"Muon_pt", "Electron_pt"})
                 .Define("Lepton_eta", concatF, {"Muon_eta", "Electron_eta"})
                 .Define("Lepton_phi", concatF, {"Muon_phi", "Electron_phi"})
                 .Define("Lepton_mass", concatF, {"Muon_mass", "Electron_mass"})
                 .Define("Lepton_charge", concatI, {"Muon_charge", "Electron_charge"})
                 .Define("Lepton_flavour",
                         [](unsigned int nMuon, unsigned int nElectron) {
                            return Concatenate(ROOT::RVec<int>(nMuon, 0), ROOT::RVec<int>(nElectron, 1));
                         },
                         {"nMuon", "nElectron"})
                 .Define("AdditionalLepton_pt", benchmark8_additional_lepton_pt,
                         {"Lepton_pt", "Lepton_eta", "Lepton_phi", "Lepton_mass", "Lepton_charge", "Lepton_flavour"})
                 .Filter([](float pt) { return pt != -999; }, {"AdditionalLepton_pt"}, "No valid lepton pair found.");
   auto h1 = df2.Histo1D<float>({"", ";MET (GeV);N_{Events}", 100, 0, 2000}, "MET_sumet");
   auto h2 = df2.Histo1D<float>({"", ";Lepton p_{T} (GeV);N_{Events}", 100, 15, 60}, "AdditionalLepton_pt");
   *h1;
   *h2;
#ifndef NDEBUG
   TCanvas c;
   c.Divide(2, 1);
   c.cd(1);
   h1->Draw();
   c.cd(2);
   h2->Draw();
   c.SaveAs("benchmark8_compiled.png");
#endif
}

static void BM_RDataFrame_OpenDataBenchmark8_compiled(benchmark::State &state)
{
   for (auto _ : state) {
      const auto nthreads = state.range(0);
      benchmark8_compiled(nthreads);
   }
}
BENCHMARK(BM_RDataFrame_OpenDataBenchmark8_compiled)->Unit(benchmark::kMillisecond)->Repetitions(1)->Arg(0)->Arg(8);

BENCHMARK_MAIN();
