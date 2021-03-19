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

static void BM_LHCb_Compress(benchmark::State &state, int algo) {
    TFile *oldfile = new TFile((RB::GetDataDir() + "/lhcb_B2ppKK2011_md_noPIDstrip.root").c_str());
    TTree *oldtree1 = (TTree*)oldfile->Get("TupleB2ppKK/DecayTree");
    TTree *oldtree2 = (TTree*)oldfile->Get("TupleB2ppKPi/DecayTree");
    TTree *oldtree3 = (TTree*)oldfile->Get("TupleB2ppPiPi/DecayTree");

    int comp_level = state.range(0);
    std::string filename = "level_" + std::to_string(comp_level) + "_lhcb_" + GetAlgoName(algo) + ".root";

    for (auto _ : state) {
        state.PauseTiming();

        TFile *newfile = new TFile(filename.c_str(), "recreate");
        TTree *newtree1 = oldtree1->CloneTree();
        TTree *newtree2 = oldtree2->CloneTree();
        TTree *newtree3 = oldtree3->CloneTree();
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

static void BM_LHCb_Decompress(benchmark::State &state, int algo) {
    int comp_level = state.range(0);

    std::string filename = "level_" + std::to_string(comp_level) + "_lhcb_" + GetAlgoName(algo) + ".root";
    for (auto _ : state) {
        TFile *hfile = new TFile(filename.c_str());
        TTree *tree1 = (TTree*)hfile->Get("TupleB2ppKK/DecayTree");
        TTree *tree2 = (TTree*)hfile->Get("TupleB2ppKPi/DecayTree");
        TTree *tree3 = (TTree*)hfile->Get("TupleB2ppPiPi/DecayTree");

        Int_t nevent1 = (Int_t)tree1->GetEntries();
        Int_t nevent2 = (Int_t)tree2->GetEntries();
        Int_t nevent3 = (Int_t)tree3->GetEntries();

        Int_t nb = 0;
        Int_t ev;

        for (ev = 0; ev < nevent1; ev++) {
            nb += tree1->GetEntry(ev);
        }

        for (ev = 0; ev < nevent2; ev++) {
            nb += tree2->GetEntry(ev);
        }

        for (ev = 0; ev < nevent3; ev++) {
            nb += tree3->GetEntry(ev);
        }
    }
}

static void BM_LHCb_Compress_ZLIB(benchmark::State &state) {
    BM_LHCb_Compress(state, 1);
}
static void BM_LHCb_Compress_LZMA(benchmark::State &state) {
    BM_LHCb_Compress(state, 2);
}
static void BM_LHCb_Compress_LZ4(benchmark::State &state) {
    BM_LHCb_Compress(state, 4);
}
static void BM_LHCb_Compress_ZSTD(benchmark::State &state) {
    BM_LHCb_Compress(state, 5);
}
static void BM_LHCb_Compress_FLZMA2(benchmark::State &state) {
    BM_LHCb_Compress(state, 6);
}

static void BM_LHCb_Decompress_ZLIB(benchmark::State &state) {
    BM_LHCb_Decompress(state, 1);
}
static void BM_LHCb_Decompress_LZMA(benchmark::State &state) {
    BM_LHCb_Decompress(state, 2);
}
static void BM_LHCb_Decompress_LZ4(benchmark::State &state) {
    BM_LHCb_Decompress(state, 4);
}
static void BM_LHCb_Decompress_ZSTD(benchmark::State &state) {
    BM_LHCb_Decompress(state, 5);
}
static void BM_LHCb_Decompress_FLZMA2(benchmark::State &state) {
    BM_LHCb_Decompress(state, 6);
}


BENCHMARK(BM_LHCb_Compress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Compress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Compress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Compress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Compress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Decompress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Decompress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Decompress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Decompress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);

BENCHMARK(BM_LHCb_Decompress_FLZMA2)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(5);


BENCHMARK_MAIN(); 