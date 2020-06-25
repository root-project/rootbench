#include <LoopSUSYFrame/LoopSUSYThTh.h>
#include <LoopSUSYFrame/GenericHelpers.h>
#include <LoopSUSYFrame/LeptonHelpers.h>
#include <LoopSUSYFrame/SystematicAliases.h>

#include <ROOT/RSnapshotOptions.hxx>
#include <ROOT/RDFHelpers.hxx>
#include <TLorentzVector.h>
#include <Compression.h>

#include <array>
#include <iostream>

const float mH = 125.;
const float mW = 80.385;
const float mTop = 172.5;


LoopSUSYThTh :: LoopSUSYThTh(TTree *tree) : LoopSUSYFrame( tree )
{
	// Figure out something nicer for the conf files
	std::string weightsFile = "weights.txt";
	std::string biasFile = "biases.txt";
	std::string normFile = "norm.txt";

	theNet = myNN(weightsFile, biasFile, normFile);
}

std::pair<CutFlowReport, SnapshotResult>  LoopSUSYThTh :: Process(ROOT::RDataFrame &dataFrame, const std::string &syst)
{

	std::vector<std::string> outColumns = DefineBranches(syst);
	auto aliasedDataFrame = SetAliases(dataFrame, m_mcChan, m_isMCa, m_isMCd, m_isMCe, m_sumOfWeights, syst, false); // includeIFF== false

	auto my_data = aliasedDataFrame
		.Filter([](const bool storedValue) { return storedValue; }, {"PassGenFilterMETHT"}, "Generator filters (MC only) \t\t")
		.Filter([](const bool storedValue) { return storedValue; }, {"PassGenFilterMETHTWt"}, "Generator filters Wt (MC only) \t\t")
		.Filter([](const bool storedValue) { return !storedValue; }, {"cleaningVeto"}, "Cleaning veto\t\t\t\t");

	// This is needed because in MC we need to access the lepton Origin
	auto choose_datamc = [&my_data, &syst](bool isdata) {
		if (isdata) {
			return my_data.Define("lepIdxs", LambdaMaker::FindLeptons(7000., 5000.), GetLeptonBranches(isdata, syst));
		}
		else {
			return my_data.Define("lepIdxs", LambdaMaker::FindLeptonsMC(7000., 5000.), GetLeptonBranches(isdata, syst));
		}
	};

	std::string custom_trg2016 = "HLT_mu24_ivarloose";
	if(!m_isData) custom_trg2016 = "HLT_mu24_ivarloose_L1MU15";

	auto with_leptons = choose_datamc(m_isData).Define("nlep", CountObjects, {"lepIdxs"})
	.Filter([](const int nlep) { return nlep < 3; }, {"nlep"}, "Not more than 2 leptons\t\t\t")
	.Filter([](const int nlep) { return nlep > 0; }, {"nlep"}, "At least 1 lepton\t\t\t")
	.Define("triggerEl2015", ROOT::RDF::PassAsVec<3,int>(PassTrigger), {"HLT_e24_lhmedium_L1EM20VH", "HLT_e60_lhmedium", "HLT_e120_lhloose"} )
	.Define("triggerEl2016", ROOT::RDF::PassAsVec<3,int>(PassTrigger), {"HLT_e24_lhtight_nod0_ivarloose", "HLT_e60_lhmedium_nod0", "HLT_e140_lhloose_nod0"} )
	.Define("triggerEl2016_exc", ROOT::RDF::PassAsVec<4,int>(PassTrigger), {"HLT_e24_lhmedium_nod0_L1EM20VH", "HLT_e24_lhtight_nod0_ivarloose", "HLT_e60_lhmedium_nod0", "HLT_e140_lhloose_nod0"} )
	.Define("triggerEl2017", ROOT::RDF::PassAsVec<3,int>(PassTrigger),{"HLT_e26_lhtight_nod0_ivarloose", "HLT_e60_lhmedium_nod0", "HLT_e140_lhloose_nod0"} )
	.Define("triggerEl2018", ROOT::RDF::PassAsVec<3,int>(PassTrigger),{"HLT_e26_lhtight_nod0_ivarloose", "HLT_e60_lhmedium_nod0", "HLT_e140_lhloose_nod0"} )
	.Define("triggerMu2015", ROOT::RDF::PassAsVec<2,int>(PassTrigger), {"HLT_mu24_ivarloose","HLT_mu50"} )
	.Define("triggerMu2016_p1", ROOT::RDF::PassAsVec<2,int>(PassTrigger), {custom_trg2016,"HLT_mu50"} )
	.Define("triggerMu2016_p2", ROOT::RDF::PassAsVec<2,int>(PassTrigger), {"HLT_mu24_ivarmedium","HLT_mu50"} )
	.Define("triggerMu2017", ROOT::RDF::PassAsVec<2,int>(PassTrigger),{"HLT_mu26_ivarmedium","HLT_mu50"} )
	.Define("triggerMu2018", ROOT::RDF::PassAsVec<2,int>(PassTrigger),{"HLT_mu26_ivarmedium","HLT_mu50"} )
	.Define("triggerMET2015",ROOT::RDF::PassAsVec<1,int>(PassTrigger),{"HLT_xe70_mht"})
	.Define("triggerMET2016_p1",ROOT::RDF::PassAsVec<2,int>(PassTrigger),{"HLT_xe90_mht_L1XE50", "HLT_xe80_tc_lcw_L1XE50"})
	.Define("triggerMET2016_p2",ROOT::RDF::PassAsVec<1,int>(PassTrigger),{"HLT_xe90_mht_L1XE50"})
	.Define("triggerMET2016_p3",ROOT::RDF::PassAsVec<1,int>(PassTrigger),{"HLT_xe110_mht_L1XE50"})
	.Define("triggerMET2017_p1",ROOT::RDF::PassAsVec<2,int>(PassTrigger),{"HLT_xe90_pufit_L1XE50","HLT_xe110_pufit_L1XE55"})
	.Define("triggerMET2017_p2",ROOT::RDF::PassAsVec<3,int>(PassTrigger),{"HLT_xe100_pufit_L1XE50","HLT_xe100_pufit_L1XE55","HLT_xe110_pufit_L1XE55"})
	.Define("triggerMET2017_p3",ROOT::RDF::PassAsVec<2,int>(PassTrigger),{"HLT_xe110_pufit_L1XE50","HLT_xe110_pufit_L1XE55"})
	.Define("triggerMET2017_p4",ROOT::RDF::PassAsVec<1,int>(PassTrigger),{"HLT_xe110_pufit_L1XE50"})
	.Define("triggerMET2018_p1",ROOT::RDF::PassAsVec<2,int>(PassTrigger),{"HLT_xe110_pufit_L1XE50","HLT_xe120_pufit_L1XE50"})
	.Define("triggerMET2018_p2",ROOT::RDF::PassAsVec<1,int>(PassTrigger),{"HLT_xe110_pufit_xe70_L1XE50"})
	.Filter([](const bool triggerEl2015, const bool triggerEl2016, const bool triggerEl2016_exc, const bool triggerEl2017,const bool triggerEl2018, const bool triggerMu2015, const bool triggerMu2016_p1, const bool triggerMu2016_p2, const bool triggerMu2017,const bool triggerMu2018, const bool triggerMET2015, const bool triggerMET2016_p1,const bool triggerMET2016_p2, const bool triggerMET2016_p3, const bool triggerMET2017_p1, const bool triggerMET2017_p2, const bool triggerMET2017_p3, const bool triggerMET2017_p4, const bool triggerMET2018_p1, const bool triggerMET2018_p2, const unsigned int RunNumber)
		{return 
		// Electron Triggers
		 (triggerEl2015 and RunNumber<297730)
		 or (triggerEl2016 and RunNumber >= 297730 and RunNumber <=302872 and RunNumber != 298687)
		 or (triggerEl2016_exc and RunNumber == 298687)
		 or (triggerEl2017 and RunNumber > 302872 and RunNumber <= 348197)
		 or (triggerEl2018 and RunNumber > 348197)
		 // Muons Triggers
		 or (triggerMu2015 and RunNumber<297730)
		 or (triggerMu2016_p1 and RunNumber >= 297730 and RunNumber < 300345)
		 or (triggerMu2016_p2 and RunNumber >= 300345 and RunNumber <= 302872)
		 or (triggerMu2017 and RunNumber > 302872 and RunNumber <= 348197)
		 or (triggerMu2018 and RunNumber > 348197 )
		 // MET Triggers
		or (triggerMET2015 and RunNumber<297730)
		or (triggerMET2016_p1 and RunNumber >= 297730 and RunNumber < 302394)
		or (triggerMET2016_p2 and RunNumber >= 302394 and RunNumber < 302873)
		or (triggerMET2016_p3 and RunNumber >= 302873 and RunNumber < 311482)
		or (triggerMET2017_p1 and RunNumber >= 311482 and RunNumber < 328394)
		or (triggerMET2017_p2 and RunNumber >= 328394 and RunNumber < 330471)
		or (triggerMET2017_p3 and RunNumber >= 330471 and RunNumber < 331976)
		or (triggerMET2017_p4 and RunNumber >= 331976 and RunNumber < 348197)
		or (triggerMET2018_p1 and RunNumber >= 348197 and RunNumber < 355274)
		or (triggerMET2018_p2 and RunNumber >= 355274 );
		}, {"triggerEl2015", "triggerEl2016", "triggerEl2016_exc", "triggerEl2017", "triggerEl2018","triggerMu2015", "triggerMu2016_p1", "triggerMu2016_p2", "triggerMu2017", "triggerMu2018", "triggerMET2015","triggerMET2016_p1","triggerMET2016_p2","triggerMET2016_p3","triggerMET2017_p1","triggerMET2017_p2","triggerMET2017_p3","triggerMET2017_p4","triggerMET2018_p1","triggerMET2018_p2","RunNumber"})
	.Define("jetIdxs", LambdaMaker::FindJets(30000.), {"ptjets", "etajets", "passORjet"})
	.Define("MET", "float(EtMiss_tst/1000.)")
	.Define("MET_soft", "Etmiss_PVSoftTrk/1000.")
	.Alias("METphi", "EtMiss_tstPhi")
	.Alias("METsig", "EtMiss_SigObj")
	.Define("lep1pT", LambdaMaker::FindNLeading(0, true), {"ptleptons", "lepIdxs"})
	.Filter([](const float ptlep, const float MET) { return ptlep > 30. or (ptlep <= 30. and MET > 200.); }, {"lep1pT", "MET"}, "Leading lepton pT > 30 GeV\t\t")
	.Define("njet", CountObjects, {"jetIdxs"})
	.Filter([](const int njet) { return njet > 3; }, {"njet"}, "At least 4 jets\t\t\t\t")
	.Define("bjetIdxs", LambdaMaker::FindBJets(30000.), {"ptjets", "etajets", "passORjet", "isBjets"})
	.Define("nbjet", CountObjects, {"bjetIdxs"})
	.Filter([](const int nbjet) { return nbjet > 2; }, {"nbjet"}, "At least 3 b-jets\t\t\t")
	.Filter([](const int nbjet, const float metsig) { return (nbjet > 3 || metsig>7); }, {"nbjet","METsig"}, "At least 4 b-jets or METsig>7\t\t");

	auto cutflow_report = with_leptons.Report();

	// Continue by setting up the final tree branches
	auto my_final_data = with_leptons.Define("WeightEvents_trigger", "WeightEvents_trigger_single")
	                     .Define("njet60", LambdaMaker::CountObjectsAbovePt(60000.), {"jetIdxs", "ptjets"})
	                     .Define("njet100", LambdaMaker::CountObjectsAbovePt(100000.), {"jetIdxs", "ptjets"})
	                     .Define("jet1pT", LambdaMaker::FindNLeading(0, true), {"ptjets", "jetIdxs"})
	                     .Define("jet2pT", LambdaMaker::FindNLeading(1, true), {"ptjets", "jetIdxs"})
	                     .Define("jet3pT", LambdaMaker::FindNLeading(2, true), {"ptjets", "jetIdxs"})
	                     .Define("jet4pT", LambdaMaker::FindNLeading(3, true), {"ptjets", "jetIdxs"})
	                     .Define("jet5pT", LambdaMaker::FindNLeading(4, true), {"ptjets", "jetIdxs"})
	                     .Define("jet6pT", LambdaMaker::FindNLeading(5, true), {"ptjets", "jetIdxs"})
	                     .Define("jet1eta", LambdaMaker::FindNLeading(0, false), {"etajets", "jetIdxs"})
	                     .Define("jet2eta", LambdaMaker::FindNLeading(1, false), {"etajets", "jetIdxs"})
	                     .Define("jet3eta", LambdaMaker::FindNLeading(2, false), {"etajets", "jetIdxs"})
	                     .Define("jet4eta", LambdaMaker::FindNLeading(3, false), {"etajets", "jetIdxs"})
	                     .Define("jet5eta", LambdaMaker::FindNLeading(4, false), {"etajets", "jetIdxs"})
	                     .Define("jet6eta", LambdaMaker::FindNLeading(5, false), {"etajets", "jetIdxs"})
	                     .Define("jet1phi", LambdaMaker::FindNLeading(0, false), {"phijets", "jetIdxs"})
	                     .Define("jet2phi", LambdaMaker::FindNLeading(1, false), {"phijets", "jetIdxs"})
	                     .Define("jet3phi", LambdaMaker::FindNLeading(2, false), {"phijets", "jetIdxs"})
	                     .Define("jet4phi", LambdaMaker::FindNLeading(3, false), {"phijets", "jetIdxs"})
	                     .Define("jet5phi", LambdaMaker::FindNLeading(4, false), {"phijets", "jetIdxs"})
	                     .Define("jet6phi", LambdaMaker::FindNLeading(5, false), {"phijets", "jetIdxs"})
	                     .Define("jet1mass", LambdaMaker::FindNLeading(0, true), {"massjets", "jetIdxs"})
	                     .Define("jet2mass", LambdaMaker::FindNLeading(1, true), {"massjets", "jetIdxs"})
	                     .Define("jet3mass", LambdaMaker::FindNLeading(2, true), {"massjets", "jetIdxs"})
	                     .Define("jet4mass", LambdaMaker::FindNLeading(3, true), {"massjets", "jetIdxs"})
	                     .Define("jet5mass", LambdaMaker::FindNLeading(4, true), {"massjets", "jetIdxs"})
	                     .Define("jet6mass", LambdaMaker::FindNLeading(5, true), {"massjets", "jetIdxs"})
	                     .Define("jet1bTagBin", LambdaMaker::FindNLeading_Int(0, false), {"isBjets", "jetIdxs"})
	                     .Define("jet2bTagBin", LambdaMaker::FindNLeading_Int(1, false), {"isBjets", "jetIdxs"})
	                     .Define("jet3bTagBin", LambdaMaker::FindNLeading_Int(2, false), {"isBjets", "jetIdxs"})
	                     .Define("jet4bTagBin", LambdaMaker::FindNLeading_Int(3, false), {"isBjets", "jetIdxs"})
	                     .Define("jet5bTagBin", LambdaMaker::FindNLeading_Int(4, false), {"isBjets", "jetIdxs"})
	                     .Define("jet6bTagBin", LambdaMaker::FindNLeading_Int(5, false), {"isBjets", "jetIdxs"})
	                     .Define("bjet1pT", LambdaMaker::FindNLeading(0, true), {"ptjets", "bjetIdxs"})
	                     .Define("bjet2pT", LambdaMaker::FindNLeading(1, true), {"ptjets", "bjetIdxs"})
	                     .Define("bjet3pT", LambdaMaker::FindNLeading(2, true), {"ptjets", "bjetIdxs"})
	                     .Define("bjet4pT", LambdaMaker::FindNLeading(3, true), {"ptjets", "bjetIdxs"})
	                     .Define("bjet1eta", LambdaMaker::FindNLeading(0, false), {"etajets", "bjetIdxs"})
	                     .Define("bjet2eta", LambdaMaker::FindNLeading(1, false), {"etajets", "bjetIdxs"})
	                     .Define("bjet3eta", LambdaMaker::FindNLeading(2, false), {"etajets", "bjetIdxs"})
	                     .Define("bjet4eta", LambdaMaker::FindNLeading(3, false), {"etajets", "bjetIdxs"})
	                     .Define("bjet1phi", LambdaMaker::FindNLeading(0, false), {"phijets", "bjetIdxs"})
	                     .Define("bjet2phi", LambdaMaker::FindNLeading(1, false), {"phijets", "bjetIdxs"})
	                     .Define("bjet3phi", LambdaMaker::FindNLeading(2, false), {"phijets", "bjetIdxs"})
	                     .Define("bjet4phi", LambdaMaker::FindNLeading(3, false), {"phijets", "bjetIdxs"})
	                     .Define("bjet1mass", LambdaMaker::FindNLeading(0, true), {"massjets", "bjetIdxs"})
	                     .Define("bjet2mass", LambdaMaker::FindNLeading(1, true), {"massjets", "bjetIdxs"})
	                     .Define("bjet3mass", LambdaMaker::FindNLeading(2, true), {"massjets", "bjetIdxs"})
	                     .Define("bjet4mass", LambdaMaker::FindNLeading(3, true), {"massjets", "bjetIdxs"})
	                     .Define("lep1eta", LambdaMaker::FindNLeading(0), {"etaleptons", "lepIdxs"})
	                     .Define("lep1phi", LambdaMaker::FindNLeading(0), {"phileptons", "lepIdxs"})
	                     .Define("lep1flav", LambdaMaker::FindNLeading_Int(0), {"flavlep", "lepIdxs"})
	                     .Define("dPhiLepMET", DeltaPhi, {"lep1phi", "METphi"})
	                     .Define("mT", LambdaMaker::GetMT(false), {"lep1pT", "MET", "dPhiLepMET"})
	                     .Define("dPhimin", GetDeltaPhiMin, {"jetIdxs", "phijets", "METphi"})
	                     .Define("HT", LambdaMaker::GetHT(true), {"jetIdxs", "ptjets"})
	.Define("DRVars", Find_mbb_DR, {"ptjets", "etajets", "phijets", "massjets", "bjetIdxs", "isWhichjet"})
	.Define("DR_mbb", [](const std::pair<std::array<float, 3>, bool> &vars) { return vars.first[0]; }, {"DRVars"})
	.Define("DR_ptbb", [](const std::pair<std::array<float, 3>, bool> &vars) { return vars.first[1]; }, {"DRVars"})
	.Define("DR_truth", [](const std::pair<std::array<float, 3>, bool> &vars) { return vars.second; }, {"DRVars"})
	.Define("NNVars", LambdaMaker::GetNNvarsDetail(theNet), {"ptjets", "etajets", "phijets", "massjets", "isBjets", "jetIdxs", "isWhichjet", "labeljets_reco"})
	.Define("NN_mjj", [](const std::pair<std::array<float, 8>, std::pair<std::vector<float>,std::vector<int>>> &vars) { return vars.first[0]; }, {"NNVars"})
	.Define("NN_ptjj", [](const std::pair<std::array<float, 8>, std::pair<std::vector<float>,std::vector<int>>> &vars) { return vars.first[1]; }, {"NNVars"})
	.Define("NN_dRjj", [](const std::pair<std::array<float, 8>, std::pair<std::vector<float>,std::vector<int>>> &vars) { return vars.first[2]; }, {"NNVars"})
	.Define("NN_highscore", [](const std::pair<std::array<float, 8>, std::pair<std::vector<float>,std::vector<int>>> &vars) { return vars.first[3]; }, {"NNVars"})
	.Define("NN_nHiggs_07", [](const std::pair<std::array<float, 8>, std::pair<std::vector<float>,std::vector<int>>> &vars) { return vars.first[5]; }, {"NNVars"})
	.Define("NN_scores", [](const std::pair<std::array<float, 8>, std::pair<std::vector<float>,std::vector<int>>> &vars) { return (vars.second).first; }, {"NNVars"})
	.Define("NN_higgs_truth", [](const std::pair<std::array<float, 8>, std::pair<std::vector<float>,std::vector<int>>> &vars) { return (vars.second).second; }, {"NNVars"})
	.Define("WeightBR", [](const int N2decay){ if(N2decay==0) return 1.; else if (N2decay==1) return 1.; else if(N2decay==2) return 1.; else return 0.;}, {"NeutralinoTwoDecayType"});

	std::string outTreeName = m_outTreeName + "_" + syst;
	std::string	outFileName = m_outFileName + "_" + syst + ".root";

	std::pair<CutFlowReport,SnapshotResult> the_pair = std::make_pair(cutflow_report, my_final_data.Snapshot(outTreeName, outFileName, outColumns));

	return the_pair;

}


