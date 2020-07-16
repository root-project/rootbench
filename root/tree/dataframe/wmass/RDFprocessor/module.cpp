#include "module.h"


std::vector<ROOT::RDF::RResultPtr<TH1D>> Module::getTH1(){ 
	return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> Module::getTH2(){ 
	return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> Module::getTH3(){ 
	return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> Module::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> Module::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> Module::getGroupTH3(){ 
  return _h3Group;
}

void Module::reset(){
	
	_h1List.clear();
	_h2List.clear();
	_h3List.clear();

	_h1Group.clear();
	_h2Group.clear();
	_h3Group.clear();

}
