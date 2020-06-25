/* INFERENCE IN CPP
 * 
 * This script perform inference using a pytorch training sample converted in three .txt files by source/modelReader.py
 * norm.txt contains normalization parameters
 * bias.txt contains bias parameters for the forward propagation
 * weights.txt contains weights for the forward propagation
 * the output is the ROOT file cppNN.root, containing 4 reconstructed branches: Mjj, pTjj, dRjj and highest score per event
 *
 * gabriele.damen@cern.ch
 */

#include <LoopSUSYFrame/cppnn.h>
#include <string>
#include <TVector.h>
#include <TMatrixF.h>
#include <TFile.h>
#include <algorithm>
#include <fstream>
#include <iostream>

//////////////////////////////////////
// UTILITIES
//////////////////////////////////////

// split std::string by delimiter
std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    return res;
}


std::vector<std::string> splitString(std::string str, std::string delimiter = ",") {
    auto v = split(str, delimiter);
    return v;
}

std::vector<Float_t> string2float(std::vector<std::string> str) {
    
    std::vector<Float_t> flt;
    for (unsigned int i = 0; i < str.size(); i++) {
        flt.push_back(stof(str[i]));
    }
    return flt;
}

//////////////////////////////////////
// ACTIVATION FUNCTIONS
//////////////////////////////////////

TVector leaky_relu(TVector input, Float_t slope = 1e-2) {
    TVector output(input.GetNoElements());
    for (auto i = 0; i < input.GetNoElements(); i++) {
        output[i] = std::max(0., (Double_t)input[i]) + slope * std::min(0., (Double_t)input[i]);
    }
    return output;
}

TVector sigmoid(TVector input) {
    TVector output(input.GetNoElements());
    for (auto i = 0; i < input.GetNoElements(); i++) {
        output[i] = 1/(1 + std::exp(-input[i]));
    }
    return output;
}

//////////////////////////////////////
// WEIGHTS PARSING
//////////////////////////////////////

TMatrixF fillWeigths(TMatrixF matrix, std::vector<std::vector<Float_t>> weights, Int_t oLayerSize, Int_t iLayerSize, Int_t incremental) {
    for (auto i = incremental; i < oLayerSize + incremental; i++){
        for (auto j = 0; j < iLayerSize; j++){
            TMatrixFColumn(matrix, j)(i-incremental) = weights[i][j];
        }
    }
    return matrix;
}

std::vector<std::vector<Float_t>> readWeights(std::string filename) {
    
    std::vector<std::vector<Float_t>> weights;
    std::vector<std::string> vstr;
    std::vector<Float_t> vflo;
    
    std::string line;

    std::ifstream weightFile;
    weightFile.open(filename);
    if(weightFile.is_open()){
        while(getline(weightFile, line)){
            vstr = splitString(line,",");
            vflo = string2float(vstr);
            weights.push_back(vflo);
        } weightFile.close();
    } 

    return weights;
}

//////////////////////////////////////
// BIAS PARSING
//////////////////////////////////////

TVector fillBias(TVector vector, std::vector<Float_t> biases, Int_t oLayerSize, int incremental) {
    
    for (int i = incremental; i < oLayerSize + incremental; i++){
        vector[i - incremental] = biases[i];
    }
    return vector;
}

std::vector<Float_t> readBiases(std::string filename) {
    std::vector<Float_t> biases;
    std::vector<Float_t> vflo;
    
    std::string line;
    
    std::ifstream biasFile;
    biasFile.open(filename);
    if(biasFile.is_open()){
        while(getline(biasFile, line)){
            biases.push_back(stof(line));     
        } biasFile.close();
    } 
    return biases;
}

