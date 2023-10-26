#ifndef LEPTON_HELPERS_H
#define LEPTON_HELPERS_H
#include <ROOT/RVec.hxx>
#include <TLorentzVector.h>
#include <TH2D.h>
#include <TString.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <exception>
#include <regex>
#include <map>

// Some Helper Functions for leptons

std::pair<std::array<float, 4>, std::array<short unsigned int, 3>> ClosestMllVars(const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, const ROOT::VecOps::RVec<int> &flavlep);

// WhichBin function for 2L events
int WhichBin(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<int> &flavlep);
// WhichBin function for 3L events (2L SF)
int WhichBin3L(const int flav12, const int flav3);

int EventType(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx, const short unsigned int match1_idx, const short unsigned int match2_idx, const short unsigned int flavZ, const ROOT::VecOps::RVec<int> &flavlep);

float GetMT2(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &phi, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &mass, const float MET, const float METphi);
float GetMCT2(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &phi, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &mass, const float MET, const float METphi);
float GetMT2_heavyParticles(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &phi, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &mass, const float MET, const float METphi, const double mtrial1, const double mtrial2);
float GetPbllMOD(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &phi, const float MET, const float METphi);
float GetPhiMetPbll(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &phi, const float MET, const float METphi);
std::array<bool, 2> isOS_isSF(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<int> &flavlep);

int GetNotMatchLepIdx(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx, const short unsigned int match1_idx, const short unsigned int match2_idx);

std::array<short unsigned int, 2> GetNotMatchLepIdx4lep(const int nlep, const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx, const short unsigned int lep4_idx, const short unsigned int match1_idx, const short unsigned int match2_idx);

float GetMT2_3l(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx, const short unsigned int match1_idx, const short unsigned int match2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &phi, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &mass, const float MET, const float METphi);

float Get_aMT2(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx, const short unsigned int match1_idx, const short unsigned int match2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &phi, const ROOT::VecOps::RVec<float> &mass, const float MET, const float METphi, const std::vector<short unsigned int> jet_idx, const std::vector<short unsigned int> bjet_idx, const ROOT::VecOps::RVec<float> &jet_pt, const ROOT::VecOps::RVec<float> &jet_eta, const ROOT::VecOps::RVec<float> &jet_phi, const ROOT::VecOps::RVec<float> &jet_mass);

float Get_aMT2_3l(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx, const short unsigned int match1_idx, const short unsigned int match2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &phi, const ROOT::VecOps::RVec<float> &mass, const float MET, const float METphi, const std::vector<short unsigned int> jet_idx, const std::vector<short unsigned int> bjet_idx, const ROOT::VecOps::RVec<float> &jet_pt, const ROOT::VecOps::RVec<float> &jet_eta, const ROOT::VecOps::RVec<float> &jet_phi, const ROOT::VecOps::RVec<float> &jet_mass);

float Get_ugo(const short unsigned int lep1_idx, const short unsigned int lep2_idx, const short unsigned int lep3_idx, const short unsigned int match1_idx, const short unsigned int match2_idx, const ROOT::VecOps::RVec<float> &pt, const ROOT::VecOps::RVec<float> &eta, const ROOT::VecOps::RVec<float> &phi, const ROOT::VecOps::RVec<float> &mass, const float MET, const float METphi, const std::vector<short unsigned int> jet_idx, const std::vector<short unsigned int> bjet_idx, const ROOT::VecOps::RVec<float> &jet_pt, const ROOT::VecOps::RVec<float> &jet_eta, const ROOT::VecOps::RVec<float> &jet_phi, const ROOT::VecOps::RVec<float> &jet_mass);

std::vector<std::string> GetLeptonBranches(const bool isdata, const std::string &syst);
std::vector<std::string> GetCustomLeptonBranches(const bool isdata, const std::string &syst);
std::vector<std::string> GetLeptonBranchesTest(const bool isdata, const std::string &syst, const std::string isSignallepTest);


namespace LambdaMaker
{

inline auto FindLeptons(const float ptelecut, const float ptmuocut)
{
	return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, const ROOT::VecOps::RVec<bool> &isSignallep) {
		std::vector<std::pair<float, short unsigned int>> the_leptons;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{

			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);
			
			if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
			{

				if (passORlep[ilep] == false)
					continue;
				if (isSignallep[ilep] == false)
					continue;

				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				the_leptons.push_back(new_lep);
			}
		}

		// sort indices by pT
		sort(the_leptons.rbegin(), the_leptons.rend());

		std::vector<short unsigned int> the_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
		{
			the_sorted_leptons.push_back(the_leptons[ilep].second);
		}

		//std::cout << "n good lep " << the_sorted_leptons.size() << std::endl;

		return the_sorted_leptons;
	};
}

