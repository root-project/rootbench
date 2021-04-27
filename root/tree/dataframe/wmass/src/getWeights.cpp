#include "inc/getWeights.hpp"


RNode getWeights::run(RNode d){

    auto getNorm = [](float, float, const ROOT::VecOps::RVec<float> &AngCoeff, ROOT::VecOps::RVec<float> harmonicsVec, float totMap){

        float norm = harmonicsVec[8]*totMap;
        
        harmonicsVec[0]/=2.;
        harmonicsVec[1]/=(2.*TMath::Sqrt(2));
        harmonicsVec[2]/=4.;
        harmonicsVec[3]/=(4.*TMath::Sqrt(2));
        harmonicsVec[4]/=2.;
        harmonicsVec[5]/=2.;
        harmonicsVec[6]/=(2.*TMath::Sqrt(2));
        harmonicsVec[7]/=(4.*TMath::Sqrt(2));

        for(unsigned int i=0; i<harmonicsVec.size()-1; i++){ //loop over angular coefficients

             norm+=(AngCoeff[i]*harmonicsVec[i]*totMap); //sum Ai*Pi

        }

        float fact = 3./(16.*TMath::Pi());
        norm*=fact;

        return norm;

    };

    auto getWeights = [](float norm, const ROOT::VecOps::RVec<float>& harmonicsVec, float w){

        return (harmonicsVec/norm)*w;

    };

    auto d1 = d.Define("norm", getNorm, {"Wpt_preFSR", "Wrap_preFSR_abs", "AngCoeffVec", "harmonicsVec", "totMap"})
    .Define("harmonicsWeights", getWeights, {"norm", "harmonicsVec", "lumiweight"});    

    return d1;
    
}

std::vector<ROOT::RDF::RResultPtr<TH1D>> getWeights::getTH1(){ 
    return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> getWeights::getTH2(){ 
    return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> getWeights::getTH3(){ 
    return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> getWeights::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> getWeights::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> getWeights::getGroupTH3(){ 
  return _h3Group;
}

void getWeights::reset(){
    
    _h1List.clear();
    _h2List.clear();
    _h3List.clear();

    _h1Group.clear();
    _h2Group.clear();
    _h3Group.clear();

}
