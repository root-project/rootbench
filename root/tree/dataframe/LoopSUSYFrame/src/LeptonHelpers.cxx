#include <LoopSUSYFrame/LeptonHelpers.h>
#include <LoopSUSYFrame/MT2_ROOT.h>
#include <LoopSUSYFrame/MCT2_ROOT.h>
#include <stdint.h>

#include <ROOT/RVec.hxx>

#include <algorithm>
#include <cmath>
#include <vector>

// Some Helper Functions
std::vector<std::string> GetLeptonBranches(const bool isdata, const std::string &) {

	std::vector<std::string> branches;

	if (isdata) branches = {"ptleptons", "etaleptons", "flavlep", "passORlep", "isSignallep"};
	else  branches = {"ptleptons", "etaleptons", "flavlep", "passORlep", "isSignallep", "Originlep", "ChannelNumber"};

	return branches;
}

std::vector<std::string> GetLeptonBranchesTest(const bool isdata, const std::string &, const std::string isSignallepTest) {

	std::vector<std::string> branches;

	if (isdata) branches = {"ptleptons", "etaleptons", "flavlep", "passORlep", isSignallepTest};
	else  branches = {"ptleptons", "etaleptons", "flavlep", "passORlep", isSignallepTest, "Originlep", "ChannelNumber"};

	return branches;
}

std::vector<std::string> GetCustomLeptonBranches(const bool isdata, const std::string &) {

  std::vector<std::string> branches;

  if (isdata) branches = {"ptleptons", "etaleptons", "flavlep", "passORlep","isSignallep" , "isMediumlep", "LepIsoFCLoose", "d0sig"};
  else  branches = {"ptleptons", "etaleptons", "flavlep", "passORlep", "isSignallep", "Originlep", "isMediumlep", "LepIsoFCLoose", "d0sig", "ChannelNumber"};
  //  else  branches = {"ptleptons", "etaleptons", "flavlep", "passORlep", "isSignallep", "Originlep", "isMediumlep", "d0sig", "ChannelNumber"};



  return branches;
}



std::pair<std::array<float, 4>, std::array<short unsigned int, 3>> ClosestMllVars(const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec, const ROOT::VecOps::RVec<int> &flavlep)
{

	const float mZ = 91200.;
	float closest_mll = -1;
	float closest_ptll = -1.;
	float closest_dphill = -1.;
	float closest_phi = -10.;

	short unsigned int flavZ = 0;
	short unsigned int matchZ1 = 0;
	short unsigned int matchZ2 = 0;

	for (UInt_t id1 = 0; id1 < idxs.size(); id1++) {

		short unsigned int ilep = idxs[id1];

		TLorentzVector lep1;
		lep1.SetPtEtaPhiM(ptvec[ilep], etavec[ilep], phivec[ilep], massvec[ilep]);

		for (UInt_t id2 = id1 + 1; id2 < idxs.size(); id2++) {

			short unsigned int ilep2 = idxs[id2];

			TLorentzVector lep2;
			lep2.SetPtEtaPhiM(ptvec[ilep2], etavec[ilep2], phivec[ilep2], massvec[ilep2]);
			float mll_12 = (lep1 + lep2).M();
			int isOS_12 = flavlep[ilep] * flavlep[ilep2];
			if ( isOS_12 < 0 && fabs(flavlep[ilep]) == fabs(flavlep[ilep2]) && ((fabs(mll_12 - mZ) < fabs(closest_mll - mZ)) || (closest_mll == -1)) ) {

				closest_mll = mll_12;
				closest_ptll = (lep1 + lep2).Perp();
				closest_dphill = fabs(lep1.DeltaPhi(lep2));
				closest_phi = (lep1 + lep2).Phi();
				flavZ = fabs(flavlep[ilep]);
				matchZ1 = ilep;
				matchZ2 = ilep2;

			}
		}
	}

	if ( flavZ == 0 ) {
		for (UInt_t id1 = 0; id1 < idxs.size(); id1++) {

			short unsigned int ilep = idxs[id1];

			TLorentzVector lep1;
			lep1.SetPtEtaPhiM(ptvec[ilep], etavec[ilep], phivec[ilep], massvec[ilep]);

			for (UInt_t id2 = id1; id2 < idxs.size(); id2++) {

				short unsigned int ilep2 = idxs[id2];
				if ( ilep == ilep2 ) continue;

				TLorentzVector lep2;
				lep2.SetPtEtaPhiM(ptvec[ilep2], etavec[ilep2], phivec[ilep2], massvec[ilep2]);
				float mll_12 = (lep1 + lep2).M();
				if ( fabs(flavlep[ilep]) != fabs(flavlep[ilep2]) && ((fabs(mll_12 - mZ) < fabs(closest_mll - mZ)) || (closest_mll == -1)) ) {

					closest_mll = mll_12;
					closest_ptll = (lep1 + lep2).Perp();
					closest_dphill = fabs(lep1.DeltaPhi(lep2));
					closest_phi = (lep1 + lep2).Phi();
					matchZ1 = ilep;
					matchZ2 = ilep2;

				}
			}
		}
	}

	// std::cout<<closest_mll<<" FINE"<<std::endl; 

	std::array<float, 4> the_vars = {(float)closest_mll/(float)1000., (float)closest_ptll/(float)1000., closest_dphill, closest_phi};
	std::array<short unsigned int, 3> the_indices = {matchZ1, matchZ2, flavZ};

	std::pair<std::array<float, 4>, std::array<short unsigned int, 3>> the_pair = std::make_pair(the_vars, the_indices);
	return the_pair;

}

