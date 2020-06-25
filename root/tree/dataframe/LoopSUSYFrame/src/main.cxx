/* LoopSUSYFrame is an ATLAS tool.
 * This file was modified to make it standalone and run a typical workload.
 */


#include "LoopSUSYFrame/LoopSUSYThTh.h"
#include "TSystem.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1D.h"
#include "TROOT.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include "TSystemDirectory.h"
#include "TList.h"
#include <sys/stat.h>
#include <chrono>

bool is_file(const char *path)
{
  struct stat buf;
  stat(path, &buf);
  return S_ISREG(buf.st_mode);
}

bool is_dir(const char *path)
{
  struct stat buf;
  stat(path, &buf);
  return S_ISDIR(buf.st_mode);
}

bool checkFile(std::string path)
{
  bool statusOK = false;
  TFile *fIn = new TFile(TString(path));
  TH1D *hnev = (TH1D *)fIn->Get("NumberEvents");
  TTree *myTree = (TTree *)fIn->Get("myTree");
  if (hnev != NULL && myTree != NULL && !TString(path).Contains("data1"))
    statusOK = true;
  else if (myTree != NULL && TString(path).Contains("data1"))
    statusOK = true;
  delete myTree;
  delete hnev;
  fIn->Close();
  delete fIn;
  return statusOK;
}

