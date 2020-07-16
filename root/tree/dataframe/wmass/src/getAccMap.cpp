#include "inc/getAccMap.hpp"

RNode getAccMap::run(RNode d){

    TH2D mapAccEta;
    TH2D mapAcc;
    TH2D mapTot;

    for(auto &h : _h2List){
        
        if(strcmp(h->GetName(),"mapAccEta")==0){ mapAccEta = h.GetValue();} 
        else if(strcmp(h->GetName(),"mapAcc")==0){ mapAcc = h.GetValue();} 
        else if(strcmp(h->GetName(),"mapTot")==0){ mapTot = h.GetValue();} 

    }

    mapAccEta.Divide(&mapTot);

    auto fillAccMapEta = [mapTot, mapAccEta](float y, float pt)mutable->float{

        int bin = mapAccEta.FindBin(y, pt);
        return mapAccEta.GetBinContent(bin);

    };

    mapAcc.Divide(&mapTot);
    auto fillAccMap = [mapTot, mapAcc](float y, float pt)mutable->float{

        int bin = mapAcc.FindBin(y, pt);
        return mapAcc.GetBinContent(bin);

    };

    auto fillTotMap = [mapTot](float y, float pt)mutable->float{

        int bin = mapTot.FindBin(y, pt);
        return mapTot.GetBinContent(bin);

    };

    auto d1 = d.Define("accMapEta", fillAccMapEta, {"Wrap_preFSR_abs", "Wpt_preFSR"}).Define("accMap", fillAccMap, {"Wrap_preFSR_abs", "Wpt_preFSR"}).Define("totMap", fillTotMap, {"Wrap_preFSR_abs", "Wpt_preFSR"});
    return d1;

}

std::vector<ROOT::RDF::RResultPtr<TH1D>> getAccMap::getTH1(){ 
    return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> getAccMap::getTH2(){ 
    return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> getAccMap::getTH3(){ 
    return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> getAccMap::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> getAccMap::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> getAccMap::getGroupTH3(){ 
  return _h3Group;
}

void getAccMap::reset(){
    
    _h1List.clear();
    _h2List.clear();
    _h3List.clear();

    _h1Group.clear();
    _h2Group.clear();
    _h3Group.clear();

}