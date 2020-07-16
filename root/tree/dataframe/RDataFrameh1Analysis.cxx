#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>

#include <benchmark/benchmark.h>
#include <rootbench/RBConfig.h>

auto Select = [](ROOT::RDataFrame &dataFrame) {
   using Farray_t = ROOT::VecOps::RVec<float>;
   using Iarray_t = ROOT::VecOps::RVec<int>;

   auto ret = dataFrame.Filter("TMath::Abs(md0_d - 1.8646) < 0.04")
                 .Filter("ptds_d > 2.5")
                 .Filter("TMath::Abs(etads_d) < 1.5")
                 .Filter([](int ik, int ipi, Iarray_t& nhitrp) { return nhitrp[ik - 1] * nhitrp[ipi - 1] > 1; },
                         {"ik", "ipi", "nhitrp"})
                 .Filter([](int ik, Farray_t& rstart, Farray_t& rend) { return rend[ik - 1] - rstart[ik - 1] > 22; },
                         {"ik", "rstart", "rend"})
                 .Filter([](int ipi, Farray_t& rstart, Farray_t& rend) { return rend[ipi - 1] - rstart[ipi - 1] > 22; },
                         {"ipi", "rstart", "rend"})
                 .Filter([](int ik, Farray_t& nlhk) { return nlhk[ik - 1] > 0.1; }, {"ik", "nlhk"})
                 .Filter([](int ipi, Farray_t& nlhpi) { return nlhpi[ipi - 1] > 0.1; }, {"ipi", "nlhpi"})
                 .Filter([](int ipis, Farray_t& nlhpi) { return nlhpi[ipis - 1] > 0.1; }, {"ipis", "nlhpi"})
                 .Filter("njets >= 1");

   return ret;
};

const Double_t dxbin = (0.17 - 0.13) / 40; // Bin-width

Double_t fdm5(Double_t *xx, Double_t *par)
{
   Double_t x = xx[0];
   if (x <= 0.13957)
      return 0;
   Double_t xp3 = (x - par[3]) * (x - par[3]);
   Double_t res =
      dxbin * (par[0] * pow(x - 0.13957, par[1]) + par[2] / 2.5066 / par[4] * exp(-xp3 / 2 / par[4] / par[4]));
   return res;
}

Double_t fdm2(Double_t *xx, Double_t *par)
{
   static const Double_t sigma = 0.0012;
   Double_t x = xx[0];
   if (x <= 0.13957)
      return 0;
   Double_t xp3 = (x - 0.1454) * (x - 0.1454);
   Double_t res = dxbin * (par[0] * pow(x - 0.13957, 0.25) + par[1] / 2.5066 / sigma * exp(-xp3 / 2 / sigma / sigma));
   return res;
}

void df101_h1Analysis()
{
   ROOT::RDataFrame dataFrame("h42", RB::GetDataDir() + "/h1analysis*.root");
   auto selected = Select(dataFrame);
   auto hdmdARP = selected.Histo1D({"hdmd", "Dm_d", 40, 0.13, 0.17}, "dm_d");
   auto selectedAddedBranch = selected.Define("h2_y", "rpd0_t / 0.029979f * 1.8646f / ptd0_d");
   auto h2ARP = selectedAddedBranch.Histo2D({"h2", "ptD0 vs Dm_d", 30, 0.135, 0.165, 30, -3, 6}, "dm_d", "h2_y");

   h2ARP.GetValue(); // trigger event loop
}

static void BM_RDataFrame_h1Analysis(benchmark::State &state)
{
   for (auto _ : state)
      df101_h1Analysis();
}
BENCHMARK(BM_RDataFrame_h1Analysis)->Repetitions(1);

static void BM_RDataFrame_h1Analysis_MT(benchmark::State &state)
{
   ROOT::EnableImplicitMT(state.range(0));
   for (auto _ : state)
      df101_h1Analysis();
   ROOT::DisableImplicitMT();
}
BENCHMARK(BM_RDataFrame_h1Analysis_MT)->Repetitions(1)->Arg(8);

BENCHMARK_MAIN();
