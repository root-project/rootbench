#include "TMVA/CrossValidation.h"

#include "TRandom3.h"
#include "TTree.h"

#include "TMVA/DataLoader.h"
#include "TFile.h"

#include "benchmark/benchmark.h"

#include "MakeRandomTTree.h"

static void BM_TMVA_BDTTraining(benchmark::State &state){
   UInt_t nVars = 4;
   UInt_t nEvents = 10000;

   // Set up
   TTree *sigTree = genTree(nEvents, nVars,0.3, 0.5, 100);
   TTree *bkgTree = genTree(nEvents, nVars,-0.3, 0.5, 101);

   auto *dataloader = new TMVA::DataLoader("bdt-bench");
   dataloader->AddSignalTree(sigTree);
   dataloader->AddBackgroundTree(bkgTree);

   for(UInt_t i = 0; i < nVars; i++){
      std::string var_name = "var" + std::to_string(i);
      std::string var_leaflist = var_name + "/F";

      dataloader->AddVariable(var_name.c_str(), 'D');
   }

   dataloader->PrepareTrainingAndTestTree("", Form("SplitMode=Block:nTrain_Signal=%i:nTrain_Background=%i:!V",
                                                                                                            nEvents, nEvents));

   // Benchmarking
   for(auto _: state){
      // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
      TString outfileName( "bdt_bench_output.root" );
      TFile* outputFile = TFile::Open(outfileName, "RECREATE");
      auto factory = new TMVA::Factory("bdt-bench", outputFile,
                                       "!V:!DrawProgressBar:AnalysisType=Classification");

      // Construct training options string
      std::string opts = "!V:!H:NTrees=" + std::to_string(state.range(0)) +
                         ":MaxDepth=" + std::to_string(state.range(1));

      // Train a TMVA method
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT", opts);
      factory->TrainAllMethods();
   }

   // Teardown
   delete sigTree;
   delete bkgTree;
}
BENCHMARK(BM_TMVA_BDTTraining)->ArgsProduct({{100, 400, 1000, 2000},{2, 4, 6, 8, 10}});

BENCHMARK_MAIN();