int GetNotMatchLepIdx(const short unsigned int lep1_idx, 
						const short unsigned int lep2_idx,
						const short unsigned int lep3_idx,
						const int match1_idx, const int match2_idx)
{
	
	int noMatch = -1;
	if (match1_idx == lep1_idx) {
		if(match2_idx == lep2_idx) noMatch = lep3_idx;
		else noMatch = lep2_idx;
	}
	else if(match2_idx == lep1_idx) {
		if(match1_idx == lep2_idx) noMatch = lep3_idx;
		else noMatch = lep2_idx;
	}
	else noMatch = lep1_idx;

	//std::cout << "noMatch " << noMatch << std::endl;

	return noMatch;

}

std::array<short unsigned int, 2>  GetNotMatchLepIdx4lep(
						  const int nlep,
						  const short unsigned int lep1_idx, 
						  const short unsigned int lep2_idx,
						  const short unsigned int lep3_idx,
						  const short unsigned int lep4_idx,
						  const short unsigned int match1_idx, 
						  const short unsigned int match2_idx)
{
	short unsigned int noMatch1 = -1 , noMatch2 = -1;
	if(nlep==4){
		// std::cout<<"4 lep --> "<<match1_idx<<" "<<match2_idx<<" "<<std::endl;
		if ((match1_idx == lep1_idx && match2_idx == lep2_idx) || (match2_idx == lep1_idx && match1_idx == lep2_idx)) {noMatch1=lep3_idx; noMatch2=lep4_idx;}
		if ((match1_idx == lep1_idx && match2_idx == lep3_idx) || (match2_idx == lep1_idx && match1_idx == lep3_idx)) {noMatch1=lep2_idx; noMatch2=lep4_idx;}
		if ((match1_idx == lep1_idx && match2_idx == lep4_idx) || (match2_idx == lep1_idx && match1_idx == lep4_idx)) {noMatch1=lep2_idx; noMatch2=lep3_idx;}
		if ((match1_idx == lep2_idx && match2_idx == lep3_idx) || (match2_idx == lep2_idx && match1_idx == lep3_idx)) {noMatch1=lep1_idx; noMatch2=lep4_idx;}
		if ((match1_idx == lep2_idx && match2_idx == lep4_idx) || (match2_idx == lep2_idx && match1_idx == lep4_idx)) {noMatch1=lep1_idx; noMatch2=lep3_idx;}
		if ((match1_idx == lep3_idx && match2_idx == lep4_idx) || (match2_idx == lep3_idx && match1_idx == lep4_idx)) {noMatch1=lep1_idx; noMatch2=lep2_idx;}
		// std::cout<<"No Matched --> "<<noMatch[0]<<" "<<noMatch[1]<<" "<<std::endl;
	}
	else if(nlep==3){
		// std::cout<<"3 lep --> "<<match1_idx<<" "<<match2_idx<<" "<<std::endl;
		if ((match1_idx == lep1_idx && match2_idx == lep2_idx) || (match2_idx == lep1_idx && match1_idx == lep2_idx)) {noMatch1=lep3_idx; noMatch2=lep4_idx;}
		if ((match1_idx == lep1_idx && match2_idx == lep3_idx) || (match2_idx == lep1_idx && match1_idx == lep3_idx)) {noMatch1=lep2_idx; noMatch2=lep4_idx;}
		if ((match1_idx == lep2_idx && match2_idx == lep3_idx) || (match2_idx == lep2_idx && match1_idx == lep3_idx)) {noMatch1=lep1_idx; noMatch2=lep4_idx;}
		// std::cout<<"No Matched --> "<<noMatch[0]<<" "<<noMatch[1]<<" "<<std::endl;
	}
	std::array<short unsigned int, 2> noMatch = {noMatch1, noMatch2};

	// std::cout<<"--> "<<noMatch[0]<<" "<<noMatch[1]<<" "<<std::endl;
	
	return noMatch;
}


