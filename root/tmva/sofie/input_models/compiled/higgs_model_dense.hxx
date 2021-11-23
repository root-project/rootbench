//Code generated automatically by TMVA for Inference of Model file [higgs_model_dense.onnx] at [Tue Nov 23 11:08:08 2021] 
#include<algorithm>
#include<cmath>
#include<vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_higgs_model_dense{
namespace BLAS{
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
std::vector<float> fTensor_sequentialdense3BiasAddReadVariableOp0 = std::vector<float>(100);
float * tensor_sequentialdense3BiasAddReadVariableOp0 = fTensor_sequentialdense3BiasAddReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense1BiasAddReadVariableOp0 = std::vector<float>(100);
float * tensor_sequentialdense1BiasAddReadVariableOp0 = fTensor_sequentialdense1BiasAddReadVariableOp0.data();
std::vector<float> fTensor_sequentialdenseMatMulReadVariableOp0 = std::vector<float>(700);
float * tensor_sequentialdenseMatMulReadVariableOp0 = fTensor_sequentialdenseMatMulReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense2BiasAddReadVariableOp0 = std::vector<float>(100);
float * tensor_sequentialdense2BiasAddReadVariableOp0 = fTensor_sequentialdense2BiasAddReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense4BiasAddReadVariableOp0 = std::vector<float>(100);
float * tensor_sequentialdense4BiasAddReadVariableOp0 = fTensor_sequentialdense4BiasAddReadVariableOp0.data();
std::vector<float> fTensor_sequentialdenseBiasAddReadVariableOp0 = std::vector<float>(100);
float * tensor_sequentialdenseBiasAddReadVariableOp0 = fTensor_sequentialdenseBiasAddReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense4MatMulReadVariableOp0 = std::vector<float>(10000);
float * tensor_sequentialdense4MatMulReadVariableOp0 = fTensor_sequentialdense4MatMulReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense3MatMulReadVariableOp0 = std::vector<float>(10000);
float * tensor_sequentialdense3MatMulReadVariableOp0 = fTensor_sequentialdense3MatMulReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense1MatMulReadVariableOp0 = std::vector<float>(10000);
float * tensor_sequentialdense1MatMulReadVariableOp0 = fTensor_sequentialdense1MatMulReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense5BiasAddReadVariableOp0 = std::vector<float>(2);
float * tensor_sequentialdense5BiasAddReadVariableOp0 = fTensor_sequentialdense5BiasAddReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense2MatMulReadVariableOp0 = std::vector<float>(10000);
float * tensor_sequentialdense2MatMulReadVariableOp0 = fTensor_sequentialdense2MatMulReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense5MatMulReadVariableOp0 = std::vector<float>(200);
float * tensor_sequentialdense5MatMulReadVariableOp0 = fTensor_sequentialdense5MatMulReadVariableOp0.data();
std::vector<float> fTensor_sequentialdense4MatMulGemm100 = std::vector<float>(100);
float * tensor_sequentialdense4MatMulGemm100 = fTensor_sequentialdense4MatMulGemm100.data();
std::vector<float> fTensor_sequentialdense5MatMulGemm110 = std::vector<float>(2);
float * tensor_sequentialdense5MatMulGemm110 = fTensor_sequentialdense5MatMulGemm110.data();
std::vector<float> fTensor_sequentialdense4Relu0 = std::vector<float>(100);
float * tensor_sequentialdense4Relu0 = fTensor_sequentialdense4Relu0.data();
std::vector<float> fTensor_sequentialdense3Relu0 = std::vector<float>(100);
float * tensor_sequentialdense3Relu0 = fTensor_sequentialdense3Relu0.data();
std::vector<float> fTensor_sequentialdenseRelu0 = std::vector<float>(100);
float * tensor_sequentialdenseRelu0 = fTensor_sequentialdenseRelu0.data();
std::vector<float> fTensor_sequentialdense1Relu0 = std::vector<float>(100);
float * tensor_sequentialdense1Relu0 = fTensor_sequentialdense1Relu0.data();
std::vector<float> fTensor_sequentialdense2MatMulGemm80 = std::vector<float>(100);
float * tensor_sequentialdense2MatMulGemm80 = fTensor_sequentialdense2MatMulGemm80.data();
std::vector<float> fTensor_sequentialdense3MatMulGemm90 = std::vector<float>(100);
float * tensor_sequentialdense3MatMulGemm90 = fTensor_sequentialdense3MatMulGemm90.data();
std::vector<float> fTensor_sequentialdense2Relu0 = std::vector<float>(100);
float * tensor_sequentialdense2Relu0 = fTensor_sequentialdense2Relu0.data();
std::vector<float> fTensor_dense5 = std::vector<float>(2);
float * tensor_dense5 = fTensor_dense5.data();
std::vector<float> fTensor_sequentialdense1MatMulGemm70 = std::vector<float>(100);
float * tensor_sequentialdense1MatMulGemm70 = fTensor_sequentialdense1MatMulGemm70.data();
std::vector<float> fTensor_sequentialdenseMatMulGemm60 = std::vector<float>(100);
float * tensor_sequentialdenseMatMulGemm60 = fTensor_sequentialdenseMatMulGemm60.data();


Session(std::string filename ="") {
   if (filename.empty()) filename = "higgs_model_dense.dat";
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()){
      throw std::runtime_error("tmva-sofie failed to open file for input weights");
   }
   std::string tensor_name;
   int length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense3BiasAddReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense3BiasAddReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense3BiasAddReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense1BiasAddReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense1BiasAddReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense1BiasAddReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdenseMatMulReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdenseMatMulReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 700) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 700 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdenseMatMulReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense2BiasAddReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense2BiasAddReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense2BiasAddReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense4BiasAddReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense4BiasAddReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense4BiasAddReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdenseBiasAddReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdenseBiasAddReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdenseBiasAddReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense4MatMulReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense4MatMulReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 10000) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 10000 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense4MatMulReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense3MatMulReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense3MatMulReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 10000) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 10000 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense3MatMulReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense1MatMulReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense1MatMulReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 10000) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 10000 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense1MatMulReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense5BiasAddReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense5BiasAddReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense5BiasAddReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense2MatMulReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense2MatMulReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 10000) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 10000 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense2MatMulReadVariableOp0[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_sequentialdense5MatMulReadVariableOp0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_sequentialdense5MatMulReadVariableOp0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_sequentialdense5MatMulReadVariableOp0[i];
   f.close();
}

