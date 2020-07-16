#ifndef TH1WEIGHTSHELPER_H
#define TH1WEIGHTSHELPER_H

#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "ROOT/RDF/RInterface.hxx"

class TH1weightsHelper : public ROOT::Detail::RDF::RActionImpl<TH1weightsHelper> {

public:
   /// This type is a requirement for every helper.
   using Result_t = std::vector<TH1D>;
private:
   std::vector<std::shared_ptr<std::vector<TH1D>>> fHistos; // one per data processing slot
   std::string _name;
   int _nbinsX;
   std::vector<float> _xbins;
   std::vector<std::string> _weightNames;
  

public:
   /// This constructor takes all the parameters necessary to build the THnTs. In addition, it requires the names of
   /// the columns which will be used.
   TH1weightsHelper(std::string name, std::string title, 
                    int nbinsX, std::vector<float> xbins,
                    std::vector<std::string> weightNames
                    );

   TH1weightsHelper(TH1weightsHelper &&) = default;
   TH1weightsHelper(const TH1weightsHelper &) = delete;
   std::shared_ptr<std::vector<TH1D>> GetResultPtr() const;
   void Initialize();
   void InitTask(TTreeReader *, unsigned int);
   /// This is a method executed at every entry

   void Exec(unsigned int slot, const float &var1, const  ROOT::VecOps::RVec<float> &weights);
   void Finalize();
   std::string GetActionName();
};

#endif

