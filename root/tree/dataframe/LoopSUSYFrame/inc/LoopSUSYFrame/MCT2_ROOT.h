#include "LoopSUSYFrame/MCT2.h"
#include "TLorentzVector.h"
#include <stdlib.h>
#include <stdio.h>

/*
===========================================================================
This is a class for computing (asymmetric) MCT2 using the bisection method. 
Created: October 17, 2014
Author: Christopher Lester
Maintainers: Christopher Lester (lester@hep.phy.cam.ac.uk) and Benjamin Nachman (bnachman@cern.ch)
===========================================================================

===============
Instructions:
===============

For TLorentzVectors visa, visb, metp (the visible momenta and the vector sum of the missed 
particles) an for trial masses ma and mb, 

ComputeMCT2 mct2class = ComputeMCT2(visa,visb,metp,0.,80.);
double mct2 = mct2class.Compute();

you can also do something like

ComputeMCT2 mct2class = ComputeMCT2(visa,visb,metp,"Wboson","Neutrino");
double mct2 = mct2class.Compute();

to use the W boson and neutrino masses as trial masses.  If you use a name that
is not in the database, it will list them for you and quit the program.

If you want to know the actual values of the missing particle momenta that minimize MCT2, you can do
std::pair <double,double> sols = mct2class.get_solutions();
double solution1 = sols.first;
double solution2 = sols.first;

*/

class ComputeMCT2 {
 public:
  double particletype(TString part);
  void listparticles();
  ComputeMCT2(TLorentzVector visa, TLorentzVector visb, TLorentzVector MET, double ma=0., double mb=0.);
  ComputeMCT2(TLorentzVector visa, TLorentzVector visb, TLorentzVector MET, TString name1, TString name2){
    if (particletype(name1) >= 0 && particletype(name2) >= 0){
      Init(visa, visb, MET, particletype(name1), particletype(name2));
    }
    else{
      std::cout << "MCT2 Error: the particle names you give are not on the list (or have the wrong syntax)!" << std::endl;
      std::cout << "Choices are: " << std::endl;
      listparticles();
      exit(1);
    }
  }    
  ~ComputeMCT2();
  double Compute() ;
  std::pair <double,double> get_solutions(){
    if (myMCT2 < 0){
      std::cout << "MCT2 Error: You have not yet run MCT2!" << std::endl;
      exit(1);   
    } 
    else{
      std::pair <double,double> out =  ben_findsolsMCT2(myMCT2, V1.Px(), V1.Py(), V1.M(), Ma, V2.Px(), V2.Py(), ET.Px(), ET.Py(), V2.M(),  Mb);
      return out;
    }
  }
 private:
  void Init(TLorentzVector visa, TLorentzVector visb, TLorentzVector MET, double ma, double mb);
  TLorentzVector V1;
  TLorentzVector V2;
  TLorentzVector ET;
  double Ma;
  double Mb;
  double myMCT2;
  double sol1;
  double sol2; 
};

ComputeMCT2::ComputeMCT2(TLorentzVector visa, TLorentzVector visb, TLorentzVector MET, double ma, double mb) {
  
  Init(visa, visb, MET, ma, mb);

}

void ComputeMCT2::Init(TLorentzVector visa, TLorentzVector visb, TLorentzVector MET, double ma, double mb) {
  
  if (V1.M() < 0 || V2.M() < 0){
    std::cout << "MCT2 Error: Your input particles have negative mass" << std::endl;
    exit(1);
  }

  V1 = visa;
  V2 = visb;
  ET = MET;
  Ma = ma;
  Mb = mb;
  myMCT2 = -1;
  sol1 = -1;
  sol2 = -1;

}

ComputeMCT2::~ComputeMCT2() {
}

double ComputeMCT2::Compute()  {

    myMCT2 = asymm_mct2_lester_bisect::get_mCT2(V1.M(),V1.Px(),V1.Py(),V2.M(),V2.Px(),V2.Py(),ET.Px(),ET.Py(),Ma,Mb);
    sol1 = 0;
    sol2 = 0;
    return myMCT2;

}

double ComputeMCT2::particletype(TString part){

  if (part == "Wboson_PDG2014_GeV") return 80.385;
  if (part == "Neutrino") return 0;
  if (part == "Top_PDG2014_GeV") return 173.21;
  if (part == "Lepton") return 0.;
  return -1;

}

void ComputeMCT2::listparticles(){
  std::cout << "Wboson_PDG2014_GeV, mass = 80.385 GeV" << std::endl;
  std::cout << "Neutrino, mass = 0 GeV" << std::endl;
  std::cout << "Top_PDG2014_GeV, mass = 173.21 GeV" << std::endl;
  std::cout << "Lepton, mass = 0 GeV" << std::endl;
}


