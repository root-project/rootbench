#include "higgs_model_dense.hxx"
#include <iostream>
#include <memory>
#include "TROOT.h"
#include "TSystem.h"
#include "ROOT/RDataFrame.hxx"

#include <benchmark/benchmark.h>

// Functor to wrap SOFIE session to RDF functor signature

template <typename I, typename F, typename T>
class SofieFunctorHelper;

template <std::size_t... N,  typename S, typename T>
class SofieFunctorHelper<std::index_sequence<N...>, S, T> {
   /// this is the magic to defined the operator () with N fixed parameter arguments
   template <std::size_t Idx>
   using AlwaysT = T;

   std::vector<std::vector<T>> fInput;
   std::vector<std::shared_ptr<S>> fSessions;

public:

   SofieFunctorHelper(int nslots) :
      fInput(nslots)
   {
      for (int i = 0; i < nslots; i++) {
         fSessions.emplace_back(std::make_shared<S>());
      }
   }

   double operator()(unsigned slot, AlwaysT<N>... args) {
      fInput[slot] = {args...};
      auto y =  fSessions[slot]->infer(fInput[slot].data());
      return y[0];
   }


};

template <std::size_t N, typename F>
auto SofieFunctor(int nslot) -> SofieFunctorHelper<std::make_index_sequence<N>, F, float>
{
   return SofieFunctorHelper<std::make_index_sequence<N>, F, float>(nslot);
}


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


   //auto functor = SofieFunctor<TMVA_SOFIE_higgs_model_dense::Session,7>(nslot);
   // auto rdf_functor = [&](int slot, float x1, float x2, float x3, float x4, float x5, float x6, float x7){
   //    return functor(slot, x1,x2,x3,x4,x5,x6,x7);
   // };
   SofieFunctorHelper<std::make_index_sequence<7>, TMVA_SOFIE_higgs_model_dense::Session, float> functor(nslot);

   // test
   auto y = functor(0,1.,2.,3.,4.,5.,6.,7.);
   std::cout << y << std::endl;

   std::vector<double> durations;

   double ntot = 0;

   for (auto _ : state) {

      auto h1 = df.DefineSlot("DNN_Value", SofieFunctor<7,TMVA_SOFIE_higgs_model_dense::Session>(nslot), {"m_jj", "m_jjj", "m_lv", "m_jlv", "m_bb", "m_wbb", "m_wwbb"})
                   .Histo1D("DNN_Value");
      // auto h1 = df.Define("DNN_Value", "functor(m_jj, m_jjj, m_lv,m_jlv, m_bb, m_wbb, m_wwbb)")
      //              .Histo1D("DNN_Value");

      auto t1 = std::chrono::high_resolution_clock::now();

      auto n = h1->GetEntries();
      //int n = 100;
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