#include "inc/dataObs.hpp"


RNode dataObs::run(RNode d){
	

	TH3::SetDefaultSumw2(true);
  TH2::SetDefaultSumw2(true);

  const int nBinsEta = 100;
  const int nBinsPt = 80;

  std::vector<float> etaArr(nBinsEta+1);
  std::vector<float> ptArr(nBinsPt+1);

  for(int i=0; i<nBinsEta+1; i++){

    float binSize = 5.0/nBinsEta;
    etaArr[i] = -2.5 + i*binSize;

  }

  for(int i=0; i<nBinsPt+1; i++){

    float binSize = (65.-25.)/nBinsPt;
    ptArr[i] = 25. + i*binSize;

  }

  std::vector<std::string> PDF;
  for(int i =0; i<102; i++) PDF.push_back("replica" + std::to_string(i+1));

  // then template to be fixed

  auto dFix = d.Filter("accMapEta<0.4");
  auto fixBin = dFix.Histo2D(TH2D("lowAcc", "lowAcc", nBinsEta, etaArr.data(), nBinsPt, ptArr.data()),"Mueta_preFSR" ,"Mupt_preFSR", "lumiweight"); 
  _h2List.push_back(fixBin);

  // TH2weightsHelper helperPDFAcc(std::string("lowAcc_PDF"), std::string("lowAcc_PDF"), nBinsEta, etaArr, nBinsPt, ptArr, PDF);
  // auto lowAccPDF = dFix.Define("LHEPdfWeightLumi",multByWeight,{"lumiweight", "LHEPdfWeight"}).Book<float,  float, ROOT::VecOps::RVec<float>>(std::move(helperPDFAcc), {"Mueta_preFSR", "Mupt_preFSR", "LHEPdfWeightLumi"});

  // _h2Group.push_back(lowAccPDF);

  // pseudo data
    
  auto pseudodata = d.Histo2D(TH2D("data_obs", "data_obs", nBinsEta, etaArr.data(), nBinsPt, ptArr.data()),"Mueta_preFSR" ,"Mupt_preFSR", "lumiweight");    
  _h2List.push_back(pseudodata);

  // TH2weightsHelper helperPDFData(std::string("data_obs_PDF"), std::string("data_obs_PDF"), nBinsEta, etaArr, nBinsPt, ptArr, PDF);
  // auto pseudodataPDF = d.Define("LHEPdfWeightLumi",multByWeight,{"lumiweight", "LHEPdfWeight"}).Book<float,  float, ROOT::VecOps::RVec<float>>(std::move(helperPDFData), {"Mueta_preFSR", "Mupt_preFSR", "LHEPdfWeightLumi"});

  // _h2Group.push_back(pseudodataPDF);

  
  return d;
  
  }

std::vector<ROOT::RDF::RResultPtr<TH1D>> dataObs::getTH1(){ 
    return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> dataObs::getTH2(){ 
    return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> dataObs::getTH3(){ 
    return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> dataObs::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> dataObs::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> dataObs::getGroupTH3(){ 
  return _h3Group;
}

void dataObs::reset(){
    
    _h1List.clear();
    _h2List.clear();
    _h3List.clear();

    _h1Group.clear();
    _h2Group.clear();
    _h3Group.clear();

}