int WhichBin3L(const int flav12, const int flav3) {
	//Number scheme of the myhistos bins
	int bin = 0;
	if (fabs(flav12) == 11 && fabs(flav3) == 11) bin = 1; //eee
	if (fabs(flav12) == 11 && fabs(flav3) == 13) bin = 2; //eem
	if (fabs(flav12) == 13 && fabs(flav3) == 11) bin = 3; //mme
	if (fabs(flav12) == 13 && fabs(flav3) == 13) bin = 4; //mmm
	if (flav12 == 0) bin = 5; //DF events for VRF
	return bin;
}

int WhichBin(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<int> &flavlep) {
	//Number scheme of the myhistos bins
	int bin = 0;
	if (fabs(flavlep[lep1_idx]) == 11 && fabs(flavlep[lep2_idx]) == 11) bin = 1; //ee
	if (fabs(flavlep[lep1_idx]) == 11 && fabs(flavlep[lep2_idx]) == 13) bin = 2; //em
	if (fabs(flavlep[lep1_idx]) == 13 && fabs(flavlep[lep2_idx]) == 11) bin = 3; //me
	if (fabs(flavlep[lep1_idx]) == 13 && fabs(flavlep[lep2_idx]) == 13) bin = 4; //mm
	return bin;
}

std::array<bool, 2> isOS_isSF(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<int> &flavlep) {
	bool isOS = false;
	if (lep1_idx==65535 || lep2_idx==65535) {
		// std::cout<<lep1_idx<<" "<<lep2_idx<<std::endl; 
		return {false,false};
		}
	if (flavlep[lep1_idx]*flavlep[lep2_idx] < 0) isOS = true; //ee
	bool isSF = false;
	if (fabs(flavlep[lep1_idx]) == 11 && fabs(flavlep[lep2_idx]) == 11) isSF = true; //ee
	if (fabs(flavlep[lep1_idx]) == 11 && fabs(flavlep[lep2_idx]) == 13) isSF = false; //em
	if (fabs(flavlep[lep1_idx]) == 13 && fabs(flavlep[lep2_idx]) == 11) isSF = false; //me
	if (fabs(flavlep[lep1_idx]) == 13 && fabs(flavlep[lep2_idx]) == 13) isSF = true; //mm

	return {isOS,isSF};
}

int EventType(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx,  const short unsigned int match1_idx,  const short unsigned int match2_idx,  const short unsigned int flavZ, const ROOT::VecOps::RVec<int> &flavlep)
{
	int bin = 0;
	int flavlep1 = flavlep[lep1_idx];
	int flavlep2 = flavlep[lep2_idx];
	int flavlep3 = flavlep[lep3_idx];

	if ((lep1_idx == match1_idx || lep1_idx == match2_idx) && (lep2_idx == match1_idx || lep2_idx == match2_idx)) bin = WhichBin3L(flavZ, flavlep3);
	if ((lep1_idx == match1_idx || lep1_idx == match2_idx) && (lep3_idx == match1_idx || lep3_idx == match2_idx)) bin = WhichBin3L(flavZ, flavlep2);
	if ((lep2_idx == match1_idx || lep2_idx == match2_idx) && (lep3_idx == match1_idx || lep3_idx == match2_idx)) bin = WhichBin3L(flavZ, flavlep1);
	return bin;
}

