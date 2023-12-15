#include "TestWorkspaces.h"

#include <RooMsgService.h>
#include <RooStats/HistFactory/MakeModelAndMeasurementsFast.h>

#include <TROOT.h>
#include <TSystem.h>

#include <iostream>
#include <string>

/// Returns the workspace that is also created in the hf001_example.C tutorial.
/// Note that running this function creates a directory `hf001_data` in the
/// current directory.
std::unique_ptr<RooWorkspace>
TestWorkspaces::getWorkspace001(RooStats::HistFactory::HistoToWorkspaceFactoryFast::Configuration const &cfg)
{
   using namespace RooStats::HistFactory;

   const std::string inputFile = "./hf001/data/example.root";
   // in case the file is not found
   if (bool bfile = gSystem->AccessPathName(inputFile.c_str())) {
      std::cout << "Input file is not found - run prepareHistFactory script " << std::endl;
      gSystem->mkdir("hf001");
      gROOT->ProcessLine(".! prepareHistFactory hf001");
      bfile = gSystem->AccessPathName(inputFile.c_str());
      if (bfile) {
         std::cout << "Still no " << inputFile << ", giving up.\n";
         exit(1);
      }
   }

   // Create the measurement
   Measurement meas("meas", "meas");

   meas.SetOutputFilePrefix("./results/example_UsingC");
   meas.SetPOI("SigXsecOverSM");
   meas.AddConstantParam("alpha_syst1");
   meas.AddConstantParam("Lumi");

   meas.SetLumi(1.0);
   meas.SetLumiRelErr(0.10);
   meas.SetExportOnly(false);
   meas.SetBinHigh(2);

   // Create a channel

   Channel chan("channel1");
   chan.SetData("data", inputFile);
   chan.SetStatErrorConfig(0.05, "Poisson");

   // Now, create some samples

   // Create the signal sample
   Sample signal("signal", "signal", inputFile);
   signal.AddOverallSys("syst1", 0.95, 1.05);
   signal.AddNormFactor("SigXsecOverSM", 1, 0, 3);
   chan.AddSample(signal);

   // Background 1
   Sample background1("background1", "background1", inputFile);
   background1.ActivateStatError("background1_statUncert", inputFile);
   background1.AddOverallSys("syst2", 0.95, 1.05);
   chan.AddSample(background1);

   // Background 1
   Sample background2("background2", "background2", inputFile);
   background2.ActivateStatError();
   background2.AddOverallSys("syst3", 0.95, 1.05);
   chan.AddSample(background2);

   // Done with this channel
   // Add it to the measurement:
   meas.AddChannel(chan);

   // Collect the histograms from their files,
   // print some output,
   meas.CollectHistograms();
   meas.PrintTree(oocoutI(nullptr, HistFactory));

   meas.SetExportOnly(true);

   // Now, do the measurement
   return std::unique_ptr<RooWorkspace>{MakeModelAndMeasurementFast(meas, cfg)};
}