inline auto FindLeptonsMC(const float ptelecut, const float ptmuocut)
{
	return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, const ROOT::VecOps::RVec<bool> &isSignallep, const ROOT::VecOps::RVec<int> &Originlep, const int ChannelNumber) {
		std::vector<std::pair<float, short unsigned int>> the_leptons;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{

			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);

			if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
			{

				if (passORlep[ilep] == false)
					continue;
				if (isSignallep[ilep] == false)
					continue;

				// select origin to avoid fakes double counting
				if (ChannelNumber == 410142 || ChannelNumber == 410144 || ChannelNumber == 364242 || ChannelNumber == 364243 || ChannelNumber == 364244 || ChannelNumber == 364245 || ChannelNumber == 364246 || ChannelNumber == 364247 || ChannelNumber == 364248 || ChannelNumber == 364249)
				{
					if (Originlep[ilep] != 10 && Originlep[ilep] != 0 && Originlep[ilep] != 12 && Originlep[ilep] != 13 && Originlep[ilep] != 14 && Originlep[ilep] != 43 && Originlep[ilep] != 22)
						continue;
				}
				else
				{
					if (Originlep[ilep] != 10 && Originlep[ilep] != 12 && Originlep[ilep] != 13 && Originlep[ilep] != 14 && Originlep[ilep] != 43 && Originlep[ilep] != 22)
						continue;
				}

				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				the_leptons.push_back(new_lep);
			}
		}

		// sort indices by pT
		sort(the_leptons.rbegin(), the_leptons.rend());

		std::vector<short unsigned int> the_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
		{
			the_sorted_leptons.push_back(the_leptons[ilep].second);
		}

		return the_sorted_leptons;
	};
}


 inline auto FindCustomSignalLeptons(const float ptelecut, const float ptmuocut)
 {
   return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, const ROOT::VecOps::RVec<bool> &isSignallep, const ROOT::VecOps::RVec<bool> &isMediumlep, const ROOT::VecOps::RVec<bool> &LepIsoFCLoose, const ROOT::VecOps::RVec<float> &d0sig) {
     std::vector<std::pair<float, short unsigned int>> the_leptons;

     for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
       {

         double ptlep = ptleptons[ilep];
         double etalep = std::fabs(etaleptons[ilep]);
         int flavlepton = int(flavlep[ilep]);



         if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
           {

             if (passORlep[ilep] == false)
               continue;
             if (std::fabs(flavlepton) == 13 && isSignallep[ilep] == false)
               continue;
             if (std::fabs(flavlepton) == 11 && isMediumlep[ilep] == false && LepIsoFCLoose[ilep] == false && d0sig[ilep] == false)
               continue;

	     std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
             the_leptons.push_back(new_lep);
           }
       }
     // sort indices by pT
     sort(the_leptons.rbegin(), the_leptons.rend());
     std::vector<short unsigned int> the_sorted_leptons;
     for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
       {
         the_sorted_leptons.push_back(the_leptons[ilep].second);
       }

     //std::cout << "n good lep " << the_sorted_leptons.size() << std::endl;

     return the_sorted_leptons;
   };
 }

 inline auto FindCustomLeptonsMC(const float ptelecut, const float ptmuocut)
 {
   return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, const ROOT::VecOps::RVec<bool> &isSignallep, const ROOT::VecOps::RVec<int> &Originlep, const ROOT::VecOps::RVec<bool> &isMediumlep, const ROOT::VecOps::RVec<bool> &LepIsoFCLoose, const ROOT::VecOps::RVec<float> &d0sig, const int ChannelNumber) {
     std::vector<std::pair<float, short unsigned int>> the_leptons;

     for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
       {

         double ptlep = ptleptons[ilep];
         double etalep = std::fabs(etaleptons[ilep]);
         int flavlepton = int(flavlep[ilep]);

	 if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
           {

             if (passORlep[ilep] == false)
               continue;
             if (std::fabs(flavlepton) == 13 && isSignallep[ilep] == false)
               continue;
             if (std::fabs(flavlepton) == 11 && isMediumlep[ilep] == false && LepIsoFCLoose[ilep] == false && d0sig[ilep] == false)
               continue;

             // select origin to avoid fakes double counting
             if (ChannelNumber == 410142 || ChannelNumber == 410144 || ChannelNumber == 364242 || ChannelNumber == 364243 || ChannelNumber == 364244 || ChannelNumber == 364245 || ChannelNumber == 364246 || ChannelNumber == 364247 || ChannelNumber == 364248 || ChannelNumber == 364249)
               {
                 if (Originlep[ilep] != 10 && Originlep[ilep] != 0 && Originlep[ilep] != 12 && Originlep[ilep] != 13 && Originlep[ilep] != 14 && Originlep[ilep] != 43 && Originlep[ilep] != 22)
                   continue;
               }
             else
               {
                 if (Originlep[ilep] != 10 && Originlep[ilep] != 12 && Originlep[ilep] != 13 && Originlep[ilep] != 14 && Originlep[ilep] != 43 && Originlep[ilep] != 22)
                   continue;
               }

	     std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
             the_leptons.push_back(new_lep);
           }
       }

     // sort indices by pT
     sort(the_leptons.rbegin(), the_leptons.rend());
     std::vector<short unsigned int> the_sorted_leptons;
     for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
       {
         the_sorted_leptons.push_back(the_leptons[ilep].second);
       }

     return the_sorted_leptons;
   };
 }
 

inline auto FindLeptonsLoose(const float ptelecut, const float ptmuocut)
{
	return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, ROOT::VecOps::RVec<bool> &) {
		std::vector<std::pair<float, short unsigned int>> the_leptons;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{

			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);

			if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
			{

				if (passORlep[ilep] == false)
					continue;

				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				the_leptons.push_back(new_lep);
			}
		}

		// sort indices by pT
		sort(the_leptons.rbegin(), the_leptons.rend());

		std::vector<short unsigned int> the_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
		{
			the_sorted_leptons.push_back(the_leptons[ilep].second);
		}

		//std::cout << "n good lep " << the_sorted_leptons.size() << std::endl;

		return the_sorted_leptons;
	};
}

