/* Authored by Xandru Mifsud (CERN Summer Student) and Lorenzo Moneta (Summer Project Supervisor) */

#include "TMVA/CrossValidation.h"

#include "TRandom3.h"
#include "TTree.h"

#include "TMVA/RReader.hxx"
#include "TMVA/RTensorUtils.hxx"
#include "TMVA/DataLoader.h"
#include "TMVA/Factory.h"
#include "TMVA/MethodBase.h"
#include "TMVA/Types.h"
#include "TFile.h"

#include "benchmark/benchmark.h"

#include "MakeRandomTTree.h"

using namespace TMVA::Experimental;

static void BM_TMVA_BDTTraining(benchmark::State &state){
   UInt_t nVars = 4;
   UInt_t nEvents = 500;

   // Set up (generate one extra event for testing)
   TTree *sigTree = genTree(nEvents+1, nVars,0.3, 0.5, 100);
   TTree *bkgTree = genTree(nEvents+1, nVars,-0.3, 0.5, 101);

   // one could maybe avoid TMVA to create output file by passing a nullptr to the Factory constructor
   TString outfileName( "bdt_bench_output.root" );
   TFile* outputFile = TFile::Open(outfileName, "RECREATE");
   auto factory = new TMVA::Factory("bdt-bench", outputFile,
                                    "Silent:!DrawProgressBar:AnalysisType=Classification");

   // Prepare a DataLoader instance, registering the signal and background TTrees
   auto *dataloader = new TMVA::DataLoader("bdt-bench");
   dataloader->AddSignalTree(sigTree);
   dataloader->AddBackgroundTree(bkgTree);

   // Register variables in dataloader, using naming convention for randomly generated TTrees in MakeRandomTTree.h
   for(UInt_t i = 0; i < nVars; i++){
      std::string var_name = "var" + std::to_string(i);
      std::string var_leaflist = var_name + "/F";

      dataloader->AddVariable(var_name.c_str(), 'D');
   }

   // We add the single test event to avoid the printing of any errors from TMVA.
   // For each benchmark we specifically ignore this test event such that we exclusively benchmark training.
   dataloader->PrepareTrainingAndTestTree("",
                  Form("SplitMode=Block:nTrain_Signal=%i:nTrain_Background=%i:nTest_Signal=%i:nTest_Background=%i:!V",
                                                                                                nEvents, nEvents, 1, 1));

   // Benchmarking
   for(auto _: state){
      // Create a ROOT output file where TMVA will store ntuples, histograms, etc.

      // Construct training options string
      std::string opts = "!V:!H:NTrees=" + std::to_string(state.range(0)) +
                         ":MaxDepth=" + std::to_string(state.range(1));

      // Train a TMVA method
      std::string methodTitle = "BDT_" + std::to_string(state.range(0)) + "_" + std::to_string(state.range(1));
      auto method = factory->BookMethod(dataloader, TMVA::Types::kBDT, methodTitle, opts);
      TMVA::Event::SetIsTraining(kTRUE);
      method->TrainMethod();
      TMVA::Event::SetIsTraining(kFALSE);
      method->Data()->DeleteAllResults(TMVA::Types::kTraining, method->GetAnalysisType());

      factory->DeleteAllMethods();
      factory->fMethodsMap.clear();
   }

   // Teardown
   outputFile->Close();
   delete factory;
   delete outputFile;
   delete sigTree;
   delete bkgTree;
}
BENCHMARK(BM_TMVA_BDTTraining)->ArgsProduct({{100, 400, 1000, 2000},{2, 4, 6, 8, 10}});

static void BM_TMVA_BDTTesting(benchmark::State &state){
   UInt_t nVars = 4;
   UInt_t nEvents = 500;

   // Set up
   TTree *testTree = genTree(nEvents, nVars,0.3, 0.5, 102);
   ROOT::RDataFrame testDF(*testTree);
   auto testTensor = AsTensor<Float_t>(testDF);

   // Benchmarking
   for(auto _: state){
      // Test a TMVA method via RReader
      std::string methodTitle = std::to_string(state.range(0)) + "_" + std::to_string(state.range(1));
      RReader model("bdt-bench_BDT_" + methodTitle + ".weights.xml");
      model.Compute(testTensor);
   }

   // Teardown
   delete testTree;
}
BENCHMARK(BM_TMVA_BDTTesting)->ArgsProduct({{100, 400, 1000, 2000},{2, 4, 6, 8, 10}});

BENCHMARK_MAIN();
