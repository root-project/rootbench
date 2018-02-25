#include "ROOT/TDataFrame.hxx"
#include "TROOT.h"   // ROOT::EnableImplicitMT
#include "TSystem.h" // TSystem::Unlink
#include "benchmark/benchmark.h"
#include <string>
#include <vector>
using namespace ROOT::Experimental;

// FIXME change hardcoded path with env variable or equivalent
const std::string scratchDir = "/tmp/tmpfs";

static void BM_TDF_CreateEmpty(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(0);
}
BENCHMARK(BM_TDF_CreateEmpty)->Unit(benchmark::kMicrosecond);

static void BM_TDF_CreateFromFile(benchmark::State &state)
{
   const auto fname = scratchDir + "/tdf_createfromfile.root";
   const auto treeName = "t";
   TDataFrame(0).Snapshot<>("t", fname, {});

   for (auto _ : state)
      TDataFrame("t", fname);

   gSystem->Unlink(fname.c_str());
}
BENCHMARK(BM_TDF_CreateFromFile)->Unit(benchmark::kMicrosecond);

int Zero()
{
   return 0;
}

static void BM_TDF_Define(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(0).Define("", Zero);
}
BENCHMARK(BM_TDF_Define)->Unit(benchmark::kMicrosecond);

static void BM_TDF_DefineJitted(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(0).Define("", "0");
}
BENCHMARK(BM_TDF_DefineJitted)->Unit(benchmark::kMicrosecond);

bool Yes()
{
   return true;
}

static void BM_TDF_Filter(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(0).Filter(Yes);
}
BENCHMARK(BM_TDF_Filter)->Unit(benchmark::kMicrosecond);

static void BM_TDF_FilterJitted(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(0).Filter("true");
}
BENCHMARK(BM_TDF_FilterJitted)->Unit(benchmark::kMicrosecond);

static void BM_TDF_NoOpLoop(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(state.range(0)).Foreach([] {});
}
BENCHMARK(BM_TDF_NoOpLoop)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

static void BM_TDF_NoOpLoopOnFile(benchmark::State &state)
{
   const auto fname = scratchDir + "/tdf_nooplooponfile" + std::to_string(state.range(0)) + ".root";
   const auto treeName = "t";
   TDataFrame(state.range(0)).Snapshot<>("t", fname, {});

   for (auto _ : state)
      TDataFrame("t", fname).Foreach([] {});

   gSystem->Unlink(fname.c_str());
}
BENCHMARK(BM_TDF_NoOpLoopOnFile)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

// measure time taken updating the custom column value and passing it to an action
static void BM_TDF_NoOpLoopOnCustomColumn(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(state.range(0)).Define("x", Zero).Foreach([](int) {}, {"x"});
}
BENCHMARK(BM_TDF_NoOpLoopOnCustomColumn)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

// measure time taken checking an upstream filter
static void BM_TDF_NoOpLoopWithFilter(benchmark::State &state)
{
   for (auto _ : state)
      *TDataFrame(state.range(0)).Filter(Yes).Count();
}
BENCHMARK(BM_TDF_NoOpLoopWithFilter)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

static void BM_TDF_BookHisto(benchmark::State &state)
{
   for (auto _ : state)
      TDataFrame(0).Histo1D<ULong64_t>({"h", "h", 100, 0., 1.}, "tdfentry_");
}
BENCHMARK(BM_TDF_BookHisto)->Unit(benchmark::kMicrosecond);

// serves as baseline for the benchmarks that follow
static void BM_TDF_FillHistoNoTDF(benchmark::State &state)
{
   for (auto _ : state) {
      auto nFills = state.range(0);
      TH1D h("h", "h", nFills, 0., nFills);
      for (auto i = 0; i < nFills; ++i)
         h.Fill(i);
   }
}
BENCHMARK(BM_TDF_FillHistoNoTDF)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

// serves as baseline for the benchmarks that follow
static void BM_TDF_FillHistoRangeDeductionNoTDF(benchmark::State &state)
{
   for (auto _ : state) {
      auto nFills = state.range(0);
      TH1D h("h", "h", nFills, 0., 0.);
      for (auto i = 0; i < nFills; ++i)
         h.Fill(i);
   }
}
BENCHMARK(BM_TDF_FillHistoRangeDeductionNoTDF)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

// Fill a histogram from a single thread
// Data is generated on the fly, not read from a file
// The overhead of generating the data and passing it to the Histo action should be
// the one measured by BM_TDF_NoOpLoopOnCustomColumn
static void BM_TDF_FillHisto(benchmark::State &state)
{
   TDF::TH1DModel h("h", "h", state.range(0), 0., state.range(0));
   for (auto _ : state)
      *TDataFrame(state.range(0)).Histo1D<ULong64_t>(h, "tdfentry_");
}
BENCHMARK(BM_TDF_FillHisto)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

static void BM_TDF_FillHistoRangeDeduction(benchmark::State &state)
{
   for (auto _ : state)
      *TDataFrame(state.range(0)).Histo1D<ULong64_t>("tdfentry_");
}
BENCHMARK(BM_TDF_FillHistoRangeDeduction)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

// Fill a histogram from multiple-threads, merge partial results of each thread
static void BM_TDF_FillHistoMT(benchmark::State &state)
{
   TDF::TH1DModel h("h", "h", state.range(0), 0., state.range(0));
   ROOT::EnableImplicitMT();
   for (auto _ : state)
      *TDataFrame(state.range(0)).Histo1D<ULong64_t>(h, "tdfentry_");
   ROOT::DisableImplicitMT();
}
BENCHMARK(BM_TDF_FillHistoMT)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);
// FIXME booking the following benchmark causes a segfault
// BENCHMARK(BM_TDF_FillHistoMT)->Unit(benchmark::kMicrosecond)->UseRealTime()->ThreadPerCpu();

static void BM_TDF_FillHistoRangeDeductionMT(benchmark::State &state)
{
   ROOT::EnableImplicitMT();
   for (auto _ : state)
      *TDataFrame(state.range(0)).Histo1D<ULong64_t>("tdfentry_");
   ROOT::DisableImplicitMT();
}
BENCHMARK(BM_TDF_FillHistoRangeDeductionMT)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

BENCHMARK_MAIN();
