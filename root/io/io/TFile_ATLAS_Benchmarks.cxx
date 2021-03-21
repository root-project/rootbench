#include "TFile.h"
#include "TTree.h"
#include "TStopwatch.h"

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"

#include <map>
#include <iostream>

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

static void BM_ATLAS_Compress(benchmark::State &state, int algo) {
    std::string path = RB::GetDataDir() + "/gg_data-zstd.root";
    auto oldfile = TFile::Open(path.c_str());
    auto oldtree = oldfile->Get<TTree>("mini");
    TStopwatch timer;
    const auto nevents = oldtree->GetEntries();
    int comp_level = state.range(0);
    std::string filename = "level_" + std::to_string(comp_level) + "_atlas_" + GetAlgoName(algo) + ".root";

    for (auto _ : state) {
        state.PauseTiming();
        auto newfile = new TFile(filename.c_str(), "recreate");
        newfile->SetCompressionAlgorithm(algo);
        newfile->SetCompressionLevel(comp_level);
        auto newtree = oldtree->CloneTree();

        state.ResumeTiming();
        timer.Start();
        newfile->Write();
        timer.Stop();
        state.PauseTiming();

        state.counters["comp_size"] = newfile->GetSize();
        double rtime = timer.RealTime();
        double ctime = timer.CpuTime();
        state.counters["mb_rts"] = newfile->GetSize()/rtime;
        state.counters["mb_cts"] = newfile->GetSize()/ctime;
        newfile->Close();
        state.ResumeTiming();
    }
}

static void BM_ATLAS_Decompress(benchmark::State &state, int algo) {
    int comp_level = state.range(0);
    int nb;
    TStopwatch timer;
    std::string filename = "level_" + std::to_string(comp_level) + "_atlas_" + GetAlgoName(algo) + ".root";
    for (auto _ : state) {
        timer.Start();
        TFile f(filename.c_str());
        auto tree = static_cast<TTree *>(f.Get("mini"));
        const auto nevents = tree->GetEntries();
        Int_t ev;
        for (ev = 0; ev < nevents; ++ev) {
            nb += tree->GetEntry(ev);
        }
        timer.Stop();
        double rtime = timer.RealTime();
        double ctime = timer.CpuTime();
        state.counters["mb_rts"] = f.GetSize()/rtime;
        state.counters["mb_cts"] = f.GetSize()/ctime;
        f.Close();
    }
}

static void BM_ATLAS_Compress_ZLIB(benchmark::State &state) {
    BM_ATLAS_Compress(state, 1);
}
static void BM_ATLAS_Compress_LZMA(benchmark::State &state) {
    BM_ATLAS_Compress(state, 2);
}
static void BM_ATLAS_Compress_LZ4(benchmark::State &state) {
    BM_ATLAS_Compress(state, 4);
}
static void BM_ATLAS_Compress_ZSTD(benchmark::State &state) {
    BM_ATLAS_Compress(state, 5);
}
static void BM_ATLAS_Compress_FLZMA2(benchmark::State &state) {
    BM_ATLAS_Compress(state, 6);
}

static void BM_ATLAS_Decompress_ZLIB(benchmark::State &state) {
    BM_ATLAS_Decompress(state, 1);
}
static void BM_ATLAS_Decompress_LZMA(benchmark::State &state) {
    BM_ATLAS_Decompress(state, 2);
}
static void BM_ATLAS_Decompress_LZ4(benchmark::State &state) {
    BM_ATLAS_Decompress(state, 4);
}
static void BM_ATLAS_Decompress_ZSTD(benchmark::State &state) {
    BM_ATLAS_Decompress(state, 5);
}
static void BM_ATLAS_Decompress_FLZMA2(benchmark::State &state) {
    BM_ATLAS_Decompress(state, 6);
}

BENCHMARK(BM_ATLAS_Compress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Compress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Compress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Compress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Compress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);



BENCHMARK(BM_ATLAS_Decompress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Decompress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Decompress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Decompress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_ATLAS_Decompress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);


BENCHMARK_MAIN(); 