inline auto FindLeptonsLooseMC(const float ptelecut, const float ptmuocut)
{

	return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, const ROOT::VecOps::RVec<bool> &, const ROOT::VecOps::RVec<int> &Originlep, const int ChannelNumber) {
		std::vector<std::pair<float, short unsigned int>> the_leptons;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{

			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);

			if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
			{

				if (passORlep[ilep] == false)
					continue;

				// select origin to avoid fakes double counting
				if (ChannelNumber == 410142 || ChannelNumber == 410144 || ChannelNumber == 364242 || ChannelNumber == 364243 || ChannelNumber == 364244 || ChannelNumber == 364245 || ChannelNumber == 364246 || ChannelNumber == 364247 || ChannelNumber == 364248 || ChannelNumber == 364249)
				{
					if (Originlep[ilep] != 10 && Originlep[ilep] != 0 && Originlep[ilep] != 12 && Originlep[ilep] != 13 && Originlep[ilep] != 14 && Originlep[ilep] != 43 && Originlep[ilep] != 22)
						continue;
				}
				else
				{
					if (Originlep[ilep] != 10 && Originlep[ilep] != 12 && Originlep[ilep] != 13 && Originlep[ilep] != 14 && Originlep[ilep] != 43 && Originlep[ilep] != 22)
						continue;
				}

				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				the_leptons.push_back(new_lep);
			}
		}

		// sort indices by pT
		sort(the_leptons.rbegin(), the_leptons.rend());

		std::vector<short unsigned int> the_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
		{
			the_sorted_leptons.push_back(the_leptons[ilep].second);
		}

		//std::cout << "n good lep " << the_sorted_leptons.size() << std::endl;

		return the_sorted_leptons;
	};
}

inline auto FindLeptonsLooseMC_withFakes(const float ptelecut, const float ptmuocut)
{

	return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, const ROOT::VecOps::RVec<bool> &, const ROOT::VecOps::RVec<int> &, const int) {
		std::vector<std::pair<float, short unsigned int>> the_leptons;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{

			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);

			if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
			{

				if (passORlep[ilep] == false)
					continue;
				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				the_leptons.push_back(new_lep);
			}
		}

		// sort indices by pT
		sort(the_leptons.rbegin(), the_leptons.rend());

		std::vector<short unsigned int> the_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
		{
			the_sorted_leptons.push_back(the_leptons[ilep].second);
		}

		//std::cout << "n good lep " << the_sorted_leptons.size() << std::endl;

		return the_sorted_leptons;
	};
}

inline auto FindBaselineLeptonsMuonExtendedCoverage()
{
	return [](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep) {
		std::vector<short unsigned int> my_leptons;
		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);
			if ((std::fabs(flavlepton) == 11 && etalep < 2.47) || (std::fabs(flavlepton) == 13 && etalep < 2.7))
				my_leptons.push_back(ilep);
		}
		return my_leptons;
	};
}

inline auto FindBaselineLeptons()
{
	return [](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep) {
		std::vector<short unsigned int> my_leptons;
		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);
			if ((std::fabs(flavlepton) == 11 && etalep < 2.47) || (std::fabs(flavlepton) == 13 && etalep < 2.4))
				my_leptons.push_back(ilep);
		}
		return my_leptons;
	};
}

inline auto FindORLeptonsMuonExtendedCoverage()
{
	return [](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep) {
		std::vector<std::pair<float, short unsigned int>> my_leptons;
		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{
			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);
			if ((std::fabs(flavlepton) == 11 && etalep < 2.47) || (std::fabs(flavlepton) == 13 && etalep < 2.7))
			{
				if (passORlep[ilep] == false)
					continue;
				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				my_leptons.push_back(new_lep);
			}
		}
		sort(my_leptons.rbegin(), my_leptons.rend());

		std::vector<short unsigned int> my_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < my_leptons.size(); ilep++)
			my_sorted_leptons.push_back(my_leptons[ilep].second);
		return my_sorted_leptons;
	};
}

inline auto FindORLeptons()
{
	return [](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep) {
		std::vector<std::pair<float, short unsigned int>> my_leptons;
		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{
			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);
			if ((std::fabs(flavlepton) == 11 && etalep < 2.47) || (std::fabs(flavlepton) == 13 && etalep < 2.4))
			{
				if (passORlep[ilep] == false)
					continue;
				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				my_leptons.push_back(new_lep);
			}
		}
		sort(my_leptons.rbegin(), my_leptons.rend());

		std::vector<short unsigned int> my_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < my_leptons.size(); ilep++)
			my_sorted_leptons.push_back(my_leptons[ilep].second);
		return my_sorted_leptons;
	};
}

inline auto FindSignalLeptons_withFakes(const float ptelecut, const float ptmuocut)
{
	return [ptelecut, ptmuocut](const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<bool> &passORlep, const ROOT::VecOps::RVec<bool> &isSignallep, const ROOT::VecOps::RVec<int> &, const int) {
		std::vector<std::pair<float, short unsigned int>> the_leptons;
		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++)
		{
			double ptlep = ptleptons[ilep];
			double etalep = std::fabs(etaleptons[ilep]);
			int flavlepton = int(flavlep[ilep]);
			if ((std::fabs(flavlepton) == 11 && ptlep > ptelecut && etalep < 2.47) || (std::fabs(flavlepton) == 13 && ptlep > ptmuocut && etalep < 2.4))
			{
				if (passORlep[ilep] == false)
					continue;
				if (isSignallep[ilep] == false)
					continue;
				// select origin to avoid fakes double counting
				std::pair<float, short unsigned int> new_lep = std::make_pair(ptlep, ilep);
				the_leptons.push_back(new_lep);
			}
		}
		sort(the_leptons.rbegin(), the_leptons.rend());
		std::vector<short unsigned int> the_sorted_leptons;
		for (short unsigned int ilep = 0; ilep < the_leptons.size(); ilep++)
		{
			the_sorted_leptons.push_back(the_leptons[ilep].second);
		}
		return the_sorted_leptons;
	};
}