myNN :: myNN( std::string wei_file, std::string bias_file, std::string norm_file )
{    

    // NET STRUCTURE
    layerSize = {10, 10, 4, 6, 4, 8, 1};

    // EXTERNAL WEIGHTS PARSING from weights.txt
    auto weights = readWeights(wei_file);
    int incrW = 0;
    for (unsigned int i = 0 ; i < (layerSize.size() - 1); i++){
        TMatrixF newMatrix(layerSize[i + 1], layerSize[i]); 
        newMatrix = fillWeigths(newMatrix, weights, layerSize[i+1], layerSize[i], incrW);
        weightsMatrix.push_back(newMatrix);
        incrW += layerSize[i+1];
    }
    
    // EXTERNAL BIASES PARSING from biases.txt
    auto biases = readBiases(bias_file);
    int incrB = 0;
    for (unsigned int i = 1 ; i < (layerSize.size()); i++){
        TVector newVector(layerSize[i]); 
        newVector = fillBias(newVector, biases, layerSize[i], incrB);
        biasVector.push_back(newVector);
        incrB += layerSize[i];
    }
    
    // EXTERNAL NORMALIZATION PARSING from norm.txt
    readNormalization(norm_file);

}

TVector myNN :: batch_norm(TVector &input) const {
    // BATCH NORMALIZATION LAYER
    
    TVector output = input;
    output -= normVector[2];
    ElementDiv(output, normVector[3]);    
    ElementMult(output, normVector[0]);
    
    output += normVector[1];

    return output;
}


//////////////////////////////////////
// NORMALIZATION
//////////////////////////////////////

void myNN :: readNormalization(std::string filename) {
    
    Float_t eps = 1e-5;

    std::vector<Float_t> nWv;
    std::vector<Float_t> nBv;
    std::vector<Float_t> nRMv;
    std::vector<Float_t> nRVv;
    
    std::string line;
    std::ifstream normFile;
    normFile.open(filename);
    
    if(normFile.is_open()){
        for(auto i = 0; getline(normFile, line); i++){
            if (i < layerSize[0]) 
                nWv.push_back(stof(line));
            else if (i < 2*layerSize[0]) 
                nBv.push_back(stof(line));
            else if (i < 3*layerSize[0]) 
                nRMv.push_back(stof(line));
            else if (i < 4*layerSize[0]) 
                nRVv.push_back(std::sqrt(stof(line) + eps));
        } normFile.close();
    } 
    // questo va in FillNormalization()
    TVector tvWv(nWv.size(), &nWv[0]);
    TVector tvBv(nBv.size(), &nBv[0]);
    TVector tvRMv(nRMv.size(), &nRMv[0]);
    TVector tvRVv(nRVv.size(), &nRVv[0]);

    normVector.push_back(tvWv);
    normVector.push_back(tvBv);
    normVector.push_back(tvRMv);
    normVector.push_back(tvRVv);


}


//////////////////////////////////////
// INFERENCE
//////////////////////////////////////

Float_t myNN :: forward(const float &j1pT_over_mjj, const float &j1_eta, const float &j1_phi, const float &j1_mass, const float &j1_btag, const float &j2_over_mjj, const float &j2_eta, const float &j2_phi, const float &j2_mass, const float &j2_btag)  const
{    
    std::vector<Float_t> inputs = {j1pT_over_mjj, j1_eta, j1_phi, j1_mass, (Float_t)j1_btag, j2_over_mjj, j2_eta, j2_phi, j2_mass, (Float_t)j2_btag};
    TVector layer0(layerSize[0], &inputs[0]);

    // BATCH NORMALIZATION of LAYER0
    layer0 = batch_norm(layer0);
    
    // TODO Create general version
    TVector prod1 = weightsMatrix[0]*layer0 + biasVector[0];
    TVector layer1 = leaky_relu(prod1);
    
    TVector prod2 = weightsMatrix[1]*layer1 + biasVector[1];
    TVector layer2 = leaky_relu(prod2);
    
    TVector prod3 = weightsMatrix[2]*layer2 + biasVector[2];
    TVector layer3 = leaky_relu(prod3);
    
    TVector prod4 = weightsMatrix[3]*layer3 + biasVector[3];
    TVector layer4 = leaky_relu(prod4);
    
    TVector prod5 = weightsMatrix[4]*layer4 + biasVector[4];
    TVector layer5 = leaky_relu(prod5);
    
    TVector prod6 = weightsMatrix[5]*layer5 + biasVector[5];
    TVector layer6 = sigmoid(prod6);
    
    Float_t score = layer6[0];
    
    return score;
}