#include <TFile.h>
#include <TTree.h>
#include <TSystem.h>

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"

#include <iostream>
#include <map>

static std::string GetAlgoName(int algo) {
   std::map<int, std::string> algoName = {
      {1, "zlib"},
      {2, "lzma"},
      {4, "lz4"},
      {5, "zstd"},
      {6, "flzma2"}
   };

   if (algoName.find(algo) != algoName.end())
      return algoName[algo];
   else
      return "error";
}

static void BM_MainEvent_Compress(benchmark::State &state, int algo) {
   TFile *oldfile = new TFile((RB::GetDataDir() + "/Event0-sample.root").c_str());
   TTree *oldtree = (TTree*)oldfile->Get("T");

   int comp_level = state.range(0);
   std::string filename = "level_"+std::to_string(comp_level)+"_Event0_"+GetAlgoName(algo)+".root";

   for (auto _ : state) {
      state.PauseTiming();

      TFile *newfile = new TFile(filename.c_str(),"recreate");
      if (!TString(gSystem->GetLibraries()).Contains("Event")) {
        if(gSystem->Load("$ROOTSYS/test/libEvent.so")) {
          std::cout << "Could not load libEvent.so" << std::endl;
          return;
        }
      }
      TTree *newtree = oldtree->CloneTree();
      (void)newtree; // silence unused variable warnings. ROOT internals use this tree.
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

static void BM_MainEvent_Decompress(benchmark::State &state, int algo) {
   int comp_level = state.range(0);

   std::string filename = "level_"+std::to_string(comp_level)+"_Event0_"+GetAlgoName(algo)+".root";
   for (auto _ : state) {
      TFile *hfile = new TFile(filename.c_str());
      TTree *tree = (TTree*)hfile->Get("T");
      (void)tree; // silence unused variable warnings. ROOT internals use this tree.

      Int_t nevent = (Int_t)tree->GetEntries();

      Int_t nb = 0;
      Int_t ev;

      for (ev = 0; ev < nevent; ev++) {
         nb += tree->GetEntry(ev);
      }
   }
}

static void BM_MainEvent_Compress_ZLIB(benchmark::State &state) {
   BM_MainEvent_Compress(state, 1);
}
static void BM_MainEvent_Compress_LZMA(benchmark::State &state) {
   BM_MainEvent_Compress(state, 2);
}
static void BM_MainEvent_Compress_LZ4(benchmark::State &state) {
   BM_MainEvent_Compress(state, 4);
}
static void BM_MainEvent_Compress_ZSTD(benchmark::State &state) {
   BM_MainEvent_Compress(state, 5);
}
static void BM_MainEvent_Compress_FLZMA2(benchmark::State &state) {
   BM_MainEvent_Compress(state, 6);
}


static void BM_MainEvent_Decompress_ZLIB(benchmark::State &state) {
   BM_MainEvent_Decompress(state, 1);
}
static void BM_MainEvent_Decompress_LZMA(benchmark::State &state) {
   BM_MainEvent_Decompress(state, 2);
}
static void BM_MainEvent_Decompress_LZ4(benchmark::State &state) {
   BM_MainEvent_Decompress(state, 4);
}
static void BM_MainEvent_Decompress_ZSTD(benchmark::State &state) {
   BM_MainEvent_Decompress(state, 5);
}
static void BM_MainEvent_Decompress_FLZMA2(benchmark::State &state) {
   BM_MainEvent_Decompress(state, 6);
}


BENCHMARK(BM_MainEvent_Compress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Compress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Compress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Compress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Compress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);


BENCHMARK(BM_MainEvent_Decompress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Decompress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Decompress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Decompress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_MainEvent_Decompress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);



BENCHMARK_MAIN();