std::vector<float> infer(float* tensor_input){

//--------- Gemm
   char op_0_transA = 'n';
   char op_0_transB = 'n';
   int op_0_m = 1;
   int op_0_n = 100;
   int op_0_k = 7;
   float op_0_alpha = 1;
   float op_0_beta = 1;
   int op_0_lda = 7;
   int op_0_ldb = 100;
   std::copy(tensor_sequentialdenseBiasAddReadVariableOp0, tensor_sequentialdenseBiasAddReadVariableOp0 + 100, tensor_sequentialdenseMatMulGemm60);
   BLAS::sgemm_(&op_0_transB, &op_0_transA, &op_0_n, &op_0_m, &op_0_k, &op_0_alpha, tensor_sequentialdenseMatMulReadVariableOp0, &op_0_ldb, tensor_input, &op_0_lda, &op_0_beta, tensor_sequentialdenseMatMulGemm60, &op_0_n);

//------ RELU
   for (int id = 0; id < 100 ; id++){
      tensor_sequentialdenseRelu0[id] = ((tensor_sequentialdenseMatMulGemm60[id] > 0 )? tensor_sequentialdenseMatMulGemm60[id] : 0);
   }

//--------- Gemm
   char op_2_transA = 'n';
   char op_2_transB = 'n';
   int op_2_m = 1;
   int op_2_n = 100;
   int op_2_k = 100;
   float op_2_alpha = 1;
   float op_2_beta = 1;
   int op_2_lda = 100;
   int op_2_ldb = 100;
   std::copy(tensor_sequentialdense1BiasAddReadVariableOp0, tensor_sequentialdense1BiasAddReadVariableOp0 + 100, tensor_sequentialdense1MatMulGemm70);
   BLAS::sgemm_(&op_2_transB, &op_2_transA, &op_2_n, &op_2_m, &op_2_k, &op_2_alpha, tensor_sequentialdense1MatMulReadVariableOp0, &op_2_ldb, tensor_sequentialdenseRelu0, &op_2_lda, &op_2_beta, tensor_sequentialdense1MatMulGemm70, &op_2_n);

//------ RELU
   for (int id = 0; id < 100 ; id++){
      tensor_sequentialdense1Relu0[id] = ((tensor_sequentialdense1MatMulGemm70[id] > 0 )? tensor_sequentialdense1MatMulGemm70[id] : 0);
   }

//--------- Gemm
   char op_4_transA = 'n';
   char op_4_transB = 'n';
   int op_4_m = 1;
   int op_4_n = 100;
   int op_4_k = 100;
   float op_4_alpha = 1;
   float op_4_beta = 1;
   int op_4_lda = 100;
   int op_4_ldb = 100;
   std::copy(tensor_sequentialdense2BiasAddReadVariableOp0, tensor_sequentialdense2BiasAddReadVariableOp0 + 100, tensor_sequentialdense2MatMulGemm80);
   BLAS::sgemm_(&op_4_transB, &op_4_transA, &op_4_n, &op_4_m, &op_4_k, &op_4_alpha, tensor_sequentialdense2MatMulReadVariableOp0, &op_4_ldb, tensor_sequentialdense1Relu0, &op_4_lda, &op_4_beta, tensor_sequentialdense2MatMulGemm80, &op_4_n);

//------ RELU
   for (int id = 0; id < 100 ; id++){
      tensor_sequentialdense2Relu0[id] = ((tensor_sequentialdense2MatMulGemm80[id] > 0 )? tensor_sequentialdense2MatMulGemm80[id] : 0);
   }

//--------- Gemm
   char op_6_transA = 'n';
   char op_6_transB = 'n';
   int op_6_m = 1;
   int op_6_n = 100;
   int op_6_k = 100;
   float op_6_alpha = 1;
   float op_6_beta = 1;
   int op_6_lda = 100;
   int op_6_ldb = 100;
   std::copy(tensor_sequentialdense3BiasAddReadVariableOp0, tensor_sequentialdense3BiasAddReadVariableOp0 + 100, tensor_sequentialdense3MatMulGemm90);
   BLAS::sgemm_(&op_6_transB, &op_6_transA, &op_6_n, &op_6_m, &op_6_k, &op_6_alpha, tensor_sequentialdense3MatMulReadVariableOp0, &op_6_ldb, tensor_sequentialdense2Relu0, &op_6_lda, &op_6_beta, tensor_sequentialdense3MatMulGemm90, &op_6_n);

//------ RELU
   for (int id = 0; id < 100 ; id++){
      tensor_sequentialdense3Relu0[id] = ((tensor_sequentialdense3MatMulGemm90[id] > 0 )? tensor_sequentialdense3MatMulGemm90[id] : 0);
   }

//--------- Gemm
   char op_8_transA = 'n';
   char op_8_transB = 'n';
   int op_8_m = 1;
   int op_8_n = 100;
   int op_8_k = 100;
   float op_8_alpha = 1;
   float op_8_beta = 1;
   int op_8_lda = 100;
   int op_8_ldb = 100;
   std::copy(tensor_sequentialdense4BiasAddReadVariableOp0, tensor_sequentialdense4BiasAddReadVariableOp0 + 100, tensor_sequentialdense4MatMulGemm100);
   BLAS::sgemm_(&op_8_transB, &op_8_transA, &op_8_n, &op_8_m, &op_8_k, &op_8_alpha, tensor_sequentialdense4MatMulReadVariableOp0, &op_8_ldb, tensor_sequentialdense3Relu0, &op_8_lda, &op_8_beta, tensor_sequentialdense4MatMulGemm100, &op_8_n);

//------ RELU
   for (int id = 0; id < 100 ; id++){
      tensor_sequentialdense4Relu0[id] = ((tensor_sequentialdense4MatMulGemm100[id] > 0 )? tensor_sequentialdense4MatMulGemm100[id] : 0);
   }

//--------- Gemm
   char op_10_transA = 'n';
   char op_10_transB = 'n';
   int op_10_m = 1;
   int op_10_n = 2;
   int op_10_k = 100;
   float op_10_alpha = 1;
   float op_10_beta = 1;
   int op_10_lda = 100;
   int op_10_ldb = 2;
   std::copy(tensor_sequentialdense5BiasAddReadVariableOp0, tensor_sequentialdense5BiasAddReadVariableOp0 + 2, tensor_sequentialdense5MatMulGemm110);
   BLAS::sgemm_(&op_10_transB, &op_10_transA, &op_10_n, &op_10_m, &op_10_k, &op_10_alpha, tensor_sequentialdense5MatMulReadVariableOp0, &op_10_ldb, tensor_sequentialdense4Relu0, &op_10_lda, &op_10_beta, tensor_sequentialdense5MatMulGemm110, &op_10_n);
	for (int id = 0; id < 2 ; id++){
		tensor_dense5[id] = 1 / (1 + std::exp( - tensor_sequentialdense5MatMulGemm110[id]));
	}
	std::vector<float> ret (tensor_dense5, tensor_dense5 + 2);
	return ret;
}
};
} //TMVA_SOFIE_higgs_model_dense
