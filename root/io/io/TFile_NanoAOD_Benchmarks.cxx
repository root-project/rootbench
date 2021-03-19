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
        {5, "zstd"},
        {6, "flzma2"}
    };

    if (algoName.find(algo) != algoName.end())
        return algoName[algo];
    else
        return "error";
}

static void BM_NanoAOD_Compress(benchmark::State &state, int algo) {
    TFile *oldfile = new TFile((RB::GetDataDir() + "/Run2012B_DoubleMuParked.root").c_str());
    TTree *oldtree = (TTree*)oldfile->Get("Events");

    int comp_level = state.range(0);
    std::string filename = "level_" + std::to_string(comp_level) + "_nanoaod_" + GetAlgoName(algo) + ".root";

    for (auto _ : state) {
        state.PauseTiming();

        TFile *newfile = new TFile(filename.c_str(), "recreate");
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

static void BM_NanoAOD_Decompress(benchmark::State &state, int algo) {
    int comp_level = state.range(0);

    std::string filename = "level_" + std::to_string(comp_level) + "_nanoaod_" + GetAlgoName(algo) + ".root";
    for (auto _ : state) {
        TFile *hfile = new TFile(filename.c_str());
        TTree *tree = (TTree*)hfile->Get("Events");

        Int_t nevent = (Int_t)tree->GetEntries();

        Int_t nb = 0;
        Int_t ev;

        for (ev = 0; ev < nevent; ev++) {
            nb += tree->GetEntry(ev);
        }
    }
}

static void BM_NanoAOD_Compress_ZLIB(benchmark::State &state) {
    BM_NanoAOD_Compress(state, 1);
}
static void BM_NanoAOD_Compress_LZMA(benchmark::State &state) {
    BM_NanoAOD_Compress(state, 2);
}
static void BM_NanoAOD_Compress_LZ4(benchmark::State &state) {
    BM_NanoAOD_Compress(state, 4);
}
static void BM_NanoAOD_Compress_ZSTD(benchmark::State &state) {
    BM_NanoAOD_Compress(state, 5);
}
static void BM_NanoAOD_Compress_FLZMA2(benchmark::State &state) {
    BM_NanoAOD_Compress(state, 6);
}

static void BM_NanoAOD_Decompress_ZLIB(benchmark::State &state) {
    BM_NanoAOD_Decompress(state, 1);
}
static void BM_NanoAOD_Decompress_LZMA(benchmark::State &state) {
    BM_NanoAOD_Decompress(state, 2);
}
static void BM_NanoAOD_Decompress_LZ4(benchmark::State &state) {
    BM_NanoAOD_Decompress(state, 4);
}
static void BM_NanoAOD_Decompress_ZSTD(benchmark::State &state) {
    BM_NanoAOD_Decompress(state, 5);
}
static void BM_NanoAOD_Decompress_FLZMA2(benchmark::State &state) {
    BM_NanoAOD_Decompress(state, 6);
}


BENCHMARK(BM_NanoAOD_Compress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Compress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Compress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Compress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Compress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);


BENCHMARK(BM_NanoAOD_Decompress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Decompress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Decompress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Decompress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_NanoAOD_Decompress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);


BENCHMARK_MAIN();
