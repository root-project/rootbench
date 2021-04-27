#include <LoopSUSYFrame/GenericHelpers.h>

// Some Helper Functions
int CountObjects(const std::vector<short unsigned int> &idxs)
{
  return int(idxs.size());
}

float DeltaPhi(const float part1phi, const float part2phi)
{
  double x = part1phi - part2phi;
  while (x >= M_PI) x -= 2.*M_PI;
  while (x < -M_PI) x += 2.*M_PI;
  return x;
}

float GetDeltaPhiMin(const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<float> &phivec, const float METphi)
{

  float dPhiMin = 20.;

  for (short unsigned int ijet = 0; ijet < idxs.size(); ijet++) {

    int id_jet = idxs[ijet];
    float dPhi = DeltaPhi(phivec[id_jet], METphi);

    if (fabs(dPhi) < fabs(dPhiMin)) dPhiMin = dPhi;

  }

  return dPhiMin;
}

float GetDeltaPhiMinMin(const std::vector<short unsigned int> &idxs1, const ROOT::VecOps::RVec<float> &phivec1, const std::vector<short unsigned int> &idxs2, const ROOT::VecOps::RVec<float> &phivec2)
{

  float dPhiMin = 20.;

  for (short unsigned int ijet = 0; ijet < idxs1.size(); ijet++) { //loop over jets

    for (short unsigned int ilep = 0; ilep < idxs2.size(); ilep++) { //loop over jets    

      int id_jet = idxs1[ijet];
      int id_lep = idxs2[ilep];

      float dPhi = DeltaPhi(phivec1[id_jet], phivec2[id_lep]);

      if (fabs(dPhi) < fabs(dPhiMin)) dPhiMin = dPhi;
    }

  }

  return dPhiMin;
}

float GetDeltaRMin( int id1,
                    const ROOT::VecOps::RVec<float> &pt1,
                    const ROOT::VecOps::RVec<float> &eta1,
                    const ROOT::VecOps::RVec<float> &phi1,
                    const ROOT::VecOps::RVec<float> &mass1,
                    const ROOT::VecOps::RVec<bool>  &,
                    const std::vector<short unsigned int> &idxs2,
                    const ROOT::VecOps::RVec<float> &pt2,
                    const ROOT::VecOps::RVec<float> &eta2,
                    const ROOT::VecOps::RVec<float> &phi2,
                    const ROOT::VecOps::RVec<float> &mass2,
                    const ROOT::VecOps::RVec<bool>  &)
{
  TLorentzVector vec1, vec2;
  double dR = 10000;
  vec1.SetPtEtaPhiM(pt1[id1], eta1[id1], phi1[id1], mass1[id1]);
  //if(passOR1[id1] == 0) std::cout << "passOR lep " << passOR1[id1] << std::endl;

  for(UInt_t id2 = 0; id2 < idxs2.size(); id2++) {
    vec2.SetPtEtaPhiM(pt2[idxs2[id2]], eta2[idxs2[id2]], phi2[idxs2[id2]], mass2[idxs2[id2]]);
    double deltaR = vec1.DeltaR(vec2);
    //std::cout << "passOR jet " << passOR2[idxs2[id2]] << std::endl;

    if(fabs(deltaR)<dR) dR = deltaR;
    /*
    if(deltaR<0.4) {
      std::cout << "dR " << deltaR << std::endl;
      std::cout << "passOR lep " << passOR1[id1] << std::endl;
      std::cout << "lep: " << vec1.Pt() << " " << vec1.Eta() << " " << vec1.Phi() << std::endl;
      std::cout << "passOR jet " << passOR2[idxs2[id2]] << std::endl;
      std::cout << "jet " << vec2.Pt() << " " << vec2.Eta() << " " << vec2.Phi() << std::endl;

    } 
  */
  }

  //std::cout << "dR " << dR << std::endl;

  return dR;

}

