#include <TFile.h>
#include <TSystem.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>

#include <benchmark/benchmark.h>

#include <vector>

static constexpr auto treeName = "Events";
static constexpr auto fileName = "databranchelement.root";
static constexpr auto branchName = "arr";
static constexpr auto nEntries = 8000;

// an assert implementation that is not no-op for optimized builds
void ensure(bool b)
{
   if (!b)
      std::abort();
}

void MakeDataFixedArray()
{
   TFile f(fileName, "recreate");
   TTree t(treeName, treeName);
   int x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
   t.Branch(branchName, x, (std::string(branchName) + "[8]/I").c_str());
   for (auto i = 0; i < nEntries; ++i)
      t.Fill();
   t.Write();
}

void MakeDataVarArray()
{
   TFile f(fileName, "recreate");
   TTree t(treeName, treeName);
   int n = 8;
   int *x = new int[n]{1, 2, 3, 4, 5, 6, 7, 8};
   t.Branch("n", &n);
   t.Branch(branchName, x, (std::string(branchName) + "[n]/I").c_str());
   for (auto i = 0; i < nEntries; ++i)
      t.Fill();
   t.Write();
}

void MakeDataStdVector()
{
   TFile f(fileName, "recreate");
   TTree t(treeName, treeName);
   std::vector<int> x({1,2,3,4,5,6,7,8});
   t.Branch(branchName, &x);
   for (auto i = 0; i < nEntries; ++i)
      t.Fill();
   t.Write();
}

static void FixedSizeArrayTBranch(benchmark::State &state)
{
   MakeDataFixedArray();
   TFile f(fileName);
   auto t = static_cast<TTree *>(f.Get(treeName));
   auto b = t->GetBranch(branchName);
   volatile int n = 8; // hopefully compiler won't optimize for n
   int *x = new int[n];
   b->SetAddress(x);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         b->GetEntry(e);
         for (auto i = 0; i < n; ++i)
            sum += x[i];
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(FixedSizeArrayTBranch);

static void VarSizeArrayTBranch(benchmark::State &state)
{
   MakeDataVarArray();
   TFile f(fileName);
   auto t = static_cast<TTree *>(f.Get(treeName));
   auto b = t->GetBranch(branchName);
   volatile int n = 8; // hopefully compiler won't optimize for n
   int *x = new int[n];
   b->SetAddress(x);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         b->GetEntry(e);
         for (auto i = 0; i < n; ++i)
            sum += x[i];
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(VarSizeArrayTBranch);

static void StdVectorTBranch(benchmark::State &state)
{
   MakeDataStdVector();
   TFile f(fileName);
   auto t = static_cast<TTree *>(f.Get(treeName));
   auto b = t->GetBranch(branchName);
   std::vector<int> *v = nullptr;
   b->SetAddress(&v);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         b->GetEntry(e);
         for (auto e : *v)
            sum += e;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(StdVectorTBranch);

static void RunReaderArray(benchmark::State &state)
{
   TFile f(fileName);
   auto t = static_cast<TTree *>(f.Get(treeName));
   TTreeReader r(t);
   TTreeReaderArray<int> vec(r, branchName);
   int sum = 0;
   for (auto _ : state) {
      sum = 0;
      r.Restart();
      while (r.Next()) {
         for (auto e : vec)
            sum += e;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}

static void FixedSizeArrayReaderArray(benchmark::State &state)
{
   MakeDataFixedArray();
   RunReaderArray(state);
}
BENCHMARK(FixedSizeArrayReaderArray);

static void VarSizeArrayReaderArray(benchmark::State &state)
{
   MakeDataVarArray();
   RunReaderArray(state);
}
BENCHMARK(VarSizeArrayReaderArray);

static void StdVectorReaderArray(benchmark::State &state)
{
   MakeDataStdVector();
   RunReaderArray(state);
}
BENCHMARK(StdVectorReaderArray);

BENCHMARK_MAIN();
