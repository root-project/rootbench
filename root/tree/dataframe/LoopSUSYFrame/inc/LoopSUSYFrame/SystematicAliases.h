#ifndef SYSTEMATIC_ALIASES_H
#define SYSTEMATIC_ALIASES_H

#include <ROOT/RDataFrame.hxx>
#include <string>

// This file is for a single function, that replaces the old LoopSUSYCore
// Differently than for the old system we have to set the aliases for all branches that can change for every variation
// this is a long file, but the branch setting is different for every variation
// and I didn't yet think of how to make this more compact

inline auto SetAliases(ROOT::RDataFrame &inDataFrame, const int mcChan, const bool isMCa, const bool isMCd, const bool isMCe, const double sumOfWeights, const std::string &syst, const bool includeIFF)
{

	bool isData = false;
	if (mcChan < 99999)
		isData = true;

	auto withMCchan = inDataFrame.Define("ChannelNumber", LambdaMaker::GetMCchan(mcChan))
						  .Define("nVx", "NumPrimaryVertices")
						  .Define("mu", "AverageInteractionsPerCrossing")
						  .Define("WeightLumi", LambdaMaker::LumiWeightCalc(sumOfWeights, isMCa, isMCd, isMCe))
						  .Define("PassGenFilterMET", LambdaMaker::MCFiltMET(isData), {"ChannelNumber", "GenFiltMET"})
						  .Define("PassGenFilterMETWt", LambdaMaker::MCFiltMETWt(isData), {"ChannelNumber", "GenFiltMET"})
						  .Define("PassGenFilterHT", LambdaMaker::MCFiltHT(isData), {"ChannelNumber", "GenFiltHT"})
						  .Define("PassGenFilterMETHT", LambdaMaker::MCFiltMETHT(isData), {"ChannelNumber", "GenFiltMET", "GenFiltHT"})
						  .Define("PassGenFilterMETHTWt", LambdaMaker::MCFiltMETHTWt(isData), {"ChannelNumber", "GenFiltMET", "GenFiltHT"});

	auto withMCOnlyVars = withMCchan;

	std::cout << "Running Systematic ==> " << syst << std::endl;

	if (syst == "NONE" || syst == "Nominal" || syst == "WEIGHTS")
	{
		auto namelist = withMCOnlyVars.GetColumnNames();
		auto outDataFrame2 = withMCOnlyVars;
		for (const auto &sys : namelist)
		{
			if (sys.find("_Nominal") != std::string::npos)
			{
				std::size_t pos = sys.find("_Nominal"); // position of "live" in str
				// std::cout << sys.substr (0, pos) <<" "<< sys << std::endl;
				const auto c = sys.substr(0, pos);
				// if (c != "flavlep" && c!="Typelep") {
				withMCOnlyVars = outDataFrame2;
				auto outDataFrame = withMCOnlyVars.Define(c, sys);
				outDataFrame2 = outDataFrame;
				// }
			}
		}
		return outDataFrame2;
	}
	else
	{
		auto namelist = withMCOnlyVars.GetColumnNames();
		auto outDataFrame2 = withMCOnlyVars;

		for (const auto &sys : namelist)
		{

			if (sys.find(syst) != std::string::npos && sys.find("HLT") == std::string::npos)
			{
				std::size_t pos = sys.find(syst); // position of "live" in str
				if (sys.find("_" + syst) != std::string::npos) {pos = pos;}
				else{pos = pos+1;}				
				const auto c = sys.substr(0, pos - 1);
				// std::cout << " Systematic ==>" << sys.substr(0, pos - 1) << " " << sys << std::endl;
				withMCOnlyVars = outDataFrame2;
				auto outDataFrame = withMCOnlyVars.Define(c, sys);
				outDataFrame2 = outDataFrame;
			}

		}
		withMCOnlyVars = outDataFrame2;


		for (const auto &sysvar : namelist)
		{
			if (sysvar.find("HLT_") != std::string::npos && sysvar.find("Nominal") != std::string::npos)
			{
				std::size_t pos = sysvar.find("Nominal"); // position of "live" in str
				if (sysvar.find("_Nominal") != std::string::npos) {pos = pos;}
				else {pos = pos + 1;}
				const auto c = sysvar.substr(0, pos - 1);
				// std::cout << sysvar.substr(0, pos - 1) << " " << "_Nominal" << std::endl;
				withMCOnlyVars = outDataFrame2;
				auto outDataFrame = withMCOnlyVars.Define(c, sysvar);
				outDataFrame2 = outDataFrame;
			}
		}

		if (syst.find("EG_") != std::string::npos)
		{
			withMCOnlyVars = outDataFrame2;
			auto outDataFrame = withMCOnlyVars.Define("ptjets", "ptjets_Nominal")
									.Define("isBjets", "isBjets_Nominal")
									.Define("etajets", "etajets_Nominal")
									.Define("phijets", "phijets_Nominal")
									.Define("massjets", "massjets_Nominal")
									.Define("isWhichjet", "isWhichjet_Nominal")									
									.Define("WeightEventsPU", "WeightEventsPU_Nominal")
									.Define("WeightEventsJVT", "WeightEventsJVT_Nominal")
									.Define("WeightEventsbTag", "WeightEventsbTag_Nominal");
			outDataFrame2 = outDataFrame;
		}
		if (syst.find("MUON_") != std::string::npos)
		{
			withMCOnlyVars = outDataFrame2;
			auto outDataFrame = withMCOnlyVars.Define("ptjets", "ptjets_Nominal")
									.Define("isBjets", "isBjets_Nominal")
									.Define("etajets", "etajets_Nominal")
									.Define("phijets", "phijets_Nominal")
									.Define("massjets", "massjets_Nominal")
									.Define("isWhichjet", "isWhichjet_Nominal")	
									.Define("WeightEventsPU", "WeightEventsPU_Nominal")
									.Define("WeightEventsJVT", "WeightEventsJVT_Nominal")
									.Define("WeightEventsbTag", "WeightEventsbTag_Nominal");
			outDataFrame2 = outDataFrame;
		}
		if (syst.find("MET_") != std::string::npos)
		{
			withMCOnlyVars = outDataFrame2;
			auto outDataFrame = withMCOnlyVars.Define("ptleptons", "ptleptons_Nominal")
									.Define("phileptons", "phileptons_Nominal")
									.Define("etaleptons", "etaleptons_Nominal")
									.Define("isSignallep", "isSignallep_Nominal")
									.Define("isMediumlep", "isMediumlep_Nominal")
									.Define("massleptons", "massleptons_Nominal")
									.Define("Originlep", "Originlep_Nominal")
									.Define("flavlep", "flavlep_Nominal")
									.Define("Typelep", "Typelep_Nominal")
									.Define("d0sig", "d0sig_Nominal")
									.Define("z0sinTheta", "z0sinTheta_Nominal")
									.Define("passORlep", "passORlep_Nominal")
									.Define("ptjets", "ptjets_Nominal")
									.Define("isBjets", "isBjets_Nominal")
									.Define("etajets", "etajets_Nominal")
									.Define("phijets", "phijets_Nominal")
									.Define("massjets", "massjets_Nominal")
									.Define("isWhichjet", "isWhichjet_Nominal")	
									.Define("passORjet", "passORjet_Nominal")
									.Define("LepIsoGradient","LepIsoGradient_Nominal")
									.Define("LepIsoFCLoose","LepIsoFCLoose_Nominal")
									.Define("WeightEventsPU", "WeightEventsPU_Nominal")
									.Define("WeightEventsJVT", "WeightEventsJVT_Nominal")
									.Define("WeightEventsbTag", "WeightEventsbTag_Nominal")
									.Define("WeightEventselSF", "WeightEventselSF_Nominal")
									.Define("WeightEventsmuSF", "WeightEventsmuSF_Nominal")
									.Define("WeightEvents_trigger_single", "WeightEvents_trigger_single_Nominal")
									.Define("WeightEventsSF_global", "WeightEventsSF_global_Nominal");
			outDataFrame2 = outDataFrame;
			if (includeIFF)
			{
				std::cout << "Adding IFF Branch " << std::endl;
				auto forIFF = outDataFrame2;
				auto outDataFrame3 = forIFF.Define("IFFTypelep", "IFFTypelep_Nominal");
				outDataFrame2 = outDataFrame3;
			}
		}
		if (syst.find("JET_") != std::string::npos)
		{
			withMCOnlyVars = outDataFrame2;
			auto outDataFrame = withMCOnlyVars.Define("ptleptons", "ptleptons_Nominal")
									.Define("phileptons", "phileptons_Nominal")
									.Define("etaleptons", "etaleptons_Nominal")
									.Define("isSignallep", "isSignallep_Nominal")
									.Define("isMediumlep", "isMediumlep_Nominal")
									.Define("Originlep", "Originlep_Nominal")
									.Define("massleptons", "massleptons_Nominal")
									.Define("flavlep", "flavlep_Nominal")
									.Define("Typelep", "Typelep_Nominal")
									.Define("d0sig", "d0sig_Nominal")
									.Define("z0sinTheta", "z0sinTheta_Nominal")
									.Define("LepIsoGradient","LepIsoGradient_Nominal")
									.Define("LepIsoFCLoose","LepIsoFCLoose_Nominal")
									.Define("WeightEvents_trigger_single", "WeightEvents_trigger_single_Nominal")
									.Define("WeightEventsPU", "WeightEventsPU_Nominal")
									.Define("WeightEventselSF", "WeightEventselSF_Nominal")
									.Define("WeightEventsmuSF", "WeightEventsmuSF_Nominal")
									.Define("WeightEventsSF_global", "WeightEventsSF_global_Nominal");
			outDataFrame2 = outDataFrame;
			if (includeIFF)
			{
				auto forIFF = outDataFrame2;
				std::cout << "Adding IFF Branch " << std::endl;
				auto outDataFrame3 = forIFF.Define("IFFTypelep", "IFFTypelep_Nominal");
				outDataFrame2 = outDataFrame3;
			}
		}

		return outDataFrame2;
	}
}

#endif
