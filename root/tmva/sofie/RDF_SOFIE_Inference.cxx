#include "higgs_model_dense.hxx"
#include <iostream>
#include <memory>
#include "TROOT.h"
#include "TSystem.h"
#include "ROOT/RDataFrame.hxx"

#include <benchmark/benchmark.h>

// Functor to wrap SOFIE session to RDF functor signature 
template <typename Func>
struct SofieFunctor {
   std::vector<float> input;
   std::vector<std::shared_ptr<Func>> sessions;
   SofieFunctor(unsigned nslots) :
      input(7*nslots,0) {
      for (int i = 0; i < nslots; i++) {
         sessions.push_back(std::make_shared<Func>());
      }
   }

   double operator()(unsigned nslots, float x0, float x1, float x2, float x3, float x4, float x5, float x6) {
      int off = nslots*7;
      input[off] = x0;
      input[off+1] = x1;
      input[off+2] = x2;
      input[off+3] = x3;
      input[off+4] = x4;
      input[off+5] = x5;
      input[off+6] = x6;
      auto y =  sessions[nslots]->infer(input.data()+nslots*7);
      return y[0];
   }
   
};

int NEVTS = -1;
void BM_RDF_SOFIE_Inference(benchmark::State &state)
{
   int nslot = state.range(0);

   if (nslot > 1)
      ROOT::EnableImplicitMT(nslot);
   auto fileName = "Higgs_data_full.root";
   //file is available at "https://cernbox.cern.ch/index.php/s/YuSHwTXBa0UBEhD/download";
   // do curl https://cernbox.cern.ch/index.php/s/XaPBtaGrnN38wU0 -o Higgs_data_full.root
   if (gSystem->AccessPathName(fileName) ) {
      std::string cmd = "curl https://cernbox.cern.ch/index.php/s/YuSHwTXBa0UBEhD/download -o ";
      cmd  += fileName;
      gSystem->Exec(cmd.c_str());
   }
   auto treeName = "test_tree";
   ROOT::RDataFrame df(treeName, fileName);


   SofieFunctor<TMVA_SOFIE_higgs_model_dense::Session> functor(nslot);

   std::vector<double> durations;

   double ntot = 0;

   for (auto _ : state) {

      auto h1 = df.DefineSlot("DNN_Value", functor, {"m_jj", "m_jjj", "m_lv", "m_jlv", "m_bb", "m_wbb", "m_wwbb"})
                   .Histo1D("DNN_Value");

      auto t1 = std::chrono::high_resolution_clock::now();

      auto n = h1->GetEntries();
      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
   
      durations.push_back(duration / 1.E6);
      NEVTS = n;
      ntot += n;
      // std::cout << " Processed " << n << " entries "
      //           << " time = " << duration / 1.E6 << " (sec)  time/event = " << duration / double(n) << " musec"
      //           << std::endl;
   }

   double avgDuration = TMath::Mean(durations.begin(), durations.end());
   state.counters["avg-time(s)"] = avgDuration;
   if (durations.size() > 1)
      state.counters["+/-"] = TMath::StdDev(durations.begin(), durations.end()) / sqrt(durations.size() - 1);
   state.counters["time/evt(s)"] = avgDuration *double(durations.size()) / ntot;
   // h1->DrawClone();
}

BENCHMARK(BM_RDF_SOFIE_Inference)
   ->Unit(benchmark::kMillisecond)
   // ->ComputeStatistics("Time/evt",
   //                     [](const std::vector<double> &v) -> double {
   //                        return std::accumulate(v.begin(), v.end(), 0.) / (v.size() * NEVTS);}
   //                     , benchmark::StatisticUnit::kTime)
   ->Arg(1)
   ->Arg(2)
   ->Arg(4);

BENCHMARK_MAIN();