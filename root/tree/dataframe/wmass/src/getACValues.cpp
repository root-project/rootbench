#include "inc/getACValues.hpp"

void getACValues::getAngCoeff(ROOT::RDF::RResultPtr<std::vector<TH2D>> helXsecs){

    auto &histos = *helXsecs.GetPtr();
        for(auto &h : histos){
        
            std::string s = h.GetName();
            std::string delimiter = "_";
            std::string token = s.substr(0,s.find(delimiter));

            std::string token2 = "";
            if(s.find(delimiter)!=std::string::npos){
            
                token2 = s.substr(s.find(delimiter)+delimiter.length(),std::string::npos);
                token2 = delimiter+token2;
            }
            for(auto &h2 : histos){
                
                if(h2.GetName()=="harmonicsAUL"+token2) h.Divide(&h2);
            }
        
            if(token == "harmonicsA0"){
                
                for(int xbin = 1; xbin<(h).GetNbinsX()+1;xbin++){
                    for(int ybin = 1; ybin<(h).GetNbinsY()+1;ybin++){

                        auto content = (h).GetBinContent(xbin,ybin);
                        (h).SetBinContent(xbin,ybin, 20./3.*(content + 1./10.));

                        }
                    }
            }
            else if(token == "harmonicsA2") {
                (h).Scale(20.);
                
            }
            else if(token == "harmonicsA1") (h).Scale(5.);
                
            else if(token == "harmonicsA5") (h).Scale(5.);
                
            else if(token == "harmonicsA6") (h).Scale(5.);
                
            else(h).Scale(4.);
                
        }

}

RNode getACValues::run(RNode d){
    
    getAngCoeff(_h2Group[0]);

    auto getACValues = [this](float y, float pt)mutable{

        ROOT::VecOps::RVec<float> AngCoeff;
        
        auto &histos = *_h2Group[0].GetPtr();
        for(auto &h : histos){
        
            int bin = h.FindBin(y, pt);
            AngCoeff.push_back(h.GetBinContent(bin));

        }
        
        return AngCoeff;

    };

    auto d1 = d.Define("AngCoeffVec", getACValues, {"Wrap_preFSR_abs", "Wpt_preFSR"});
    
    return d1;

}

std::vector<ROOT::RDF::RResultPtr<TH1D>> getACValues::getTH1(){ 
    return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> getACValues::getTH2(){ 
    return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> getACValues::getTH3(){ 
    return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> getACValues::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> getACValues::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> getACValues::getGroupTH3(){ 
  return _h3Group;
}

void getACValues::reset(){
    
    _h1List.clear();
    _h2List.clear();
    _h3List.clear();

    _h1Group.clear();
    _h2Group.clear();
    _h3Group.clear();

}