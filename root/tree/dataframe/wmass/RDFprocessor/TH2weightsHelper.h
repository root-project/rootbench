#ifndef TH2WEIGHTSHELPER_H
#define TH2WEIGHTSHELPER_H

#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "ROOT/RDF/RInterface.hxx"

class TH2weightsHelper : public ROOT::Detail::RDF::RActionImpl<TH2weightsHelper> {

public:
   /// This type is a requirement for every helper.
   using Result_t = std::vector<TH2D>;
private:
   std::vector<std::shared_ptr<std::vector<TH2D>>> fHistos; // one per data processing slot
   std::string _name;
   int _nbinsX;
   std::vector<float> _xbins;
   int _nbinsY;
   std::vector<float> _ybins;
   std::vector<std::string> _weightNames;
  

public:
   /// This constructor takes all the parameters necessary to build the THnTs. In addition, it requires the names of
   /// the columns which will be used.
   TH2weightsHelper(std::string name, std::string title, 
                    int nbinsX, std::vector<float> xbins,
                    int nbinsY, std::vector<float> ybins,
                    std::vector<std::string> weightNames
                    );

   TH2weightsHelper(TH2weightsHelper &&) = default;
   TH2weightsHelper(const TH2weightsHelper &) = delete;
   std::shared_ptr<std::vector<TH2D>> GetResultPtr() const;
   void Initialize();
   void InitTask(TTreeReader *, unsigned int);
   /// This is a method executed at every entry

   void Exec(unsigned int slot, const float &var1, const float &var2, const  ROOT::VecOps::RVec<float> &weights);
   void Finalize();
   std::string GetActionName();
};

#endif

