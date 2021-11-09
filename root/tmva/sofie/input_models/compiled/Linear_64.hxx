//Code generated automatically by TMVA for Inference of Model file [Linear_64.onnx] at [Tue Nov  9 21:20:14 2021] 
#include<algorithm>
#include<vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_Linear_64{
namespace BLAS{
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
float tensor_8weight[2500] = {};
float tensor_8bias[3200] = {};
float tensor_4bias[3200] = {};
float tensor_2weight[2500] = {};
float tensor_0bias[3200] = {};
float tensor_12bias[3200] = {};
float tensor_18bias[640] = {};
float tensor_14bias[3200] = {};
float tensor_4weight[2500] = {};
float tensor_10weight[2500] = {};
float tensor_6bias[3200] = {};
float tensor_18weight[500] = {};
float tensor_0weight[5000] = {};
float tensor_10bias[3200] = {};
float tensor_2bias[3200] = {};
float tensor_6weight[2500] = {};
float tensor_14weight[2500] = {};
float tensor_16weight[2500] = {};
float tensor_12weight[2500] = {};
float tensor_16bias[3200] = {};
std::vector<float> fTensor_39 = std::vector<float>(640);
float * tensor_39 = fTensor_39.data();
std::vector<float> fTensor_38 = std::vector<float>(3200);
float * tensor_38 = fTensor_38.data();
std::vector<float> fTensor_36 = std::vector<float>(3200);
float * tensor_36 = fTensor_36.data();
std::vector<float> fTensor_35 = std::vector<float>(3200);
float * tensor_35 = fTensor_35.data();
std::vector<float> fTensor_34 = std::vector<float>(3200);
float * tensor_34 = fTensor_34.data();
std::vector<float> fTensor_21 = std::vector<float>(3200);
float * tensor_21 = fTensor_21.data();
std::vector<float> fTensor_24 = std::vector<float>(3200);
float * tensor_24 = fTensor_24.data();
std::vector<float> fTensor_22 = std::vector<float>(3200);
float * tensor_22 = fTensor_22.data();
std::vector<float> fTensor_23 = std::vector<float>(3200);
float * tensor_23 = fTensor_23.data();
std::vector<float> fTensor_37 = std::vector<float>(3200);
float * tensor_37 = fTensor_37.data();
std::vector<float> fTensor_26 = std::vector<float>(3200);
float * tensor_26 = fTensor_26.data();
std::vector<float> fTensor_27 = std::vector<float>(3200);
float * tensor_27 = fTensor_27.data();
std::vector<float> fTensor_28 = std::vector<float>(3200);
float * tensor_28 = fTensor_28.data();
std::vector<float> fTensor_31 = std::vector<float>(3200);
float * tensor_31 = fTensor_31.data();
std::vector<float> fTensor_29 = std::vector<float>(3200);
float * tensor_29 = fTensor_29.data();
std::vector<float> fTensor_30 = std::vector<float>(3200);
float * tensor_30 = fTensor_30.data();
std::vector<float> fTensor_25 = std::vector<float>(3200);
float * tensor_25 = fTensor_25.data();
std::vector<float> fTensor_32 = std::vector<float>(3200);
float * tensor_32 = fTensor_32.data();
std::vector<float> fTensor_33 = std::vector<float>(3200);
float * tensor_33 = fTensor_33.data();


Session(std::string filename ="") {
   if (filename.empty()) filename = "Linear_64.dat";
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()){
      throw std::runtime_error("tmva-sofie failed to open file for input weights");
   }
   std::string tensor_name;
   int length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_8weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_8weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_8weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_8bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_8bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_8bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_4bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_4bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_4bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_2weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_2weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_2weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_0bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_0bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_0bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_12bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_12bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_12bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_18bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_18bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 640) {
      std::cout << "Error in tensor size : expected tensor size is 640 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_18bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_14bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_14bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_14bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_4weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_4weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_4weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_10weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_10weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_10weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_6bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_6bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_6bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_18weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_18weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 500) {
      std::cout << "Error in tensor size : expected tensor size is 500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_18weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_0weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_0weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 5000) {
      std::cout << "Error in tensor size : expected tensor size is 5000 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_0weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_10bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_10bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_10bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_2bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_2bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_2bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_6weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_6weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_6weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_14weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_14weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_14weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_16weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_16weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_16weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_12weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_12weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2500) {
      std::cout << "Error in tensor size : expected tensor size is 2500 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_12weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_16bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_16bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_16bias[i];
   f.close();
}