int LoopSUSYFrame_main(int argc, const char *argv[])
{

  if (argc < 3)
  {
    std::cerr << "Usage: ntupleMaker ANALYSIS PATH_TO_INPUT DO_SYST OUT_TREE_NAME OUT_FILE_PATH ENABLE_MT (STORE_ISO_VARS XSECT file..4bodies-ONLY options)" << std::endl;
    return 1;
  }

  TString analysis(argv[1]);

  std::string inputFile = argv[2];
  bool is_single_sys = false;
  
  std::string doSys;
  std::vector<std::string> syst = {"NONE"};
  if (argc > 3)
  {
    doSys = argv[3];
    if (doSys == "WEIGHTS")
    {
      syst = {"WEIGHTS"};
      is_single_sys = true;
    }
    else if (doSys == "FS")
    {
      syst = {"WEIGHTS",
              "EG_RESOLUTION_ALL__1down", "EG_RESOLUTION_ALL__1up",
              "EG_SCALE_ALL__1down", "EG_SCALE_ALL__1up",
              "JET_EtaIntercalibration_NonClosure_highE__1up", "JET_EtaIntercalibration_NonClosure_highE__1down",
              "JET_EtaIntercalibration_NonClosure_negEta__1up", "JET_EtaIntercalibration_NonClosure_negEta__1down",
              "JET_EtaIntercalibration_NonClosure_posEta__1up", "JET_EtaIntercalibration_NonClosure_posEta__1down",
              "JET_Flavor_Response__1up", "JET_Flavor_Response__1down",
              "JET_GroupedNP_1__1up", "JET_GroupedNP_1__1down",
              "JET_GroupedNP_2__1up", "JET_GroupedNP_2__1down",
              "JET_GroupedNP_3__1up", "JET_GroupedNP_3__1down",
              "JET_JER_DataVsMC_MC16__1up", "JET_JER_DataVsMC_MC16__1down",
              "JET_JER_EffectiveNP_1__1up", "JET_JER_EffectiveNP_1__1down",
              "JET_JER_EffectiveNP_2__1up", "JET_JER_EffectiveNP_2__1down",
              "JET_JER_EffectiveNP_3__1up", "JET_JER_EffectiveNP_3__1down",
              "JET_JER_EffectiveNP_4__1up", "JET_JER_EffectiveNP_4__1down",
              "JET_JER_EffectiveNP_5__1up", "JET_JER_EffectiveNP_5__1down",
              "JET_JER_EffectiveNP_6__1up", "JET_JER_EffectiveNP_6__1down",
              "JET_JER_EffectiveNP_7restTerm__1up", "JET_JER_EffectiveNP_7restTerm__1down",
              "MET_SoftTrk_ResoPara",
              "MET_SoftTrk_ResoPerp",
              "MET_SoftTrk_ScaleDown",
              "MET_SoftTrk_ScaleUp",
              "MUON_ID__1down", "MUON_ID__1up",
              "MUON_MS__1down", "MUON_MS__1up",
              "MUON_SAGITTA_RESBIAS__1down", "MUON_SAGITTA_RESBIAS__1up",
              "MUON_SAGITTA_RHO__1down", "MUON_SAGITTA_RHO__1up",
              "MUON_SCALE__1down", "MUON_SCALE__1up"};
    }
    else if (doSys == "AF2")
    {
      syst = {"WEIGHTS",
              "EG_RESOLUTION_ALL__1down", "EG_RESOLUTION_ALL__1up",
              "EG_SCALE_AF2__1down", "EG_SCALE_AF2__1up",
              "JET_EtaIntercalibration_NonClosure_highE__1up", "JET_EtaIntercalibration_NonClosure_highE__1down",
              "JET_EtaIntercalibration_NonClosure_negEta__1up", "JET_EtaIntercalibration_NonClosure_negEta__1down",
              "JET_EtaIntercalibration_NonClosure_posEta__1up", "JET_EtaIntercalibration_NonClosure_posEta__1down",
              "JET_Flavor_Response__1up", "JET_Flavor_Response__1down",
              "JET_GroupedNP_1__1up", "JET_GroupedNP_1__1down",
              "JET_GroupedNP_2__1up", "JET_GroupedNP_2__1down",
              "JET_GroupedNP_3__1up", "JET_GroupedNP_3__1down",
              "JET_JER_DataVsMC_AFII__1up", "JET_JER_DataVsMC_AFII__1down",
              "JET_JER_EffectiveNP_1__1up", "JET_JER_EffectiveNP_1__1down",
              "JET_JER_EffectiveNP_2__1up", "JET_JER_EffectiveNP_2__1down",
              "JET_JER_EffectiveNP_3__1up", "JET_JER_EffectiveNP_3__1down",
              "JET_JER_EffectiveNP_4__1up", "JET_JER_EffectiveNP_4__1down",
              "JET_JER_EffectiveNP_5__1up", "JET_JER_EffectiveNP_5__1down",
              "JET_JER_EffectiveNP_6__1up", "JET_JER_EffectiveNP_6__1down",
              "JET_JER_EffectiveNP_7restTerm__1up", "JET_JER_EffectiveNP_7restTerm__1down",
              "MET_SoftTrk_ResoPara",
              "MET_SoftTrk_ResoPerp",
              "MET_SoftTrk_ScaleDown",
              "MET_SoftTrk_ScaleUp",
              "MUON_ID__1down", "MUON_ID__1up",
              "MUON_MS__1down", "MUON_MS__1up",
              "MUON_SAGITTA_RESBIAS__1down", "MUON_SAGITTA_RESBIAS__1up",
              "MUON_SAGITTA_RHO__1down", "MUON_SAGITTA_RHO__1up",
              "MUON_SCALE__1down", "MUON_SCALE__1up"};
    }
    else if (doSys == "FS")
    {
      syst = {"WEIGHTS",
              "EG_RESOLUTION_ALL__1down", "EG_RESOLUTION_ALL__1up",
              "EG_SCALE_ALL__1down", "EG_SCALE_ALL__1up",
              "JET_EtaIntercalibration_NonClosure_highE__1up", "JET_EtaIntercalibration_NonClosure_highE__1down",
              "JET_EtaIntercalibration_NonClosure_negEta__1up", "JET_EtaIntercalibration_NonClosure_negEta__1down",
              "JET_EtaIntercalibration_NonClosure_posEta__1up", "JET_EtaIntercalibration_NonClosure_posEta__1down",
              "JET_Flavor_Response__1up", "JET_Flavor_Response__1down",
              "JET_GroupedNP_1__1up", "JET_GroupedNP_1__1down",
              "JET_GroupedNP_2__1up", "JET_GroupedNP_2__1down",
              "JET_GroupedNP_3__1up", "JET_GroupedNP_3__1down",
              "JET_JER_DataVsMC_MC16__1up", "JET_JER_DataVsMC_MC16__1down",
              "JET_JER_EffectiveNP_1__1up", "JET_JER_EffectiveNP_1__1down",
              "JET_JER_EffectiveNP_2__1up", "JET_JER_EffectiveNP_2__1down",
              "JET_JER_EffectiveNP_3__1up", "JET_JER_EffectiveNP_3__1down",
              "JET_JER_EffectiveNP_4__1up", "JET_JER_EffectiveNP_4__1down",
              "JET_JER_EffectiveNP_5__1up", "JET_JER_EffectiveNP_5__1down",
              "JET_JER_EffectiveNP_6__1up", "JET_JER_EffectiveNP_6__1down",
              "JET_JER_EffectiveNP_7restTerm__1up", "JET_JER_EffectiveNP_7restTerm__1down",
              "MET_SoftTrk_ResoPara",
              "MET_SoftTrk_ResoPerp",
              "MET_SoftTrk_ScaleDown",
              "MET_SoftTrk_ScaleUp",
              "MUON_ID__1down", "MUON_ID__1up",
              "MUON_MS__1down", "MUON_MS__1up",
              "MUON_SAGITTA_RESBIAS__1down", "MUON_SAGITTA_RESBIAS__1up",
              "MUON_SAGITTA_RHO__1down", "MUON_SAGITTA_RHO__1up",
              "MUON_SCALE__1down", "MUON_SCALE__1up"};
    }
    else if (doSys == "AF2")
    {
      syst = {"WEIGHTS",
              "EG_RESOLUTION_ALL__1down", "EG_RESOLUTION_ALL__1up",
              "EG_SCALE_AF2__1down", "EG_SCALE_AF2__1up",
              "JET_EtaIntercalibration_NonClosure_highE__1up", "JET_EtaIntercalibration_NonClosure_highE__1down",
              "JET_EtaIntercalibration_NonClosure_negEta__1up", "JET_EtaIntercalibration_NonClosure_negEta__1down",
              "JET_EtaIntercalibration_NonClosure_posEta__1up", "JET_EtaIntercalibration_NonClosure_posEta__1down",
              "JET_Flavor_Response__1up", "JET_Flavor_Response__1down",
              "JET_GroupedNP_1__1up", "JET_GroupedNP_1__1down",
              "JET_GroupedNP_2__1up", "JET_GroupedNP_2__1down",
              "JET_GroupedNP_3__1up", "JET_GroupedNP_3__1down",
              "JET_JER_DataVsMC_AFII__1up", "JET_JER_DataVsMC_AFII__1down",
              "JET_JER_EffectiveNP_1__1up", "JET_JER_EffectiveNP_1__1down",
              "JET_JER_EffectiveNP_2__1up", "JET_JER_EffectiveNP_2__1down",
              "JET_JER_EffectiveNP_3__1up", "JET_JER_EffectiveNP_3__1down",
              "JET_JER_EffectiveNP_4__1up", "JET_JER_EffectiveNP_4__1down",
              "JET_JER_EffectiveNP_5__1up", "JET_JER_EffectiveNP_5__1down",
              "JET_JER_EffectiveNP_6__1up", "JET_JER_EffectiveNP_6__1down",
              "JET_JER_EffectiveNP_7restTerm__1up", "JET_JER_EffectiveNP_7restTerm__1down",
              "MET_SoftTrk_ResoPara",
              "MET_SoftTrk_ResoPerp",
              "MET_SoftTrk_ScaleDown",
              "MET_SoftTrk_ScaleUp",
              "MUON_ID__1down", "MUON_ID__1up",
              "MUON_MS__1down", "MUON_MS__1up",
              "MUON_SAGITTA_RESBIAS__1down", "MUON_SAGITTA_RESBIAS__1up",
              "MUON_SAGITTA_RHO__1down", "MUON_SAGITTA_RHO__1up",
              "MUON_SCALE__1down", "MUON_SCALE__1up"};
    }
    else if (doSys == "false")
    {
      syst = {"NONE"};
      is_single_sys = true;
    }
    else
    {
      std::cout << "Runnning over one systematic: " << argv[3] << std::endl;
      syst = {argv[3]};
      is_single_sys = true;
    }
  }

  std::string outputTree_name = "HistFitterTree";
  if (argc > 4)
  {
    outputTree_name = argv[4];
  }

  std::string outputFile_path = ".";
  if (argc > 5)
  {
    outputFile_path = argv[5];
  }
  bool enable_MT = true; //On by default, as bugs should be fixed in the ROOT nightly now
  if (argc > 6)
  {
    std::string en_string = argv[6];
    if (en_string.find("alse") != std::string::npos)
      enable_MT = false;
  }
  if (analysis == "torch" || analysis == "Torch")
    enable_MT = false;

  std::cout << "Writing to dir: " << outputFile_path << std::endl;
  bool storeISOvars = false;
  if (argc > 7)
  {
    std::string saveVars = argv[7];
    if (saveVars.find("rue") != std::string::npos)
      storeISOvars = true;
    std::cout << "Isolation variables saving set to " << storeISOvars << std::endl;
  }

  std::string signals = "none";
  if (argc > 8)
  {
    signals = argv[8];
    std::cout << "Selected file to import Signal Cross Section: " << signals << std::endl;
  }

  std::vector<TString> namefileslist;
  TChain *tree = new TChain("myTree");

  if (is_file(inputFile.c_str()))
  {
    if (checkFile(inputFile))
    {
      std::cout << "Adding file " << inputFile << std::endl;
      namefileslist.push_back(inputFile);
      tree->Add(TString(inputFile));
    }
    else
    {
      std::cerr << "myTree TTree or NumberEvents histogram missing in " << inputFile << std::endl;
      return 1;
    }
  }
  else if (is_dir(inputFile.c_str()))
  {
    std::cout << "Opening directory " << inputFile << std::endl;
    if (inputFile.substr(inputFile.length() - 1) != "/")
      inputFile = inputFile + "/";
    TSystemDirectory *directory = new TSystemDirectory(inputFile.c_str(), inputFile.c_str());
    TList *files = directory->GetListOfFiles();
    if (files)
    {
      TSystemFile *file;
      TString fname;
      TIter next(files);
      while ((file = (TSystemFile *)next()))
      {
        fname = file->GetName();
        if (!file->IsDirectory() && fname.EndsWith(".root"))
        {
          if (checkFile(inputFile + fname.Data()))
          {
            std::cout << "  adding file " << fname << std::endl;
            namefileslist.push_back(fname);
            tree->Add(TString(inputFile + fname));
          }
          else
            std::cout << "Skipping file " << inputFile << fname << std::endl;
        }
      }
      delete file;
      delete files;
      delete directory;
    }
  }

  double num_ev = 0.;
  bool isdata = true;
  int mc_chan = -1;
  bool isMCa = false;
  bool isMCd = false;
  bool isMCe = false;
  bool isData15 = false;
  bool isData16 = false;
  bool isData17 = false;
  bool isData18 = false;

  bool isSignal = (signals.compare("none") != 0) ? true : false;
  float xsectFromFile = 1., kFactor = 1., filtEff = 1.;
  std::string outputFile_name;

  std::size_t found = inputFile.find("data1");
  if (found == std::string::npos)
  {

    std::vector<std::string> Alternative_SOW_name;
    std::cout << outputTree_name << std::endl;
    if (outputTree_name.find("SOWVar3c") != std::string::npos)
    {
      std::cout << "Computing Var3c normalisation; Only running normalization step." << std::endl;
      Alternative_SOW_name = {"NumberEvents", "LHE3Weight_Var3cDown", "LHE3Weight_Var3cUp"};
    }
    else if (outputTree_name.find("SOWFSR") != std::string::npos)
    {
      std::cout << "Computing FSR ttbar normalisation; Only running normalization step." << std::endl;
      Alternative_SOW_name = {"NumberEvents", "LHE3Weight_isr:muRfac=10_fsr:muRfac=05", "LHE3Weight_isr:muRfac=10_fsr:muRfac=20"};
    }
    else if (outputTree_name.find("SOWmuRmuF") != std::string::npos)
    {
      std::cout << "Computing Scale muRXmuFX normalisation; Only running normalization step." << std::endl;
      Alternative_SOW_name = {"NumberEvents", "LHE3Weight_muR05muF05", "LHE3Weight_muR05muF10", "LHE3Weight_muR10muF05", "LHE3Weight_muR10muF10", "LHE3Weight_muR10muF20", "LHE3Weight_muR20muF10", "LHE3Weight_muR20muF20"};
    }
    else
    {
      std::cout << "Computing nominal normalisation" << std::endl;
      Alternative_SOW_name = {"NumberEvents"};
    }
    std::vector<double> Alternative_SOW;

    for (const auto &m_Alternative_SOW_name : Alternative_SOW_name)
    {
      num_ev = 0.;
      std::cout << m_Alternative_SOW_name << std::endl;
      if (is_file(inputFile.c_str()))
      {
        TFile *fIn = new TFile(TString(inputFile));
        TH1D *hnev = (TH1D *)fIn->Get(m_Alternative_SOW_name.c_str());
        num_ev = hnev->GetBinContent(2);
        if(outputTree_name.find("SOW")== std::string::npos) std::cout << " Number events: " << num_ev << std::endl;
        delete hnev;
        fIn->Close();
        delete fIn;
      }
      else if (is_dir(inputFile.c_str()))
      {
        for (const auto &namefileactual : namefileslist)
        {
          TFile *fIn = new TFile(TString(inputFile + namefileactual));
          TH1D *hnev = (TH1D *)fIn->Get(m_Alternative_SOW_name.c_str());
          num_ev = num_ev + hnev->GetBinContent(2);
          if(outputTree_name.find("SOW")== std::string::npos) {std::cout << "    " << namefileactual << " - "<< " sumOfWeights: " << hnev->GetBinContent(2) << std::endl;}
          delete hnev;
          fIn->Close();
          delete fIn;
        }
      }
      Alternative_SOW.push_back(num_ev);

      std::cout << std::fixed << "This is a MC sample with systematic: "<< m_Alternative_SOW_name << " Total sumOfWeights: " << num_ev << " "<< float(Alternative_SOW[0]/num_ev) << std::endl;
    }
    isdata = false;
    num_ev = Alternative_SOW[0];
    std::cout << std::fixed << "This is a MC sample: "
              << " Nominal sumOfWeights: " << num_ev << std::endl;

    if (outputTree_name.find("SOW") != std::string::npos)
      return 0;

    std::string temp_mc_chan;
    if (inputFile.find("mc16_13TeV") != std::string::npos)
    {
      std::size_t find_mc = inputFile.find("mc16_13TeV");
      temp_mc_chan = inputFile.substr(find_mc + 11, 6);
    }
    else if (inputFile.find("user.") != std::string::npos)
    {
      std::size_t founddot = inputFile.find("user.");
      std::size_t find_mc = inputFile.find(".", founddot + 5);
      temp_mc_chan = inputFile.substr(find_mc + 1, 6);
    }
    else
    {
      std::cerr << "Sample name not recognised" << std::endl;
      return 1;
    }

    mc_chan = std::atoi(temp_mc_chan.c_str());

    outputFile_name = outputFile_path + "/mc16_13TeV." + temp_mc_chan + "." + analysis;
    std::cout << "Output file base name: " << outputFile_name << std::endl;

    std::size_t foundMCa = inputFile.find("mc16a");
    std::size_t foundMCd = inputFile.find("mc16d");
    std::size_t foundMCe = inputFile.find("mc16e");

    if (foundMCa == std::string::npos)
      isMCa = false;
    else
    {
      isMCa = true;
      outputFile_name = outputFile_path + "/mc16_13TeV." + temp_mc_chan + "." + analysis + ".mc16a";
    }
    if (foundMCd == std::string::npos)
      isMCd = false;
    else
    {
      isMCd = true;
      outputFile_name = outputFile_path + "/mc16_13TeV." + temp_mc_chan + "." + analysis + ".mc16d";
    }
    if (foundMCe == std::string::npos)
      isMCe = false;
    else
    {
      isMCe = true;
      outputFile_name = outputFile_path + "/mc16_13TeV." + temp_mc_chan + "." + analysis + ".mc16e";
    }

    if (isSignal)
    {
      std::string line;
      std::ifstream xsect(signals);
      std::vector<std::pair<int, int>> spaces;
      if (xsect.is_open())
      {
        while (getline(xsect, line))
        {
          if (line.compare(0, 6, temp_mc_chan) == 0)
          {
            std::pair<int, int> count(0, 0);
            for (unsigned int i = 0; i < line.length(); i++)
            {
              if (line[i] == ' ' && count.first == 0)
                count.first = i;
              else if (line[i] != ' ' && count.first != 0)
              {
                count.second = i - 1;
                spaces.push_back(count);
                count.first = 0, count.second = 0;
              }
              else if (line[i] != ' ' && count.first == 0 && count.second == 0)
                continue;
            }
            std::reverse(spaces.begin(), spaces.end());
            for (unsigned int j = 0; j < spaces.size(); j++)
              if (spaces.at(j).first != spaces.at(j).second)
                line.replace(spaces.at(j).first, spaces.at(j).second - spaces.at(j).first + 1, " ");
            std::istringstream ss(line);
            std::string ID, FS, XSEC, K, FILT, UNC;
            std::getline(ss, ID, ' ');
            std::getline(ss, FS, ' ');
            std::getline(ss, XSEC, ' ');
            std::getline(ss, K, ' ');
            std::getline(ss, FILT, ' ');
            std::getline(ss, UNC, ' ');
            xsectFromFile = std::atof(XSEC.c_str());
            kFactor = std::atof(K.c_str());
            filtEff = std::atof(FILT.c_str());
            std::cout << "Parameters taken from file: xsec=" << xsectFromFile << " kFactor=" << kFactor << " filtEff=" << filtEff << std::endl;
          }
        }
      }
      else
      {
        std::cerr << "Failed to open cross-section file. Exiting!" << std::endl;
        return 1;
      }
      xsect.close();
    }
  }
  else
  {
    std::size_t find_data = inputFile.find("data1");
    std::cout << "This is data " << std::endl;
    //the next line is most likely going to need some adjustment
    outputFile_name = outputFile_path + "/" + inputFile.substr(find_data, 20) + "." + analysis;
    std::cout << "out file name " << outputFile_name << std::endl;
    syst = {"NONE"}; //We never want to run syst on data

    //what year is it?
    std::size_t foundData15 = inputFile.find("data15");
    std::size_t foundData16 = inputFile.find("data16");
    std::size_t foundData17 = inputFile.find("data17");
    std::size_t foundData18 = inputFile.find("data18");

    if (foundData15 == std::string::npos)
      isData15 = false;
    else
    {
      isData15 = true;
    }
    if (foundData16 == std::string::npos)
      isData16 = false;
    else
    {
      isData16 = true;
    }
    if (foundData17 == std::string::npos)
      isData17 = false;
    else
    {
      isData17 = true;
    }
    if (foundData18 == std::string::npos)
      isData18 = false;
    else
    {
      isData18 = true;
    }
  }

  std::cout << "Processing " << syst.size() << " variations" << std::endl;

  unsigned int nOutEvents = 0;
  auto t1 = std::chrono::high_resolution_clock::now();
  if (analysis == "stoph" || analysis == "stopH")
  {
    LoopSUSYThTh t(tree);
    t.setSumOfWeights(num_ev);
    t.setSyst(syst);
    t.setOutFileName(outputFile_name);
    t.setOutTreeName(outputTree_name);
    t.setIsData(isdata);
    t.setMcChan(mc_chan);
    t.setMcProd(isMCa, isMCd, isMCe);
    t.setMultiThread(enable_MT);
    std::cout << "Processing" << std::endl;
    nOutEvents += t.Execute();
    std::cout << "Written out" << std::endl;
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
  std::cout << "Event loop took " << int_ms.count() << " ms" << std::endl;

  // Clean-up
  if (!is_single_sys)
  {
    if (nOutEvents > 0)
    {
      if (analysis == "torch" || analysis == "Torch")
      {
        gSystem->Exec(("hadd -f " + outputFile_name + ".root " + outputFile_name + "*_NONE.root").c_str());
      }
      else
      {
        gSystem->Exec(("hadd -f " + outputFile_name + ".root " + outputFile_name + "*_*.root").c_str());
      }
    }
    std::cout << ("rm -f " + outputFile_name + "_*.root").c_str() << std::endl;
    gSystem->Exec(("rm -f " + outputFile_name + "_*.root").c_str());
  }
  else
  {
    if (nOutEvents == 0)
    {
      std::cout << "Deleting file:" + outputFile_name + "_" + syst[0] + ".root" + "since no events pass the seletion"<<std::endl;
      std::cout << ("rm -f " + outputFile_name + "_" + syst[0] + ".root").c_str() << std::endl;
      gSystem->Exec(("rm -f " + outputFile_name + "_" + syst[0] + ".root").c_str());
    }
  }
  
  std::cout << "All done!" << std::endl;

  return 0;
}


/*************** BENCHMARK START ***************/
#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"

static void BM_RDataFrame_LoopSUSYFrame(benchmark::State &state)
{
   const std::string data = RB::GetDataDir() + "/user.anon.436647.MGPy8EG_A14N23LO_T1T1_onestepN2N2_950_350_1L20.mc16e_stopH_v67_output.root";
   const char *argv[6] = {"LoopSUSYFrameBench", "stopH", "", "false", "outtree", "."};
   argv[2] = data.c_str();
   for (auto _ : state)
      LoopSUSYFrame_main(6, argv);
}
BENCHMARK(BM_RDataFrame_LoopSUSYFrame)->Repetitions(1);

BENCHMARK_MAIN();
/*************** BENCHMARK END ****************/
