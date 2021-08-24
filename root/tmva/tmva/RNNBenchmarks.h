#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/DataSetInfo.h"
#include "TMVA/Config.h"
#include "TMVA/MethodDL.h"
#include "TMVA/PyMethodBase.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TMacro.h"
#include "TSystem.h"
#include "TH1.h"
#include "TF1.h"
#include "TRandom.h"
#include "TPad.h"
#include "TCanvas.h"

void MakeTimeData(int n, int ntime, int ndim ){
   TString fname = TString::Format("time_data_t%d_d%d.root", ntime, ndim);
   
   std::vector<TH1 *> v1(ntime);
   std::vector<TH1 *> v2(ntime);
   
   int i = 0;
   
   for (int i = 0; i < ntime; ++i) {
      v1[i] = new TH1D(TString::Format("h1_%d", i), "h1", ndim, 0, 10);
      v2[i] = new TH1D(TString::Format("h2_%d", i), "h2", ndim, 0, 10);
   }

   auto f1 = new TF1("f1", "gaus");
   auto f2 = new TF1("f2", "gaus");

   TTree sgn("sgn", "sgn");
   TTree bkg("bkg", "bkg");
   TFile f(fname, "RECREATE");

   std::vector<std::vector<float>> x1(ntime);
   std::vector<std::vector<float>> x2(ntime);

   for (int i = 0; i < ntime; ++i) {
      x1[i] = std::vector<float>(ndim);
      x2[i] = std::vector<float>(ndim);
   }

   for (auto i = 0; i < ntime; i++) {
      bkg.Branch(Form("vars_time%d", i), "std::vector<float>", &x1[i]);
      sgn.Branch(Form("vars_time%d", i), "std::vector<float>", &x2[i]);
   }

   sgn.SetDirectory(&f);
   bkg.SetDirectory(&f);
   gRandom->SetSeed(0);

   std::vector<double> mean1(ntime);
   std::vector<double> mean2(ntime);
   std::vector<double> sigma1(ntime);
   std::vector<double> sigma2(ntime);
   
   for (int j = 0; j < ntime; ++j) {
      mean1[j] = 5. + 0.2 * sin(TMath::Pi() * j / double(ntime));
      mean2[j] = 5. + 0.2 * cos(TMath::Pi() * j / double(ntime));
      sigma1[j] = 4 + 0.3 * sin(TMath::Pi() * j / double(ntime));
      sigma2[j] = 4 + 0.3 * cos(TMath::Pi() * j / double(ntime));
   }
   
   for (int i = 0; i < n; ++i) {
      if (i % 1000 == 0)
         std::cout << "Generating  event ... " << i << std::endl;

      for (int j = 0; j < ntime; ++j) {
         auto h1 = v1[j];
         auto h2 = v2[j];
         h1->Reset();
         h2->Reset();

         f1->SetParameters(1, mean1[j], sigma1[j]);
         f2->SetParameters(1, mean2[j], sigma2[j]);

         h1->FillRandom("f1", 1000);
         h2->FillRandom("f2", 1000);

         for (int k = 0; k < ndim; ++k) {
            x1[j][k] = h1->GetBinContent(k + 1) + gRandom->Gaus(0, 10);
            x2[j][k] = h2->GetBinContent(k + 1) + gRandom->Gaus(0, 10);
         }
      }

      sgn.Fill();
      bkg.Fill();

      if (n == 1) {
         auto c1 = new TCanvas();
         c1->Divide(ntime, 2);
         
         for (int j = 0; j < ntime; ++j) {
            c1->cd(j + 1);
            v1[j]->Draw();
         }
         
         for (int j = 0; j < ntime; ++j) {
            c1->cd(ntime + j + 1);
            v2[j]->Draw();
         }
         
         gPad->Update();
      }
   }
   
   if (n > 1) {
      sgn.Write();
      bkg.Write();
      sgn.Print();
      bkg.Print();
      f.Close();
   }
}