std::vector<std::string> LoopSUSYThTh :: DefineBranches(const std::string &syst)
{

	std::vector<std::string> outColumns;

	// Let's define the structure of the output tree
	outColumns.push_back("EventNumber");
	outColumns.push_back("WeightLumi");
	outColumns.push_back("nVx");
	outColumns.push_back("mu");
	outColumns.push_back("xsec");
	outColumns.push_back("WeightEventsPU");
	outColumns.push_back("WeightEventselSF");
	outColumns.push_back("WeightEventsmuSF");
	outColumns.push_back("WeightEvents");
	outColumns.push_back("WeightEventsJVT");
	outColumns.push_back("WeightEventsbTag");
	outColumns.push_back("WeightEvents_trigger_single");
	outColumns.push_back("jet1pT");
	outColumns.push_back("jet2pT");
	outColumns.push_back("jet3pT");
	outColumns.push_back("jet4pT");
	outColumns.push_back("jet5pT");
	outColumns.push_back("jet6pT");
	outColumns.push_back("jet1eta");
	outColumns.push_back("jet2eta");
	outColumns.push_back("jet3eta");
	outColumns.push_back("jet4eta");
	outColumns.push_back("jet5eta");
	outColumns.push_back("jet6eta");
	outColumns.push_back("jet1phi");
	outColumns.push_back("jet2phi");
	outColumns.push_back("jet3phi");
	outColumns.push_back("jet4phi");
	outColumns.push_back("jet5phi");
	outColumns.push_back("jet6phi");
	outColumns.push_back("jet1mass");
	outColumns.push_back("jet2mass");
	outColumns.push_back("jet3mass");
	outColumns.push_back("jet4mass");
	outColumns.push_back("jet5mass");
	outColumns.push_back("jet6mass");
	outColumns.push_back("jet1bTagBin");
	outColumns.push_back("jet2bTagBin");
	outColumns.push_back("jet3bTagBin");
	outColumns.push_back("jet4bTagBin");
	outColumns.push_back("jet5bTagBin");
	outColumns.push_back("jet6bTagBin");
	outColumns.push_back("bjet1pT");
	outColumns.push_back("bjet2pT");
	outColumns.push_back("bjet3pT");
	outColumns.push_back("bjet4pT");
	outColumns.push_back("bjet1eta");
	outColumns.push_back("bjet2eta");
	outColumns.push_back("bjet3eta");
	outColumns.push_back("bjet4eta");
	outColumns.push_back("bjet1phi");
	outColumns.push_back("bjet2phi");
	outColumns.push_back("bjet3phi");
	outColumns.push_back("bjet4phi");
	outColumns.push_back("bjet1mass");
	outColumns.push_back("bjet2mass");
	outColumns.push_back("bjet3mass");
	outColumns.push_back("bjet4mass");
	outColumns.push_back("mT");
	outColumns.push_back("DR_mbb");
	outColumns.push_back("DR_ptbb");
	outColumns.push_back("DR_truth");	
	outColumns.push_back("njet");
	outColumns.push_back("njet60");
	outColumns.push_back("njet100");
	outColumns.push_back("nbjet");
	outColumns.push_back("lep1pT");
	outColumns.push_back("lep1eta");
	outColumns.push_back("lep1phi");
	outColumns.push_back("lep1flav");
	outColumns.push_back("nlep");
	outColumns.push_back("MET");
	outColumns.push_back("METsig");
	outColumns.push_back("MET_soft");
	outColumns.push_back("dPhimin");
	outColumns.push_back("HT");
	outColumns.push_back("GenFiltMET");
	outColumns.push_back("GenFiltHT");
	outColumns.push_back("NN_mjj");
	outColumns.push_back("NN_ptjj");
	outColumns.push_back("NN_dRjj");
	outColumns.push_back("NN_highscore");
	outColumns.push_back("NN_nHiggs_07");
	outColumns.push_back("NN_scores");
	outColumns.push_back("NN_higgs_truth");
	outColumns.push_back("DecayType");
	outColumns.push_back("HFclass");
	outColumns.push_back("NeutralinoTwoDecayType");
	outColumns.push_back("WeightBR");

	outColumns.push_back("RunNumber");
	if (!m_isData) {
		if (syst == "WEIGHTS") {
			outColumns = AddWeightBranches(outColumns);
		}
	}
	
	return outColumns;

}

