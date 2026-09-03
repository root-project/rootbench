/* Authored by Xandru Mifsud (CERN Summer Student) and Lorenzo Moneta (Summer Project Supervisor) */

#include "TSystem.h"
#include "TTree.h"
#include "TFile.h"

#include "TMVA/RReader.hxx"
#include "TMVA/RTensorUtils.hxx"
#include "TMVA/DataLoader.h"
#include "TMVA/Factory.h"
#include "TMVA/MethodBase.h"
#include "TMVA/Types.h"

#include "benchmark/benchmark.h"

#include "MakeRandomTTree.h"

using namespace TMVA::Experimental;
using namespace std;

static void BM_TMVA_BDTTraining(benchmark::State &state){
   // Parameters
   UInt_t nVars = 4;
   UInt_t nEvents = 500;
   // Open output file
   TString outfileName( "bdt_bench_train_output.root" );
   TFile* outputFile = TFile::Open(outfileName, "RECREATE");

   // Set up (generate one extra event for testing)
   TTree *sigTree = genTree("sigTree", nEvents, nVars,0.3, 0.5, 100);
   TTree *bkgTree = genTree("bkgTree", nEvents, nVars,-0.3, 0.5, 101);

   // Prepare a DataLoader instance, registering the signal and background TTrees
   auto *dataloader = new TMVA::DataLoader("bdt-bench");
   dataloader->AddSignalTree(sigTree);
   dataloader->AddBackgroundTree(bkgTree);

   // Register variables in dataloader, using naming convention for randomly generated TTrees in MakeRandomTTree.h
   for(UInt_t i = 0; i < nVars; i++){
      string var_name = "var" + to_string(i);
      string var_leaflist = var_name + "/F";

      dataloader->AddVariable(var_name.c_str(), 'D');
   }

   // For each benchmark we specifically ignore this test event such that we exclusively benchmark training.
   dataloader->PrepareTrainingAndTestTree("",
                  Form("SplitMode=Block:nTrain_Signal=%i:nTrain_Background=%i:!V", nEvents, nEvents));

   for(auto _: state){
      // Create factory instance
      auto factory = new TMVA::Factory("bdt-bench", outputFile,
                                    "Silent:!DrawProgressBar:AnalysisType=Classification");

      // Construct training options string
      string opts = "!V:!H:NTrees=" + to_string(state.range(0)) + ":MaxDepth=" + to_string(state.range(1));

      // Train a TMVA method
      string key = to_string(state.range(0)) + "_" + to_string(state.range(1));
      auto method = factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT_" + key, opts);
      TMVA::Event::SetIsTraining(kTRUE);
      method->TrainMethod();

      TMVA::Event::SetIsTraining(kFALSE);
      method->Data()->DeleteAllResults(TMVA::Types::kTraining, method->GetAnalysisType());

      // Destroy factory entirely
      factory->DeleteAllMethods();
      factory->fMethodsMap.clear();
      delete factory;
   }

   // Teardown
   delete sigTree;
   delete bkgTree;

   outputFile->Close();
   delete outputFile;
}
BENCHMARK(BM_TMVA_BDTTraining)->ArgsProduct({{2000, 1000, 400, 100}, {10, 8, 6, 4, 2}});

static void BM_TMVA_BDTTesting(benchmark::State &state){
   // Parameters
   UInt_t nVars = 4;
   UInt_t nEvents = 500;
   // Open output file
   TString outfileName( "bdt_bench_test_output.root" );
   TFile* outputFile = TFile::Open(outfileName, "RECREATE");

   // Set up
   auto inputFile = new TFile("bdt_bench_test_input.root","RECREATE");
   TTree *testTree = genTree("testTree", nEvents, nVars,0.3, 0.5, 102, false);
   testTree->Write();
   delete testTree;
   inputFile->Close();
   delete inputFile;

   ROOT::RDataFrame testDF("testTree","bdt_bench_test_input.root");
   auto testTensor = AsTensor<Float_t>(testDF);

   for(auto _: state){
      // Test a TMVA method via RReader
      string key = to_string(state.range(0)) + "_" + to_string(state.range(1));

      RReader model("./bdt-bench/weights/bdt-bench_BDT_" + key + ".weights.xml");
      model.Compute(testTensor);
   }

   // Teardown
   outputFile->Close();
}
BENCHMARK(BM_TMVA_BDTTesting)->ArgsProduct({{2000, 1000, 400, 100}, {10, 8, 6, 4, 2}});

BENCHMARK_MAIN();
