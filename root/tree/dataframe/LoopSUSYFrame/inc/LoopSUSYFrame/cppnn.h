#ifndef CPPNN_H
#define CPPNN_H

#include <vector>
#include <string>
#include <TVector.h>
#include <TMatrixF.h>
#include <TFile.h>
#include <algorithm>
#include <fstream>

//////////////////////////////////////
// UTILITIES
//////////////////////////////////////

// split std::string by delimiter
std::vector<std::string> split (std::string s, std::string delimiter);
std::vector<std::string> splitString(std::string str, std::string delimiter);
std::vector<Float_t> string2float(std::vector<std::string> str);

//////////////////////////////////////
// ACTIVATION FUNCTIONS
//////////////////////////////////////

TVector leaky_relu(TVector input, Float_t slope);
TVector sigmoid(TVector input);

//////////////////////////////////////
// WEIGHTS PARSING
//////////////////////////////////////

TMatrixF fillWeigths(TMatrixF matrix, std::vector<std::vector<Float_t>> weights, Int_t oLayerSize, Int_t iLayerSize, Int_t incremental);
std::vector<std::vector<Float_t>> readWeights(std::string filename);

//////////////////////////////////////
// BIAS PARSING
//////////////////////////////////////

TVector fillBias(TVector vector, std::vector<Float_t> biases, Int_t oLayerSize, int incremental);
std::vector<Float_t> readBiases(std::string filename);

//////////////////////////////////////
// INPUTs PARSING
//////////////////////////////////////

class myNN {

public:

	// this is a standard constructor
    myNN(){};
	myNN( std::string wei_file, std::string bias_file, std::string norm_file);

	~myNN(){};

    void readNormalization(std::string filename);
    Float_t forward(const float &j1pT_over_mjj, const float &j1_eta, const float &j1_phi, const float &j1_mass, const float &j1_btag, const float &j2_over_mjj, const float &j2_eta, const float &j2_phi, const float &j2_mass, const float &j2_btag) const;
    TVector batch_norm(TVector &input) const;

private:
    
    // NET STRUCTURE
    std::vector<Int_t> layerSize;
    std::vector<TMatrixF> weightsMatrix;
    std::vector<TVector> biasVector;
    std::vector<TVector> normVector;

};

#endif
