#include "TFile.h"
#include "TTree.h"
#include "TStopwatch.h"

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

static void BM_NanoAOD_Compress(benchmark::State &state, int algo) {
    std::string path = RB::GetDataDir() + "/Run2012B_DoubleMuParked.root";
    //std::string path = RB::GetDataDir() + "/NanoAOD_DoubleMuon_CMS2011OpenData.root";
    auto oldfile = TFile::Open(path.c_str());
    auto oldtree = oldfile->Get<TTree>("Events");
    TStopwatch timer;
    const auto nevents = oldtree->GetEntries();
    int comp_level = state.range(0);
    std::string filename = "level_" + std::to_string(comp_level) + "_nanoaod_" + GetAlgoName(algo) + ".root";

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
        // For Run2012B_DoubleMuParked.root:
        float size_mb = 774.619423;
        // For NanoAOD_DoubleMuon_CMS2011OpenData.root:
        //float size_mb = 774.619423;
        state.counters["mb_rts"] = size_mb/rtime;
        state.counters["mb_cts"] = size_mb/ctime;
        newfile->Close();
        state.ResumeTiming();
    }
}

static void BM_NanoAOD_Decompress(benchmark::State &state, int algo) {
    int comp_level = state.range(0);
    int nb;
    TStopwatch timer;
    std::string filename = "level_" + std::to_string(comp_level) + "_nanoaod_" + GetAlgoName(algo) + ".root";
    for (auto _ : state) {
        timer.Start();
        TFile f(filename.c_str());
        auto tree = static_cast<TTree *>(f.Get("Events"));
        const auto nevents = tree->GetEntries();
        Int_t ev;
        for (ev = 0; ev < nevents; ++ev) {
            nb += tree->GetEntry(ev);
        }
        timer.Stop();
        double rtime = timer.RealTime();
        double ctime = timer.CpuTime();
        // For Run2012B_DoubleMuParked.root:
        float size_mb = 774.619423;
        // For NanoAOD_DoubleMuon_CMS2011OpenData.root:
        //float size_mb = 4871.365001;
        state.counters["mb_rts"] = size_mb/rtime;
        state.counters["mb_cts"] = size_mb/ctime;
        f.Close();
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


BENCHMARK(BM_NanoAOD_Compress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_NanoAOD_Compress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_NanoAOD_Compress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_NanoAOD_Compress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);


BENCHMARK(BM_NanoAOD_Decompress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_NanoAOD_Decompress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_NanoAOD_Decompress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);

BENCHMARK(BM_NanoAOD_Decompress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(1);


BENCHMARK_MAIN();
