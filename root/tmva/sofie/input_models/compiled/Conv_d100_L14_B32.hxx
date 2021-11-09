//Code generated automatically by TMVA for Inference of Model file [Conv_d100_L14_B32.onnx] at [Wed Nov 10 19:42:12 2021] 
#include<vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_Conv_d100_L14_B32{
namespace BLAS{
	extern "C" void saxpy_(const int * n, const float * alpha, const float * x,
	                         const int * incx, float * y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
float tensor_conv13bias[1] = {};
float tensor_conv11weight[800] = {};
float tensor_conv10weight[3200] = {};
float tensor_conv10bias[8] = {};
float tensor_conv9bias[16] = {};
float tensor_conv8bias[32] = {};
float tensor_conv8weight[51200] = {};
float tensor_conv13weight[50] = {};
float tensor_conv6bias[128] = {};
float tensor_conv0weight[50] = {};
float tensor_conv0bias[2] = {};
float tensor_conv9weight[12800] = {};
float tensor_conv7bias[64] = {};
float tensor_conv1weight[200] = {};
float tensor_conv3bias[16] = {};
float tensor_conv2weight[800] = {};
float tensor_conv4weight[12800] = {};
float tensor_conv2bias[8] = {};
float tensor_conv1bias[4] = {};
float tensor_conv5bias[64] = {};
float tensor_conv3weight[3200] = {};
float tensor_conv7weight[204800] = {};
float tensor_conv4bias[32] = {};
float tensor_conv12bias[2] = {};
float tensor_conv12weight[200] = {};
float tensor_conv5weight[51200] = {};
float tensor_conv11bias[4] = {};
float tensor_conv6weight[204800] = {};
std::vector<float> fTensor_conv13biasbcast = std::vector<float>(61952);
float * tensor_conv13biasbcast = fTensor_conv13biasbcast.data();
std::vector<float> fTensor_54 = std::vector<float>(147456);
float * tensor_54 = fTensor_54.data();
std::vector<float> fTensor_conv12biasbcast = std::vector<float>(147456);
float * tensor_conv12biasbcast = fTensor_conv12biasbcast.data();
std::vector<float> fTensor_51 = std::vector<float>(346112);
float * tensor_51 = fTensor_51.data();
std::vector<float> fTensor_50 = std::vector<float>(802816);
float * tensor_50 = fTensor_50.data();
std::vector<float> fTensor_conv10biasbcast = std::vector<float>(802816);
float * tensor_conv10biasbcast = fTensor_conv10biasbcast.data();
std::vector<float> fTensor_35 = std::vector<float>(3612672);
float * tensor_35 = fTensor_35.data();
std::vector<float> fTensor_conv8biasbcast = std::vector<float>(4194304);
float * tensor_conv8biasbcast = fTensor_conv8biasbcast.data();
std::vector<float> fTensor_47 = std::vector<float>(1843200);
float * tensor_47 = fTensor_47.data();
std::vector<float> fTensor_34 = std::vector<float>(1982464);
float * tensor_34 = fTensor_34.data();
std::vector<float> fTensor_conv3biasbcast = std::vector<float>(3612672);
float * tensor_conv3biasbcast = fTensor_conv3biasbcast.data();
std::vector<float> fTensor_37 = std::vector<float>(6553600);
float * tensor_37 = fTensor_37.data();
std::vector<float> fTensor_conv2biasbcast = std::vector<float>(1982464);
float * tensor_conv2biasbcast = fTensor_conv2biasbcast.data();
std::vector<float> fTensor_conv1biasbcast = std::vector<float>(1083392);
float * tensor_conv1biasbcast = fTensor_conv1biasbcast.data();
std::vector<float> fTensor_55 = std::vector<float>(61952);
float * tensor_55 = fTensor_55.data();
std::vector<float> fTensor_31 = std::vector<float>(1083392);
float * tensor_31 = fTensor_31.data();
std::vector<float> fTensor_33 = std::vector<float>(1982464);
float * tensor_33 = fTensor_33.data();
std::vector<float> fTensor_32 = std::vector<float>(1083392);
float * tensor_32 = fTensor_32.data();
std::vector<float> fTensor_43 = std::vector<float>(9469952);
float * tensor_43 = fTensor_43.data();
std::vector<float> fTensor_48 = std::vector<float>(1843200);
float * tensor_48 = fTensor_48.data();
std::vector<float> fTensor_conv0biasbcast = std::vector<float>(589824);
float * tensor_conv0biasbcast = fTensor_conv0biasbcast.data();
std::vector<float> fTensor_56 = std::vector<float>(61952);
float * tensor_56 = fTensor_56.data();
std::vector<float> fTensor_29 = std::vector<float>(589824);
float * tensor_29 = fTensor_29.data();
std::vector<float> fTensor_40 = std::vector<float>(11829248);
float * tensor_40 = fTensor_40.data();
std::vector<float> fTensor_conv4biasbcast = std::vector<float>(6553600);
float * tensor_conv4biasbcast = fTensor_conv4biasbcast.data();
std::vector<float> fTensor_53 = std::vector<float>(147456);
float * tensor_53 = fTensor_53.data();
std::vector<float> fTensor_38 = std::vector<float>(6553600);
float * tensor_38 = fTensor_38.data();
std::vector<float> fTensor_41 = std::vector<float>(21233664);
float * tensor_41 = fTensor_41.data();
std::vector<float> fTensor_49 = std::vector<float>(802816);
float * tensor_49 = fTensor_49.data();
std::vector<float> fTensor_42 = std::vector<float>(21233664);
float * tensor_42 = fTensor_42.data();
std::vector<float> fTensor_36 = std::vector<float>(3612672);
float * tensor_36 = fTensor_36.data();
std::vector<float> fTensor_conv6biasbcast = std::vector<float>(21233664);
float * tensor_conv6biasbcast = fTensor_conv6biasbcast.data();
std::vector<float> fTensor_39 = std::vector<float>(11829248);
float * tensor_39 = fTensor_39.data();
std::vector<float> fTensor_conv7biasbcast = std::vector<float>(9469952);
float * tensor_conv7biasbcast = fTensor_conv7biasbcast.data();
std::vector<float> fTensor_conv5biasbcast = std::vector<float>(11829248);
float * tensor_conv5biasbcast = fTensor_conv5biasbcast.data();
std::vector<float> fTensor_44 = std::vector<float>(9469952);
float * tensor_44 = fTensor_44.data();
std::vector<float> fTensor_30 = std::vector<float>(589824);
float * tensor_30 = fTensor_30.data();
std::vector<float> fTensor_45 = std::vector<float>(4194304);
float * tensor_45 = fTensor_45.data();
std::vector<float> fTensor_46 = std::vector<float>(4194304);
float * tensor_46 = fTensor_46.data();
std::vector<float> fTensor_52 = std::vector<float>(346112);
float * tensor_52 = fTensor_52.data();
std::vector<float> fTensor_conv11biasbcast = std::vector<float>(346112);
float * tensor_conv11biasbcast = fTensor_conv11biasbcast.data();
std::vector<float> fTensor_conv9biasbcast = std::vector<float>(1843200);
float * tensor_conv9biasbcast = fTensor_conv9biasbcast.data();

std::vector<float> fVec_op_0_f = std::vector<float>(50);
std::vector<float> fVec_op_0_xpad = std::vector<float>(320000);
std::vector<float> fVec_op_0_xcol = std::vector<float>(230400);

std::vector<float> fVec_op_2_f = std::vector<float>(200);
std::vector<float> fVec_op_2_xpad = std::vector<float>(589824);
std::vector<float> fVec_op_2_xcol = std::vector<float>(423200);

std::vector<float> fVec_op_4_f = std::vector<float>(800);
std::vector<float> fVec_op_4_xpad = std::vector<float>(1083392);
std::vector<float> fVec_op_4_xcol = std::vector<float>(774400);

std::vector<float> fVec_op_6_f = std::vector<float>(3200);
std::vector<float> fVec_op_6_xpad = std::vector<float>(1982464);
std::vector<float> fVec_op_6_xcol = std::vector<float>(1411200);

std::vector<float> fVec_op_8_f = std::vector<float>(12800);
std::vector<float> fVec_op_8_xpad = std::vector<float>(3612672);
std::vector<float> fVec_op_8_xcol = std::vector<float>(2560000);

std::vector<float> fVec_op_10_f = std::vector<float>(51200);
std::vector<float> fVec_op_10_xpad = std::vector<float>(6553600);
std::vector<float> fVec_op_10_xcol = std::vector<float>(4620800);

std::vector<float> fVec_op_12_f = std::vector<float>(204800);
std::vector<float> fVec_op_12_xpad = std::vector<float>(11829248);
std::vector<float> fVec_op_12_xcol = std::vector<float>(8294400);

std::vector<float> fVec_op_14_f = std::vector<float>(204800);
std::vector<float> fVec_op_14_xpad = std::vector<float>(21233664);
std::vector<float> fVec_op_14_xcol = std::vector<float>(14796800);

std::vector<float> fVec_op_16_f = std::vector<float>(51200);
std::vector<float> fVec_op_16_xpad = std::vector<float>(9469952);
std::vector<float> fVec_op_16_xcol = std::vector<float>(6553600);

std::vector<float> fVec_op_18_f = std::vector<float>(12800);
std::vector<float> fVec_op_18_xpad = std::vector<float>(4194304);
std::vector<float> fVec_op_18_xcol = std::vector<float>(2880000);

std::vector<float> fVec_op_20_f = std::vector<float>(3200);
std::vector<float> fVec_op_20_xpad = std::vector<float>(1843200);
std::vector<float> fVec_op_20_xcol = std::vector<float>(1254400);

std::vector<float> fVec_op_22_f = std::vector<float>(800);
std::vector<float> fVec_op_22_xpad = std::vector<float>(802816);
std::vector<float> fVec_op_22_xcol = std::vector<float>(540800);

std::vector<float> fVec_op_24_f = std::vector<float>(200);
std::vector<float> fVec_op_24_xpad = std::vector<float>(346112);
std::vector<float> fVec_op_24_xcol = std::vector<float>(230400);

std::vector<float> fVec_op_26_f = std::vector<float>(50);
std::vector<float> fVec_op_26_xpad = std::vector<float>(147456);
std::vector<float> fVec_op_26_xcol = std::vector<float>(96800);


Session(std::string filename ="") {
   if (filename.empty()) filename = "Conv_d100_L14_B32.dat";
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()){
      throw std::runtime_error("tmva-sofie failed to open file for input weights");
   }
   std::string tensor_name;
   int length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv13bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv13bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 1) {
      std::cout << "Error in tensor size : expected tensor size is 1 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv13bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv11weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv11weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 800) {
      std::cout << "Error in tensor size : expected tensor size is 800 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv11weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv10weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv10weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv10weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv10bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv10bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 8) {
      std::cout << "Error in tensor size : expected tensor size is 8 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv10bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv9bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv9bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 16) {
      std::cout << "Error in tensor size : expected tensor size is 16 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv9bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv8bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv8bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 32) {
      std::cout << "Error in tensor size : expected tensor size is 32 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv8bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv8weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv8weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 51200) {
      std::cout << "Error in tensor size : expected tensor size is 51200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv8weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv13weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv13weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 50) {
      std::cout << "Error in tensor size : expected tensor size is 50 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv13weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv6bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv6bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 128) {
      std::cout << "Error in tensor size : expected tensor size is 128 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv6bias[i];
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
   if (tensor_name != "tensor_conv9weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv9weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 12800) {
      std::cout << "Error in tensor size : expected tensor size is 12800 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv9weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv7bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv7bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 64) {
      std::cout << "Error in tensor size : expected tensor size is 64 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv7bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv1weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv1weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 200) {
      std::cout << "Error in tensor size : expected tensor size is 200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv1weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv3bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv3bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 16) {
      std::cout << "Error in tensor size : expected tensor size is 16 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv3bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv2weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv2weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 800) {
      std::cout << "Error in tensor size : expected tensor size is 800 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv2weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv4weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv4weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 12800) {
      std::cout << "Error in tensor size : expected tensor size is 12800 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv4weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv2bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv2bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 8) {
      std::cout << "Error in tensor size : expected tensor size is 8 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv2bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv1bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv1bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 4) {
      std::cout << "Error in tensor size : expected tensor size is 4 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv1bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv5bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv5bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 64) {
      std::cout << "Error in tensor size : expected tensor size is 64 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv5bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv3weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv3weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 3200) {
      std::cout << "Error in tensor size : expected tensor size is 3200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv3weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv7weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv7weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 204800) {
      std::cout << "Error in tensor size : expected tensor size is 204800 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv7weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv4bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv4bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 32) {
      std::cout << "Error in tensor size : expected tensor size is 32 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv4bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv12bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv12bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 2) {
      std::cout << "Error in tensor size : expected tensor size is 2 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv12bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv12weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv12weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 200) {
      std::cout << "Error in tensor size : expected tensor size is 200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv12weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv5weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv5weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 51200) {
      std::cout << "Error in tensor size : expected tensor size is 51200 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv5weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv11bias" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv11bias read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 4) {
      std::cout << "Error in tensor size : expected tensor size is 4 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv11bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_conv6weight" ) {
      std::cout << "Error in tensor name : expected tensor name is tensor_conv6weight read " << tensor_name << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor name");
    }
   if (length != 204800) {
      std::cout << "Error in tensor size : expected tensor size is 204800 read " << length << std::endl;
      throw std::runtime_error("tmva-sofie failed to read the correct tensor size");
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_conv6weight[i];
   f.close();
   {
      std::vector<size_t> oldShape = { 2 };
      std::vector<size_t> newShape = { 2, 96, 96};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv0bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv0biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 4 };
      std::vector<size_t> newShape = { 4, 92, 92};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv1bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv1biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 8 };
      std::vector<size_t> newShape = { 8, 88, 88};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv2bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv2biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 16 };
      std::vector<size_t> newShape = { 16, 84, 84};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv3bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv3biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 32 };
      std::vector<size_t> newShape = { 32, 80, 80};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv4bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv4biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 64 };
      std::vector<size_t> newShape = { 64, 76, 76};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv5bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv5biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 128 };
      std::vector<size_t> newShape = { 128, 72, 72};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv6bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv6biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 64 };
      std::vector<size_t> newShape = { 64, 68, 68};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv7bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv7biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 32 };
      std::vector<size_t> newShape = { 32, 64, 64};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv8bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv8biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 16 };
      std::vector<size_t> newShape = { 16, 60, 60};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv9bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv9biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 8 };
      std::vector<size_t> newShape = { 8, 56, 56};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv10bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv10biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 4 };
      std::vector<size_t> newShape = { 4, 52, 52};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv11bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv11biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 2 };
      std::vector<size_t> newShape = { 2, 48, 48};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv12bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv12biasbcast + i * length);
   }
   {
      std::vector<size_t> oldShape = { 1 };
      std::vector<size_t> newShape = { 1, 44, 44};
      oldShape.resize(newShape.size(), 1.);
      float * newData_ptr = TMVA::Experimental::SOFIE::UTILITY::Unidirectional_broadcast<float>(tensor_conv13bias, oldShape, newShape);
      int length = TMVA::Experimental::SOFIE::ConvertShapeToLength(newShape);
      for (int i = 0; i < 32 ; i++)
         std::copy(newData_ptr, newData_ptr + length , tensor_conv13biasbcast + i * length);
   }
}

