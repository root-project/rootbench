//Code generated automatically by TMVA for Inference of Model file [Conv_d100_L1_B1.onnx] at [Sun Nov 21 22:14:25 2021] 
#include<vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_Conv_d100_L1_B1{
namespace BLAS{
	extern "C" void saxpy_(const int * n, const float * alpha, const float * x,
	                         const int * incx, float * y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
std::vector<float> fTensor_conv0bias = std::vector<float>(2);
float * tensor_conv0bias = fTensor_conv0bias.data();
std::vector<float> fTensor_conv0weight = std::vector<float>(50);
float * tensor_conv0weight = fTensor_conv0weight.data();
std::vector<float> fTensor_4 = std::vector<float>(20000);
float * tensor_4 = fTensor_4.data();
std::vector<float> fTensor_conv0biasbcast = std::vector<float>(20000);
float * tensor_conv0biasbcast = fTensor_conv0biasbcast.data();
std::vector<float> fTensor_3 = std::vector<float>(20000);
float * tensor_3 = fTensor_3.data();

std::vector<float> fVec_op_0_f = std::vector<float>(50);
std::vector<float> fVec_op_0_xpad = std::vector<float>(10816);
std::vector<float> fVec_op_0_xcol = std::vector<float>(250000);


Session(std::string filename ="") {
   if (filename.empty()) filename = "Conv_d100_L1_B1.dat";
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()){
      throw std::runtime_error("tmva-sofie failed to open file for input weights");
   }
   std::string tensor_name;
   int length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv0bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_conv0bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv0bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_conv0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv0weight[i];
   f.close();
   {
      std::vector<size_t> oldShape = { 2 };
      std::vector<size_t> newShape = { 2, 100, 100};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv0bias, oldShape, newShape);
      for (int i = 0; i < 1 ; i++)
         std::copy(newData_ptr, newData_ptr + 20000, tensor_conv0biasbcast + i * 20000);
      delete [] newData_ptr;
   }
}

std::vector<float> infer(float* tensor_input){

//----  operator Conv op_0
   float * op_0_f = fVec_op_0_f.data();
   for (std::size_t k = 0; k < 2; k++) {
      for (std::size_t d = 0; d < 1; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_0_f[k * 25 + d * 25 + h * 5 + w * 1  ] = tensor_conv0weight[k * 25 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   char op_0_transA = 'N';
   char op_0_transB = 'N';
   int op_0_m = 10000;
   int op_0_n = 2;
   int op_0_k = 25;
   float op_0_alpha = 1.0;
   float op_0_beta = 0.0;
   float * op_0_xpad = fVec_op_0_xpad.data();
   float * op_0_xcol = fVec_op_0_xcol.data();
   size_t offset_tensor_3 = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 10000;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_input + x_offset,1,100,100,5,5,2,2,1,1,1,1,op_0_xcol);

       BLAS::sgemm_(&op_0_transA, &op_0_transB, &op_0_m, &op_0_n, &op_0_k, &op_0_alpha, op_0_xcol, &op_0_m,
         op_0_f, &op_0_k, &op_0_beta, tensor_3 + offset_tensor_3, &op_0_m);
      offset_tensor_3 += 20000;
   }
   int op_0_size = 20000;
   float op_0_gamma = 1.0;
   int op_0_incx = 1;
   int op_0_incy = 1;
   BLAS::saxpy_(&op_0_size, &op_0_gamma, tensor_conv0biasbcast, &op_0_incx, tensor_3, &op_0_incy);

//------ RELU
   for (int id = 0; id < 20000 ; id++){
      tensor_4[id] = ((tensor_3[id] > 0 )? tensor_3[id] : 0);
   }
	std::vector<float> ret (tensor_4, tensor_4 + 20000);
	return ret;
}
};
} //TMVA_SOFIE_Conv_d100_L1_B1