std::vector<std::string> AddWeightBranches(std::vector<std::string> &inBranches)
{

  inBranches.push_back("WeightEventsJVT_JET_JvtEfficiency__1down");
  inBranches.push_back("WeightEventsJVT_JET_JvtEfficiency__1up");

  // inBranches.push_back("WeightEventsJVT_JET_RelativeNonClosure_AFII__1down");
  // inBranches.push_back("WeightEventsJVT_JET_RelativeNonClosure_AFII__1up");

  inBranches.push_back("WeightEventsPU_PRW_DATASF__1down");
  inBranches.push_back("WeightEventsPU_PRW_DATASF__1up");
  //inBranches.push_back("WeightEventsSF_global_EG_SCALE_AF2__1down");
  //inBranches.push_back("WeightEventsSF_global_EG_SCALE_AF2__1up");
  //inBranches.push_back("WeightEventsSF_global_MUON_SAGITTA_RESBIAS__1down");
  //inBranches.push_back("WeightEventsSF_global_MUON_SAGITTA_RESBIAS__1up");
  //inBranches.push_back("WeightEventsSF_global_MUON_SAGITTA_RHO__1down");
  //inBranches.push_back("WeightEventsSF_global_MUON_SAGITTA_RHO__1up");
  //inBranches.push_back("WeightEvents_trigger_single_EG_SCALE_AF2__1down");
  //inBranches.push_back("WeightEvents_trigger_single_EG_SCALE_AF2__1up");
  //inBranches.push_back("WeightEvents_trigger_single_MUON_SAGITTA_RESBIAS__1down");
  //inBranches.push_back("WeightEvents_trigger_single_MUON_SAGITTA_RESBIAS__1up");
  //inBranches.push_back("WeightEvents_trigger_single_MUON_SAGITTA_RHO__1down");
  //inBranches.push_back("WeightEvents_trigger_single_MUON_SAGITTA_RHO__1up");
  inBranches.push_back("WeightEventsbTag_FT_EFF_B_systematics__1down");
  inBranches.push_back("WeightEventsbTag_FT_EFF_B_systematics__1up");
  inBranches.push_back("WeightEventsbTag_FT_EFF_C_systematics__1down");
  inBranches.push_back("WeightEventsbTag_FT_EFF_C_systematics__1up");
  inBranches.push_back("WeightEventsbTag_FT_EFF_Light_systematics__1down");
  inBranches.push_back("WeightEventsbTag_FT_EFF_Light_systematics__1up");
  inBranches.push_back("WeightEventsbTag_FT_EFF_extrapolation__1down");
  inBranches.push_back("WeightEventsbTag_FT_EFF_extrapolation__1up");
  inBranches.push_back("WeightEventsbTag_FT_EFF_extrapolation_from_charm__1down");
  inBranches.push_back("WeightEventsbTag_FT_EFF_extrapolation_from_charm__1up");

  // inBranches.push_back("WeightEventsbTag_JET_RelativeNonClosure_AFII__1down");
  // inBranches.push_back("WeightEventsbTag_JET_RelativeNonClosure_AFII__1up");
  //inBranches.push_back("WeightEventselSF_EG_SCALE_AF2__1down");
  //inBranches.push_back("WeightEventselSF_EG_SCALE_AF2__1up");
  //inBranches.push_back("WeightEventselSF_MUON_SAGITTA_RESBIAS__1down");
  //inBranches.push_back("WeightEventselSF_MUON_SAGITTA_RESBIAS__1up");
  //inBranches.push_back("WeightEventselSF_MUON_SAGITTA_RHO__1down");
  //inBranches.push_back("WeightEventselSF_MUON_SAGITTA_RHO__1up");
  //inBranches.push_back("WeightEventsmuSF_EG_SCALE_AF2__1down");
  //inBranches.push_back("WeightEventsmuSF_EG_SCALE_AF2__1up");
  //inBranches.push_back("WeightEventsmuSF_MUON_SAGITTA_RESBIAS__1down");
  //inBranches.push_back("WeightEventsmuSF_MUON_SAGITTA_RESBIAS__1up");
  //inBranches.push_back("WeightEventsmuSF_MUON_SAGITTA_RHO__1down");
  //inBranches.push_back("WeightEventsmuSF_MUON_SAGITTA_RHO__1up");
  inBranches.push_back("WeightEventselSF_EL_EFF_ChargeIDSel_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_ChargeIDSel_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_ChargeIDSel_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventselSF_EL_EFF_ChargeIDSel_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_ChargeIDSel_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_ChargeIDSel_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventselSF_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventselSF_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventselSF_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventselSF_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventselSF_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventselSF_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventselSF_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventselSF_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventselSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down");
  inBranches.push_back("WeightEventselSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventsSF_global_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEvents_trigger_single_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_STAT__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_STAT__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_STAT__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_SYS__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_SYS__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_SYS__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_ISO_STAT__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_ISO_STAT__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_ISO_STAT__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_ISO_STAT__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_ISO_STAT__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_ISO_STAT__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_ISO_SYS__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_ISO_SYS__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_ISO_SYS__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_ISO_SYS__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_ISO_SYS__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_ISO_SYS__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_STAT__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_STAT__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_STAT__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_STAT__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_STAT__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_STAT__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_STAT_LOWPT__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_STAT_LOWPT__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_STAT_LOWPT__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_STAT_LOWPT__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_STAT_LOWPT__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_STAT_LOWPT__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_SYS__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_SYS__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_SYS__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_SYS__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_SYS__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_SYS__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_SYS_LOWPT__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_SYS_LOWPT__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_SYS_LOWPT__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_RECO_SYS_LOWPT__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_RECO_SYS_LOWPT__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_RECO_SYS_LOWPT__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TTVA_STAT__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TTVA_STAT__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TTVA_STAT__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TTVA_STAT__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TTVA_STAT__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TTVA_STAT__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TTVA_SYS__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TTVA_SYS__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TTVA_SYS__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TTVA_SYS__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TTVA_SYS__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TTVA_SYS__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TrigStatUncertainty__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TrigStatUncertainty__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TrigStatUncertainty__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TrigStatUncertainty__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TrigStatUncertainty__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TrigStatUncertainty__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TrigSystUncertainty__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TrigSystUncertainty__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TrigSystUncertainty__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_TrigSystUncertainty__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_TrigSystUncertainty__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_TrigSystUncertainty__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_STAT__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_STAT__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_STAT__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_STAT__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_STAT__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_STAT__1up");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_SYS__1down");
  inBranches.push_back("WeightEventsmuSF_MUON_EFF_BADMUON_SYS__1up");
  inBranches.push_back("WeightEventsSF_global_MUON_EFF_BADMUON_SYS__1up");
  inBranches.push_back("WeightEvents_trigger_single_MUON_EFF_BADMUON_SYS__1up");


  return inBranches;
}


bool PassTrigger(const ROOT::VecOps::RVec<int> triggerVec) {

	for(unsigned int i=0; i < triggerVec.size(); i++){
		if(triggerVec[i] > 0) return true;
	}
	return false;

}

