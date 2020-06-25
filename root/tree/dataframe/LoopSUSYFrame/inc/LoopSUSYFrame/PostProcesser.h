#include <ROOT/RDataFrame.hxx>
#include <type_traits>
#include <memory>
#include <ROOT/RSnapshotOptions.hxx>
#include "TROOT.h"
#include <TFile.h>
#include "TSystem.h"
#include <TString.h>
#include <TObjArray.h>
#include <Compression.h>
#include <iostream>

template <typename TDF, typename AliasedDF = decltype(std::declval<TDF>().Alias("", ""))>
std::unique_ptr<AliasedDF>
ApplyAliases(TDF &df, const std::vector<std::string> &out, const std::vector<std::string> &in)
{
	auto latestDF = std::make_unique<AliasedDF>(df.Alias(out[0], in[0]));

	for (auto i = 1u; i < out.size(); ++i)
		latestDF = std::make_unique<AliasedDF>(latestDF->Alias(out[i], in[i]));

	return latestDF;
}

inline void PostProcess(const std::string &treeBaseName, const std::string &outFileName, const std::vector<std::string> &syst, const bool enable_MT) {

	std::cerr << "This function is not needed anymore and you should not be using it!" << std::endl;

	std::cerr << "Starting post-processing" << std::endl;
	std::string mergedFileName = outFileName + ".root";

	for (size_t j = 0; j < syst.size(); j++) {
		std::cerr << "  processing " << syst[j] << std::endl;

		std::string inputFile = outFileName + "_" + syst[j] + ".root";

		std::cout << "inputFile " << inputFile << std::endl;

		std::unique_ptr<TFile> fIn = std::make_unique<TFile>( TString(inputFile) );
		if (fIn->IsZombie()) {
			std::cerr << "Couldn't find " << inputFile << std::endl;
			continue;
		}

		std::string this_tree = treeBaseName + "_" + syst[j];
		std::string new_tree = treeBaseName + "_" + syst[j];

		std::cout << "this_tree " << this_tree << std::endl;

		std::size_t found = treeBaseName.find("data");
		if (found != std::string::npos) {
			new_tree = "data";
		}

		std::cout << "before getting the tree" << std::endl;

		TTree* tree = (TTree*)fIn->Get( TString(this_tree) );
		if (tree->IsZombie()) {
			std::cerr << "Couldn't find " << this_tree << std::endl;
			continue;
		}

		std::cout << "before getting the branches" << std::endl;

		TObjArray *myarray = tree->GetListOfBranches();
		if (myarray->GetEntries() == 0) {
			std::cerr << "Empty tree for " << this_tree << std::endl;
			continue;
		}

		std::vector<std::string> inBranches;
		std::vector<std::string> outBranches;

		std::vector<std::string> ForAliasInBranches;
		std::vector<std::string> ForAliasOutBranches;

		for (int i = 0; i < myarray->GetEntries(); ++i) {
			std::string temp_branch = myarray->At(i)->GetName();
			inBranches.push_back(temp_branch);

			std::size_t found_sys = temp_branch.find(syst[j]);
			if ( found_sys != std::string::npos ) {

				std::string new_name = temp_branch.substr(found_sys + syst[j].size() + 1);
				outBranches.push_back(new_name);

				ForAliasInBranches.push_back(temp_branch);
				ForAliasOutBranches.push_back(new_name);

			}
			else {
				outBranches.push_back(temp_branch);
			}
		}

		if (enable_MT) ROOT::EnableImplicitMT();

		ROOT::RDataFrame dataFrame( *tree );
		auto aliasedDF = ApplyAliases(dataFrame, ForAliasOutBranches, ForAliasInBranches);

		if (j == 0) {
			aliasedDF->Snapshot(new_tree, mergedFileName, outBranches);
		}
		else {
			std::string fMode = "UPDATE";            //< Mode of creation of output file
			ROOT::ECompressionAlgorithm fCompressionAlgorithm = ROOT::kLZ4; //< Compression algorithm of output file
			int fCompressionLevel = 4;                 //< Compression level of output file
			int fAutoFlush = 0;                        //< AutoFlush value for output tree
			int fSplitLevel = 99;                      //< Split level of output tree
			bool fLazy = false;                        //< Delay the snapshot of the dataset
			ROOT::RDF::RSnapshotOptions myOptions(fMode, fCompressionAlgorithm, fCompressionLevel, fAutoFlush, fSplitLevel, fLazy);
			aliasedDF->Snapshot(new_tree, mergedFileName, outBranches, myOptions);
		}

		fIn->Close();

	}

	std::cerr << "Post-processing done" << std::endl;

}

inline void SplitTarget(const std::string &treeBaseName, const std::string &outFileName) {

	std::cerr << "Split torch ntuple" << std::endl;
	std::string mergedFileName = outFileName + "_NONE.root";

	std::unique_ptr<TFile> fIn = std::make_unique<TFile>( TString(mergedFileName) );
	if (fIn->IsZombie()) {
		std::cerr << "Couldn't find " << mergedFileName << std::endl;
		return;
	}

	std::string new_tree = treeBaseName + "_NONE";
	TTree* tree = (TTree*)fIn->Get( TString(new_tree) );
	if (tree->IsZombie()) {
		std::cerr << "Couldn't find " << new_tree << std::endl;
		return;
	}

	ROOT::RDataFrame dataFrame( *tree );

	auto goodDF = dataFrame.Filter([](const int storedValue) { return storedValue == 1; }, {"target"}, "Select signal \t");
	auto cutflow_report = goodDF.Report();
	int ngood_entries = (--std::end(cutflow_report))->GetPass();
	auto subDF = dataFrame.Range(ngood_entries);
	auto badDF = subDF.Filter([](const int storedValue) { return storedValue == 0; }, {"target"}, "Select background \t");

	std::string goodFileName = outFileName + ".goodPairs.root";
	std::string badFileName = outFileName + ".badPairs.root";

	goodDF.Snapshot(new_tree, goodFileName);
	badDF.Snapshot(new_tree, badFileName);

	fIn->Close();

	std::string trainFileName = outFileName + ".HTag.root";

	gSystem->Exec(("hadd -f " + trainFileName + " " + goodFileName + " " + badFileName).c_str());
	gSystem->Exec(("rm -f " + goodFileName + " " + badFileName).c_str());
	gSystem->Exec(("mv " + mergedFileName + " " + outFileName + ".Proof.root").c_str());

	std::cerr << "Splitting done" << std::endl;

}