std::vector<float> infer(float* tensor_input1){

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
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 1; c++) {
         for (size_t h = 0; h < 100; h++) {
            size_t xpad_offset = n * 10000 + c * 10000 + (h + 0) * 100 + 0;
            size_t x_offset = n * 10000 + c * 10000 + h * 100;
         std::copy(tensor_input1 + x_offset, tensor_input1 + x_offset + 100, op_0_xpad + xpad_offset);
         }
      }
   }
   char op_0_transA = 'T';
   char op_0_transB = 'N';
   int op_0_m = 9216;
   int op_0_n = 2;
   int op_0_k = 25;
   float op_0_alpha = 1.0;
   float op_0_beta = 0.0;
   float * op_0_xcol = fVec_op_0_xcol.data();
   size_t offset_tensor_29 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 1; c++) {
         for (size_t h = 0; h < 100; h++) {
            size_t xpad_offset = c * 10000 + (h + 0) * 100 + 0;
            size_t x_offset = n * 10000 + c * 10000 + h * 100;
            std::copy(tensor_input1 + x_offset, tensor_input1 + x_offset + 100, op_0_xpad + xpad_offset);
         }
      }
      size_t op_0_index = 0;
      for (size_t h = 0; h < 96; h += 1) {
         for (size_t w = 0; w < 96;w += 1) {
            for (size_t c = 0; c < 1; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 10000 + (h + x) * 100 + w;
               std::copy(op_0_xpad + offset, op_0_xpad + offset + 5, op_0_xcol + op_0_index);
               op_0_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_0_transA, &op_0_transB, &op_0_m, &op_0_n, &op_0_k, &op_0_alpha, op_0_xcol, &op_0_k,
         op_0_f, &op_0_k, &op_0_beta, tensor_29 + offset_tensor_29, &op_0_m);
      offset_tensor_29 += 18432;
   }
   int op_0_size = 589824;
   float op_0_gamma = 1.0;
   int op_0_incx = 1;
   int op_0_incy = 1;
   BLAS::saxpy_(&op_0_size, &op_0_gamma, tensor_conv0biasbcast, &op_0_incx, tensor_29, &op_0_incy);

//------ RELU
   for (int id = 0; id < 589824 ; id++){
      tensor_30[id] = ((tensor_29[id] > 0 )? tensor_29[id] : 0);
   }

//----  operator Conv op_2
   float * op_2_f = fVec_op_2_f.data();
   for (std::size_t k = 0; k < 4; k++) {
      for (std::size_t d = 0; d < 2; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_2_f[k * 50 + d * 25 + h * 5 + w * 1  ] = tensor_conv1weight[k * 50 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_2_xpad = fVec_op_2_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 2; c++) {
         for (size_t h = 0; h < 96; h++) {
            size_t xpad_offset = n * 18432 + c * 9216 + (h + 0) * 96 + 0;
            size_t x_offset = n * 18432 + c * 9216 + h * 96;
         std::copy(tensor_30 + x_offset, tensor_30 + x_offset + 96, op_2_xpad + xpad_offset);
         }
      }
   }
   char op_2_transA = 'T';
   char op_2_transB = 'N';
   int op_2_m = 8464;
   int op_2_n = 4;
   int op_2_k = 50;
   float op_2_alpha = 1.0;
   float op_2_beta = 0.0;
   float * op_2_xcol = fVec_op_2_xcol.data();
   size_t offset_tensor_31 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 2; c++) {
         for (size_t h = 0; h < 96; h++) {
            size_t xpad_offset = c * 9216 + (h + 0) * 96 + 0;
            size_t x_offset = n * 18432 + c * 9216 + h * 96;
            std::copy(tensor_30 + x_offset, tensor_30 + x_offset + 96, op_2_xpad + xpad_offset);
         }
      }
      size_t op_2_index = 0;
      for (size_t h = 0; h < 92; h += 1) {
         for (size_t w = 0; w < 92;w += 1) {
            for (size_t c = 0; c < 2; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 9216 + (h + x) * 96 + w;
               std::copy(op_2_xpad + offset, op_2_xpad + offset + 5, op_2_xcol + op_2_index);
               op_2_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_2_transA, &op_2_transB, &op_2_m, &op_2_n, &op_2_k, &op_2_alpha, op_2_xcol, &op_2_k,
         op_2_f, &op_2_k, &op_2_beta, tensor_31 + offset_tensor_31, &op_2_m);
      offset_tensor_31 += 33856;
   }
   int op_2_size = 1083392;
   float op_2_gamma = 1.0;
   int op_2_incx = 1;
   int op_2_incy = 1;
   BLAS::saxpy_(&op_2_size, &op_2_gamma, tensor_conv1biasbcast, &op_2_incx, tensor_31, &op_2_incy);

//------ RELU
   for (int id = 0; id < 1083392 ; id++){
      tensor_32[id] = ((tensor_31[id] > 0 )? tensor_31[id] : 0);
   }

//----  operator Conv op_4
   float * op_4_f = fVec_op_4_f.data();
   for (std::size_t k = 0; k < 8; k++) {
      for (std::size_t d = 0; d < 4; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_4_f[k * 100 + d * 25 + h * 5 + w * 1  ] = tensor_conv2weight[k * 100 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_4_xpad = fVec_op_4_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 4; c++) {
         for (size_t h = 0; h < 92; h++) {
            size_t xpad_offset = n * 33856 + c * 8464 + (h + 0) * 92 + 0;
            size_t x_offset = n * 33856 + c * 8464 + h * 92;
         std::copy(tensor_32 + x_offset, tensor_32 + x_offset + 92, op_4_xpad + xpad_offset);
         }
      }
   }
   char op_4_transA = 'T';
   char op_4_transB = 'N';
   int op_4_m = 7744;
   int op_4_n = 8;
   int op_4_k = 100;
   float op_4_alpha = 1.0;
   float op_4_beta = 0.0;
   float * op_4_xcol = fVec_op_4_xcol.data();
   size_t offset_tensor_33 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 4; c++) {
         for (size_t h = 0; h < 92; h++) {
            size_t xpad_offset = c * 8464 + (h + 0) * 92 + 0;
            size_t x_offset = n * 33856 + c * 8464 + h * 92;
            std::copy(tensor_32 + x_offset, tensor_32 + x_offset + 92, op_4_xpad + xpad_offset);
         }
      }
      size_t op_4_index = 0;
      for (size_t h = 0; h < 88; h += 1) {
         for (size_t w = 0; w < 88;w += 1) {
            for (size_t c = 0; c < 4; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 8464 + (h + x) * 92 + w;
               std::copy(op_4_xpad + offset, op_4_xpad + offset + 5, op_4_xcol + op_4_index);
               op_4_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_4_transA, &op_4_transB, &op_4_m, &op_4_n, &op_4_k, &op_4_alpha, op_4_xcol, &op_4_k,
         op_4_f, &op_4_k, &op_4_beta, tensor_33 + offset_tensor_33, &op_4_m);
      offset_tensor_33 += 61952;
   }
   int op_4_size = 1982464;
   float op_4_gamma = 1.0;
   int op_4_incx = 1;
   int op_4_incy = 1;
   BLAS::saxpy_(&op_4_size, &op_4_gamma, tensor_conv2biasbcast, &op_4_incx, tensor_33, &op_4_incy);

//------ RELU
   for (int id = 0; id < 1982464 ; id++){
      tensor_34[id] = ((tensor_33[id] > 0 )? tensor_33[id] : 0);
   }

//----  operator Conv op_6
   float * op_6_f = fVec_op_6_f.data();
   for (std::size_t k = 0; k < 16; k++) {
      for (std::size_t d = 0; d < 8; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_6_f[k * 200 + d * 25 + h * 5 + w * 1  ] = tensor_conv3weight[k * 200 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_6_xpad = fVec_op_6_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 8; c++) {
         for (size_t h = 0; h < 88; h++) {
            size_t xpad_offset = n * 61952 + c * 7744 + (h + 0) * 88 + 0;
            size_t x_offset = n * 61952 + c * 7744 + h * 88;
         std::copy(tensor_34 + x_offset, tensor_34 + x_offset + 88, op_6_xpad + xpad_offset);
         }
      }
   }
   char op_6_transA = 'T';
   char op_6_transB = 'N';
   int op_6_m = 7056;
   int op_6_n = 16;
   int op_6_k = 200;
   float op_6_alpha = 1.0;
   float op_6_beta = 0.0;
   float * op_6_xcol = fVec_op_6_xcol.data();
   size_t offset_tensor_35 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 8; c++) {
         for (size_t h = 0; h < 88; h++) {
            size_t xpad_offset = c * 7744 + (h + 0) * 88 + 0;
            size_t x_offset = n * 61952 + c * 7744 + h * 88;
            std::copy(tensor_34 + x_offset, tensor_34 + x_offset + 88, op_6_xpad + xpad_offset);
         }
      }
      size_t op_6_index = 0;
      for (size_t h = 0; h < 84; h += 1) {
         for (size_t w = 0; w < 84;w += 1) {
            for (size_t c = 0; c < 8; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 7744 + (h + x) * 88 + w;
               std::copy(op_6_xpad + offset, op_6_xpad + offset + 5, op_6_xcol + op_6_index);
               op_6_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_6_transA, &op_6_transB, &op_6_m, &op_6_n, &op_6_k, &op_6_alpha, op_6_xcol, &op_6_k,
         op_6_f, &op_6_k, &op_6_beta, tensor_35 + offset_tensor_35, &op_6_m);
      offset_tensor_35 += 112896;
   }
   int op_6_size = 3612672;
   float op_6_gamma = 1.0;
   int op_6_incx = 1;
   int op_6_incy = 1;
   BLAS::saxpy_(&op_6_size, &op_6_gamma, tensor_conv3biasbcast, &op_6_incx, tensor_35, &op_6_incy);

//------ RELU
   for (int id = 0; id < 3612672 ; id++){
      tensor_36[id] = ((tensor_35[id] > 0 )? tensor_35[id] : 0);
   }

//----  operator Conv op_8
   float * op_8_f = fVec_op_8_f.data();
   for (std::size_t k = 0; k < 32; k++) {
      for (std::size_t d = 0; d < 16; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_8_f[k * 400 + d * 25 + h * 5 + w * 1  ] = tensor_conv4weight[k * 400 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_8_xpad = fVec_op_8_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 16; c++) {
         for (size_t h = 0; h < 84; h++) {
            size_t xpad_offset = n * 112896 + c * 7056 + (h + 0) * 84 + 0;
            size_t x_offset = n * 112896 + c * 7056 + h * 84;
         std::copy(tensor_36 + x_offset, tensor_36 + x_offset + 84, op_8_xpad + xpad_offset);
         }
      }
   }
   char op_8_transA = 'T';
   char op_8_transB = 'N';
   int op_8_m = 6400;
   int op_8_n = 32;
   int op_8_k = 400;
   float op_8_alpha = 1.0;
   float op_8_beta = 0.0;
   float * op_8_xcol = fVec_op_8_xcol.data();
   size_t offset_tensor_37 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 16; c++) {
         for (size_t h = 0; h < 84; h++) {
            size_t xpad_offset = c * 7056 + (h + 0) * 84 + 0;
            size_t x_offset = n * 112896 + c * 7056 + h * 84;
            std::copy(tensor_36 + x_offset, tensor_36 + x_offset + 84, op_8_xpad + xpad_offset);
         }
      }
      size_t op_8_index = 0;
      for (size_t h = 0; h < 80; h += 1) {
         for (size_t w = 0; w < 80;w += 1) {
            for (size_t c = 0; c < 16; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 7056 + (h + x) * 84 + w;
               std::copy(op_8_xpad + offset, op_8_xpad + offset + 5, op_8_xcol + op_8_index);
               op_8_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_8_transA, &op_8_transB, &op_8_m, &op_8_n, &op_8_k, &op_8_alpha, op_8_xcol, &op_8_k,
         op_8_f, &op_8_k, &op_8_beta, tensor_37 + offset_tensor_37, &op_8_m);
      offset_tensor_37 += 204800;
   }
   int op_8_size = 6553600;
   float op_8_gamma = 1.0;
   int op_8_incx = 1;
   int op_8_incy = 1;
   BLAS::saxpy_(&op_8_size, &op_8_gamma, tensor_conv4biasbcast, &op_8_incx, tensor_37, &op_8_incy);

//------ RELU
   for (int id = 0; id < 6553600 ; id++){
      tensor_38[id] = ((tensor_37[id] > 0 )? tensor_37[id] : 0);
   }

//----  operator Conv op_10
   float * op_10_f = fVec_op_10_f.data();
   for (std::size_t k = 0; k < 64; k++) {
      for (std::size_t d = 0; d < 32; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_10_f[k * 800 + d * 25 + h * 5 + w * 1  ] = tensor_conv5weight[k * 800 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_10_xpad = fVec_op_10_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 32; c++) {
         for (size_t h = 0; h < 80; h++) {
            size_t xpad_offset = n * 204800 + c * 6400 + (h + 0) * 80 + 0;
            size_t x_offset = n * 204800 + c * 6400 + h * 80;
         std::copy(tensor_38 + x_offset, tensor_38 + x_offset + 80, op_10_xpad + xpad_offset);
         }
      }
   }
   char op_10_transA = 'T';
   char op_10_transB = 'N';
   int op_10_m = 5776;
   int op_10_n = 64;
   int op_10_k = 800;
   float op_10_alpha = 1.0;
   float op_10_beta = 0.0;
   float * op_10_xcol = fVec_op_10_xcol.data();
   size_t offset_tensor_39 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 32; c++) {
         for (size_t h = 0; h < 80; h++) {
            size_t xpad_offset = c * 6400 + (h + 0) * 80 + 0;
            size_t x_offset = n * 204800 + c * 6400 + h * 80;
            std::copy(tensor_38 + x_offset, tensor_38 + x_offset + 80, op_10_xpad + xpad_offset);
         }
      }
      size_t op_10_index = 0;
      for (size_t h = 0; h < 76; h += 1) {
         for (size_t w = 0; w < 76;w += 1) {
            for (size_t c = 0; c < 32; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 6400 + (h + x) * 80 + w;
               std::copy(op_10_xpad + offset, op_10_xpad + offset + 5, op_10_xcol + op_10_index);
               op_10_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_10_transA, &op_10_transB, &op_10_m, &op_10_n, &op_10_k, &op_10_alpha, op_10_xcol, &op_10_k,
         op_10_f, &op_10_k, &op_10_beta, tensor_39 + offset_tensor_39, &op_10_m);
      offset_tensor_39 += 369664;
   }
   int op_10_size = 11829248;
   float op_10_gamma = 1.0;
   int op_10_incx = 1;
   int op_10_incy = 1;
   BLAS::saxpy_(&op_10_size, &op_10_gamma, tensor_conv5biasbcast, &op_10_incx, tensor_39, &op_10_incy);

//------ RELU
   for (int id = 0; id < 11829248 ; id++){
      tensor_40[id] = ((tensor_39[id] > 0 )? tensor_39[id] : 0);
   }

//----  operator Conv op_12
   float * op_12_f = fVec_op_12_f.data();
   for (std::size_t k = 0; k < 128; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_12_f[k * 1600 + d * 25 + h * 5 + w * 1  ] = tensor_conv6weight[k * 1600 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_12_xpad = fVec_op_12_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 64; c++) {
         for (size_t h = 0; h < 76; h++) {
            size_t xpad_offset = n * 369664 + c * 5776 + (h + 0) * 76 + 0;
            size_t x_offset = n * 369664 + c * 5776 + h * 76;
         std::copy(tensor_40 + x_offset, tensor_40 + x_offset + 76, op_12_xpad + xpad_offset);
         }
      }
   }
   char op_12_transA = 'T';
   char op_12_transB = 'N';
   int op_12_m = 5184;
   int op_12_n = 128;
   int op_12_k = 1600;
   float op_12_alpha = 1.0;
   float op_12_beta = 0.0;
   float * op_12_xcol = fVec_op_12_xcol.data();
   size_t offset_tensor_41 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 64; c++) {
         for (size_t h = 0; h < 76; h++) {
            size_t xpad_offset = c * 5776 + (h + 0) * 76 + 0;
            size_t x_offset = n * 369664 + c * 5776 + h * 76;
            std::copy(tensor_40 + x_offset, tensor_40 + x_offset + 76, op_12_xpad + xpad_offset);
         }
      }
      size_t op_12_index = 0;
      for (size_t h = 0; h < 72; h += 1) {
         for (size_t w = 0; w < 72;w += 1) {
            for (size_t c = 0; c < 64; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 5776 + (h + x) * 76 + w;
               std::copy(op_12_xpad + offset, op_12_xpad + offset + 5, op_12_xcol + op_12_index);
               op_12_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_12_transA, &op_12_transB, &op_12_m, &op_12_n, &op_12_k, &op_12_alpha, op_12_xcol, &op_12_k,
         op_12_f, &op_12_k, &op_12_beta, tensor_41 + offset_tensor_41, &op_12_m);
      offset_tensor_41 += 663552;
   }
   int op_12_size = 21233664;
   float op_12_gamma = 1.0;
   int op_12_incx = 1;
   int op_12_incy = 1;
   BLAS::saxpy_(&op_12_size, &op_12_gamma, tensor_conv6biasbcast, &op_12_incx, tensor_41, &op_12_incy);

//------ RELU
   for (int id = 0; id < 21233664 ; id++){
      tensor_42[id] = ((tensor_41[id] > 0 )? tensor_41[id] : 0);
   }

//----  operator Conv op_14
   float * op_14_f = fVec_op_14_f.data();
   for (std::size_t k = 0; k < 64; k++) {
      for (std::size_t d = 0; d < 128; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_14_f[k * 3200 + d * 25 + h * 5 + w * 1  ] = tensor_conv7weight[k * 3200 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_14_xpad = fVec_op_14_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 128; c++) {
         for (size_t h = 0; h < 72; h++) {
            size_t xpad_offset = n * 663552 + c * 5184 + (h + 0) * 72 + 0;
            size_t x_offset = n * 663552 + c * 5184 + h * 72;
         std::copy(tensor_42 + x_offset, tensor_42 + x_offset + 72, op_14_xpad + xpad_offset);
         }
      }
   }
   char op_14_transA = 'T';
   char op_14_transB = 'N';
   int op_14_m = 4624;
   int op_14_n = 64;
   int op_14_k = 3200;
   float op_14_alpha = 1.0;
   float op_14_beta = 0.0;
   float * op_14_xcol = fVec_op_14_xcol.data();
   size_t offset_tensor_43 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 128; c++) {
         for (size_t h = 0; h < 72; h++) {
            size_t xpad_offset = c * 5184 + (h + 0) * 72 + 0;
            size_t x_offset = n * 663552 + c * 5184 + h * 72;
            std::copy(tensor_42 + x_offset, tensor_42 + x_offset + 72, op_14_xpad + xpad_offset);
         }
      }
      size_t op_14_index = 0;
      for (size_t h = 0; h < 68; h += 1) {
         for (size_t w = 0; w < 68;w += 1) {
            for (size_t c = 0; c < 128; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 5184 + (h + x) * 72 + w;
               std::copy(op_14_xpad + offset, op_14_xpad + offset + 5, op_14_xcol + op_14_index);
               op_14_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_14_transA, &op_14_transB, &op_14_m, &op_14_n, &op_14_k, &op_14_alpha, op_14_xcol, &op_14_k,
         op_14_f, &op_14_k, &op_14_beta, tensor_43 + offset_tensor_43, &op_14_m);
      offset_tensor_43 += 295936;
   }
   int op_14_size = 9469952;
   float op_14_gamma = 1.0;
   int op_14_incx = 1;
   int op_14_incy = 1;
   BLAS::saxpy_(&op_14_size, &op_14_gamma, tensor_conv7biasbcast, &op_14_incx, tensor_43, &op_14_incy);

//------ RELU
   for (int id = 0; id < 9469952 ; id++){
      tensor_44[id] = ((tensor_43[id] > 0 )? tensor_43[id] : 0);
   }

//----  operator Conv op_16
   float * op_16_f = fVec_op_16_f.data();
   for (std::size_t k = 0; k < 32; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_16_f[k * 1600 + d * 25 + h * 5 + w * 1  ] = tensor_conv8weight[k * 1600 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_16_xpad = fVec_op_16_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 64; c++) {
         for (size_t h = 0; h < 68; h++) {
            size_t xpad_offset = n * 295936 + c * 4624 + (h + 0) * 68 + 0;
            size_t x_offset = n * 295936 + c * 4624 + h * 68;
         std::copy(tensor_44 + x_offset, tensor_44 + x_offset + 68, op_16_xpad + xpad_offset);
         }
      }
   }
   char op_16_transA = 'T';
   char op_16_transB = 'N';
   int op_16_m = 4096;
   int op_16_n = 32;
   int op_16_k = 1600;
   float op_16_alpha = 1.0;
   float op_16_beta = 0.0;
   float * op_16_xcol = fVec_op_16_xcol.data();
   size_t offset_tensor_45 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 64; c++) {
         for (size_t h = 0; h < 68; h++) {
            size_t xpad_offset = c * 4624 + (h + 0) * 68 + 0;
            size_t x_offset = n * 295936 + c * 4624 + h * 68;
            std::copy(tensor_44 + x_offset, tensor_44 + x_offset + 68, op_16_xpad + xpad_offset);
         }
      }
      size_t op_16_index = 0;
      for (size_t h = 0; h < 64; h += 1) {
         for (size_t w = 0; w < 64;w += 1) {
            for (size_t c = 0; c < 64; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 4624 + (h + x) * 68 + w;
               std::copy(op_16_xpad + offset, op_16_xpad + offset + 5, op_16_xcol + op_16_index);
               op_16_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_16_transA, &op_16_transB, &op_16_m, &op_16_n, &op_16_k, &op_16_alpha, op_16_xcol, &op_16_k,
         op_16_f, &op_16_k, &op_16_beta, tensor_45 + offset_tensor_45, &op_16_m);
      offset_tensor_45 += 131072;
   }
   int op_16_size = 4194304;
   float op_16_gamma = 1.0;
   int op_16_incx = 1;
   int op_16_incy = 1;
   BLAS::saxpy_(&op_16_size, &op_16_gamma, tensor_conv8biasbcast, &op_16_incx, tensor_45, &op_16_incy);

//------ RELU
   for (int id = 0; id < 4194304 ; id++){
      tensor_46[id] = ((tensor_45[id] > 0 )? tensor_45[id] : 0);
   }

//----  operator Conv op_18
   float * op_18_f = fVec_op_18_f.data();
   for (std::size_t k = 0; k < 16; k++) {
      for (std::size_t d = 0; d < 32; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_18_f[k * 800 + d * 25 + h * 5 + w * 1  ] = tensor_conv9weight[k * 800 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_18_xpad = fVec_op_18_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 32; c++) {
         for (size_t h = 0; h < 64; h++) {
            size_t xpad_offset = n * 131072 + c * 4096 + (h + 0) * 64 + 0;
            size_t x_offset = n * 131072 + c * 4096 + h * 64;
         std::copy(tensor_46 + x_offset, tensor_46 + x_offset + 64, op_18_xpad + xpad_offset);
         }
      }
   }
   char op_18_transA = 'T';
   char op_18_transB = 'N';
   int op_18_m = 3600;
   int op_18_n = 16;
   int op_18_k = 800;
   float op_18_alpha = 1.0;
   float op_18_beta = 0.0;
   float * op_18_xcol = fVec_op_18_xcol.data();
   size_t offset_tensor_47 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 32; c++) {
         for (size_t h = 0; h < 64; h++) {
            size_t xpad_offset = c * 4096 + (h + 0) * 64 + 0;
            size_t x_offset = n * 131072 + c * 4096 + h * 64;
            std::copy(tensor_46 + x_offset, tensor_46 + x_offset + 64, op_18_xpad + xpad_offset);
         }
      }
      size_t op_18_index = 0;
      for (size_t h = 0; h < 60; h += 1) {
         for (size_t w = 0; w < 60;w += 1) {
            for (size_t c = 0; c < 32; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 4096 + (h + x) * 64 + w;
               std::copy(op_18_xpad + offset, op_18_xpad + offset + 5, op_18_xcol + op_18_index);
               op_18_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_18_transA, &op_18_transB, &op_18_m, &op_18_n, &op_18_k, &op_18_alpha, op_18_xcol, &op_18_k,
         op_18_f, &op_18_k, &op_18_beta, tensor_47 + offset_tensor_47, &op_18_m);
      offset_tensor_47 += 57600;
   }
   int op_18_size = 1843200;
   float op_18_gamma = 1.0;
   int op_18_incx = 1;
   int op_18_incy = 1;
   BLAS::saxpy_(&op_18_size, &op_18_gamma, tensor_conv9biasbcast, &op_18_incx, tensor_47, &op_18_incy);

//------ RELU
   for (int id = 0; id < 1843200 ; id++){
      tensor_48[id] = ((tensor_47[id] > 0 )? tensor_47[id] : 0);
   }

//----  operator Conv op_20
   float * op_20_f = fVec_op_20_f.data();
   for (std::size_t k = 0; k < 8; k++) {
      for (std::size_t d = 0; d < 16; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_20_f[k * 400 + d * 25 + h * 5 + w * 1  ] = tensor_conv10weight[k * 400 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_20_xpad = fVec_op_20_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 16; c++) {
         for (size_t h = 0; h < 60; h++) {
            size_t xpad_offset = n * 57600 + c * 3600 + (h + 0) * 60 + 0;
            size_t x_offset = n * 57600 + c * 3600 + h * 60;
         std::copy(tensor_48 + x_offset, tensor_48 + x_offset + 60, op_20_xpad + xpad_offset);
         }
      }
   }
   char op_20_transA = 'T';
   char op_20_transB = 'N';
   int op_20_m = 3136;
   int op_20_n = 8;
   int op_20_k = 400;
   float op_20_alpha = 1.0;
   float op_20_beta = 0.0;
   float * op_20_xcol = fVec_op_20_xcol.data();
   size_t offset_tensor_49 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 16; c++) {
         for (size_t h = 0; h < 60; h++) {
            size_t xpad_offset = c * 3600 + (h + 0) * 60 + 0;
            size_t x_offset = n * 57600 + c * 3600 + h * 60;
            std::copy(tensor_48 + x_offset, tensor_48 + x_offset + 60, op_20_xpad + xpad_offset);
         }
      }
      size_t op_20_index = 0;
      for (size_t h = 0; h < 56; h += 1) {
         for (size_t w = 0; w < 56;w += 1) {
            for (size_t c = 0; c < 16; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 3600 + (h + x) * 60 + w;
               std::copy(op_20_xpad + offset, op_20_xpad + offset + 5, op_20_xcol + op_20_index);
               op_20_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_20_transA, &op_20_transB, &op_20_m, &op_20_n, &op_20_k, &op_20_alpha, op_20_xcol, &op_20_k,
         op_20_f, &op_20_k, &op_20_beta, tensor_49 + offset_tensor_49, &op_20_m);
      offset_tensor_49 += 25088;
   }
   int op_20_size = 802816;
   float op_20_gamma = 1.0;
   int op_20_incx = 1;
   int op_20_incy = 1;
   BLAS::saxpy_(&op_20_size, &op_20_gamma, tensor_conv10biasbcast, &op_20_incx, tensor_49, &op_20_incy);

//------ RELU
   for (int id = 0; id < 802816 ; id++){
      tensor_50[id] = ((tensor_49[id] > 0 )? tensor_49[id] : 0);
   }

//----  operator Conv op_22
   float * op_22_f = fVec_op_22_f.data();
   for (std::size_t k = 0; k < 4; k++) {
      for (std::size_t d = 0; d < 8; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_22_f[k * 200 + d * 25 + h * 5 + w * 1  ] = tensor_conv11weight[k * 200 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_22_xpad = fVec_op_22_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 8; c++) {
         for (size_t h = 0; h < 56; h++) {
            size_t xpad_offset = n * 25088 + c * 3136 + (h + 0) * 56 + 0;
            size_t x_offset = n * 25088 + c * 3136 + h * 56;
         std::copy(tensor_50 + x_offset, tensor_50 + x_offset + 56, op_22_xpad + xpad_offset);
         }
      }
   }
   char op_22_transA = 'T';
   char op_22_transB = 'N';
   int op_22_m = 2704;
   int op_22_n = 4;
   int op_22_k = 200;
   float op_22_alpha = 1.0;
   float op_22_beta = 0.0;
   float * op_22_xcol = fVec_op_22_xcol.data();
   size_t offset_tensor_51 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 8; c++) {
         for (size_t h = 0; h < 56; h++) {
            size_t xpad_offset = c * 3136 + (h + 0) * 56 + 0;
            size_t x_offset = n * 25088 + c * 3136 + h * 56;
            std::copy(tensor_50 + x_offset, tensor_50 + x_offset + 56, op_22_xpad + xpad_offset);
         }
      }
      size_t op_22_index = 0;
      for (size_t h = 0; h < 52; h += 1) {
         for (size_t w = 0; w < 52;w += 1) {
            for (size_t c = 0; c < 8; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 3136 + (h + x) * 56 + w;
               std::copy(op_22_xpad + offset, op_22_xpad + offset + 5, op_22_xcol + op_22_index);
               op_22_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_22_transA, &op_22_transB, &op_22_m, &op_22_n, &op_22_k, &op_22_alpha, op_22_xcol, &op_22_k,
         op_22_f, &op_22_k, &op_22_beta, tensor_51 + offset_tensor_51, &op_22_m);
      offset_tensor_51 += 10816;
   }
   int op_22_size = 346112;
   float op_22_gamma = 1.0;
   int op_22_incx = 1;
   int op_22_incy = 1;
   BLAS::saxpy_(&op_22_size, &op_22_gamma, tensor_conv11biasbcast, &op_22_incx, tensor_51, &op_22_incy);

//------ RELU
   for (int id = 0; id < 346112 ; id++){
      tensor_52[id] = ((tensor_51[id] > 0 )? tensor_51[id] : 0);
   }

//----  operator Conv op_24
   float * op_24_f = fVec_op_24_f.data();
   for (std::size_t k = 0; k < 2; k++) {
      for (std::size_t d = 0; d < 4; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_24_f[k * 100 + d * 25 + h * 5 + w * 1  ] = tensor_conv12weight[k * 100 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_24_xpad = fVec_op_24_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 4; c++) {
         for (size_t h = 0; h < 52; h++) {
            size_t xpad_offset = n * 10816 + c * 2704 + (h + 0) * 52 + 0;
            size_t x_offset = n * 10816 + c * 2704 + h * 52;
         std::copy(tensor_52 + x_offset, tensor_52 + x_offset + 52, op_24_xpad + xpad_offset);
         }
      }
   }
   char op_24_transA = 'T';
   char op_24_transB = 'N';
   int op_24_m = 2304;
   int op_24_n = 2;
   int op_24_k = 100;
   float op_24_alpha = 1.0;
   float op_24_beta = 0.0;
   float * op_24_xcol = fVec_op_24_xcol.data();
   size_t offset_tensor_53 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 4; c++) {
         for (size_t h = 0; h < 52; h++) {
            size_t xpad_offset = c * 2704 + (h + 0) * 52 + 0;
            size_t x_offset = n * 10816 + c * 2704 + h * 52;
            std::copy(tensor_52 + x_offset, tensor_52 + x_offset + 52, op_24_xpad + xpad_offset);
         }
      }
      size_t op_24_index = 0;
      for (size_t h = 0; h < 48; h += 1) {
         for (size_t w = 0; w < 48;w += 1) {
            for (size_t c = 0; c < 4; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 2704 + (h + x) * 52 + w;
               std::copy(op_24_xpad + offset, op_24_xpad + offset + 5, op_24_xcol + op_24_index);
               op_24_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_24_transA, &op_24_transB, &op_24_m, &op_24_n, &op_24_k, &op_24_alpha, op_24_xcol, &op_24_k,
         op_24_f, &op_24_k, &op_24_beta, tensor_53 + offset_tensor_53, &op_24_m);
      offset_tensor_53 += 4608;
   }
   int op_24_size = 147456;
   float op_24_gamma = 1.0;
   int op_24_incx = 1;
   int op_24_incy = 1;
   BLAS::saxpy_(&op_24_size, &op_24_gamma, tensor_conv12biasbcast, &op_24_incx, tensor_53, &op_24_incy);

//------ RELU
   for (int id = 0; id < 147456 ; id++){
      tensor_54[id] = ((tensor_53[id] > 0 )? tensor_53[id] : 0);
   }

//----  operator Conv op_26
   float * op_26_f = fVec_op_26_f.data();
   for (std::size_t k = 0; k < 1; k++) {
      for (std::size_t d = 0; d < 2; d++) {
         for (std::size_t h = 0; h < 5; h++) {
            for (std::size_t w = 0; w < 5; w++) {
               op_26_f[k * 50 + d * 25 + h * 5 + w * 1  ] = tensor_conv13weight[k * 50 + d * 25 + h * 5 + w ];
            }
         }
      }
   }
   float * op_26_xpad = fVec_op_26_xpad.data();
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 2; c++) {
         for (size_t h = 0; h < 48; h++) {
            size_t xpad_offset = n * 4608 + c * 2304 + (h + 0) * 48 + 0;
            size_t x_offset = n * 4608 + c * 2304 + h * 48;
         std::copy(tensor_54 + x_offset, tensor_54 + x_offset + 48, op_26_xpad + xpad_offset);
         }
      }
   }
   char op_26_transA = 'T';
   char op_26_transB = 'N';
   int op_26_m = 1936;
   int op_26_n = 1;
   int op_26_k = 50;
   float op_26_alpha = 1.0;
   float op_26_beta = 0.0;
   float * op_26_xcol = fVec_op_26_xcol.data();
   size_t offset_tensor_55 = 0;
   for (size_t n = 0; n < 32; n++) {
      for (size_t c = 0; c < 2; c++) {
         for (size_t h = 0; h < 48; h++) {
            size_t xpad_offset = c * 2304 + (h + 0) * 48 + 0;
            size_t x_offset = n * 4608 + c * 2304 + h * 48;
            std::copy(tensor_54 + x_offset, tensor_54 + x_offset + 48, op_26_xpad + xpad_offset);
         }
      }
      size_t op_26_index = 0;
      for (size_t h = 0; h < 44; h += 1) {
         for (size_t w = 0; w < 44;w += 1) {
            for (size_t c = 0; c < 2; c++) {
               for (size_t x = 0; x < 5; x++) {
               size_t offset =  c * 2304 + (h + x) * 48 + w;
               std::copy(op_26_xpad + offset, op_26_xpad + offset + 5, op_26_xcol + op_26_index);
               op_26_index += 5;
               }
            }
         }
      }
      BLAS::sgemm_(&op_26_transA, &op_26_transB, &op_26_m, &op_26_n, &op_26_k, &op_26_alpha, op_26_xcol, &op_26_k,
         op_26_f, &op_26_k, &op_26_beta, tensor_55 + offset_tensor_55, &op_26_m);
      offset_tensor_55 += 1936;
   }
   int op_26_size = 61952;
   float op_26_gamma = 1.0;
   int op_26_incx = 1;
   int op_26_incy = 1;
   BLAS::saxpy_(&op_26_size, &op_26_gamma, tensor_conv13biasbcast, &op_26_incx, tensor_55, &op_26_incy);

//------ RELU
   for (int id = 0; id < 61952 ; id++){
      tensor_56[id] = ((tensor_55[id] > 0 )? tensor_55[id] : 0);
   }
	std::vector<float> ret (tensor_56, tensor_56 + 61952);
	return ret;
}
};
} //TMVA_SOFIE_Conv_d100_L14_B32
