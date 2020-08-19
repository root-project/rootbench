#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

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

static void BM_LHCb_Decompress(benchmark::State &state, int algo) {

    int comp_level = state.range(0);
    std::string comp_setting = std::to_string(algo * 100 + comp_level);
    std::string old_filename = (RB::GetDataDir() + "/lhcb_B2ppKK2011_md_noPIDstrip.root").c_str();
    std::string new_filename = "level_" + std::to_string(comp_level) + "_lhcb_" + GetAlgoName(algo) + ".root";

    gSystem->Exec(("hadd -v 0 -f" + comp_setting + " " + new_filename + " " + old_filename).c_str());

    TFile *newfile = new TFile(new_filename.c_str());
    state.counters["comp_size"] = newfile->GetSize();
    newfile->Close();

    for (auto _ : state) {
        
        TFile *hfile = new TFile(new_filename.c_str());
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

        hfile->Close();

    }

    gSystem->Exec(("rm -f " + new_filename).c_str());
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


BENCHMARK(BM_LHCb_Decompress_ZLIB)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(3);

BENCHMARK(BM_LHCb_Decompress_LZMA)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(3);

BENCHMARK(BM_LHCb_Decompress_LZ4)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(3);

BENCHMARK(BM_LHCb_Decompress_ZSTD)
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond)->Iterations(3);


BENCHMARK_MAIN();