inline auto FindAllOriginLeptons()
{
	return [](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<int> &Originlep, const int dsid) {
		bool allOrigin = false;
		std::pair<bool, bool> leptons(false, false);
		int lep1 = int(Originlep[idx1]);
		int lep2 = int(Originlep[idx2]);
		if (lep1 == 22 || lep1 == 10 || lep1 == 12 || lep1 == 13 || lep1 == 14 || lep1 == 43)
			leptons.first = true;
		if (lep2 == 22 || lep2 == 10 || lep2 == 12 || lep2 == 13 || lep2 == 14 || lep2 == 43)
			leptons.second = true;
		if (leptons.first && leptons.second)
			allOrigin = true;
		if (lep1 == 0 && lep2 == 0 && (dsid == 364242 || dsid == 364243 || dsid == 364244 || dsid == 364245 || dsid == 364246 || dsid == 364247 || dsid == 364248 || dsid == 364249))
			allOrigin = true;
		return allOrigin;
	};
}

inline auto FindDFLeptons()
{
	return [](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<int> &flavlep) {
		bool DF = false;
		int lep1 = int(flavlep[idx1]);
		int lep2 = int(flavlep[idx2]);
		if (std::fabs(lep1) != std::fabs(lep2))
			DF = true;
		return DF;
	};
}

inline auto FindSSLeptons()
{
	return [](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<int> &flavlep) {
		bool SS = false;
		int lep1 = int(flavlep[idx1]);
		int lep2 = int(flavlep[idx2]);
		if (lep1 * lep2 > 0)
			SS = true;
		return SS;
	};
}

inline auto GetFF_Eta_Pt(const TH2D *temp_FakeFactor2D_el_pt_eta, const TH2D *temp_FakeFactor2D_mu_pt_eta)
{
	return [temp_FakeFactor2D_el_pt_eta, temp_FakeFactor2D_mu_pt_eta](const short unsigned int idx1, const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep) {
                if (idx1 != 65535){
		   if (std::fabs(flavlep[idx1]) == 11)
		   {
			double bcx = ((TAxis *)temp_FakeFactor2D_el_pt_eta->GetXaxis())->FindBin(ptleptons[idx1] / 1000.);
			double bcy = ((TAxis *)temp_FakeFactor2D_el_pt_eta->GetYaxis())->FindBin(std::abs(etaleptons[idx1]));
			double FFel = temp_FakeFactor2D_el_pt_eta->GetBinContent(bcx,bcy);
                        
			//std::cout << ptleptons[idx1] / 1000. << " " << std::abs(etaleptons[idx1]) << " " << FFel << std::endl;
			if (FFel>0) return FFel;
                        else{
                           unsigned int iX=0;
                           for (; bcx-iX>1;){
                              iX++;
                              FFel = temp_FakeFactor2D_el_pt_eta->GetBinContent(bcx-iX,bcy);
                              if (FFel>0){
                                 //std::cout<<"FFel>0 for bin ("<<bcx-iX<<","<<bcy<<") starting from bin ("<<bcx<<","<<bcy<<")"<<std::endl; 
                                 return FFel;
                              }
                           }
                           unsigned int iY=0;
                           for (; bcy-iY>1;){
                              iY++;
                              FFel = temp_FakeFactor2D_el_pt_eta->GetBinContent(bcx,bcy-iY);
                              if (FFel>0){
                                 //std::cout<<"FFel>0 for bin ("<<bcx<<","<<bcy-iY<<") starting from bin ("<<bcx<<","<<bcy<<")"<<std::endl; 
                                 return FFel;
                              }
                           }
                           iX=0, iY=0;
                           for (;(bcx-iX>1 && bcy-iY>1);){
                              iX++;
                              iY++;
                              FFel = temp_FakeFactor2D_el_pt_eta->GetBinContent(bcx-iX,bcy-iY);
                              if (FFel>0){
                                 //std::cout<<"FFel>0 for bin ("<<bcx-iX<<","<<bcy-iY<<") starting from bin ("<<bcx<<","<<bcy<<")"<<std::endl; 
                                 return FFel;
                              }
                           } 
                           
                           std::cerr<<"electrons outside the range"<<std::endl;
                           std::cerr<<"Electron Pt:"<<ptleptons[idx1] / 1000.<<" Eta:"<<std::abs(etaleptons[idx1])<<std::endl; 
                           return -99.;
                          
                        }
		   }
		   else if (std::fabs(flavlep[idx1]) == 13)
		   {
			double bcx = ((TAxis *)temp_FakeFactor2D_mu_pt_eta->GetXaxis())->FindBin(ptleptons[idx1] / 1000.);
			double bcy = ((TAxis *)temp_FakeFactor2D_mu_pt_eta->GetYaxis())->FindBin(std::abs(etaleptons[idx1]));
			double FFmu = temp_FakeFactor2D_mu_pt_eta->GetBinContent(bcx, bcy);
			//std::cout << ptleptons[idx1] / 1000. << " " << std::abs(etaleptons[idx1]) << " " << FFmu << std::endl;
			if (FFmu>0) return FFmu;
                        else{
                           unsigned int iX=0;
                           for (; bcx-iX>1;){
                              iX++;
                              FFmu = temp_FakeFactor2D_mu_pt_eta->GetBinContent(bcx-iX,bcy);
                              if (FFmu>0){
                                 //std::cout<<"FFmu>0 for bin ("<<bcx-iX<<","<<bcy<<") starting from bin ("<<bcx<<","<<bcy<<")"<<std::endl; 
                                 return FFmu;
                              }
                           }
                           unsigned int iY=0;
                           for (; bcy-iY>1;){
                              iY++;
                              FFmu = temp_FakeFactor2D_mu_pt_eta->GetBinContent(bcx,bcy-iY);
                              if (FFmu>0){
                                 //std::cout<<"FFmu>0 for bin ("<<bcx<<","<<bcy-iY<<") starting from bin ("<<bcx<<","<<bcy<<")"<<std::endl; 
                                 return FFmu;
                              }
                           }
                           iX=0, iY=0;
                           for (;(bcx-iX>1 && bcy-iY>1);){
                              iX++;
                              iY++;
                              FFmu = temp_FakeFactor2D_mu_pt_eta->GetBinContent(bcx-iX,bcy-iY);
                              if (FFmu>0){
                                 //std::cout<<"FFmu>0 for bin ("<<bcx-iX<<","<<bcy-iY<<") starting from bin ("<<bcx<<","<<bcy<<")"<<std::endl; 
                                 return FFmu;
                              }
                           } 
                           std::cerr<<"muons outside the range"<<std::endl;
                           std::cerr<<"Muons Pt:"<<ptleptons[idx1] / 1000.<<" Eta:"<<std::abs(etaleptons[idx1])<<std::endl; 
                           return -99.;
                          
                         
                        }
		   }else{
                          std::cerr<<"no electron/muon or no "<<flavlep[idx1]<<" lepton "<<std::endl;
                          return -99.;
                   }
		}else{
			return -99.;
		}
	};
}


