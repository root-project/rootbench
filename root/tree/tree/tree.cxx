#include <TFile.h>
#include <TSystem.h>
#include <TTree.h>

#include <benchmark/benchmark.h>

#include <vector>

static constexpr auto treeName = "Events";
static constexpr auto fileNameOneBranch = "dataonebranch.root";
static constexpr auto fileNameTwoBranches = "datatwobranches.root";
static constexpr auto branchOne = "x";
static constexpr auto branchTwo = "y";
static constexpr auto nEntries = 8000;

// an assert implementation that is not no-op for optimized builds
void ensure(bool b)
{
   if (!b)
      std::abort();
}

void MakeDataOneBranch()
{
   const bool hasData = gSystem->AccessPathName(fileNameOneBranch) == 0;
   if (hasData)
      return;
   TFile f(fileNameOneBranch, "create");
   TTree t(treeName, treeName);
   int x = 42;
   t.Branch(branchOne, &x);
   for (auto i = 0; i < nEntries; ++i)
      t.Fill();
   t.Write();
}

void MakeDataTwoBranches()
{
   const bool hasData = gSystem->AccessPathName(fileNameTwoBranches) == 0;
   if (hasData)
      return;
   TFile f(fileNameTwoBranches, "create");
   TTree t(treeName, treeName);
   int x = 42;
   int y = 84;
   t.Branch(branchOne, &x);
   t.Branch(branchTwo, &y);
   for (auto i = 0; i < nEntries; ++i)
      t.Fill();
   t.Write();
}

static void TreeGetEntryReadOneOfOne(benchmark::State &state)
{
   MakeDataOneBranch();
   TFile f(fileNameOneBranch);
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchStatus("*", false);
   t->SetBranchStatus(branchOne, true);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(TreeGetEntryReadOneOfOne);

static void TreeGetEntryReadNoneOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(fileNameTwoBranches);
   auto t = static_cast<TTree *>(f.Get(treeName));
   t->SetBranchStatus("*", kFALSE);
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      for (Long64_t e = 0ll; e < nEntries; ++e)
         t->GetEntry(e);
   }
}
BENCHMARK(TreeGetEntryReadNoneOfTwo);

static void TreeGetEntryReadOneOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(fileNameTwoBranches);
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchStatus("*", false);
   t->SetBranchStatus(branchOne, true);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(TreeGetEntryReadOneOfTwo);

static void TreeGetEntryReadTwoOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(fileNameTwoBranches);
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(TreeGetEntryReadTwoOfTwo);

static void BranchGetEntryReadOneOfOne(benchmark::State &state)
{
   MakeDataOneBranch();
   TFile f(fileNameOneBranch);
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   auto b = t->GetBranch(branchOne);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(BranchGetEntryReadOneOfOne);

static void BranchGetEntryReadOneOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(fileNameTwoBranches);
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   auto b = t->GetBranch(branchOne);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(BranchGetEntryReadOneOfTwo);

BENCHMARK_MAIN();
