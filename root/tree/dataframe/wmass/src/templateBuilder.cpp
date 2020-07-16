#include "inc/templateBuilder.hpp"


RNode templateBuilder::run(RNode d){
	

	TH3::SetDefaultSumw2(true);
  TH2::SetDefaultSumw2(true);

  std::vector<float> yArr = {0, 0.4, 0.8, 1.2 ,1.6, 2.0, 2.5, 3.0, 6.0};
  std::vector<float> qtArr = {0., 4., 8., 12., 16., 20., 24., 32., 40., 60., 100., 200.};

  const int nBinsY = 8;
  const int nBinsQt = 11;

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


  auto dFit = d.Filter("accMapEta>0.4");
  /*
  auto cut1 = [](float map){ return map > 0.4;};
  auto cut2 = [](float map){ return map < 0.4;};
  
  auto dFit = d.Filter("fabs(Mueta_preFSR)<2.4 && Mupt_preFSR>25. && Mupt_preFSR<65.").Filter(cut1, {"accMapEta"}, "accMapEta fit");
  auto cutReport1 = dFit.Report();

  auto dFix = d.Filter("fabs(Mueta_preFSR)<2.4 && Mupt_preFSR>25. && Mupt_preFSR<65.").Filter(cut2, {"accMapEta"}, "accMapEta fix");
  auto cutReport2 = dFix.Report();

  cutReport1->Print();
  cutReport2->Print();
  */
 
  std::vector<std::string> helXsecs = {"L", "I", "T", "A", "P", "7", "8", "9", "UL"};

  // first the templates for the fit
  auto h = new TH2F("h", "h", nBinsY, yArr.data(), nBinsQt, qtArr.data());

  for(int j=1; j<h->GetNbinsY()+1; j++){ // for each W pt bin

    float lowEdgePt = h->GetYaxis()->GetBinLowEdge(j);
    float upEdgePt = h->GetYaxis()->GetBinUpEdge(j);

    auto sel = [lowEdgePt, upEdgePt](float pt) { return (pt >lowEdgePt && pt<upEdgePt);};


    TH3weightsHelper helperHelXsecs(std::string("pt_")+std::to_string(j)+std::string("_helXsecs"), std::string("pt_")+std::to_string(j)+std::string("_helXsecs"), nBinsEta, etaArr, nBinsPt, ptArr, nBinsY, yArr, helXsecs);
    auto htmp = dFit.Filter(sel, {"Wpt_preFSR"}).Book<float, float,  float, ROOT::VecOps::RVec<float>>(std::move(helperHelXsecs), { "Mueta_preFSR" ,"Mupt_preFSR", "Wrap_preFSR_abs", "harmonicsWeights"});
    _h3Group.push_back(htmp);

  }

  return dFit;
  
  }

std::vector<ROOT::RDF::RResultPtr<TH1D>> templateBuilder::getTH1(){ 
    return _h1List;
}
std::vector<ROOT::RDF::RResultPtr<TH2D>> templateBuilder::getTH2(){ 
    return _h2List;
}
std::vector<ROOT::RDF::RResultPtr<TH3D>> templateBuilder::getTH3(){ 
    return _h3List;
}

std::vector<ROOT::RDF::RResultPtr<std::vector<TH1D>>> templateBuilder::getGroupTH1(){ 
  return _h1Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH2D>>> templateBuilder::getGroupTH2(){ 
  return _h2Group;
}
std::vector<ROOT::RDF::RResultPtr<std::vector<TH3D>>> templateBuilder::getGroupTH3(){ 
  return _h3Group;
}

void templateBuilder::reset(){
    
    _h1List.clear();
    _h2List.clear();
    _h3List.clear();

    _h1Group.clear();
    _h2Group.clear();
    _h3Group.clear();

}