#include "ROOT/RDataFrame.hxx"
#include "TROOT.h"   // ROOT::EnableImplicitMT
#include "TSystem.h" // TSystem::Unlink
#include "benchmark/benchmark.h"
#include <string>
#include <vector>

#include "rootbench/RBConfig.h"

using namespace ROOT;

const std::string scratchDir = RB::GetTempFs();

static void BM_RDF_CreateEmpty(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(0);
}
BENCHMARK(BM_RDF_CreateEmpty)->Unit(benchmark::kMicrosecond);

static void BM_RDF_CreateFromFile(benchmark::State &state)
{
   const auto fname = scratchDir + "/tdf_createfromfile.root";
   const auto treeName = "t";
   RDataFrame(0).Snapshot<>(treeName, fname, {});

   for (auto _ : state)
      RDataFrame(treeName, fname);

   gSystem->Unlink(fname.c_str());
}
BENCHMARK(BM_RDF_CreateFromFile)->Unit(benchmark::kMicrosecond);

int Zero()
{
   return 0;
}

static void BM_RDF_Define(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(0).Define("d", Zero);
}
BENCHMARK(BM_RDF_Define)->Unit(benchmark::kMicrosecond);

static void BM_RDF_DefineJitted(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(0).Define("d", "0");
}
BENCHMARK(BM_RDF_DefineJitted)->Unit(benchmark::kMicrosecond);

bool Yes()
{
   return true;
}

static void BM_RDF_Filter(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(0).Filter(Yes);
}
BENCHMARK(BM_RDF_Filter)->Unit(benchmark::kMicrosecond);

static void BM_RDF_FilterJitted(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(0).Filter("true");
}
BENCHMARK(BM_RDF_FilterJitted)->Unit(benchmark::kMicrosecond);

static void BM_RDF_NoOpLoop(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(state.range(0)).Foreach([] {});
}
BENCHMARK(BM_RDF_NoOpLoop)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

static void BM_RDF_NoOpLoopOnFile(benchmark::State &state)
{
   const auto fname = scratchDir + "/tdf_nooplooponfile" + std::to_string(state.range(0)) + ".root";
   const auto treeName = "t";
   RDataFrame(state.range(0)).Snapshot<>(treeName, fname, {});

   for (auto _ : state)
      RDataFrame(treeName, fname).Foreach([] {});

   gSystem->Unlink(fname.c_str());
}
BENCHMARK(BM_RDF_NoOpLoopOnFile)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

// measure time taken updating the custom column value and passing it to an action
static void BM_RDF_NoOpLoopOnCustomColumn(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(state.range(0)).Define("x", Zero).Foreach([](int) {}, {"x"});
}
BENCHMARK(BM_RDF_NoOpLoopOnCustomColumn)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

// measure time taken checking an upstream filter
static void BM_RDF_NoOpLoopWithFilter(benchmark::State &state)
{
   for (auto _ : state)
      *RDataFrame(state.range(0)).Filter(Yes).Count();
}
BENCHMARK(BM_RDF_NoOpLoopWithFilter)->Unit(benchmark::kMicrosecond)->Arg(0)->Arg(1)->Arg(100)->Arg(100000);

static void BM_RDF_BookHisto(benchmark::State &state)
{
   for (auto _ : state)
      RDataFrame(0).Histo1D<ULong64_t>({"h", "h", 100, 0., 1.}, "tdfentry_");
}
BENCHMARK(BM_RDF_BookHisto)->Unit(benchmark::kMicrosecond);

// serves as baseline for the benchmarks that follow
static void BM_RDF_FillHistoNoRDF(benchmark::State &state)
{
   for (auto _ : state) {
      auto nFills = state.range(0);
      TH1D h("h", "h", nFills, 0., nFills);
      for (auto i = 0; i < nFills; ++i)
         h.Fill(i);
   }
}
BENCHMARK(BM_RDF_FillHistoNoRDF)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

// serves as baseline for the benchmarks that follow
static void BM_RDF_FillHistoRangeDeductionNoRDF(benchmark::State &state)
{
   for (auto _ : state) {
      auto nFills = state.range(0);
      TH1D h("h", "h", nFills, 0., 0.);
      for (auto i = 0; i < nFills; ++i)
         h.Fill(i);
   }
}
BENCHMARK(BM_RDF_FillHistoRangeDeductionNoRDF)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

// Fill a histogram from a single thread
// Data is generated on the fly, not read from a file
// The overhead of generating the data and passing it to the Histo action should be
// the one measured by BM_RDF_NoOpLoopOnCustomColumn
static void BM_RDF_FillHisto(benchmark::State &state)
{
   RDF::TH1DModel h("h", "h", state.range(0), 0., state.range(0));
   for (auto _ : state)
      *RDataFrame(state.range(0)).Histo1D<ULong64_t>(h, "tdfentry_");
}
BENCHMARK(BM_RDF_FillHisto)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

static void BM_RDF_FillHistoRangeDeduction(benchmark::State &state)
{
   for (auto _ : state)
      *RDataFrame(state.range(0)).Histo1D<ULong64_t>("tdfentry_");
}
BENCHMARK(BM_RDF_FillHistoRangeDeduction)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);

#ifdef R__USE_IMT
// Fill a histogram from multiple-threads, merge partial results of each thread
static void BM_RDF_FillHistoMT(benchmark::State &state)
{
   RDF::TH1DModel h("h", "h", state.range(0), 0., state.range(0));
   ROOT::EnableImplicitMT();
   for (auto _ : state)
      *RDataFrame(state.range(0)).Histo1D<ULong64_t>(h, "tdfentry_");
   ROOT::DisableImplicitMT();
}
BENCHMARK(BM_RDF_FillHistoMT)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);
// FIXME booking the following benchmark causes a segfault
// BENCHMARK(BM_RDF_FillHistoMT)->Unit(benchmark::kMicrosecond)->UseRealTime()->ThreadPerCpu();

static void BM_RDF_FillHistoRangeDeductionMT(benchmark::State &state)
{
   ROOT::EnableImplicitMT();
   for (auto _ : state)
      *RDataFrame(state.range(0)).Histo1D<ULong64_t>("tdfentry_");
   ROOT::DisableImplicitMT();
}
BENCHMARK(BM_RDF_FillHistoRangeDeductionMT)->Unit(benchmark::kMicrosecond)->Arg(100)->Arg(100000);
#endif // R__USE_IMT

BENCHMARK_MAIN();