float GetMT2( 	const short unsigned int lep1_idx,
                const short unsigned int lep2_idx,
                const ROOT::VecOps::RVec<float> &pt,
                const ROOT::VecOps::RVec<float> &eta,
                const ROOT::VecOps::RVec<float> &phi,
                const ROOT::VecOps::RVec<float> &mass,
                const float MET,
                const float METphi)
{
	if(lep2_idx == 65535 || lep1_idx == 65535) return -1.;

	TLorentzVector lep1, lep2;
	lep1.SetPtEtaPhiM(pt[lep1_idx], eta[lep1_idx], phi[lep1_idx], mass[lep1_idx]);
	lep2.SetPtEtaPhiM(pt[lep2_idx], eta[lep2_idx], phi[lep2_idx], mass[lep2_idx]);
	TLorentzVector Etmiss;
	Etmiss.SetPtEtaPhiM(MET*1000., 0., METphi, 0.);
	ComputeMT2 mycalc = ComputeMT2(lep1, lep2, Etmiss, 0., 0.);
	float MT2 = mycalc.Compute() / 1000.;
	return MT2;

}
float GetMCT2(   const short unsigned int lep1_idx,
                const short unsigned int lep2_idx,
		const ROOT::VecOps::RVec<float> &pt,
                const ROOT::VecOps::RVec<float> &eta,
		const ROOT::VecOps::RVec<float> &phi,
                const ROOT::VecOps::RVec<float> &mass,
                const float MET,
		const float METphi)
{
  TLorentzVector lep1, lep2;
  lep1.SetPtEtaPhiM(pt[lep1_idx], eta[lep1_idx], phi[lep1_idx], mass[lep1_idx]);
  lep2.SetPtEtaPhiM(pt[lep2_idx], eta[lep2_idx], phi[lep2_idx], mass[lep2_idx]);
  TLorentzVector Etmiss;
  Etmiss.SetPtEtaPhiM(MET*1000., 0., METphi, 0.);
  ComputeMCT2 mycalc = ComputeMCT2(lep1, lep2, Etmiss, 100.*1000., 100.*1000.); //Assuming trial masses = 100 GeV
  float MCT2 = mycalc.Compute() / 1000.;
  return MCT2;

}
float GetMT2_heavyParticles(   const short unsigned int lep1_idx,
                const short unsigned int lep2_idx,
		const ROOT::VecOps::RVec<float> &pt,
		const ROOT::VecOps::RVec<float> &eta,
		const ROOT::VecOps::RVec<float> &phi,
		const ROOT::VecOps::RVec<float> &mass,
		const float MET,
		const float METphi,
	        const double mtrial1 = 0., 
		const double mtrial2 = 0.)
{
  TLorentzVector lep1, lep2;
  lep1.SetPtEtaPhiM(pt[lep1_idx], eta[lep1_idx], phi[lep1_idx], mass[lep1_idx]);
  lep2.SetPtEtaPhiM(pt[lep2_idx], eta[lep2_idx], phi[lep2_idx], mass[lep2_idx]);
  TLorentzVector Etmiss;
  Etmiss.SetPtEtaPhiM(MET*1000., 0., METphi, 0.);
  ComputeMT2 mycalc = ComputeMT2(lep1, lep2, Etmiss, mtrial1*1000., mtrial2*1000.); //trial masses for the invisible particles
  float MT2 = mycalc.Compute() / 1000.;
  return MT2;

}