inline auto GetXMLFF_Eta_Pt(const std::vector<TString> ele_systList, const std::vector<TString> muon_systList, const std::map<TString,std::vector<TString>> eleMap, const std::map<TString,std::vector<TString>> muonMap) 
{
		return [ele_systList, muon_systList, eleMap, muonMap](const short unsigned int idx1, const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &etaleptons, const ROOT::VecOps::RVec<int> &flavlep, const bool isTrigMatch) {

               std::map<TString, float> FFvalues;
               FFvalues["fakeWeight"] = -99.;
               FFvalues["fakeWeight_statUp"] = -99.; 
               FFvalues["fakeWeight_statDown"] = -99.;
 
               std::vector<TString> allSyst;
               allSyst.reserve(ele_systList.size());
               for (const auto &syst : ele_systList) allSyst.push_back(syst);
               for(const auto &muSys: muon_systList){
                   bool exist = false;
                   for(const auto &syst : allSyst){
                      if (syst == muSys){
                         exist = true;
                         break;
                      }          
                   }
                   if(!exist) allSyst.push_back(muSys);
               }
    
               for (const auto &syst : allSyst){
                   FFvalues["fakeWeight_"+syst+"Up"] = -99;
                   FFvalues["fakeWeight_"+syst+"Down"] = -99;
               }

               if (idx1 != 65535){
                  float pt = ptleptons[idx1] / 1000.;
                  float eta = std::abs(etaleptons[idx1]);
                  float trigMatch = isTrigMatch==true ? 1. : 0. ;
                  bool isEle = std::fabs(flavlep[idx1]) == 11 ? true : false;

                  TString contentFF;

                  std::regex reInt("\\[(.*),(.*)\\]");

                  if(isEle){

                   try{
                    for (unsigned int i=0; i<eleMap.at("FFval").size();i++){

                      std::cmatch mEta;
                      std::regex_match(eleMap.at("eta")[i].Data(),mEta,reInt);
                      bool isEtaMatch = TString(mEta[1]).Atof()<eta && TString(mEta[2]).Atof()>eta;
                      std::cmatch mPt;
                      std::regex_match(eleMap.at("pt")[i].Data(),mPt,reInt);
                      bool isPtMatch = TString(mPt[1]).Atof()<pt && TString(mPt[2]).Atof()>pt;
                      std::cmatch mTrig;
                      std::regex_match(eleMap.at("trigMatchedToInvLep")[i].Data(),mTrig,reInt);
                      bool isTrig = TString(mTrig[1]).Atof()<trigMatch && TString(mTrig[2]).Atof()>trigMatch;

                      if (isEtaMatch && isPtMatch && isTrig){ 
                          contentFF = eleMap.at("FFval")[i]; 
                          break;
                      }

                   }
                  }catch(const std::exception& e) { // caught by reference to base
                        std::cout << " exception in looking for correct electron pt-eta-trig match bin, with message '"<< e.what() <<std::endl;
                  }   
                 }else{
                   try{
                    for (unsigned int i=0; i<muonMap.at("FFval").size();i++){

                      std::cmatch mEta;
                      std::regex_match(muonMap.at("eta")[i].Data(),mEta,reInt);
                      bool isEtaMatch = TString(mEta[1]).Atof()<eta && TString(mEta[2]).Atof()>eta;
                      std::cmatch mPt;
                      std::regex_match(muonMap.at("pt")[i].Data(),mPt,reInt);
                      bool isPtMatch = TString(mPt[1]).Atof()<pt && TString(mPt[2]).Atof()>pt;
                      std::cmatch mTrig;
                      std::regex_match(muonMap.at("trigMatchedToInvLep")[i].Data(),mTrig,reInt);
                      bool isTrig = TString(mTrig[1]).Atof()<trigMatch && TString(mTrig[2]).Atof()>trigMatch;

                      if (isEtaMatch && isPtMatch && isTrig){
                          contentFF = muonMap.at("FFval")[i]; 
                          break;
                      }

                   }
                  }catch(const std::exception& e) { // caught by reference to base
                     std::cout << " exception in looking for correct muon pt-eta-trig match bin, with message '"<< e.what() <<std::endl;
                  } 

                 } 

                 //std::cout<<"eta: "<<eta<<"  pt: "<<pt<<" trigMatchedToInvLep:"<<trigMatch<<std::endl;  
                 //std::cout<<"binContent: "<<contentFF<<std::endl;
                 TString regExpression = "(.*) \\+(.*)\\-(.*) \\(stat\\)";
                 if(isEle){
                   for (const auto &syst : ele_systList) regExpression+=" \\+(.*)\\-(.*) \\("+syst+"\\)"; 
                 }else{
                   for (const auto &syst : muon_systList) regExpression+=" \\+(.*)\\-(.*) \\("+syst+"\\)"; 
                 }
                 regExpression+="(.*)";
                 //std::cout<<regExpression<<std::endl;
                 //std::regex reCon("(.*) \\+(.*)\\-(.*) \\(stat\\) \\+(.*)\\-(.*) \\(composition_Syst\\) \\+(.*)\\-(.*) \\(nonclosure_Syst\\) \\+(.*)\\-(.*) \\(comb_Syst\\) \\+(.*)\\-(.*) \\(prompt_Syst\\)(.*)");
                 std::regex reCon(regExpression.Data());
                 std::cmatch val;
                 try{
                   std::regex_match(contentFF.Data(),val,reCon);
                 }catch(const std::exception& e) { // caught by reference to base
                     std::cout << " expection in parsing: "<<contentFF<<" , with message '"<< e.what() <<std::endl;
                 }

                 //FFvalues["fakeWeight"] = TString(val[1]).Atof();
                 for (const auto &m : FFvalues) FFvalues[m.first] = TString(val[1]).Atof(); //Set all the syst variations to the nominal FF
                 if (val[2] != "" && val[3] != "" ){
                    FFvalues["fakeWeight_statUp"] = TString(val[1]).Atof()+TString(val[2]).Atof();
                    FFvalues["fakeWeight_statDown"] = TString(val[1]).Atof()+TString(val[3]).Atof();
                 }else{
                     if((val[2] != "" && val[3] == "") || (val[2] == "" && val[3] != "") ){
                         FFvalues["fakeWeight_statUp"] = TString(val[1]).Atof()+TString(val[2]).Atof()+TString(val[3]).Atof();
                         FFvalues["fakeWeight_statDown"] = TString(val[1]).Atof()-TString(val[2]).Atof()-TString(val[3]).Atof();
                     }else{
                         FFvalues["fakeWeight_statUp"] = TString(val[1]).Atof();
                         FFvalues["fakeWeight_statDown"] = TString(val[1]).Atof();
                     }      
                 }

                 if(isEle){
                   for (unsigned int i=0; i<ele_systList.size();i++){
                    int x1 = 4+i*2, x2 = 5+i*2;
                    if (val[x1] != "" && val[x2] != "" ){
                       FFvalues["fakeWeight_"+ele_systList[i]+"Up"] = TString(val[1]).Atof()+TString(val[x1]).Atof();
                       FFvalues["fakeWeight_"+ele_systList[i]+"Down"] = TString(val[1]).Atof()-TString(val[x2]).Atof()>0? TString(val[1]).Atof()-TString(val[x2]).Atof():0;
                    }else{
                       if((val[x1] != "" && val[x2] == "") || (val[x1] == "" && val[x2] != "") ){
                           FFvalues["fakeWeight_"+ele_systList[i]+"Up"] = TString(val[1]).Atof()+TString(val[x1]).Atof()+TString(val[x2]).Atof();
                           FFvalues["fakeWeight_"+ele_systList[i]+"Down"] = TString(val[1]).Atof()-TString(val[x1]).Atof()-TString(val[x2]).Atof()> 0 ? TString(val[1]).Atof()-TString(val[x1]).Atof()-TString(val[x2]).Atof():0;
                       }else{
                           FFvalues["fakeWeight_"+ele_systList[i]+"Up"] = TString(val[1]).Atof();
                           FFvalues["fakeWeight_"+ele_systList[i]+"Down"] = TString(val[1]).Atof();
                       }
                    }

                   } 
                 }else{
                   for (unsigned int i=0; i<muon_systList.size();i++){
                    int x1 = 4+i*2, x2 = 5+i*2;
                    if (val[x1] != "" && val[x2] != "" ){
                       FFvalues["fakeWeight_"+muon_systList[i]+"Up"] = TString(val[1]).Atof()+TString(val[x1]).Atof();
                       FFvalues["fakeWeight_"+muon_systList[i]+"Down"] = TString(val[1]).Atof()-TString(val[x2]).Atof()>0 ? TString(val[1]).Atof()-TString(val[x2]).Atof() : 0;
                    }else{
                       if((val[x1] != "" && val[x2] == "") || (val[x1] == "" && val[x2] != "") ){
                           FFvalues["fakeWeight_"+muon_systList[i]+"Up"] = TString(val[1]).Atof()+TString(val[x1]).Atof()+TString(val[x2]).Atof();
                           FFvalues["fakeWeight_"+muon_systList[i]+"Down"] = TString(val[1]).Atof()-TString(val[x1]).Atof()-TString(val[x2]).Atof()>0 ? TString(val[1]).Atof()-TString(val[x1]).Atof()-TString(val[x2]).Atof() : 0;
                       }else{
                           FFvalues["fakeWeight_"+muon_systList[i]+"Up"] = TString(val[1]).Atof();
                           FFvalues["fakeWeight_"+muon_systList[i]+"Down"] = TString(val[1]).Atof();
                       }
                    }

                   }
                 }

                 //for (const auto &el : FFvalues) std::cout<<el.first<<": "<<el.second<<std::endl;
                                 
                 return FFvalues;        
 
               }else{
                
                 return FFvalues; 

               }
        };
}