std::vector<float> infer(float* tensor_input1){

//--------- Gemm
   char op_0_transA = 'n';
   char op_0_transB = 't';
   int op_0_m = 64;
   int op_0_n = 50;
   int op_0_k = 100;
   float op_0_alpha = 1;
   float op_0_beta = 1;
   int op_0_lda = 100;
   int op_0_ldb = 100;
   std::copy(tensor_0bias, tensor_0bias + 3200, tensor_21);
   BLAS::sgemm_(&op_0_transB, &op_0_transA, &op_0_n, &op_0_m, &op_0_k, &op_0_alpha, tensor_0weight, &op_0_ldb, tensor_input1, &op_0_lda, &op_0_beta, tensor_21, &op_0_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_22[id] = ((tensor_21[id] > 0 )? tensor_21[id] : 0);
   }

//--------- Gemm
   char op_2_transA = 'n';
   char op_2_transB = 't';
   int op_2_m = 64;
   int op_2_n = 50;
   int op_2_k = 50;
   float op_2_alpha = 1;
   float op_2_beta = 1;
   int op_2_lda = 50;
   int op_2_ldb = 50;
   std::copy(tensor_2bias, tensor_2bias + 3200, tensor_23);
   BLAS::sgemm_(&op_2_transB, &op_2_transA, &op_2_n, &op_2_m, &op_2_k, &op_2_alpha, tensor_2weight, &op_2_ldb, tensor_22, &op_2_lda, &op_2_beta, tensor_23, &op_2_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_24[id] = ((tensor_23[id] > 0 )? tensor_23[id] : 0);
   }

//--------- Gemm
   char op_4_transA = 'n';
   char op_4_transB = 't';
   int op_4_m = 64;
   int op_4_n = 50;
   int op_4_k = 50;
   float op_4_alpha = 1;
   float op_4_beta = 1;
   int op_4_lda = 50;
   int op_4_ldb = 50;
   std::copy(tensor_4bias, tensor_4bias + 3200, tensor_25);
   BLAS::sgemm_(&op_4_transB, &op_4_transA, &op_4_n, &op_4_m, &op_4_k, &op_4_alpha, tensor_4weight, &op_4_ldb, tensor_24, &op_4_lda, &op_4_beta, tensor_25, &op_4_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_26[id] = ((tensor_25[id] > 0 )? tensor_25[id] : 0);
   }

//--------- Gemm
   char op_6_transA = 'n';
   char op_6_transB = 't';
   int op_6_m = 64;
   int op_6_n = 50;
   int op_6_k = 50;
   float op_6_alpha = 1;
   float op_6_beta = 1;
   int op_6_lda = 50;
   int op_6_ldb = 50;
   std::copy(tensor_6bias, tensor_6bias + 3200, tensor_27);
   BLAS::sgemm_(&op_6_transB, &op_6_transA, &op_6_n, &op_6_m, &op_6_k, &op_6_alpha, tensor_6weight, &op_6_ldb, tensor_26, &op_6_lda, &op_6_beta, tensor_27, &op_6_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_28[id] = ((tensor_27[id] > 0 )? tensor_27[id] : 0);
   }

//--------- Gemm
   char op_8_transA = 'n';
   char op_8_transB = 't';
   int op_8_m = 64;
   int op_8_n = 50;
   int op_8_k = 50;
   float op_8_alpha = 1;
   float op_8_beta = 1;
   int op_8_lda = 50;
   int op_8_ldb = 50;
   std::copy(tensor_8bias, tensor_8bias + 3200, tensor_29);
   BLAS::sgemm_(&op_8_transB, &op_8_transA, &op_8_n, &op_8_m, &op_8_k, &op_8_alpha, tensor_8weight, &op_8_ldb, tensor_28, &op_8_lda, &op_8_beta, tensor_29, &op_8_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_30[id] = ((tensor_29[id] > 0 )? tensor_29[id] : 0);
   }

//--------- Gemm
   char op_10_transA = 'n';
   char op_10_transB = 't';
   int op_10_m = 64;
   int op_10_n = 50;
   int op_10_k = 50;
   float op_10_alpha = 1;
   float op_10_beta = 1;
   int op_10_lda = 50;
   int op_10_ldb = 50;
   std::copy(tensor_10bias, tensor_10bias + 3200, tensor_31);
   BLAS::sgemm_(&op_10_transB, &op_10_transA, &op_10_n, &op_10_m, &op_10_k, &op_10_alpha, tensor_10weight, &op_10_ldb, tensor_30, &op_10_lda, &op_10_beta, tensor_31, &op_10_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_32[id] = ((tensor_31[id] > 0 )? tensor_31[id] : 0);
   }

//--------- Gemm
   char op_12_transA = 'n';
   char op_12_transB = 't';
   int op_12_m = 64;
   int op_12_n = 50;
   int op_12_k = 50;
   float op_12_alpha = 1;
   float op_12_beta = 1;
   int op_12_lda = 50;
   int op_12_ldb = 50;
   std::copy(tensor_12bias, tensor_12bias + 3200, tensor_33);
   BLAS::sgemm_(&op_12_transB, &op_12_transA, &op_12_n, &op_12_m, &op_12_k, &op_12_alpha, tensor_12weight, &op_12_ldb, tensor_32, &op_12_lda, &op_12_beta, tensor_33, &op_12_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_34[id] = ((tensor_33[id] > 0 )? tensor_33[id] : 0);
   }

//--------- Gemm
   char op_14_transA = 'n';
   char op_14_transB = 't';
   int op_14_m = 64;
   int op_14_n = 50;
   int op_14_k = 50;
   float op_14_alpha = 1;
   float op_14_beta = 1;
   int op_14_lda = 50;
   int op_14_ldb = 50;
   std::copy(tensor_14bias, tensor_14bias + 3200, tensor_35);
   BLAS::sgemm_(&op_14_transB, &op_14_transA, &op_14_n, &op_14_m, &op_14_k, &op_14_alpha, tensor_14weight, &op_14_ldb, tensor_34, &op_14_lda, &op_14_beta, tensor_35, &op_14_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_36[id] = ((tensor_35[id] > 0 )? tensor_35[id] : 0);
   }

//--------- Gemm
   char op_16_transA = 'n';
   char op_16_transB = 't';
   int op_16_m = 64;
   int op_16_n = 50;
   int op_16_k = 50;
   float op_16_alpha = 1;
   float op_16_beta = 1;
   int op_16_lda = 50;
   int op_16_ldb = 50;
   std::copy(tensor_16bias, tensor_16bias + 3200, tensor_37);
   BLAS::sgemm_(&op_16_transB, &op_16_transA, &op_16_n, &op_16_m, &op_16_k, &op_16_alpha, tensor_16weight, &op_16_ldb, tensor_36, &op_16_lda, &op_16_beta, tensor_37, &op_16_n);

//------ RELU
   for (int id = 0; id < 3200 ; id++){
      tensor_38[id] = ((tensor_37[id] > 0 )? tensor_37[id] : 0);
   }

//--------- Gemm
   char op_18_transA = 'n';
   char op_18_transB = 't';
   int op_18_m = 64;
   int op_18_n = 10;
   int op_18_k = 50;
   float op_18_alpha = 1;
   float op_18_beta = 1;
   int op_18_lda = 50;
   int op_18_ldb = 50;
   std::copy(tensor_18bias, tensor_18bias + 640, tensor_39);
   BLAS::sgemm_(&op_18_transB, &op_18_transA, &op_18_n, &op_18_m, &op_18_k, &op_18_alpha, tensor_18weight, &op_18_ldb, tensor_38, &op_18_lda, &op_18_beta, tensor_39, &op_18_n);
	std::vector<float> ret (tensor_39, tensor_39 + 640);
	return ret;
}
};
} //TMVA_SOFIE_Linear_64
