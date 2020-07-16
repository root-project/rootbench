#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include <TFile.h>
#include <TLorentzVector.h>

#include <array>
#include <cstdlib>
#include <memory>
#include <optional>

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"

using namespace ROOT::VecOps;
using ROOT::VecOps::RVec;
using VecF = const RVec<float> &;
using VecB = const RVec<bool> &;
using VecI = const RVec<int> &;
using VecIdx = const RVec<std::size_t> &;

auto GoodElIdx(VecF el_pt, VecF el_eta, VecB el_cut)
{
   return Nonzero(el_pt > 20. && abs(el_eta) < 2.5 && el_cut > 0);
}

auto GoodMuIdx(VecF mu_pt, VecF mu_eta, VecB mu_tight_id)
{
   return Nonzero(mu_pt > 20. && abs(mu_eta) < 2.4 && mu_tight_id > 0);
}

class Lepton {
   TLorentzVector _v;
   int _id = 0;
   int _charge = 0;

public:
   Lepton() {}
   Lepton(float pt, float eta, float phi, float mass, int charge) : _charge(charge)
   {
      _v.SetPtEtaPhiM(pt, eta, phi, mass);
   }
   const TLorentzVector &LorentzVec() const { return _v; }
   int Id() const { return _id; }
   int Charge() const { return _charge; }
   void SetId(int id) { _id = id; }
};

using MaybeLepton = std::optional<Lepton>;
using Best2Maybe = std::array<MaybeLepton, 2>;
using Best2Leptons = std::array<Lepton, 2>;

Best2Maybe FindBestMaybe(VecF pt, VecF eta, VecF phi, VecF mass, VecI charge, VecIdx good_idx)
{
   // assuming arrays are ordered by decreasing pt
   // and that at this point we have at most 2 good leptons
   const auto n_good = good_idx.size();
   Best2Maybe leps;
   for (auto i = 0u; i < n_good; ++i) {
      const auto idx = good_idx[i];
      leps[i] = Lepton(pt[idx], eta[idx], phi[idx], mass[idx], charge[idx]);
   }
   return leps;
}

Best2Leptons FindBestLeptons(const Best2Maybe &best_els, const Best2Maybe &best_mus)
{
   // assuming there are exactly two leptons between els and mus
   Best2Leptons leps;
   auto n_found = 0u;
   auto retrieve_with_id = [&](const Best2Maybe &maybeleps, int id) {
      for (const auto &l : maybeleps) {
         if (!l)
            continue;
         leps[n_found] = *l;
         leps[n_found].SetId(id * l->Charge());
         ++n_found;
      }
   };
   retrieve_with_id(best_els, 11);
   retrieve_with_id(best_mus, 13);

   if (leps[0].LorentzVec().Pt() < leps[1].LorentzVec().Pt())
      return Best2Leptons{leps[1], leps[0]};
   else
      return leps;
}

static void run_zpeak()
{
   // find indices of electrons and muons passing cuts
   // the Filter could also check for too _few_ leptons, but the original code doesn't?
   auto df = ROOT::RDataFrame("Events", RB::GetDataDir() + "/zpeak_data_small.root")
                .Define("good_el_idx", GoodElIdx, {"Electron_pt", "Electron_eta", "Electron_cutBasedId"})
                .Define("good_mu_idx", GoodMuIdx, {"Muon_pt", "Muon_eta", "Muon_tightId"})
                .Filter([](VecIdx idx1, VecIdx idx2) { return idx1.size() + idx2.size() == 2; },
                        {"good_el_idx", "good_mu_idx"}, "two leptons");

   // find 2 leptons with highest pt (electrons have precedence over muons)
   auto df_bestleps =
      df.Define("best_electrons", FindBestMaybe,
                {"Electron_pt", "Electron_eta", "Electron_phi", "Electron_mass", "Electron_charge", "good_el_idx"})
         .Define("best_muons", FindBestMaybe,
                 {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass", "Muon_charge", "good_mu_idx"})
         .Define("best_leptons", FindBestLeptons, {"best_muons", "best_electrons"});

   // fill histograms
   auto df_histvars =
      df_bestleps
         .Define("dilep_mass",
                 [](const Best2Leptons &leps) { return (leps[0].LorentzVec() + leps[1].LorentzVec()).M(); },
                 {"best_leptons"})
         .Define("pt1", [](const Best2Leptons &leps) { return leps[0].LorentzVec().Pt(); }, {"best_leptons"})
         .Define("pt2", [](const Best2Leptons &leps) { return leps[1].LorentzVec().Pt(); }, {"best_leptons"});

   auto id_product_is = [](int prod) {
      return [prod](const Best2Leptons &leps) { return leps[0].Id() * leps[1].Id() == prod; };
   };

   auto df_ee = df_histvars.Filter(id_product_is(-11 * 11), {"best_leptons"});
   auto mass_ee = df_ee.Histo1D<double>({"mass_ee", "mass;M_{ll} [GeV];Counts", 120, 0., 120.}, "dilep_mass");
   auto lepPt_ee = df_ee.Histo2D<double, double>(
      {"lepPt_ee", "LepPt;Leading p_{T}^{l} [GeV];Trailing p_{T}^{l} [GeV];Counts", 50, 0., 500., 50, 0., 500.}, "pt1",
      "pt2");

   auto df_em = df_histvars.Filter(id_product_is(-11 * 13), {"best_leptons"});
   auto mass_em = df_em.Histo1D<double>({"mass_em", "mass;M_{ll} [GeV];Counts", 120, 0., 120.}, "dilep_mass");
   auto lepPt_em = df_em.Histo2D<double, double>(
      {"lepPt_em", "LepPt;Leading p_{T}^{l} [GeV];Trailing p_{T}^{l} [GeV];Counts", 50, 0., 500., 50, 0., 500.}, "pt1",
      "pt2");

   auto df_mm = df_histvars.Filter(id_product_is(-13 * 13), {"best_leptons"});
   auto mass_mm = df_mm.Histo1D<double>({"mass_mm", "mass;M_{ll} [GeV];Counts", 120, 0., 120.}, "dilep_mass");
   auto lepPt_mm = df_mm.Histo2D<double, double>(
      {"lepPt_mm", "LepPt;Leading p_{T}^{l} [GeV];Trailing p_{T}^{l} [GeV];Counts", 50, 0., 500., 50, 0., 500.}, "pt1",
      "pt2");

   mass_ee.GetValue(); // trigger event loop

   // left here for debugging purposes
   /*
   std::unique_ptr<TFile> fOut{TFile::Open("plots_RDF_nojit.root", "recreate")};
   mass_ee->Write();
   mass_em->Write();
   mass_mm->Write();
   lepPt_ee->Write();
   lepPt_em->Write();
   lepPt_mm->Write();
   */
}

static void BM_RDataFrame_ZPeak(benchmark::State &state) {
   for (auto _ : state)
      run_zpeak();
}
BENCHMARK(BM_RDataFrame_ZPeak)->Repetitions(1);

static void BM_RDataFrame_ZPeak_MT(benchmark::State &state) {
   ROOT::EnableImplicitMT(state.range(0));
   for (auto _ : state)
      run_zpeak();
   ROOT::DisableImplicitMT();
}
BENCHMARK(BM_RDataFrame_ZPeak_MT)->Repetitions(1)->Arg(8);

BENCHMARK_MAIN();
