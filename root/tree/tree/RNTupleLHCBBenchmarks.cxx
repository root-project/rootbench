#include <ROOT/RNTuple.hxx>
#include <TH1D.h>
#include <benchmark/benchmark.h>
#include <rootbench/RBConfig.h>

namespace {
constexpr double kKaonMassMeV = 493.677;

double GetP2(double px, double py, double pz)
{
   return px * px + py * py + pz * pz;
}

double GetKE(double px, double py, double pz)
{
   double p2 = GetP2(px, py, pz);
   return sqrt(p2 + kKaonMassMeV * kKaonMassMeV);
}
} // namespace

static void BM_RNTuple_LHCB(benchmark::State &state)
{
   using RNTupleReader = ROOT::Experimental::RNTupleReader;

   auto ntuple = RNTupleReader::Open("DecayTree", RB::GetDataDir() + "/B2HHH~none.ntuple");
   auto viewH1IsMuon = ntuple->GetView<int>("H1_isMuon");
   auto viewH2IsMuon = ntuple->GetView<int>("H2_isMuon");
   auto viewH3IsMuon = ntuple->GetView<int>("H3_isMuon");

   auto viewH1PX = ntuple->GetView<double>("H1_PX");
   auto viewH1PY = ntuple->GetView<double>("H1_PY");
   auto viewH1PZ = ntuple->GetView<double>("H1_PZ");
   auto viewH1ProbK = ntuple->GetView<double>("H1_ProbK");
   auto viewH1ProbPi = ntuple->GetView<double>("H1_ProbPi");

   auto viewH2PX = ntuple->GetView<double>("H2_PX");
   auto viewH2PY = ntuple->GetView<double>("H2_PY");
   auto viewH2PZ = ntuple->GetView<double>("H2_PZ");
   auto viewH2ProbK = ntuple->GetView<double>("H2_ProbK");
   auto viewH2ProbPi = ntuple->GetView<double>("H2_ProbPi");

   auto viewH3PX = ntuple->GetView<double>("H3_PX");
   auto viewH3PY = ntuple->GetView<double>("H3_PY");
   auto viewH3PZ = ntuple->GetView<double>("H3_PZ");
   auto viewH3ProbK = ntuple->GetView<double>("H3_ProbK");
   auto viewH3ProbPi = ntuple->GetView<double>("H3_ProbPi");

   auto hMass = new TH1D("B_mass", "", 500, 5050, 5500);

   const Long64_t nEntries = ntuple->GetNEntries() * (state.range(0) / 100.);

   for (auto _ : state) {
      hMass->Reset();
      for (auto i = 0ll; i < nEntries; ++i) {
         if (viewH1IsMuon(i) || viewH2IsMuon(i) || viewH3IsMuon(i)) {
            continue;
         }

         constexpr double prob_k_cut = 0.5;
         if (viewH1ProbK(i) < prob_k_cut)
            continue;
         if (viewH2ProbK(i) < prob_k_cut)
            continue;
         if (viewH3ProbK(i) < prob_k_cut)
            continue;

         constexpr double prob_pi_cut = 0.5;
         if (viewH1ProbPi(i) > prob_pi_cut)
            continue;
         if (viewH2ProbPi(i) > prob_pi_cut)
            continue;
         if (viewH3ProbPi(i) > prob_pi_cut)
            continue;

         double b_px = viewH1PX(i) + viewH2PX(i) + viewH3PX(i);
         double b_py = viewH1PY(i) + viewH2PY(i) + viewH3PY(i);
         double b_pz = viewH1PZ(i) + viewH2PZ(i) + viewH3PZ(i);
         double b_p2 = GetP2(b_px, b_py, b_pz);
         double k1_E = GetKE(viewH1PX(i), viewH1PY(i), viewH1PZ(i));
         double k2_E = GetKE(viewH2PX(i), viewH2PY(i), viewH2PZ(i));
         double k3_E = GetKE(viewH3PX(i), viewH3PY(i), viewH3PZ(i));
         double b_E = k1_E + k2_E + k3_E;
         double b_mass = sqrt(b_E * b_E - b_p2);
         hMass->Fill(b_mass);
      }
   }
   if (state.range(0) == 100) {
      // sanity checks
      RB::Ensure(int(hMass->GetMean()) == 5262);
      RB::Ensure(int(hMass->GetEntries()) == 23895);
   }
   delete hMass;
}
// Arg is the % of events to be processed
BENCHMARK(BM_RNTuple_LHCB)->Unit(benchmark::kMicrosecond)->Iterations(5)->Arg(100)->Arg(50)->Arg(25);

BENCHMARK_MAIN();