float GetMT2_3l( 	const short unsigned int lep1_idx,
                    const short unsigned int lep2_idx,
                    const short unsigned int lep3_idx,
                    const short unsigned int match1_idx,
                    const short unsigned int match2_idx,
                    const ROOT::VecOps::RVec<float> &pt,
                    const ROOT::VecOps::RVec<float> &eta,
                    const ROOT::VecOps::RVec<float> &phi,
                    const ROOT::VecOps::RVec<float> &mass,
                    const float MET,
                    const float METphi)
{

	TLorentzVector lep1, lep2, lep3, Z, empty;
	if (lep1_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	else if (lep1_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);

	if (lep2_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
	else if (lep2_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);

	if (lep3_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
	else if (lep3_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);

	Z = lep1 + lep2;
	TLorentzVector Etmiss;
	Etmiss.SetPtEtaPhiM(MET, 0., METphi, 0.);

	empty.SetPtEtaPhiM(0, 0, 0, 0);

	//std::cout << "pt Z " << Z.Pt() << " mZ " << Z.M() << std::endl;
	//std::cout << "pt lep3 " << lep3.Pt() << " m lep3 " << lep3.M() << std::endl;



	ComputeMT2 mycalc = ComputeMT2(Z, lep3, Etmiss, 0., 0.);
	float MT2 = mycalc.Compute();

	if (MT2 < 90.) MT2 = 90.;
	return MT2;

}

float Get_aMT2_3l( 	const short unsigned int lep1_idx,
                    const short unsigned int lep2_idx,
                    const short unsigned int lep3_idx,
                    const short unsigned int match1_idx,
                    const short unsigned int match2_idx,
                    const ROOT::VecOps::RVec<float> &pt,
                    const ROOT::VecOps::RVec<float> &eta,
                    const ROOT::VecOps::RVec<float> &phi,
                    const ROOT::VecOps::RVec<float> &mass,
                    const float MET,
                    const float METphi,
                    const std::vector<short unsigned int>  jet_idx,
                    const std::vector<short unsigned int>  bjet_idx,
                    const ROOT::VecOps::RVec<float> &jet_pt,
                    const ROOT::VecOps::RVec<float> &jet_eta,
                    const ROOT::VecOps::RVec<float> &jet_phi,
                    const ROOT::VecOps::RVec<float> &jet_mass)
{

	TLorentzVector lep1, lep2, lep3, Z, jet1, jet2, jet1lep, jet2lep;

	if (lep1_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	else if (lep1_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);

	if (lep2_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
	else if (lep2_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);

	if (lep3_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
	else if (lep3_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);

	Z = lep1 + lep2;

	jet1.SetPtEtaPhiM(jet_pt[bjet_idx[0]] / 1000., jet_eta[bjet_idx[0]], jet_phi[bjet_idx[0]], jet_mass[bjet_idx[0]] / 1000);

	if (bjet_idx.size() > 1) jet2.SetPtEtaPhiM(jet_pt[bjet_idx[1]] / 1000., jet_eta[bjet_idx[1]], jet_phi[bjet_idx[1]], jet_mass[bjet_idx[1]] / 1000);
	else {
		if (jet_idx[0] != bjet_idx[0]) jet2.SetPtEtaPhiM(jet_pt[jet_idx[0]] / 1000., jet_eta[jet_idx[0]], jet_phi[jet_idx[0]], jet_mass[jet_idx[0]] / 1000);
		else jet2.SetPtEtaPhiM(jet_pt[jet_idx[1]] / 1000., jet_eta[jet_idx[1]], jet_phi[jet_idx[1]], jet_mass[jet_idx[1]] / 1000);
	}

	jet1lep = jet1 + lep3;
	jet2lep = jet2 + lep3;

	TLorentzVector Etmiss;
	Etmiss.SetPtEtaPhiM(MET, 0., METphi, 0.);
	Etmiss = Etmiss + Z;

	//std::cout << "pt jet1lep " << jet1lep.Pt() << " mjet1lep " << jet1lep.M() << std::endl;
	//std::cout << "pt jet2 " << jet2.Pt() << " m jet2 " << jet2.M() << std::endl;
	//std::cout << "pt jet1 " << jet1.Pt() << " m jet1 " << jet1.M() << std::endl;


	ComputeMT2 mycalc1 = ComputeMT2(jet1lep, jet2, Etmiss, 0., 0.);
	float MT2 = mycalc1.Compute();


	ComputeMT2 mycalc2 = ComputeMT2(jet2lep, jet1, Etmiss, 0., 0.);
	float MT2_2 = mycalc2.Compute();

	if (MT2_2 < MT2) MT2 = MT2_2;

	return MT2;

}

float Get_ugo( 	const short unsigned int lep1_idx,
                    const short unsigned int lep2_idx,
                    const short unsigned int lep3_idx,
                    const short unsigned int match1_idx,
                    const short unsigned int match2_idx,
                    const ROOT::VecOps::RVec<float> &pt,
                    const ROOT::VecOps::RVec<float> &eta,
                    const ROOT::VecOps::RVec<float> &phi,
                    const ROOT::VecOps::RVec<float> &mass,
                    const float MET,
                    const float METphi,
                    const std::vector<short unsigned int>  jet_idx,
                    const std::vector<short unsigned int>  bjet_idx,
                    const ROOT::VecOps::RVec<float> &jet_pt,
                    const ROOT::VecOps::RVec<float> &jet_eta,
                    const ROOT::VecOps::RVec<float> &jet_phi,
                    const ROOT::VecOps::RVec<float> &jet_mass)
{

	TLorentzVector lep1, lep2, lep3, Z, jet1, jet2, jet1Z, jet2Z;

	if (lep1_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	else if (lep1_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);

	if (lep2_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
	else if (lep2_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);

	if (lep3_idx == match1_idx) lep1.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
	else if (lep3_idx == match2_idx) lep2.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
	else lep3.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);

	Z = lep1 + lep2;

	jet1.SetPtEtaPhiM(jet_pt[bjet_idx[0]] / 1000., jet_eta[bjet_idx[0]], jet_phi[bjet_idx[0]], jet_mass[bjet_idx[0]] / 1000);

	if (bjet_idx.size() > 1) jet2.SetPtEtaPhiM(jet_pt[bjet_idx[1]] / 1000., jet_eta[bjet_idx[1]], jet_phi[bjet_idx[1]], jet_mass[bjet_idx[1]] / 1000);
	else {
		if (jet_idx[0] != bjet_idx[0]) jet2.SetPtEtaPhiM(jet_pt[jet_idx[0]] / 1000., jet_eta[jet_idx[0]], jet_phi[jet_idx[0]], jet_mass[jet_idx[0]] / 1000);
		else jet2.SetPtEtaPhiM(jet_pt[jet_idx[1]] / 1000., jet_eta[jet_idx[1]], jet_phi[jet_idx[1]], jet_mass[jet_idx[1]] / 1000);
	}

	jet1Z = jet1 + Z;
	jet2Z = jet2 + Z;

	TLorentzVector Etmiss;
	Etmiss.SetPtEtaPhiM(MET, 0., METphi, 0.);
	Etmiss = Etmiss + lep3;

	//std::cout << "pt jet1lep " << jet1lep.Pt() << " mjet1lep " << jet1lep.M() << std::endl;
	//std::cout << "pt jet2 " << jet2.Pt() << " m jet2 " << jet2.M() << std::endl;
	//std::cout << "pt jet1 " << jet1.Pt() << " m jet1 " << jet1.M() << std::endl;


	ComputeMT2 mycalc1 = ComputeMT2(jet1Z, jet2, Etmiss, 0., 0.);
	float ugo = mycalc1.Compute();


	ComputeMT2 mycalc2 = ComputeMT2(jet2Z, jet1, Etmiss, 0., 0.);
	float ugo_2 = mycalc2.Compute();

	if (ugo_2 < ugo) ugo = ugo_2;

	return ugo;

}

float Get_aMT2( 	const short unsigned int lep1_idx,
                    const short unsigned int lep2_idx,
                    const short unsigned int lep3_idx,
                    const short unsigned int match1_idx,
                    const short unsigned int match2_idx,
                    const ROOT::VecOps::RVec<float> &pt,
                    const ROOT::VecOps::RVec<float> &eta,
                    const ROOT::VecOps::RVec<float> &phi,
                    const ROOT::VecOps::RVec<float> &mass,
                    const float MET,
                    const float METphi,
                    const std::vector<short unsigned int>  jet_idx,
                    const std::vector<short unsigned int>  bjet_idx,
                    const ROOT::VecOps::RVec<float> &jet_pt,
                    const ROOT::VecOps::RVec<float> &jet_eta,
                    const ROOT::VecOps::RVec<float> &jet_phi,
                    const ROOT::VecOps::RVec<float> &jet_mass)
{

	TLorentzVector lep, jet1, jet2, jet1lep, jet2lep;

	if (lep1_idx == match1_idx) {
		if (lep2_idx == match2_idx) lep.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
		else lep.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
	}
	else if (lep2_idx == match1_idx)
	{
		if (lep1_idx == match2_idx) lep.SetPtEtaPhiM(pt[lep3_idx] / 1000., eta[lep3_idx], phi[lep3_idx], mass[lep3_idx] / 1000);
		else lep.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	}
	else if (lep3_idx == match1_idx)
	{
		if (lep1_idx == match2_idx) lep.SetPtEtaPhiM(pt[lep2_idx] / 1000., eta[lep2_idx], phi[lep2_idx], mass[lep2_idx] / 1000);
		else lep.SetPtEtaPhiM(pt[lep1_idx] / 1000., eta[lep1_idx], phi[lep1_idx], mass[lep1_idx] / 1000);
	}

	jet1.SetPtEtaPhiM(jet_pt[bjet_idx[0]] / 1000., jet_eta[bjet_idx[0]], jet_phi[bjet_idx[0]], jet_mass[bjet_idx[0]] / 1000);

	if (bjet_idx.size() > 1) jet2.SetPtEtaPhiM(jet_pt[bjet_idx[1]] / 1000., jet_eta[bjet_idx[1]], jet_phi[bjet_idx[1]], jet_mass[bjet_idx[1]] / 1000);
	else {
		if (jet_idx[0] != bjet_idx[0]) jet2.SetPtEtaPhiM(jet_pt[jet_idx[0]] / 1000., jet_eta[jet_idx[0]], jet_phi[jet_idx[0]], jet_mass[jet_idx[0]] / 1000);
		else jet2.SetPtEtaPhiM(jet_pt[jet_idx[1]] / 1000., jet_eta[jet_idx[1]], jet_phi[jet_idx[1]], jet_mass[jet_idx[1]] / 1000);
	}

	jet1lep = jet1 + lep;
	jet2lep = jet2 + lep;

	TLorentzVector Etmiss;
	Etmiss.SetPtEtaPhiM(MET, 0., METphi, 0.);


	//std::cout << "pt jet1lep " << jet1lep.Pt() << " mjet1lep " << jet1lep.M() << std::endl;
	//std::cout << "pt jet2 " << jet2.Pt() << " m jet2 " << jet2.M() << std::endl;
	//std::cout << "pt jet1 " << jet1.Pt() << " m jet1 " << jet1.M() << std::endl;

	ComputeMT2 mycalc1 = ComputeMT2(jet1lep, jet2, Etmiss, 0., 0.);
	float MT2 = mycalc1.Compute();


	ComputeMT2 mycalc2 = ComputeMT2(jet2lep, jet1, Etmiss, 0., 0.);
	float MT2_2 = mycalc2.Compute();

	if (MT2_2 < MT2) MT2 = MT2_2;

	return MT2;

}

float GetPbllMOD(
        const short unsigned int lep1_idx,
        const short unsigned int lep2_idx,
        const ROOT::VecOps::RVec<float> &pt,
        const ROOT::VecOps::RVec<float> &,
        const ROOT::VecOps::RVec<float> &phi,
        const float MET,
        const float METphi)
{
    float plepx1=pt[lep1_idx]*cos(phi[lep1_idx]);
    float plepx2=pt[lep2_idx]*cos(phi[lep2_idx]);
    float plepy1=pt[lep1_idx]*sin(phi[lep1_idx]);
    float plepy2=pt[lep2_idx]*sin(phi[lep2_idx]);

    TVector2 pbll;
    pbll.Set(MET*cos(METphi)+plepx1+plepx2, MET*sin(METphi)+plepy1+plepy2);
    float pbllmod = pbll.Mod();
    return pbllmod;
}

float GetPhiMetPbll(
        const short unsigned int lep1_idx,
        const short unsigned int lep2_idx,
        const ROOT::VecOps::RVec<float> &pt,
        const ROOT::VecOps::RVec<float> &,
        const ROOT::VecOps::RVec<float> &phi,
        const float MET,
        const float METphi)
{
    float plepx1=pt[lep1_idx]*cos(phi[lep1_idx]);
    float plepx2=pt[lep2_idx]*cos(phi[lep2_idx]);
    float plepy1=pt[lep1_idx]*sin(phi[lep1_idx]);
    float plepy2=pt[lep2_idx]*sin(phi[lep2_idx]);

    TVector2 ptm, pbll;
    pbll.Set(MET*cos(METphi)+plepx1+plepx2, MET*sin(METphi)+plepy1+plepy2);
    ptm.Set(MET*cos(METphi),MET*sin(METphi));
    float DPhiMetPbll = std::fabs(ptm.DeltaPhi(pbll));
    return DPhiMetPbll;
}
