#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include <TFile.h>
#include <TSystem.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <stdio.h>
#include <benchmark/benchmark.h>

#include <cstdlib> // abort
#include <vector>
#include <cstring>

#include "rootbench/RBConfig.h"

using ROOT::RVec;

static constexpr auto treeName = "Events";
static constexpr auto fileName = "data.root";
static constexpr auto scalarBranch = "x";
static constexpr auto vectorBranch = "vec";
static constexpr auto nEntries = 100000;
static const auto pathToFile = RB::GetTempFs() + "/" + fileName;


void MakeDataIfNeeded()
{
   const bool hasData = gSystem->AccessPathName(pathToFile.c_str()) == 0;
   if (!hasData)
      ROOT::RDataFrame(nEntries)
         .Define(scalarBranch, [] { return 42; })
         .Define(vectorBranch, [] { return std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}; })
         .Snapshot(treeName, pathToFile.c_str(), {scalarBranch, vectorBranch});
}

static void BM_RDataFrameSum_CreateEmptyDF(benchmark::State &state)
{
   for (auto _ : state)
      ROOT::RDataFrame(10);
}
BENCHMARK(BM_RDataFrameSum_CreateEmptyDF);

static void BM_RDataFrameSum_CreateDFFromTFile(benchmark::State &state)
{
   MakeDataIfNeeded();
   for (auto _ : state)
      ROOT::RDataFrame(treeName, pathToFile.c_str());
}
BENCHMARK(BM_RDataFrameSum_CreateDFFromTFile);

static void BM_RDataFrameSum_CreateDFFromTFileAndBookSum(benchmark::State &state)
{
   MakeDataIfNeeded();
   for (auto _ : state)
      ROOT::RDataFrame(treeName, pathToFile.c_str()).Sum<int>(scalarBranch);
}
BENCHMARK(BM_RDataFrameSum_CreateDFFromTFileAndBookSum);

static void BM_RDataFrameSum_SumScalarDF(benchmark::State &state)
{
   MakeDataIfNeeded();
   ROOT::RDataFrame df(treeName, pathToFile.c_str());
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<int>(scalarBranch);
   RB::Ensure(sum == 42 * nEntries);
}
BENCHMARK(BM_RDataFrameSum_SumScalarDF);

static void BM_RDataFrameSum_SumScalarWithForeach(benchmark::State &state)
{
   MakeDataIfNeeded();
   int sum = 0;
   ROOT::RDataFrame df(treeName, pathToFile.c_str());
   for (auto _ : state) {
      sum = 0;
      df.Foreach([&sum](int x) { sum += x; }, {scalarBranch});
      benchmark::DoNotOptimize(sum);
   }
   RB::Ensure(sum == 42 * nEntries);
}
BENCHMARK(BM_RDataFrameSum_SumScalarWithForeach);

static void BM_RDataFrameSum_SumScalarAfter1Define(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df = ROOT::RDataFrame(treeName, pathToFile.c_str()).Define("defined_var", [](int x) { return x; }, {scalarBranch});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<int>("defined_var");
   RB::Ensure(sum == 42 * nEntries);
}
BENCHMARK(BM_RDataFrameSum_SumScalarAfter1Define);

static void BM_RDataFrameSum_SumScalarAfter5Defines(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df = ROOT::RDataFrame(treeName, pathToFile.c_str())
                .Define("def1", [](int x) { return x; }, {scalarBranch})
                .Define("def2", [](int x) { return x; }, {"def1"})
                .Define("def3", [](int x) { return x; }, {"def2"})
                .Define("def4", [](int x) { return x; }, {"def3"})
                .Define("def5", [](int x) { return x; }, {"def4"});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<int>("def5");
   RB::Ensure(sum == 42 * nEntries);
}
BENCHMARK(BM_RDataFrameSum_SumScalarAfter5Defines);

static void BM_RDataFrameSum_SumVectorDF(benchmark::State &state)
{
   MakeDataIfNeeded();
   ROOT::RDataFrame df(treeName, pathToFile.c_str());
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<RVec<int>>(vectorBranch);
   RB::Ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(BM_RDataFrameSum_SumVectorDF);

static void BM_RDataFrameSum_SumVectorAfter1Define(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df =
      ROOT::RDataFrame(treeName, pathToFile.c_str()).Define("defined_var", [](const RVec<int> &v) { return v; }, {vectorBranch});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<RVec<int>>("defined_var");
   RB::Ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(BM_RDataFrameSum_SumVectorAfter1Define);

static void BM_RDataFrameSum_SumVectorAfter5Defines(benchmark::State &state)
{
   MakeDataIfNeeded();
   auto df = ROOT::RDataFrame(treeName, pathToFile.c_str())
                .Define("def1", [](const RVec<int> &v) { return v; }, {vectorBranch})
                .Define("def2", [](const RVec<int> &v) { return v; }, {"def1"})
                .Define("def3", [](const RVec<int> &v) { return v; }, {"def2"})
                .Define("def4", [](const RVec<int> &v) { return v; }, {"def3"})
                .Define("def5", [](const RVec<int> &v) { return v; }, {"def4"});
   int sum = 0;
   for (auto _ : state)
      sum = *df.Sum<RVec<int>>("def5");
   RB::Ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(BM_RDataFrameSum_SumVectorAfter5Defines);
