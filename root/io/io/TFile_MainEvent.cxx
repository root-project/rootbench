#include "TFile.h"
#include "TTree.h"

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"

#include <map>

static std::string GetAlgoName(int algo) {
   std::map<int, std::string> algoName = {
      {1, "zlib"},
      {2, "lzma"},
      {4, "lz4"},
      {5, "zstd"}
   };

   if (algoName.find(algo) != algoName.end())
      return algoName[algo];
   else
      return "error";
}

static void Compress(benchmark::State &state, int algo) {
   TFile *oldfile = new TFile("Event0.root");
   TTree *oldtree = (TTree*)oldfile->Get("T");

   int comp_level = state.range(0);
   std::string filename = "level_"+std::to_string(comp_level)+"_Event0_"+GetAlgoName(algo)+".root";

   for (auto _ : state) {
      state.PauseTiming();

      TFile *newfile = new TFile(filename.c_str(),"recreate");
      TTree *newtree = oldtree->CloneTree();
      newfile->SetCompressionAlgorithm(algo);
      newfile->SetCompressionLevel(comp_level);

      state.ResumeTiming();
      newfile->Write();
      state.PauseTiming();

      state.counters["comp_size"] = newfile->GetBytesWritten();
      newfile->Close();

      state.ResumeTiming();
   }
}

static void Decompress(benchmark::State &state, int algo) {
   int comp_level = state.range(0);

   std::string filename = "level_"+std::to_string(comp_level)+"_Event0_"+GetAlgoName(algo)+".root";
   for (auto _ : state) {
      TFile *hfile = new TFile(filename.c_str());
      TTree *tree = (TTree*)hfile->Get("T");
      TBranch *branch = tree->GetBranch("event");

      Int_t nevent = (Int_t)tree->GetEntries();

      Int_t nb = 0;
      Int_t ev;

      for (ev = 0; ev < nevent; ev++) {
         nb += tree->GetEntry(ev);
      }
   }
}

static void BM_TFile_MainEvent_Compress_ZLIB(benchmark::State &state) {
   Compress(state, 1);
}
static void BM_TFile_MainEvent_Compress_LZMA(benchmark::State &state) {
   Compress(state, 2);
}
static void BM_TFile_MainEvent_Compress_LZ4(benchmark::State &state) {
   Compress(state, 4);
}


static void BM_TFile_MainEvent_Decompress_ZLIB(benchmark::State &state) {
   Decompress(state, 1);
}
static void BM_TFile_MainEvent_Decompress_LZMA(benchmark::State &state) {
   Decompress(state, 2);
}
static void BM_TFile_MainEvent_Decompress_LZ4(benchmark::State &state) {
   Decompress(state, 4);
}



BENCHMARK(BM_TFile_MainEvent_Compress_ZLIB)
->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->Arg(6)->Arg(7)->Arg(8)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK(BM_TFile_MainEvent_Compress_LZMA)
->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->Arg(6)->Arg(7)->Arg(8)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK(BM_TFile_MainEvent_Compress_LZ4)
->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->Arg(6)->Arg(7)->Arg(8)->Arg(9)
->Unit(benchmark::kMillisecond);



BENCHMARK(BM_TFile_MainEvent_Decompress_ZLIB)
->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->Arg(6)->Arg(7)->Arg(8)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK(BM_TFile_MainEvent_Decompress_LZMA)
->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->Arg(6)->Arg(7)->Arg(8)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK(BM_TFile_MainEvent_Decompress_LZ4)
->Arg(1)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->Arg(6)->Arg(7)->Arg(8)->Arg(9)
->Unit(benchmark::kMillisecond);


BENCHMARK_MAIN();
