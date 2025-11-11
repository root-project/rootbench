#include "TRandom3.h"
#include "TTree.h"

// Utility function for generating a random TTree with Gaussian float data, for the specified number of points and vars
TTree* genTree(std::string name, UInt_t nPoints, const UInt_t nVars, Double_t offset, Double_t scale = 0.3, UInt_t seed = 100,
               bool evtCol = true){
   // Initialisation
   TRandom3 rng(seed);
   Float_t vars[nVars]; for(auto& var: vars){ var = 0.0;}
   UInt_t id = 0;

   // Create new TTree instance
   auto data = new TTree(name.c_str(),name.c_str());

   // Add a branch corresponding to each variable
   for(UInt_t i = 0; i < nVars; i++){
      std::string var_name = "var" + std::to_string(i);
      std::string var_leaflist = var_name + "/F";

      data->Branch(var_name.c_str(), vars + i, var_leaflist.c_str());
   }

   // And add a branch for the (unique) Event identifier
   if(evtCol){
      data->Branch("EventNumber", &id, "EventNumber/I");
   }

   // Populate TTree instance with Gaussian data
   for(UInt_t j = 0; j < nPoints; j++){
      for(UInt_t i = 0; i < nVars; i++){
         vars[i] = rng.Gaus(offset, scale);
      }

      data->Fill();
      id++;
   }

   // Important: Disconnects the tree from the memory locations of vars[i]
   data->ResetBranchAddresses();
   return data;
}