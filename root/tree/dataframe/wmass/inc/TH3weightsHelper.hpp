#ifndef TH3WEIGHTSHELPER_H
#define TH3WEIGHTSHELPER_H

#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "ROOT/RDF/RInterface.hxx"

class TH3weightsHelper : public ROOT::Detail::RDF::RActionImpl<TH3weightsHelper> {

public:
   /// This type is a requirement for every helper.
   using Result_t = std::vector<TH3D>;
private:
   std::vector<std::shared_ptr<std::vector<TH3D>>> fHistos; // one per data processing slot
   std::string _name;
   int _nbinsX;
   std::vector<float> _xbins;
   int _nbinsY;
   std::vector<float> _ybins;
   int _nbinsZ;
   std::vector<float> _zbins;
   std::vector<std::string> _weightNames;
  

public:
   /// This constructor takes all the parameters necessary to build the THnTs. In addition, it requires the names of
   /// the columns which will be used.
   TH3weightsHelper(std::string name, std::string title, 
                    int nbinsX, std::vector<float> xbins,
                    int nbinsY, std::vector<float> ybins,
                    int nbinsZ, std::vector<float> zbins,
                    std::vector<std::string> weightNames
                    );

   TH3weightsHelper(TH3weightsHelper &&) = default;
   TH3weightsHelper(const TH3weightsHelper &) = delete;
   std::shared_ptr<std::vector<TH3D>> GetResultPtr() const;
   void Initialize();
   void InitTask(TTreeReader *, unsigned int);
   /// This is a method executed at every entry

   void Exec(unsigned int slot, const float &var1, const float &var2,  const float &var3, const  ROOT::VecOps::RVec<float> &weights);
   void Finalize();
   std::string GetActionName();
};

#endif