inline auto ClassifyLepton(const short unsigned int position)
{
	return [position](const ROOT::VecOps::RVec<int> &flavlep, const ROOT::VecOps::RVec<int> &Typelep, const ROOT::VecOps::RVec<int> &Originlep, const ROOT::VecOps::RVec<int> &mum_type, const ROOT::VecOps::RVec<int> &mum_origin, const std::vector<short unsigned int> &idxs) {
		int lep_class = -1;
		if (idxs.size() > position)
		{
			short unsigned int lep_id = idxs[position];

			if (flavlep.size() > lep_id)
			{

				//std::cout << "type " << Typelep[lep_id] << " origin " << Originlep[lep_id] << " mum_type " << mum_type[lep_id] << " mum_origin " << mum_origin[lep_id] << std::endl;

				bool isPromptOrigin = false;
				if (Originlep[lep_id] == 10 || Originlep[lep_id] == 12 || Originlep[lep_id] == 13 || Originlep[lep_id] == 14 || Originlep[lep_id] == 22 || Originlep[lep_id] == 43)
					isPromptOrigin = true;
				bool hasBOrigin = false;
				if (Originlep[lep_id] == 26 || Originlep[lep_id] == 29 || Originlep[lep_id] == 33)
					hasBOrigin = true;
				bool hasCOrigin = false;
				if (Originlep[lep_id] == 25 || Originlep[lep_id] == 27 || Originlep[lep_id] == 28 || Originlep[lep_id] == 32)
					hasCOrigin = true;
				bool hasLightOrigin = false;
				if (Originlep[lep_id] == 23 || Originlep[lep_id] == 24 || Originlep[lep_id] == 30 || Originlep[lep_id] == 31 || Originlep[lep_id] == 34 || Originlep[lep_id] == 35)
					hasLightOrigin = true;

				if (fabs(flavlep[lep_id]) == 11)
				{
					lep_class = 5; // UnknownElectron

					if (Typelep[lep_id] == 2)
						lep_class = 0; // Prompt Ele
					if (isPromptOrigin)
						lep_class = 0; // Prompt Ele
					if (Typelep[lep_id] == 4 && Originlep[lep_id] == 5 && mum_type[lep_id] == 2)
						lep_class = 0; // Prompt Ele
					if (Typelep[lep_id] == 4 && Originlep[lep_id] == 7 && mum_type[lep_id] == 2)
						lep_class = 0; // Prompt Ele
					if (Typelep[lep_id] == 4 && (Originlep[lep_id] == 5 || Originlep[lep_id] == 7) && mum_origin[lep_id] == 40)
						lep_class = 0; // Prompt Ele
					if (Typelep[lep_id] == 4 && (Originlep[lep_id] == 5 || Originlep[lep_id] == 7) && mum_type[lep_id] == 14)
						lep_class = 1; // Conversion
					if (Typelep[lep_id] == 4 && (Originlep[lep_id] == 5 || Originlep[lep_id] == 7) && mum_origin[lep_id] == 38)
						lep_class = 1; // Conversion
					if (Typelep[lep_id] == 14 && Originlep[lep_id] == 37)
						lep_class = 1; // Conversion
					if (Typelep[lep_id] == 4 && (Originlep[lep_id] == 5 || Originlep[lep_id] == 7) && mum_origin[lep_id] == 5)
						lep_class = 1; // Conversion
					if (hasLightOrigin || Originlep[lep_id] == 6)
						lep_class = 2; // LF electron
					if (Typelep[lep_id] == 17)
						lep_class = 2; // LF electron
					if (Typelep[lep_id] == 4 && (Originlep[lep_id] == 5 || Originlep[lep_id] == 7) && mum_type[lep_id] == 16 && mum_origin[lep_id] == 42)
						lep_class = 2; // LF electron
					if (Typelep[lep_id] == 4 && Originlep[lep_id] == 5 && mum_origin[lep_id] == 23)
						lep_class = 2; // LF electron
					if (Typelep[lep_id] == 16 && Originlep[lep_id] == 42)
						lep_class = 2; // LF electron
					if (hasCOrigin || hasBOrigin)
						lep_class = 3; // HF electron
					if (Typelep[lep_id] == 4 && Originlep[lep_id] == 5 && mum_origin[lep_id] == 26)
						lep_class = 3; // HF electron
					if (Typelep[lep_id] == 4 && Originlep[lep_id] == 5 && mum_origin[lep_id] == 25)
						lep_class = 3; // HF electron
					if (Typelep[lep_id] == 4 && Originlep[lep_id] == 5 && mum_origin[lep_id] == 27)
						lep_class = 3; // HF electron
					if (Typelep[lep_id] == 3 && Originlep[lep_id] == 9)
						lep_class = 4; // tau electron
				}
				else if (fabs(flavlep[lep_id]) == 13)
				{
					lep_class = 10; // UnknownMuon
					if (isPromptOrigin)
						lep_class = 6; // Prompt Muon
					if (hasCOrigin || hasBOrigin)
						lep_class = 7; // HF muon
					if (hasLightOrigin)
						lep_class = 8; // LF muon
					if (Typelep[lep_id] == 17)
						lep_class = 8; // LF muon
					if (Originlep[lep_id] == 9)
						lep_class = 9; // tau muon
				}
				else
					return -1;
				//if(lep_class == 10) std::cout << "type " << Typelep[lep_id] << " origin " << Originlep[lep_id] << " mum_type " << mum_type[lep_id] << " mum_origin " << mum_origin[lep_id] << std::endl;
			}
			else
				return -1;
		}
		return lep_class;
	};
}

