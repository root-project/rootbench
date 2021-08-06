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

   // Memory benchmark data placeholder
   auto mem_benchmarks = new multimap<string, pair<Long_t, Long_t>>;
   ProcInfo_t pinfo;
   Long_t curr_mem_res, temp_mem_res; curr_mem_res = temp_mem_res = 0;
   Long_t curr_mem_vir, temp_mem_vir; curr_mem_vir = temp_mem_vir = 0;

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
      string var_name = "var" + to_string(i);
      string var_leaflist = var_name + "/F";

      dataloader->AddVariable(var_name.c_str(), 'D');
   }

   // We add the single test event to avoid the printing of any errors from TMVA.
   // For each benchmark we specifically ignore this test event such that we exclusively benchmark training.
   dataloader->PrepareTrainingAndTestTree("",
                  Form("SplitMode=Block:nTrain_Signal=%i:nTrain_Background=%i:nTest_Signal=%i:nTest_Background=%i:!V",
                                                                                                nEvents, nEvents, 1, 1));

   // Get current memory usage statistics after setup
   gSystem->GetProcInfo(&pinfo);
   curr_mem_res = pinfo.fMemResident;
   curr_mem_vir = pinfo.fMemVirtual;

   // Benchmarking
   for(auto _: state){
      // Construct training options string
      string opts = "!V:!H:NTrees=" + to_string(state.range(0)) + ":MaxDepth=" + to_string(state.range(1));

      // Train a TMVA method
      string key = to_string(state.range(0)) + "_" + to_string(state.range(1));
      auto method = factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT_" + key, opts);
      TMVA::Event::SetIsTraining(kTRUE);
      method->TrainMethod();

      // Maintain Memory statistics (independent from Google Benchmark)
      gSystem->GetProcInfo(&pinfo);
      temp_mem_res = pinfo.fMemResident;
      temp_mem_vir = pinfo.fMemVirtual;
      mem_benchmarks->insert(make_pair(key,
                                       pair<Long_t, Long_t>(temp_mem_res - curr_mem_res, temp_mem_vir - curr_mem_vir)));
      curr_mem_res = temp_mem_res;
      curr_mem_vir = temp_mem_vir;

      TMVA::Event::SetIsTraining(kFALSE);
      method->Data()->DeleteAllResults(TMVA::Types::kTraining, method->GetAnalysisType());

      factory->DeleteAllMethods();
      factory->fMethodsMap.clear();
   }

   // Print memory benchmark statistics
   std::cout << "----------------------------------------------------------------------" << std::endl;
   std::cout << "Benchmark\t\t\tRes. Memory\t\tVir. Memory\tIterations" << std::endl;
   std::cout << "----------------------------------------------------------------------" << std::endl;
   for(auto kv = mem_benchmarks->begin(), end = mem_benchmarks->end(); kv != end;
        kv = mem_benchmarks->upper_bound(kv->first)){

      if(auto stats = mem_benchmarks->equal_range(kv->first); stats.first != stats.second){
         Int_t n_iter = mem_benchmarks->count(kv->first);
         Float_t avg_mem_res = 0.0;
         Float_t avg_mem_vir = 0.0;

         for(auto bm = stats.first; bm != stats.second; bm++){
            avg_mem_res += (bm->second).first;
            avg_mem_vir += (bm->second).second;
         }

         avg_mem_res /= n_iter;
         avg_mem_vir /= n_iter;

         std::cout << "BM_TMVA_BDTTesting_" << kv->first << "\t\t\t" << avg_mem_res << "\t\t" << avg_mem_vir << "\t" << n_iter << std::endl;
      }
   }

   // Teardown
   outputFile->Close();
   delete factory;
   delete sigTree;
   delete bkgTree;
   delete outputFile;
   delete mem_benchmarks;
}
BENCHMARK(BM_TMVA_BDTTraining)->ArgsProduct({{100, 400, 1000, 2000},{2, 4, 6, 8, 10}});

static void BM_TMVA_BDTTesting(benchmark::State &state){
   UInt_t nVars = 4;
   UInt_t nEvents = 500;

   // Set up
   TTree *testTree = genTree(nEvents, nVars,0.3, 0.5, 102, false);
   ROOT::RDataFrame testDF(*testTree);
   auto testTensor = AsTensor<Float_t>(testDF);

   // Benchmarking
   for(auto _: state){
      // Test a TMVA method via RReader
      string key = to_string(state.range(0)) + "_" + to_string(state.range(1));
      RReader model("./bdt-bench/weights/bdt-bench_BDT_" + key + ".weights.xml");
      model.Compute(testTensor);
   }

   // Teardown
   delete testTree;
}
BENCHMARK(BM_TMVA_BDTTesting)->ArgsProduct({{100, 400, 1000, 2000},{2, 4, 6, 8, 10}});

BENCHMARK_MAIN();