void RNN_benchmark(TString archName) {
   const int ninput = 30;
   const int ntime = 10;
   const int batchSize = 100;
   const int maxepochs = 20;

   int nTotEvts = 10000; 
   
#ifndef R__HAS_TMVAGPU
   if (archName == "GPU") {
   	Error("TMVA_RNN_Classification", "Architecture not supported. Cannot use TMVA Deep Learning for RNN.");
      	return;
   }
#endif
#ifndef R__HAS_TMVACPU
   if (archName == "CPU") {
   	Error("TMVA_RNN_Classification", "Architecture not supported. Cannot use TMVA Deep Learning for RNN.");
      	return;
   }
#endif

   int num_threads = 0;   
   ROOT::EnableImplicitMT(num_threads);

   TMVA::Config::Instance();

   std::cout << "Running with nthreads  = " << ROOT::GetThreadPoolSize() << std::endl;

   TString inputFileName = "time_data_t10_d30.root";

   bool fileExist = !gSystem->AccessPathName(inputFileName);

   if (!fileExist)
      MakeTimeData(nTotEvts,ntime, ninput);

   auto inputFile = TFile::Open(inputFileName);
   if (!inputFile) {
      Error("TMVA_RNN_Classification", "Error opening input file %s - exit", inputFileName.Data());
      return;
   }
   std::cout << "--- RNNClassification  : Using input file: " << inputFile->GetName() << std::endl;

   TString outfileName(TString::Format("data_RNN_%s.root", archName.Data()));
   TFile *outputFile = nullptr;
   outputFile = TFile::Open(outfileName, "RECREATE");

   // Creating the factory object
   TMVA::Factory *factory = new TMVA::Factory("TMVAClassification", outputFile,
                                              "!V:!Silent:Color:DrawProgressBar:Transformations=None:!Correlations:"
                                              "AnalysisType=Classification:ModelPersistence");
   TMVA::DataLoader *dataloader = new TMVA::DataLoader("dataset");

   TTree *signalTree = (TTree *)inputFile->Get("sgn");
   TTree *background = (TTree *)inputFile->Get("bkg");

   const int nvar = ninput * ntime;

   for (auto i = 0; i < ntime; i++) {
      dataloader->AddVariablesArray(Form("vars_time%d", i), ninput);
   }

   dataloader->AddSignalTree(signalTree, 1.0);
   dataloader->AddBackgroundTree(background, 1.0);

   int nTrainSig = 0.8 * nTotEvts;
   int nTrainBkg = 0.8 *  nTotEvts;

   TString prepareOptions = TString::Format("nTrain_Signal=%d:nTrain_Background=%d:SplitMode=Random:SplitSeed=100:NormMode=NumEvents:!V:!CalcCorrelations", nTrainSig, nTrainBkg);

   TCut mycuts = ""; 
   TCut mycutb = "";

   dataloader->PrepareTrainingAndTestTree(mycuts, mycutb, prepareOptions);

   std::cout << "prepared DATA LOADER " << std::endl;
   
   const char *rnn_type = "LSTM";

   TString inputLayoutString = TString::Format("InputLayout=%d|%d", ntime, ninput);
   TString rnnLayout = TString::Format("%s|10|%d|%d|0|1", rnn_type, ninput, ntime);
   TString layoutString = TString("Layout=") + rnnLayout + TString(",RESHAPE|FLAT,DENSE|64|TANH,LINEAR");

   TString trainingString1 = TString::Format("LearningRate=1e-3,Momentum=0.0,Repetitions=1,"
                                             "ConvergenceSteps=5,BatchSize=%d,TestRepetitions=1,"
                                             "WeightDecay=1e-2,Regularization=None,MaxEpochs=%d,"
                                             "Optimizer=ADAM,DropConfig=0.0+0.+0.+0.", batchSize, maxepochs);

   TString trainingStrategyString("TrainingStrategy=");
   trainingStrategyString += trainingString1; 

   TString rnnOptions("!H:V:ErrorStrategy=CROSSENTROPY:VarTransform=None:"
                      "WeightInitialization=XAVIERUNIFORM:ValidationSize=0.2:RandomSeed=1234");

   rnnOptions.Append(":");
   rnnOptions.Append(inputLayoutString);
   rnnOptions.Append(":");
   rnnOptions.Append(layoutString);
   rnnOptions.Append(":");
   rnnOptions.Append(trainingStrategyString);
   rnnOptions.Append(":");
   rnnOptions.Append(TString::Format("Architecture=%s", archName.Data()));

   TString rnnName = "TMVA_" + TString(rnn_type);
   factory->BookMethod(dataloader, TMVA::Types::kDL, rnnName, rnnOptions);

   factory->TrainAllMethods();
   factory->TestAllMethods();
   factory->EvaluateAllMethods();

   if (outputFile) 
   	outputFile->Close();
}