inline auto GetEventFakeWeight(){
       return[](const bool isMC, const int nLep, ROOT::VecOps::RVec<int> flavLep, ROOT::VecOps::RVec<bool> isSignal, ROOT::VecOps::RVec<bool> isFCLoose, ROOT::VecOps::RVec<bool> isGrad, ROOT::VecOps::RVec<double> FFLep, const bool goodOrigin)
       {

        /*this is valid up to 3 leptons -- to be included the case with 4 leptons*/
        double weight=0.;
        ROOT::VecOps::RVec<bool> isID;

        for (short unsigned int iLep = 0; iLep < nLep; iLep++) {

            if (fabs(flavLep[iLep])==11){
               if(isGrad[iLep] && isSignal[iLep]) isID.push_back(true);
               else isID.push_back(false);
            }else if (fabs(flavLep[iLep])==13){
               if(isFCLoose[iLep] && isSignal[iLep]) isID.push_back(true);
               else if(!isFCLoose[iLep] && isSignal[iLep]) isID.push_back(false);
               else{ 
                   //std::cerr<<"found muon with both iso and signal requests or only the signal request false"<<std::endl;
                   return weight;
               }
            }else{
                std::cerr<<"no electron or muon found while estimating the event fake weight"<<std::endl;
            }
        }

        short unsigned int nID = isID[(isID==true)].size();
        short unsigned int nAntiID = isID[(isID==false)].size();
        if (nID==nLep) return weight;
        else if(isMC && !goodOrigin){
           //std::cout<<"skipping MC Fakes!!"<<std::endl;
           return weight;
        }else{
           weight = 1.;
           for  (short unsigned int iLep = 0; iLep < nLep; iLep++) {
               if (!isID[iLep]) weight *= FFLep[iLep];
           }
        }

        if(nAntiID%2==0) weight *= -1.;

        if(isMC) weight *= -1;

        ///values copied from inline auto LumiWeightCalc
        double lumi15 = 3.2;
        double lumi16 = 33.0;
        double lumi17 = 44.3;
        double lumi18 = 58.45;
        double lumi_total = lumi15 + lumi16 + lumi17 + lumi18;
        if(!isMC) weight *= 1./lumi_total;

        return weight;
       };


}



} // namespace LambdaMaker

