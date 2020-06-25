#ifndef LoopSUSYThTh_H
#define LoopSUSYThTh_H

#include <LoopSUSYFrame/LoopSUSYFrame.h>
#include <LoopSUSYFrame/cppnn.h>

#include <utility>
#include <string>
#include <memory>
#include <vector>
#include <TTree.h>
#include <TLorentzVector.h>


using CutFlowReport = ROOT::RDF::RResultPtr<ROOT::RDF::RCutFlowReport>;
using SnapshotResult = ROOT::RDF::RResultPtr<ROOT::RDF::RInterface<ROOT::Detail::RDF::RLoopManager>>;

class LoopSUSYThTh : public LoopSUSYFrame
{

public:

	// this is a standard constructor
	LoopSUSYThTh ( TTree *tree );
	~LoopSUSYThTh(){};
	virtual std::vector<std::string> DefineBranches(const std::string &syst);
	virtual std::pair<CutFlowReport,SnapshotResult> Process(ROOT::RDataFrame &dataFrame, const std::string &syst);

private:
	myNN theNet;

};

// stoph-only helper functions
std::pair<std::array<float, 5>, bool> Find_mbb_closest(const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &truthvec);
std::pair<std::array<float, 3>, bool> Find_mbb_DR(const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &truthvec);

namespace LambdaMaker
{
	inline auto GetNNvars(const myNN &Nnet)
	{
		return [Nnet](const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, const ROOT::VecOps::RVec<int> &isBjet, const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &truthvec)
		{
			std::vector<bool> vec_isHiggs;// = -1.;
			std::vector<float> vec_score;// = -1.;

	    float highest_score = -1.;
	    float NN_mjj  = -1.;
	    float NN_ptjj = -1.;
	    float NN_drjj = -1.;
	    float NN_nHiggs_05 = 0.;
	    float NN_nHiggs_07 = 0.;
	    float NN_nHiggs_08 = 0.;
	    float NN_nHiggs_09 = 0.;
		bool isHiggs = false;
		std::vector<short unsigned int> tagged_idxs_05, tagged_idxs_07, tagged_idxs08, tagged_idxs09;
		std::vector<short unsigned int> my_idxs = idxs;

		int nHiggsEvent = 0.;
		while(my_idxs.size()>1){

			float this_highest_score = -1.;
			int this_id1 = -1;
			int this_id2 = -1;
			for (short unsigned int ijet = 0; ijet < my_idxs.size(); ijet++) {

				int id_jet = my_idxs[ijet];
				TLorentzVector jet1;
				jet1.SetPtEtaPhiM(ptvec[id_jet], etavec[id_jet], phivec[id_jet], massvec[id_jet]);
				int jet1_btag = isBjet[id_jet];

				for (short unsigned int ijet2 = ijet + 1; ijet2 < my_idxs.size(); ijet2++) {

					int id_jet2 = my_idxs[ijet2];
					TLorentzVector jet2;
					jet2.SetPtEtaPhiM(ptvec[id_jet2], etavec[id_jet2], phivec[id_jet2], massvec[id_jet2]);
					int jet2_btag = isBjet[id_jet2];

					// COMPUTE KINEMATIC VARIBLES of the pair
	    	        float MJJ = (jet1 + jet2).M()/1000.;
	    	        float RedJ1PT = (jet1.Perp()/MJJ)/1000.;
	    	        float RedJ2PT = (jet2.Perp()/MJJ)/1000.;
					Float_t M1_cut = massvec.at(id_jet)/1000.;
					Float_t M2_cut = massvec.at(id_jet2)/1000.;
 
					float score_signed = 0.;
					float score = Nnet.forward(RedJ1PT, jet1.PseudoRapidity(), jet1.Phi(), M1_cut, jet1_btag, RedJ2PT, jet2.PseudoRapidity(), jet2.Phi(), M2_cut, jet2_btag);
	    	        if (score > this_highest_score) {
	    	            NN_mjj = MJJ;
	    	            NN_ptjj = (jet1 + jet2).Perp() / 1000.;
	    	            NN_drjj = jet1.DeltaR(jet2);
	    	            this_highest_score = score;
						this_id1 = id_jet;
						this_id2 = id_jet2;

						if((truthvec[id_jet]==25) && (truthvec[id_jet2]==25)){
							isHiggs = true;
							score_signed = score;
							nHiggsEvent++;
						}
						else{
							isHiggs = false;
							score_signed = score*-1;
						}
					vec_score.push_back(score_signed);
					vec_isHiggs.push_back(isHiggs);
					}
				}
			}

			if(fabs(this_highest_score)>0.5)NN_nHiggs_05 += 1.;
			if(fabs(this_highest_score)>0.7)NN_nHiggs_07 += 1.;
			if(fabs(this_highest_score)>0.8)NN_nHiggs_08 += 1.;
			if(fabs(this_highest_score)>0.9)NN_nHiggs_09 += 1.;
			if(this_highest_score>highest_score){
				highest_score = this_highest_score;
			}

			std::vector<short unsigned int> new_idxs;
			for(short unsigned int ijet = 0; ijet < my_idxs.size(); ijet++){
				if(my_idxs[ijet]!=this_id1 && my_idxs[ijet]!=this_id2){
					new_idxs.push_back(my_idxs[ijet]);
				}
			}
			my_idxs = new_idxs;
			//}
			//else{
			//	break;
			//}
		}

		std::array<float, 8> the_vars = {float(NN_mjj), float(NN_ptjj), float(NN_drjj), float(highest_score), float(NN_nHiggs_05), float(NN_nHiggs_07), float(NN_nHiggs_08), float(NN_nHiggs_09)};
		std::pair<std::vector<float>,std::vector<bool>> pair1 = make_pair(vec_score,vec_isHiggs);
		std::pair<std::array<float,8>, std::pair<std::vector<float>,std::vector<bool>>> the_pair = std::make_pair(the_vars, pair1);

		return the_pair;
		};
	}

