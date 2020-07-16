#include "inc/AngCoeff.hpp"

std::vector<std::string> AngCoeff::stringMultiplication (const std::vector<std::string> &v1, const std::vector<std::string> &v2){

        std::vector<std::string> products;

        if(v1.size()==0) return v2;
        
        else{

            products.reserve(v1.size()*v2.size());
            for (auto e1 : v1){
                for (auto e2 : v2){
                    products.push_back(e2+"_"+e1);
                    
                }
            }

            return products;
        }

    }

RNode AngCoeff::run(RNode d){
    
    std::vector<float> yArr = {0, 0.4, 0.8, 1.2 ,1.6, 2.0, 2.5, 3.0, 6.0};
    std::vector<float> ptArr = {0., 4., 8., 12., 16., 20., 24., 32., 40., 60., 100., 200.};
    
    int nBinsY = 8;
    int nBinsPt = 11;

    auto mapTot = d.Histo2D(TH2D("mapTot", "mapTot", nBinsY, yArr.data(), nBinsPt, ptArr.data()), "Wrap_preFSR_abs", "Wpt_preFSR", "lumiweight");
    auto mapAccEta = d.Filter("fabs(Mueta_preFSR)<2.4").Histo2D(TH2D("mapAccEta", "mapAccEta", nBinsY, yArr.data(), nBinsPt, ptArr.data()), "Wrap_preFSR_abs", "Wpt_preFSR", "lumiweight");
    auto mapAcc = d.Filter("fabs(Mueta_preFSR)<2.4 && Mupt_preFSR>25. && Mupt_preFSR<65.").Histo2D(TH2D("mapAcc", "mapAcc", nBinsY, yArr.data(), nBinsPt, ptArr.data()), "Wrap_preFSR_abs", "Wpt_preFSR", "lumiweight");
    auto sumw = d.Define("genratio", "Generator_weight/genEventSumw").Histo2D(TH2D("sumw", "sumw", nBinsY, yArr.data(), nBinsPt, ptArr.data()), "Wrap_preFSR_abs", "Wpt_preFSR","genratio");

    _h2List.push_back(mapTot);
    _h2List.push_back(mapAccEta);
    _h2List.push_back(mapAcc);
    _h2List.push_back(sumw);

    std::vector<std::string> coeff = {"A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "AUL"};

    std::vector<std::string> total = stringMultiplication(_syst_name, coeff);

    
    TH2weightsHelper helper(std::string("harmonics"), std::string("harmonics"), nBinsY, yArr, nBinsPt, ptArr, total);

    auto helXsecs = d.Book<float,  float, ROOT::VecOps::RVec<float>>(std::move(helper), {"Wrap_preFSR_abs", "Wpt_preFSR", Form("%sharmonicsVecWeighted",_syst_weight.c_str())});

    _h2Group.push_back(helXsecs);
    
    return d;

}

std::vector<ROOT::RDF::RResultPtr<TH1D>> AngCoeff::getTH1(){ 
    return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> AngCoeff::getTH2(){ 
    return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> AngCoeff::getTH3(){ 
    return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> AngCoeff::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> AngCoeff::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> AngCoeff::getGroupTH3(){ 
  return _h3Group;
}

void AngCoeff::reset(){
    
    _h1List.clear();
    _h2List.clear();
    _h3List.clear();

    _h1Group.clear();
    _h2Group.clear();
    _h3Group.clear();

}