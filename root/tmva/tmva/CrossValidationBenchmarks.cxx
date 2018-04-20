#include "TMVA/CrossValidation.h"

#include "TRandom3.h"
#include "TTree.h"

#include "TMVA/DataLoader.h"

#include "benchmark/benchmark.h"

TTree *genTree(Int_t nPoints, Double_t offset, Double_t scale = 0.3, UInt_t seed = 100)
{
   TRandom3 rng(seed);
   Float_t x = 0;
   Float_t y = 0;
   UInt_t id = 0;

   auto data = new TTree();
   data->Branch("x", &x, "x/F");
   data->Branch("y", &y, "y/F");
   data->Branch("EventNumber", &id, "EventNumber/I");

   for (Int_t n = 0; n < nPoints; ++n) {
      x = rng.Gaus(offset, scale);
      y = rng.Gaus(offset, scale);
      data->Fill();
      ++id;
   }

   // Important: Disconnects the tree from the memory locations of x and y.
   data->ResetBranchAddresses();
   return data;
}

static void BM_CrossValidation_Evaluate(benchmark::State &state)
{

   // Set up
   TTree *sigTree = genTree(1000, 0.3, 0.5, 100);
   TTree *bkgTree = genTree(1000, -0.3, 0.5, 101);

   // Benchmarking
   for (auto _ : state) {
      auto *dataloader = new TMVA::DataLoader("cv-bench");
      dataloader->AddSignalTree(sigTree);
      dataloader->AddBackgroundTree(bkgTree);

      dataloader->AddVariable("x", 'D');
      dataloader->AddVariable("y", 'D');
      dataloader->PrepareTrainingAndTestTree(
         "", Form("SplitMode=Block:nTrain_Signal=%i:nTrain_Background=%i:!V", 1000, 1000));

      // TMVA::CrossValidation takes ownership of dataloader
      TMVA::CrossValidation cv{"cv-bench", dataloader,
                               "Silent:AnalysisType=Classification"
                               ":NumWorkerProcs=1:NumFolds=5)"};

      cv.BookMethod(TMVA::Types::kBDT, "BDT",
                    "!H:!V:NTrees=400:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10"
                    ":UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=3");
      cv.Evaluate();
   }

   // Teardown
   delete sigTree;
   delete bkgTree;
}
BENCHMARK(BM_CrossValidation_Evaluate);

static void BM_CrossValidation_Evaluate_Multiprocess(benchmark::State &state)
{

   // Set up
   TTree *sigTree = genTree(1000, 0.3, 0.5, 100);
   TTree *bkgTree = genTree(1000, -0.3, 0.5, 101);

   // Benchmarking
   for (auto _ : state) {
      auto *dataloader = new TMVA::DataLoader("cv-multiproc-bench");
      dataloader->AddSignalTree(sigTree);
      dataloader->AddBackgroundTree(bkgTree);

      dataloader->AddVariable("x", 'D');
      dataloader->AddVariable("y", 'D');
      dataloader->PrepareTrainingAndTestTree(
         "", Form("SplitMode=Block:nTrain_Signal=%i:nTrain_Background=%i:!V", 1000, 1000));

      // TMVA::CrossValidation takes ownership of dataloader
      TMVA::CrossValidation cv{"cv-multiproc-bench", dataloader,
                               "Silent:AnalysisType=Classification"
                               ":NumWorkerProcs=2:NumFolds=5)"};

      cv.BookMethod(TMVA::Types::kBDT, "BDT",
                    "!H:!V:NTrees=400:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10"
                    ":UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=3");
      cv.Evaluate();
   }

   // Teardown
   delete sigTree;
   delete bkgTree;
}
BENCHMARK(BM_CrossValidation_Evaluate_Multiprocess);

BENCHMARK_MAIN();