	inline auto GetNNvarsDetail(const myNN &Nnet)
	{
		return [Nnet](const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, const ROOT::VecOps::RVec<int> &isBjet, const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &truthvec, const ROOT::VecOps::RVec<int> &labelvec)
		{
			std::vector<int> vec_isHiggs;// = -1.;
			std::vector<float> vec_score;// = -1.;

	    float highest_score = -1.;
	    float NN_mjj  = -1.;
	    float NN_ptjj = -1.;
	    float NN_drjj = -1.;
	    float NN_nHiggs_05 = 0.;
	    float NN_nHiggs_07 = 0.;
	    float NN_nHiggs_08 = 0.;
	    float NN_nHiggs_09 = 0.;
		std::vector<short unsigned int> tagged_idxs_05, tagged_idxs_07, tagged_idxs08, tagged_idxs09;
		std::vector<short unsigned int> my_idxs = idxs;

		int nHiggsEvent = 0.;
		while(my_idxs.size()>1){

			float this_highest_score = -1.;
			int this_id1 = -1;
			int this_id2 = -1;
			for (short unsigned int ijet = 0; ijet < my_idxs.size(); ijet++) {

				int id_jet = my_idxs[ijet];
				TLorentzVector jet1;
				jet1.SetPtEtaPhiM(ptvec[id_jet], etavec[id_jet], phivec[id_jet], massvec[id_jet]);
				int jet1_btag = isBjet[id_jet];

				for (short unsigned int ijet2 = ijet + 1; ijet2 < my_idxs.size(); ijet2++) {

					int id_jet2 = my_idxs[ijet2];
					TLorentzVector jet2;
					jet2.SetPtEtaPhiM(ptvec[id_jet2], etavec[id_jet2], phivec[id_jet2], massvec[id_jet2]);
					int jet2_btag = isBjet[id_jet2];

					// COMPUTE KINEMATIC VARIBLES of the pair
	    	        float MJJ = (jet1 + jet2).M()/1000.;
	    	        float RedJ1PT = (jet1.Perp()/MJJ)/1000.;
	    	        float RedJ2PT = (jet2.Perp()/MJJ)/1000.;
					float_t M1_cut = massvec.at(id_jet)/1000.;
                	float_t M2_cut = massvec.at(id_jet2)/1000.;
 
					float score_signed = 0.;
					float score = Nnet.forward(RedJ1PT, jet1.PseudoRapidity(), jet1.Phi(), M1_cut, jet1_btag, RedJ2PT, jet2.PseudoRapidity(), jet2.Phi(), M2_cut, jet2_btag);
	    	        if (score > this_highest_score) {
	    	            NN_mjj = MJJ;
	    	            NN_ptjj = (jet1 + jet2).Perp() / 1000.;
	    	            NN_drjj = jet1.DeltaR(jet2);
	    	            this_highest_score = score;
						this_id1 = id_jet;
						this_id2 = id_jet2;

						int isHiggs = -1;
						if (truthvec[id_jet] && truthvec[id_jet2]){
							isHiggs = truthvec[id_jet];
							score_signed = score;
							nHiggsEvent++;
						}
						else{
							isHiggs = -1;
							score_signed = score*-1;
						}

						int cat = -1;
						if(isHiggs==-1){
							if(labelvec[id_jet] == 5 && labelvec[id_jet2] == 5 ){
								cat = 0; // bb
							}
							else if((labelvec[id_jet] == 5 && labelvec[id_jet2] != 4 && labelvec[id_jet2] != 5) || (labelvec[id_jet] != 5 && labelvec[id_jet] != 4 && labelvec[id_jet2] == 5)){
								cat = 1; // bx
							}
							else if((labelvec[id_jet] == 5 && labelvec[id_jet2] == 4) || (labelvec[id_jet] == 4 && labelvec[id_jet2] == 5)){
								cat = 2; // bc
							}
							else if(labelvec[id_jet] == 5 && labelvec[id_jet2] == 5 ){
								cat = 3; // cc
							}
							else if((labelvec[id_jet] == 4 && labelvec[id_jet2] != 4 && labelvec[id_jet2] != 5) || (labelvec[id_jet] != 5 && labelvec[id_jet] != 4 && labelvec[id_jet2] == 4)){
								cat = 4; // cx
							}
							else if((labelvec[id_jet] != 5 && labelvec[id_jet] != 4 && labelvec[id_jet2] != 4 && labelvec[id_jet2] != 5)){
								cat = 5; // xx
							}
							else{
								cat = -1;
							}
							isHiggs = cat;
						}
						vec_score.push_back(score_signed);
						vec_isHiggs.push_back(isHiggs);
					}
				}
			}

			if(fabs(this_highest_score)>0.5)NN_nHiggs_05 += 1.;
			if(fabs(this_highest_score)>0.7)NN_nHiggs_07 += 1.;
			if(fabs(this_highest_score)>0.8)NN_nHiggs_08 += 1.;
			if(fabs(this_highest_score)>0.9)NN_nHiggs_09 += 1.;
			if(this_highest_score>highest_score){
				highest_score = this_highest_score;
			}

			std::vector<short unsigned int> new_idxs;
			for(short unsigned int ijet = 0; ijet < my_idxs.size(); ijet++){
				if(my_idxs[ijet]!=this_id1 && my_idxs[ijet]!=this_id2){
					new_idxs.push_back(my_idxs[ijet]);
				}
			}
			my_idxs = new_idxs;
			//}
			//else{
			//	break;
			//}
		}

		std::array<float, 8> the_vars = {float(NN_mjj), float(NN_ptjj), float(NN_drjj), float(highest_score), float(NN_nHiggs_05), float(NN_nHiggs_07), float(NN_nHiggs_08), float(NN_nHiggs_09)};
		std::pair<std::vector<float>,std::vector<int>> pair1 = make_pair(vec_score,vec_isHiggs);
		std::pair<std::array<float,8>, std::pair<std::vector<float>,std::vector<int>>> the_pair = std::make_pair(the_vars, pair1);

		return the_pair;
		};
	}
}
#endif
