//Code generated automatically by TMVA for Inference of Model file [Conv_d100_L1_B1.onnx] at [Mon Nov  8 14:01:59 2021] 
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
float tensor_conv0bias[2] = {};
float tensor_conv0weight[50] = {};
std::vector<float> fTensor_conv0biasbcast = std::vector<float>(20000);
float * tensor_conv0biasbcast = fTensor_conv0biasbcast.data();
std::vector<float> fTensor_4 = std::vector<float>(20000);
float * tensor_4 = fTensor_4.data();
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
      std::cout << "Error in tensor name : expected tensor name is tensor_conv0bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2) {
      std::cout << "Error in tensor size : expected tensor size is 2 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv0bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv0weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv0weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 50) {
      std::cout << "Error in tensor size : expected tensor size is 50 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv0weight[i];
   f.close();
   {
      std::vector<size_t> oldShape = { 2 };
      std::vector<size_t> newShape = { 2, 100, 100};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv0bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 1 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv0biasbcast + i * length);
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
	float * op_0_xpad = fVec_op_0_xpad.data();
	for (size_t c = 0; c < 1; c++) {
		for (size_t h = 0; h < 100; h++) {
			size_t xpad_offset = c * 10816 + (h + 2) * 104 + 2;
			size_t x_offset = c * 10000 + h * 100;
			std::copy(tensor_input + x_offset, tensor_input + x_offset + 100, op_0_xpad + xpad_offset);
		}
	}
	char op_0_transA = 'T';
	char op_0_transB = 'N';
	int op_0_m = 10000;
	int op_0_n = 2;
	int op_0_k = 25;
	float op_0_alpha = 1.0;
	float op_0_beta = 0.0;
	float * op_0_xcol = fVec_op_0_xcol.data();
	for (size_t n = 0; n < 1; n++) {
		size_t op_0_index = 0;
                size_t offseth = 0;
		for (size_t h = 0; h < 100; h += 1) {
			for (size_t w = 0; w < 100;w += 1) {
                                size_t offsetc = 0; 
				for (size_t c = 0; c < 1; c++) {
                                   size_t offsetx = 0;
					for (size_t x = 0; x < 5; x++) {
					size_t offset = offsetc + offseth + offsetx  + w;
					std::copy(op_0_xpad + offset, op_0_xpad + offset + 5, op_0_xcol + op_0_index);
					op_0_index += 5;
                                        offsetx += 104;
					}
                                        offsetc += 10816;
				}
			}
                        offseth += 104;
		}
		BLAS::sgemm_(&op_0_transA, &op_0_transB, &op_0_m, &op_0_n, &op_0_k, &op_0_alpha, op_0_xcol, &op_0_k,
			op_0_f, &op_0_k, &op_0_beta, tensor_3, &op_0_m);
	}
	int op_0_size = 20000;
	float op_0_gamma = 1.0;
	int op_0_incx = 1;
	int op_0_incy = 1;
	BLAS::saxpy_(&op_0_size, &op_0_gamma, tensor_conv0biasbcast, &op_0_incx, tensor_3, &op_0_incy);
	for (int id = 0; id < 20000 ; id++){
		tensor_4[id] = ((tensor_3[id] > 0 )? tensor_3[id] : 0);
	}
	std::vector<float> ret (tensor_4, tensor_4 + 20000);
	return ret;
}
};
} //TMVA_SOFIE_Conv_d100_L1_B1