#endif

// Typelep
// Unknown           =  0,
// UnknownElectron   =  1,
// IsoElectron       =  2,
// NonIsoElectron    =  3,
// BkgElectron       =  4,
// UnknownMuon       =  5,
// IsoMuon           =  6,
// NonIsoMuon        =  7,
// BkgMuon           =  8,
// UnknownTau        =  9,
// IsoTau            =  10,
// NonIsoTau         =  11,
// BkgTau            =  12,
// UnknownPhoton     =  13,
// IsoPhoton         =  14,
// NonIsoPhoton      =  15,
// BkgPhoton         =  16,
// Hadron            =  17,
// Neutrino          =  18,
// NuclFrag          =  19,
// NonPrimary        =  20,
// GenParticle       =  21,
// SUSYParticle      =  22,
// BBbarMesonPart    =  23,
// BottomMesonPart   =  24,
// CCbarMesonPart    =  25,
// CharmedMesonPart  =  26,
// BottomBaryonPart  =  27,
// CharmedBaryonPart =  28,
// StrangeBaryonPart =  29,
// LightBaryonPart   =  30,
// StrangeMesonPart  =  31,
// LightMesonPart    =  32,
// BJet              =  33,
// CJet              =  34,
// LJet              =  35,
// GJet              =  36,
// TauJet            =  37,
// UnknownJet        =  38

// ParticleOrigin
//
// NonDefined    = 0,
//
// SingleElec    = 1,
// SingleMuon    = 2,
// SinglePhot    = 3,
// SingleTau     = 4,
//
//
// PhotonConv    = 5,
// DalitzDec     = 6,
// ElMagProc     = 7,
// Mu            = 8,
// TauLep        = 9,
// top           = 10,
// QuarkWeakDec  = 11,
// WBoson        = 12,
// ZBoson        = 13,
// Higgs         = 14,
// HiggsMSSM     = 15,
// HeavyBoson    = 16,
// WBosonLRSM    = 17,
// NuREle        = 18,
// NuRMu         = 19,
// NuRTau        = 20,
// LQ            = 21,
//
// SUSY          = 22,
// LightMeson    = 23,
// StrangeMeson  = 24,
// CharmedMeson  = 25,
// BottomMeson   = 26,
// CCbarMeson    = 27,
// JPsi          = 28,
// BBbarMeson    = 29,
// LightBaryon   = 30,
// StrangeBaryon = 31,
// CharmedBaryon = 32,
// BottomBaryon  = 33,
// PionDecay     = 34,
// KaonDecay     = 35,
// BremPhot      = 36,
// PromptPhot    = 37,
// UndrPhot      = 38,
// ISRPhot       = 39,
// FSRPhot       = 40,
// NucReact      = 41,
// PiZero        = 42,
// DiBoson       = 43,
// ZorHeavyBoson = 44,
// QCD           = 45
// };
