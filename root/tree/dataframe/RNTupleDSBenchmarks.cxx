#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleDS.hxx>
#include <ROOT/RDataFrame.hxx>

#include <benchmark/benchmark.h>
#include <string>
#include <vector>

#include <rootbench/RBConfig.h>

namespace {

constexpr double kKaonMassMeV = 493.677;

double GetP2(double px, double py, double pz)
{
   return px*px + py*py + pz*pz;
}

double GetKE(double px, double py, double pz)
{
   double p2 = GetP2(px, py, pz);
   return sqrt(p2 + kKaonMassMeV*kKaonMassMeV);
}

template <typename DF>
auto Dataframe(DF &frame)
{
   auto fn_muon_cut = [](int is_muon) { return !is_muon; };
   auto fn_k_cut = [](double prob_k) { return prob_k > 0.5; };
   auto fn_pi_cut = [](double prob_pi) { return prob_pi < 0.5; };
   auto fn_sum = [](double p1, double p2, double p3) { return p1 + p2 + p3; };
   auto fn_mass = [](double B_E, double B_P2) { double r = sqrt(B_E*B_E - B_P2); return r; };

   auto df_muon_cut = frame.Filter(fn_muon_cut, {"H1_isMuon"})
                           .Filter(fn_muon_cut, {"H2_isMuon"})
                           .Filter(fn_muon_cut, {"H3_isMuon"});
   auto df_k_cut = df_muon_cut.Filter(fn_k_cut, {"H1_ProbK"})
                              .Filter(fn_k_cut, {"H2_ProbK"})
                              .Filter(fn_k_cut, {"H3_ProbK"});
   auto df_pi_cut = df_k_cut.Filter(fn_pi_cut, {"H1_ProbPi"})
                            .Filter(fn_pi_cut, {"H2_ProbPi"})
                            .Filter(fn_pi_cut, {"H3_ProbPi"});
   auto df_mass = df_pi_cut.Define("B_PX", fn_sum, {"H1_PX", "H2_PX", "H3_PX"})
                           .Define("B_PY", fn_sum, {"H1_PY", "H2_PY", "H3_PY"})
                           .Define("B_PZ", fn_sum, {"H1_PZ", "H2_PZ", "H3_PZ"})
                           .Define("B_P2", GetP2, {"B_PX", "B_PY", "B_PZ"})
                           .Define("K1_E", GetKE, {"H1_PX", "H1_PY", "H1_PZ"})
                           .Define("K2_E", GetKE, {"H2_PX", "H2_PY", "H2_PZ"})
                           .Define("K3_E", GetKE, {"H3_PX", "H3_PY", "H3_PZ"})
                           .Define("B_E", fn_sum, {"K1_E", "K2_E", "K3_E"})
                           .Define("B_m", fn_mass, {"B_E", "B_P2"});
   auto hMass = df_mass.template Histo1D<double>({"B_mass", "", 500, 5050, 5500}, "B_m");

   return hMass;
}
} // namespace

static void BM_RNTupleDS_LHCB(benchmark::State &state)
{
   auto ntuple = ROOT::Experimental::RNTupleReader::Open("DecayTree", RB::GetDataDir() + "/B2HHH~none.ntuple");
   const Long64_t nEntries = ntuple->GetNEntries() * (state.range(0) / 100.);

   auto df = ROOT::RDF::Experimental::FromRNTuple("DecayTree", RB::GetDataDir() + "/B2HHH~none.ntuple");
   auto df2 = df.Range(nEntries);
   auto h_ptr = Dataframe(df2);
   for (auto _ : state)
      *h_ptr;
   if (state.range(0) == 100) {
      // some sanity checks
      RB::Ensure(int(h_ptr->GetMean()) == 5262);
      RB::Ensure(int(h_ptr->GetEntries()) == 23895);
   }
}
BENCHMARK(BM_RNTupleDS_LHCB)->Unit(benchmark::kMicrosecond)->Iterations(1)->Arg(100)->Arg(50)->Arg(25);

BENCHMARK_MAIN();
