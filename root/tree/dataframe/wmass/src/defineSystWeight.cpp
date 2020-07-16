#include "inc/defineSystWeight.hpp"


RNode defineSystWeight::run(RNode d){
	
  auto vecMultiplication = [](const ROOT::VecOps::RVec<float> &v1, const ROOT::VecOps::RVec<float> &v2){

      ROOT::VecOps::RVec<float> products;

      products.reserve(v1.size()*v2.size());
      for (auto e1 : v1)
        for (auto e2 : v2)
          products.push_back(e1*e2);

      return products;
  };

  auto d1 = d.Define(Form("%sharmonicsVecWeighted",_syst_weight.c_str()),vecMultiplication,{_syst_weight,"harmonicsVecWeighted"});

  return d1;
  
  }

std::vector<ROOT::RDF::RResultPtr<TH1D>> defineSystWeight::getTH1(){ 
    return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> defineSystWeight::getTH2(){ 
    return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> defineSystWeight::getTH3(){ 
    return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> defineSystWeight::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> defineSystWeight::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> defineSystWeight::getGroupTH3(){ 
  return _h3Group;
}

void defineSystWeight::reset(){
    
    _h1List.clear();
    _h2List.clear();
    _h3List.clear();

    _h1Group.clear();
    _h2Group.clear();
    _h3Group.clear();

}
