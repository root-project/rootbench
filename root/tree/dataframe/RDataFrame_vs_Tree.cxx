#include "RDataFrameBench.h"
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include <TFile.h>
#include <TSystem.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

#include <benchmark/benchmark.h>

#include <cstdlib> // abort
#include <vector>

using ROOT::RVec;

static constexpr auto treeName = "Events";
static constexpr auto fileName = "data.root";
static constexpr auto scalarBranch = "x";
static constexpr auto vectorBranch = "vec";
static constexpr auto nEntries = 100000;
static auto pathToFile = (scratchDir + "/" + fileName).c_str();

// an assert implementation that is not no-op for optimized builds
void ensure(bool b)
{
   if (!b)
      std::abort();
}

void MakeDataIfNeeded()
{
   const bool hasData = gSystem->AccessPathName("data.root") == 0;
   if (!hasData)
      ROOT::RDataFrame(nEntries)
         .Define(scalarBranch, [] { return 42; })
         .Define(vectorBranch, [] { return std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}; })
         .Snapshot<int, std::vector<int>>(treeName, fileName, {scalarBranch, vectorBranch});
}

static void CreateEmptyDF(benchmark::State &state)
{
   for (auto _ : state)
      ROOT::RDataFrame(10);
}
BENCHMARK(CreateEmptyDF);

static void CreateDFFromTFile(benchmark::State &state)
{
   MakeDataIfNeeded();
   for (auto _ : state)
      ROOT::RDataFrame(treeName, fileName);
}
BENCHMARK(CreateDFFromTFile);

static void CreateDFFromTFileAndBookSum(benchmark::State &state)
{
   MakeDataIfNeeded();
   for (auto _ : state)
      ROOT::RDataFrame(treeName, fileName).Sum<int>(scalarBranch);
}
BENCHMARK(CreateDFFromTFileAndBookSum);

static void SumScalarTBranchGetEntry(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile);
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   auto b = t->GetBranch(scalarBranch);
   b->SetAddress(&x);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         b->GetEntry(e);
         sum += x;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == 42 * nEntries);
}
BENCHMARK(SumScalarTBranchGetEntry);

// TTree::GetEntry is penalized by the presence of a TBranchElement, even if it's not read.
static void SumScalarTTreeGetEntry(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile);
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchStatus("*", false);
   t->SetBranchStatus(scalarBranch, true);
   t->SetBranchAddress(scalarBranch, &x);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         t->GetEntry(e);
         sum += x;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == 42 * nEntries);
}
BENCHMARK(SumScalarTTreeGetEntry);

static void SumScalarTTreeReader(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile);
   auto t = static_cast<TTree *>(f.Get(treeName));
   TTreeReader r(t);
   TTreeReaderValue<int> x(r, scalarBranch);
   int sum = 0;
   for (auto _ : state) {
      sum = 0;
      r.Restart();
      while (r.Next())
         sum += *x;
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == 42 * nEntries);
}
BENCHMARK(SumScalarTTreeReader);

static void SumScalarDF(benchmark::State &state)
{
   MakeDataIfNeeded();
   ROOT::RDataFrame df(treeName, fileName);
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<int>(scalarBranch);
   ensure(sum == 42 * nEntries);
}
BENCHMARK(SumScalarDF);

static void SumScalarWithForeach(benchmark::State &state)
{
   MakeDataIfNeeded();
   int sum = 0;
   ROOT::RDataFrame df(treeName, fileName);
   for (auto _ : state) {
      sum = 0;
      df.Foreach([&sum](int x) { sum += x; }, {scalarBranch});
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == 42 * nEntries);
}
BENCHMARK(SumScalarWithForeach);

static void SumScalarAfter1Define(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df = ROOT::RDataFrame(treeName, fileName).Define("defined_var", [](int x) { return x; }, {scalarBranch});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<int>("defined_var");
   ensure(sum == 42 * nEntries);
}
BENCHMARK(SumScalarAfter1Define);

static void SumScalarAfter5Defines(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df = ROOT::RDataFrame(treeName, fileName)
                .Define("def1", [](int x) { return x; }, {scalarBranch})
                .Define("def2", [](int x) { return x; }, {"def1"})
                .Define("def3", [](int x) { return x; }, {"def2"})
                .Define("def4", [](int x) { return x; }, {"def3"})
                .Define("def5", [](int x) { return x; }, {"def4"});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<int>("def5");
   ensure(sum == 42 * nEntries);
}
BENCHMARK(SumScalarAfter5Defines);

static void SumVectorTBranchGetEntry(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile);
   auto t = static_cast<TTree *>(f.Get(treeName));
   auto vec = new std::vector<int>;
   auto b = t->GetBranch(vectorBranch);
   b->SetAddress(&vec);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         b->GetEntry(e);
         for (auto el : *vec)
            sum += el;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(SumVectorTBranchGetEntry);

static void SumVectorTTreeReader(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile);
   auto t = static_cast<TTree *>(f.Get(treeName));
   TTreeReader r(t);
   TTreeReaderArray<int> vec(r, vectorBranch);
   int sum = 0;
   for (auto _ : state) {
      sum = 0;
      r.Restart();
      while (r.Next())
         for (auto e : vec)
            sum += e;
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(SumVectorTTreeReader);

static void SumVectorDF(benchmark::State &state)
{
   MakeDataIfNeeded();
   ROOT::RDataFrame df(treeName, fileName);
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<RVec<int>>(vectorBranch);
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(SumVectorDF);

static void SumVectorAfter1Define(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df =
      ROOT::RDataFrame(treeName, fileName).Define("defined_var", [](const RVec<int> &v) { return v; }, {vectorBranch});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<RVec<int>>("defined_var");
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(SumVectorAfter1Define);

static void SumVectorAfter5Defines(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df = ROOT::RDataFrame(treeName, fileName)
                .Define("def1", [](const RVec<int> &v) { return v; }, {vectorBranch})
                .Define("def2", [](const RVec<int> &v) { return v; }, {"def1"})
                .Define("def3", [](const RVec<int> &v) { return v; }, {"def2"})
                .Define("def4", [](const RVec<int> &v) { return v; }, {"def3"})
                .Define("def5", [](const RVec<int> &v) { return v; }, {"def4"});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<RVec<int>>("def5");
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(SumVectorAfter5Defines);