void RNN_Keras_benchmark(TString archName) {
   const int ninput = 30;
   const int ntime = 10;
   const int batchSize = 100;
   const int maxepochs = 20;

   int nTotEvts = 10000; 
   
	
#ifndef R__HAS_TMVAGPU
   if (archName == "GPU") {
   	Error("TMVA_RNN_Classification", "Architecture not supported. Cannot use TMVA Deep Learning for RNN.");
      	return;
   }
#endif
#ifndef R__HAS_TMVACPU
   if (archName == "CPU") {
   	Error("TMVA_RNN_Classification", "Architecture not supported. Cannot use TMVA Deep Learning for RNN.");
      	return;
   }
#endif

#ifdef R__HAS_PYMVA
   TMVA::PyMethodBase::PyInitialize();
#else
   Error("TMVA_RNN_Classification", "Cannot use Keras.");
   return;
#endif

   int num_threads = 0;   
   ROOT::EnableImplicitMT(num_threads);

   TMVA::Config::Instance();
   if (archName == "CPU") gSystem->Setenv("CUDA_VISIBLE_DEVICES","-1");
   	
   std::cout << "Running with nthreads  = " << ROOT::GetThreadPoolSize() << std::endl;

   TString inputFileName = "time_data_t10_d30.root";

   bool fileExist = !gSystem->AccessPathName(inputFileName);

   if (!fileExist)
      MakeTimeData(nTotEvts,ntime, ninput);

   auto inputFile = TFile::Open(inputFileName);
   if (!inputFile) {
      Error("TMVA_RNN_Classification", "Error opening input file %s - exit", inputFileName.Data());
      return;
   }
   std::cout << "--- RNNClassification  : Using input file: " << inputFile->GetName() << std::endl;

   TString outfileName(TString::Format("data_RNN_%s.root", archName.Data()));
   TFile *outputFile = nullptr;
   outputFile = TFile::Open(outfileName, "RECREATE");

   // Creating the factory object
   TMVA::Factory *factory = new TMVA::Factory("TMVAClassification", outputFile,
                                              "!V:!Silent:Color:DrawProgressBar:Transformations=None:!Correlations:"
                                              "AnalysisType=Classification:ModelPersistence");
   TMVA::DataLoader *dataloader = new TMVA::DataLoader("dataset");

   TTree *signalTree = (TTree *)inputFile->Get("sgn");
   TTree *background = (TTree *)inputFile->Get("bkg");

   const int nvar = ninput * ntime;

   for (auto i = 0; i < ntime; i++) {
      dataloader->AddVariablesArray(Form("vars_time%d", i), ninput);
   }

   dataloader->AddSignalTree(signalTree, 1.0);
   dataloader->AddBackgroundTree(background, 1.0);

   int nTrainSig = 0.8 * nTotEvts;
   int nTrainBkg = 0.8 *  nTotEvts;

   TString prepareOptions = TString::Format("nTrain_Signal=%d:nTrain_Background=%d:SplitMode=Random:SplitSeed=100:NormMode=NumEvents:!V:!CalcCorrelations", nTrainSig, nTrainBkg);

   TCut mycuts = ""; 
   TCut mycutb = "";

   dataloader->PrepareTrainingAndTestTree(mycuts, mycutb, prepareOptions);

   std::cout << "prepared DATA LOADER " << std::endl;
   
   const char *rnn_type = "LSTM";

   TString modelName = TString::Format("model_%s.h5", rnn_type);
   TString trainedModelName = TString::Format("trained_model_%s.h5", rnn_type);

   TMacro m;
   m.AddLine("import tensorflow");
   m.AddLine("from tensorflow.keras.models import Sequential");
   m.AddLine("from tensorflow.keras.optimizers import Adam");
   m.AddLine("from tensorflow.keras.layers import Input, Dense, Dropout, Flatten, SimpleRNN, GRU, LSTM, Reshape");
   m.AddLine("");
   m.AddLine("model = Sequential() ");
   m.AddLine("model.add(Reshape((10, 30), input_shape = (10*30, )))");
   m.AddLine("model.add(LSTM(units=10, return_sequences=True) )");
   m.AddLine("model.add(Flatten())"); 
   m.AddLine("model.add(Dense(64, activation = 'tanh')) ");
   m.AddLine("model.add(Dense(2, activation = 'sigmoid')) ");
   m.AddLine("model.compile(loss = 'binary_crossentropy', optimizer = Adam(lr = 0.001), metrics = ['accuracy'])");
   m.AddLine(TString::Format("modelName = '%s'", modelName.Data()));
   m.AddLine("model.save(modelName)");
   m.AddLine("model.summary()");

   m.SaveSource("make_rnn_model.py");
   gSystem->Exec("python make_rnn_model.py");
   
   Info("TMVA_RNN_Classification", "Booking Keras %s model", rnn_type);
   factory->BookMethod(dataloader, TMVA::Types::kPyKeras,
                       TString::Format("PyKeras_%s", rnn_type),
                       TString::Format("!H:!V:VarTransform=None:FilenameModel=%s:tf.keras:"
                                       "FilenameTrainedModel=%s:GpuOptions=allow_growth=True:"
                                       "NumEpochs=%d:BatchSize=%d",
                                       modelName.Data(), trainedModelName.Data(), maxepochs, batchSize)
   );

   factory->TrainAllMethods();
   factory->TestAllMethods();
   factory->EvaluateAllMethods();

   if (outputFile) 
   	outputFile->Close();
}