// stoph only helpers
std::pair<std::array<float, 5>, bool> Find_mbb_closest(const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &truthvec)
{

	float mbb_closest = -9999999999.;
	float ptbb_closest = -9999999999.;
	float dphibb_closest = -9999999999.;
	bool truth_closest = false;

	float Avg_mbb = 0.;
	float Avg_DRbb = 0.;

	int n_combinations = 0;

	for (short unsigned int ijet = 0; ijet < idxs.size(); ijet++) {

		int id_jet = idxs[ijet];
		TLorentzVector jet1;
		jet1.SetPtEtaPhiM(ptvec[id_jet], etavec[id_jet], phivec[id_jet], massvec[id_jet]);

		for (short unsigned int ijet2 = ijet + 1; ijet2 < idxs.size(); ijet2++) {

			int id_jet2 = idxs[ijet2];
			TLorentzVector jet2;
			jet2.SetPtEtaPhiM(ptvec[id_jet2], etavec[id_jet2], phivec[id_jet2], massvec[id_jet2]);

			float mbb_12 = (jet1 + jet2).M() / 1000.;

			n_combinations++;
			Avg_mbb += mbb_12;
			Avg_DRbb += jet1.DeltaR(jet2);

			if (std::fabs(mbb_12 - mH) < std::fabs(mbb_closest - mH)) {

				mbb_closest = mbb_12;
				ptbb_closest = (jet1 + jet2).Perp() / 1000.;
				dphibb_closest = std::fabs(jet1.DeltaPhi(jet2));
				if ((truthvec[id_jet]==25) && (truthvec[id_jet2]==25)){
					truth_closest = true;
				}
				else{
					truth_closest = false;
				}
			}
		}
	}

	Avg_mbb /= n_combinations;
	Avg_DRbb /= n_combinations;

	std::array<float, 5> the_vars = {float(mbb_closest), float(ptbb_closest), float(dphibb_closest), float(Avg_mbb), float(Avg_DRbb)};
	std::pair<std::array<float, 5>, bool> the_pair = std::make_pair(the_vars, truth_closest);

	return the_pair;

}

std::pair<std::array<float, 3>, bool> Find_mbb_DR(const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &truthvec)
{

	float mbb = 0.;
	float ptbb = 0.;
	float dphibb = 0.;
	float DRbb = 999999999.;
	bool truth_DR = false;

	for (short unsigned int ijet = 0; ijet < idxs.size(); ijet++) {

		int id_jet = idxs[ijet];
		TLorentzVector jet1;
		jet1.SetPtEtaPhiM(ptvec[id_jet], etavec[id_jet], phivec[id_jet], massvec[id_jet]);

		for (short unsigned int ijet2 = ijet + 1; ijet2 < idxs.size(); ijet2++) {

			int id_jet2 = idxs[ijet2];
			TLorentzVector jet2;
			jet2.SetPtEtaPhiM(ptvec[id_jet2], etavec[id_jet2], phivec[id_jet2], massvec[id_jet2]);

			double DRbb_12 = jet1.DeltaR(jet2);

			if ( DRbb_12 < DRbb ) {

				mbb =  (jet1 + jet2).M() / 1000.;
				ptbb = (jet1 + jet2).Perp() / 1000.;
				dphibb = std::fabs(jet1.DeltaPhi(jet2));
				DRbb = DRbb_12;
				if ((truthvec[id_jet]==25) && (truthvec[id_jet2]==25)){
					truth_DR = true;
				}
				else{
					truth_DR = false;
				}
			}
		}
	}

	std::array<float, 3> the_vars = {float(mbb), float(ptbb), float(dphibb)};
	std::pair<std::array<float, 3>, bool> the_pair = std::make_pair(the_vars, truth_DR);

	return the_pair;

}

