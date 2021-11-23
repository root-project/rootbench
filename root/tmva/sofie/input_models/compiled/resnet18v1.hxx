//Code generated automatically by TMVA for Inference of Model file [resnet18v1.onnx] at [Sun Nov 21 22:14:01 2021] 
#include<algorithm>
#include<vector>
#include<cmath>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_resnet18v1{
namespace BLAS{
	extern "C" void scopy_(const int *n, const float* x, const int *incx, float* y, const int* incy);
	extern "C" void saxpy_(const int * n, const float * alpha, const float * x,
	                         const int * incx, float * y, const int * incy);
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
std::vector<float> fTensor_resnetv15stage4batchnorm4beta = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm4beta = fTensor_resnetv15stage4batchnorm4beta.data();
std::vector<float> fTensor_resnetv15stage4batchnorm3runningvar = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm3runningvar = fTensor_resnetv15stage4batchnorm3runningvar.data();
std::vector<float> fTensor_resnetv15stage4batchnorm3runningmean = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm3runningmean = fTensor_resnetv15stage4batchnorm3runningmean.data();
std::vector<float> fTensor_resnetv15stage4batchnorm1gamma = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm1gamma = fTensor_resnetv15stage4batchnorm1gamma.data();
std::vector<float> fTensor_resnetv15stage4conv1weight = std::vector<float>(2359296);
float * tensor_resnetv15stage4conv1weight = fTensor_resnetv15stage4conv1weight.data();
std::vector<float> fTensor_resnetv15stage4batchnorm0runningvar = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm0runningvar = fTensor_resnetv15stage4batchnorm0runningvar.data();
std::vector<float> fTensor_resnetv15stage4batchnorm0runningmean = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm0runningmean = fTensor_resnetv15stage4batchnorm0runningmean.data();
std::vector<float> fTensor_resnetv15stage4batchnorm0gamma = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm0gamma = fTensor_resnetv15stage4batchnorm0gamma.data();
std::vector<float> fTensor_resnetv15stage4conv0weight = std::vector<float>(1179648);
float * tensor_resnetv15stage4conv0weight = fTensor_resnetv15stage4conv0weight.data();
std::vector<float> fTensor_resnetv15stage4batchnorm2runningmean = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm2runningmean = fTensor_resnetv15stage4batchnorm2runningmean.data();
std::vector<float> fTensor_resnetv15stage4batchnorm1beta = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm1beta = fTensor_resnetv15stage4batchnorm1beta.data();
std::vector<float> fTensor_resnetv15stage4batchnorm2gamma = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm2gamma = fTensor_resnetv15stage4batchnorm2gamma.data();
std::vector<float> fTensor_resnetv15stage4conv2weight = std::vector<float>(131072);
float * tensor_resnetv15stage4conv2weight = fTensor_resnetv15stage4conv2weight.data();
std::vector<float> fTensor_resnetv15stage4batchnorm4runningvar = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm4runningvar = fTensor_resnetv15stage4batchnorm4runningvar.data();
std::vector<float> fTensor_resnetv15stage3batchnorm4runningvar = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm4runningvar = fTensor_resnetv15stage3batchnorm4runningvar.data();
std::vector<float> fTensor_resnetv15stage4batchnorm2beta = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm2beta = fTensor_resnetv15stage4batchnorm2beta.data();
std::vector<float> fTensor_resnetv15stage3batchnorm4gamma = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm4gamma = fTensor_resnetv15stage3batchnorm4gamma.data();
std::vector<float> fTensor_resnetv15stage4batchnorm3beta = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm3beta = fTensor_resnetv15stage4batchnorm3beta.data();
std::vector<float> fTensor_resnetv15stage3batchnorm3runningvar = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm3runningvar = fTensor_resnetv15stage3batchnorm3runningvar.data();
std::vector<float> fTensor_resnetv15stage3conv3weight = std::vector<float>(589824);
float * tensor_resnetv15stage3conv3weight = fTensor_resnetv15stage3conv3weight.data();
std::vector<float> fTensor_resnetv15stage4batchnorm1runningvar = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm1runningvar = fTensor_resnetv15stage4batchnorm1runningvar.data();
std::vector<float> fTensor_resnetv15stage3batchnorm1runningvar = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm1runningvar = fTensor_resnetv15stage3batchnorm1runningvar.data();
std::vector<float> fTensor_resnetv15stage3batchnorm1runningmean = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm1runningmean = fTensor_resnetv15stage3batchnorm1runningmean.data();
std::vector<float> fTensor_resnetv15stage3batchnorm1beta = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm1beta = fTensor_resnetv15stage3batchnorm1beta.data();
std::vector<float> fTensor_resnetv15stage3conv1weight = std::vector<float>(589824);
float * tensor_resnetv15stage3conv1weight = fTensor_resnetv15stage3conv1weight.data();
std::vector<float> fTensor_resnetv15dense0bias = std::vector<float>(1000);
float * tensor_resnetv15dense0bias = fTensor_resnetv15dense0bias.data();
std::vector<float> fTensor_resnetv15stage3batchnorm0runningvar = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm0runningvar = fTensor_resnetv15stage3batchnorm0runningvar.data();
std::vector<float> fTensor_resnetv15stage2batchnorm2runningmean = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm2runningmean = fTensor_resnetv15stage2batchnorm2runningmean.data();
std::vector<float> fTensor_resnetv15stage2batchnorm2gamma = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm2gamma = fTensor_resnetv15stage2batchnorm2gamma.data();
std::vector<float> fTensor_resnetv15stage1batchnorm3runningvar = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm3runningvar = fTensor_resnetv15stage1batchnorm3runningvar.data();
std::vector<float> fTensor_resnetv15stage4conv3weight = std::vector<float>(2359296);
float * tensor_resnetv15stage4conv3weight = fTensor_resnetv15stage4conv3weight.data();
std::vector<float> fTensor_resnetv15stage3batchnorm3beta = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm3beta = fTensor_resnetv15stage3batchnorm3beta.data();
std::vector<float> fTensor_resnetv15stage2conv0weight = std::vector<float>(73728);
float * tensor_resnetv15stage2conv0weight = fTensor_resnetv15stage2conv0weight.data();
std::vector<float> fTensor_resnetv15stage2batchnorm4runningmean = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm4runningmean = fTensor_resnetv15stage2batchnorm4runningmean.data();
std::vector<float> fTensor_resnetv15stage1batchnorm3runningmean = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm3runningmean = fTensor_resnetv15stage1batchnorm3runningmean.data();
std::vector<float> fTensor_resnetv15stage2batchnorm2runningvar = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm2runningvar = fTensor_resnetv15stage2batchnorm2runningvar.data();
std::vector<float> fTensor_resnetv15stage2batchnorm4beta = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm4beta = fTensor_resnetv15stage2batchnorm4beta.data();
std::vector<float> fTensor_resnetv15stage3conv0weight = std::vector<float>(294912);
float * tensor_resnetv15stage3conv0weight = fTensor_resnetv15stage3conv0weight.data();
std::vector<float> fTensor_resnetv15stage1batchnorm1runningmean = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm1runningmean = fTensor_resnetv15stage1batchnorm1runningmean.data();
std::vector<float> fTensor_resnetv15stage1conv2weight = std::vector<float>(36864);
float * tensor_resnetv15stage1conv2weight = fTensor_resnetv15stage1conv2weight.data();
std::vector<float> fTensor_resnetv15stage3batchnorm2runningmean = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm2runningmean = fTensor_resnetv15stage3batchnorm2runningmean.data();
std::vector<float> fTensor_resnetv15stage1batchnorm3gamma = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm3gamma = fTensor_resnetv15stage1batchnorm3gamma.data();
std::vector<float> fTensor_resnetv15stage2batchnorm4gamma = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm4gamma = fTensor_resnetv15stage2batchnorm4gamma.data();
std::vector<float> fTensor_resnetv15stage3batchnorm2beta = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm2beta = fTensor_resnetv15stage3batchnorm2beta.data();
std::vector<float> fTensor_resnetv15stage1batchnorm2runningvar = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm2runningvar = fTensor_resnetv15stage1batchnorm2runningvar.data();
std::vector<float> fTensor_resnetv15stage1batchnorm2beta = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm2beta = fTensor_resnetv15stage1batchnorm2beta.data();
std::vector<float> fTensor_resnetv15stage3batchnorm1gamma = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm1gamma = fTensor_resnetv15stage3batchnorm1gamma.data();
std::vector<float> fTensor_resnetv15stage1batchnorm0gamma = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm0gamma = fTensor_resnetv15stage1batchnorm0gamma.data();
std::vector<float> fTensor_resnetv15stage3batchnorm0runningmean = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm0runningmean = fTensor_resnetv15stage3batchnorm0runningmean.data();
std::vector<float> fTensor_resnetv15stage3conv4weight = std::vector<float>(589824);
float * tensor_resnetv15stage3conv4weight = fTensor_resnetv15stage3conv4weight.data();
std::vector<float> fTensor_resnetv15stage1batchnorm2gamma = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm2gamma = fTensor_resnetv15stage1batchnorm2gamma.data();
std::vector<float> fTensor_resnetv15stage4conv4weight = std::vector<float>(2359296);
float * tensor_resnetv15stage4conv4weight = fTensor_resnetv15stage4conv4weight.data();
std::vector<float> fTensor_resnetv15stage2batchnorm2beta = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm2beta = fTensor_resnetv15stage2batchnorm2beta.data();
std::vector<float> fTensor_resnetv15stage1batchnorm1runningvar = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm1runningvar = fTensor_resnetv15stage1batchnorm1runningvar.data();
std::vector<float> fTensor_resnetv15batchnorm0gamma = std::vector<float>(802816);
float * tensor_resnetv15batchnorm0gamma = fTensor_resnetv15batchnorm0gamma.data();
std::vector<float> fTensor_resnetv15stage2conv2weight = std::vector<float>(8192);
float * tensor_resnetv15stage2conv2weight = fTensor_resnetv15stage2conv2weight.data();
std::vector<float> fTensor_resnetv15stage1conv1weight = std::vector<float>(36864);
float * tensor_resnetv15stage1conv1weight = fTensor_resnetv15stage1conv1weight.data();
std::vector<float> fTensor_resnetv15stage2batchnorm0gamma = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm0gamma = fTensor_resnetv15stage2batchnorm0gamma.data();
std::vector<float> fTensor_resnetv15batchnorm0runningmean = std::vector<float>(802816);
float * tensor_resnetv15batchnorm0runningmean = fTensor_resnetv15batchnorm0runningmean.data();
std::vector<float> fTensor_resnetv15stage3batchnorm3runningmean = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm3runningmean = fTensor_resnetv15stage3batchnorm3runningmean.data();
std::vector<float> fTensor_resnetv15conv0weight = std::vector<float>(9408);
float * tensor_resnetv15conv0weight = fTensor_resnetv15conv0weight.data();
std::vector<float> fTensor_resnetv15stage1conv0weight = std::vector<float>(36864);
float * tensor_resnetv15stage1conv0weight = fTensor_resnetv15stage1conv0weight.data();
std::vector<float> fTensor_resnetv15batchnorm0beta = std::vector<float>(802816);
float * tensor_resnetv15batchnorm0beta = fTensor_resnetv15batchnorm0beta.data();
std::vector<float> fTensor_resnetv15stage3batchnorm0gamma = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm0gamma = fTensor_resnetv15stage3batchnorm0gamma.data();
std::vector<float> fTensor_resnetv15stage1batchnorm0beta = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm0beta = fTensor_resnetv15stage1batchnorm0beta.data();
std::vector<float> fTensor_resnetv15batchnorm0runningvar = std::vector<float>(802816);
float * tensor_resnetv15batchnorm0runningvar = fTensor_resnetv15batchnorm0runningvar.data();
std::vector<float> fTensor_resnetv15stage1batchnorm0runningvar = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm0runningvar = fTensor_resnetv15stage1batchnorm0runningvar.data();
std::vector<float> fTensor_resnetv15stage4batchnorm4gamma = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm4gamma = fTensor_resnetv15stage4batchnorm4gamma.data();
std::vector<float> fTensor_resnetv15stage3conv2weight = std::vector<float>(32768);
float * tensor_resnetv15stage3conv2weight = fTensor_resnetv15stage3conv2weight.data();
std::vector<float> fTensor_resnetv15stage4batchnorm3gamma = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm3gamma = fTensor_resnetv15stage4batchnorm3gamma.data();
std::vector<float> fTensor_resnetv15stage3batchnorm4beta = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm4beta = fTensor_resnetv15stage3batchnorm4beta.data();
std::vector<float> fTensor_resnetv15stage1batchnorm1gamma = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm1gamma = fTensor_resnetv15stage1batchnorm1gamma.data();
std::vector<float> fTensor_resnetv15stage4batchnorm2runningvar = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm2runningvar = fTensor_resnetv15stage4batchnorm2runningvar.data();
std::vector<float> fTensor_resnetv15stage3batchnorm3gamma = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm3gamma = fTensor_resnetv15stage3batchnorm3gamma.data();
std::vector<float> fTensor_resnetv15stage2batchnorm3runningmean = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm3runningmean = fTensor_resnetv15stage2batchnorm3runningmean.data();
std::vector<float> fTensor_resnetv15stage1batchnorm0runningmean = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm0runningmean = fTensor_resnetv15stage1batchnorm0runningmean.data();
std::vector<float> fTensor_resnetv15dense0weight = std::vector<float>(512000);
float * tensor_resnetv15dense0weight = fTensor_resnetv15dense0weight.data();
std::vector<float> fTensor_resnetv15stage1batchnorm1beta = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm1beta = fTensor_resnetv15stage1batchnorm1beta.data();
std::vector<float> fTensor_resnetv15stage3batchnorm2gamma = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm2gamma = fTensor_resnetv15stage3batchnorm2gamma.data();
std::vector<float> fTensor_resnetv15stage1conv3weight = std::vector<float>(36864);
float * tensor_resnetv15stage1conv3weight = fTensor_resnetv15stage1conv3weight.data();
std::vector<float> fTensor_resnetv15stage2batchnorm3runningvar = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm3runningvar = fTensor_resnetv15stage2batchnorm3runningvar.data();
std::vector<float> fTensor_resnetv15stage2batchnorm0beta = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm0beta = fTensor_resnetv15stage2batchnorm0beta.data();
std::vector<float> fTensor_resnetv15stage2batchnorm0runningmean = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm0runningmean = fTensor_resnetv15stage2batchnorm0runningmean.data();
std::vector<float> fTensor_resnetv15stage1batchnorm3beta = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm3beta = fTensor_resnetv15stage1batchnorm3beta.data();
std::vector<float> fTensor_resnetv15stage2batchnorm1beta = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm1beta = fTensor_resnetv15stage2batchnorm1beta.data();
std::vector<float> fTensor_resnetv15stage2batchnorm0runningvar = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm0runningvar = fTensor_resnetv15stage2batchnorm0runningvar.data();
std::vector<float> fTensor_resnetv15stage2batchnorm1gamma = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm1gamma = fTensor_resnetv15stage2batchnorm1gamma.data();
std::vector<float> fTensor_resnetv15stage2conv1weight = std::vector<float>(147456);
float * tensor_resnetv15stage2conv1weight = fTensor_resnetv15stage2conv1weight.data();
std::vector<float> fTensor_resnetv15stage2conv3weight = std::vector<float>(147456);
float * tensor_resnetv15stage2conv3weight = fTensor_resnetv15stage2conv3weight.data();
std::vector<float> fTensor_resnetv15stage2batchnorm1runningmean = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm1runningmean = fTensor_resnetv15stage2batchnorm1runningmean.data();
std::vector<float> fTensor_resnetv15stage2batchnorm1runningvar = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm1runningvar = fTensor_resnetv15stage2batchnorm1runningvar.data();
std::vector<float> fTensor_resnetv15stage4batchnorm4runningmean = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm4runningmean = fTensor_resnetv15stage4batchnorm4runningmean.data();
std::vector<float> fTensor_resnetv15stage4batchnorm0beta = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm0beta = fTensor_resnetv15stage4batchnorm0beta.data();
std::vector<float> fTensor_resnetv15stage2conv4weight = std::vector<float>(147456);
float * tensor_resnetv15stage2conv4weight = fTensor_resnetv15stage2conv4weight.data();
std::vector<float> fTensor_resnetv15stage3batchnorm0beta = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm0beta = fTensor_resnetv15stage3batchnorm0beta.data();
std::vector<float> fTensor_resnetv15stage2batchnorm3gamma = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm3gamma = fTensor_resnetv15stage2batchnorm3gamma.data();
std::vector<float> fTensor_resnetv15stage2batchnorm3beta = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm3beta = fTensor_resnetv15stage2batchnorm3beta.data();
std::vector<float> fTensor_resnetv15stage4batchnorm1runningmean = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm1runningmean = fTensor_resnetv15stage4batchnorm1runningmean.data();
std::vector<float> fTensor_resnetv15stage2batchnorm4runningvar = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm4runningvar = fTensor_resnetv15stage2batchnorm4runningvar.data();
std::vector<float> fTensor_resnetv15stage3batchnorm4runningmean = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm4runningmean = fTensor_resnetv15stage3batchnorm4runningmean.data();
std::vector<float> fTensor_resnetv15stage1batchnorm2runningmean = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm2runningmean = fTensor_resnetv15stage1batchnorm2runningmean.data();
std::vector<float> fTensor_resnetv15stage3batchnorm2runningvar = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm2runningvar = fTensor_resnetv15stage3batchnorm2runningvar.data();
std::vector<float> fTensor_resnetv15stage4plus1 = std::vector<float>(25088);
float * tensor_resnetv15stage4plus1 = fTensor_resnetv15stage4plus1.data();
std::vector<float> fTensor_resnetv15stage4batchnorm4fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm4fwd = fTensor_resnetv15stage4batchnorm4fwd.data();
std::vector<float> fTensor_resnetv15stage4relu1fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4relu1fwd = fTensor_resnetv15stage4relu1fwd.data();
std::vector<float> fTensor_resnetv15stage4batchnorm3fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm3fwd = fTensor_resnetv15stage4batchnorm3fwd.data();
std::vector<float> fTensor_resnetv15stage4conv3fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4conv3fwd = fTensor_resnetv15stage4conv3fwd.data();
std::vector<float> fTensor_resnetv15stage2conv3fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2conv3fwd = fTensor_resnetv15stage2conv3fwd.data();
std::vector<float> fTensor_resnetv15stage1activation1 = std::vector<float>(200704);
float * tensor_resnetv15stage1activation1 = fTensor_resnetv15stage1activation1.data();
std::vector<float> fTensor_resnetv15stage4conv4fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4conv4fwd = fTensor_resnetv15stage4conv4fwd.data();
std::vector<float> fTensor_resnetv15stage2activation0 = std::vector<float>(100352);
float * tensor_resnetv15stage2activation0 = fTensor_resnetv15stage2activation0.data();
std::vector<float> fTensor_resnetv15stage2plus0 = std::vector<float>(100352);
float * tensor_resnetv15stage2plus0 = fTensor_resnetv15stage2plus0.data();
std::vector<float> fTensor_resnetv15stage1conv1fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1conv1fwd = fTensor_resnetv15stage1conv1fwd.data();
std::vector<float> fTensor_resnetv15stage2conv1fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2conv1fwd = fTensor_resnetv15stage2conv1fwd.data();
std::vector<float> fTensor_resnetv15stage2conv4fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2conv4fwd = fTensor_resnetv15stage2conv4fwd.data();
std::vector<float> fTensor_resnetv15stage3activation1 = std::vector<float>(50176);
float * tensor_resnetv15stage3activation1 = fTensor_resnetv15stage3activation1.data();
std::vector<float> fTensor_resnetv15stage2batchnorm0fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm0fwd = fTensor_resnetv15stage2batchnorm0fwd.data();
std::vector<float> fTensor_resnetv15stage2relu0fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2relu0fwd = fTensor_resnetv15stage2relu0fwd.data();
std::vector<float> fTensor_resnetv15stage2batchnorm2fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm2fwd = fTensor_resnetv15stage2batchnorm2fwd.data();
std::vector<float> fTensor_resnetv15stage4conv0fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4conv0fwd = fTensor_resnetv15stage4conv0fwd.data();
std::vector<float> fTensor_resnetv15stage1conv3fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1conv3fwd = fTensor_resnetv15stage1conv3fwd.data();
std::vector<float> fTensor_resnetv15stage1activation0 = std::vector<float>(200704);
float * tensor_resnetv15stage1activation0 = fTensor_resnetv15stage1activation0.data();
std::vector<float> fTensor_resnetv15stage2batchnorm3fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm3fwd = fTensor_resnetv15stage2batchnorm3fwd.data();
std::vector<float> fTensor_resnetv15stage2conv2fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2conv2fwd = fTensor_resnetv15stage2conv2fwd.data();
std::vector<float> fTensor_flatten170 = std::vector<float>(4608);
float * tensor_flatten170 = fTensor_flatten170.data();
std::vector<float> fTensor_resnetv15conv0fwd = std::vector<float>(802816);
float * tensor_resnetv15conv0fwd = fTensor_resnetv15conv0fwd.data();
std::vector<float> fTensor_resnetv15stage2batchnorm4fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm4fwd = fTensor_resnetv15stage2batchnorm4fwd.data();
std::vector<float> fTensor_resnetv15stage3conv3fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3conv3fwd = fTensor_resnetv15stage3conv3fwd.data();
std::vector<float> fTensor_resnetv15stage3batchnorm4fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm4fwd = fTensor_resnetv15stage3batchnorm4fwd.data();
std::vector<float> fTensor_resnetv15stage1batchnorm3fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm3fwd = fTensor_resnetv15stage1batchnorm3fwd.data();
std::vector<float> fTensor_resnetv15stage3batchnorm0fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm0fwd = fTensor_resnetv15stage3batchnorm0fwd.data();
std::vector<float> fTensor_resnetv15batchnorm0fwd = std::vector<float>(802816);
float * tensor_resnetv15batchnorm0fwd = fTensor_resnetv15batchnorm0fwd.data();
std::vector<float> fTensor_resnetv15relu0fwd = std::vector<float>(802816);
float * tensor_resnetv15relu0fwd = fTensor_resnetv15relu0fwd.data();
std::vector<float> fTensor_resnetv15stage4batchnorm2fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm2fwd = fTensor_resnetv15stage4batchnorm2fwd.data();
std::vector<float> fTensor_resnetv15stage1conv0fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1conv0fwd = fTensor_resnetv15stage1conv0fwd.data();
std::vector<float> fTensor_resnetv15stage1plus0 = std::vector<float>(200704);
float * tensor_resnetv15stage1plus0 = fTensor_resnetv15stage1plus0.data();
std::vector<float> fTensor_resnetv15stage1relu1fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1relu1fwd = fTensor_resnetv15stage1relu1fwd.data();
std::vector<float> fTensor_resnetv15stage3relu1fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3relu1fwd = fTensor_resnetv15stage3relu1fwd.data();
std::vector<float> fTensor_resnetv15stage3conv0fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3conv0fwd = fTensor_resnetv15stage3conv0fwd.data();
std::vector<float> fTensor_resnetv15stage3plus1 = std::vector<float>(50176);
float * tensor_resnetv15stage3plus1 = fTensor_resnetv15stage3plus1.data();
std::vector<float> fTensor_resnetv15pool0fwd = std::vector<float>(200704);
float * tensor_resnetv15pool0fwd = fTensor_resnetv15pool0fwd.data();
std::vector<float> fTensor_resnetv15stage3conv4fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3conv4fwd = fTensor_resnetv15stage3conv4fwd.data();
std::vector<float> fTensor_resnetv15stage1batchnorm1fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm1fwd = fTensor_resnetv15stage1batchnorm1fwd.data();
std::vector<float> fTensor_resnetv15stage4activation1 = std::vector<float>(25088);
float * tensor_resnetv15stage4activation1 = fTensor_resnetv15stage4activation1.data();
std::vector<float> fTensor_resnetv15stage2activation1 = std::vector<float>(100352);
float * tensor_resnetv15stage2activation1 = fTensor_resnetv15stage2activation1.data();
std::vector<float> fTensor_resnetv15stage3activation0 = std::vector<float>(50176);
float * tensor_resnetv15stage3activation0 = fTensor_resnetv15stage3activation0.data();
std::vector<float> fTensor_resnetv15stage1conv2fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1conv2fwd = fTensor_resnetv15stage1conv2fwd.data();
std::vector<float> fTensor_resnetv15stage1batchnorm0fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm0fwd = fTensor_resnetv15stage1batchnorm0fwd.data();
std::vector<float> fTensor_resnetv15stage1relu0fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1relu0fwd = fTensor_resnetv15stage1relu0fwd.data();
std::vector<float> fTensor_resnetv15stage2conv0fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2conv0fwd = fTensor_resnetv15stage2conv0fwd.data();
std::vector<float> fTensor_resnetv15stage3relu0fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3relu0fwd = fTensor_resnetv15stage3relu0fwd.data();
std::vector<float> fTensor_resnetv15pool1fwd = std::vector<float>(4608);
float * tensor_resnetv15pool1fwd = fTensor_resnetv15pool1fwd.data();
std::vector<float> fTensor_resnetv15stage4batchnorm0fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm0fwd = fTensor_resnetv15stage4batchnorm0fwd.data();
std::vector<float> fTensor_resnetv15stage1batchnorm2fwd = std::vector<float>(200704);
float * tensor_resnetv15stage1batchnorm2fwd = fTensor_resnetv15stage1batchnorm2fwd.data();
std::vector<float> fTensor_resnetv15stage3conv1fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3conv1fwd = fTensor_resnetv15stage3conv1fwd.data();
std::vector<float> fTensor_resnetv15stage3batchnorm2fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm2fwd = fTensor_resnetv15stage3batchnorm2fwd.data();
std::vector<float> fTensor_resnetv15stage2relu1fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2relu1fwd = fTensor_resnetv15stage2relu1fwd.data();
std::vector<float> fTensor_resnetv15stage4plus0 = std::vector<float>(25088);
float * tensor_resnetv15stage4plus0 = fTensor_resnetv15stage4plus0.data();
std::vector<float> fTensor_resnetv15stage2plus1 = std::vector<float>(100352);
float * tensor_resnetv15stage2plus1 = fTensor_resnetv15stage2plus1.data();
std::vector<float> fTensor_resnetv15stage3batchnorm1fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm1fwd = fTensor_resnetv15stage3batchnorm1fwd.data();
std::vector<float> fTensor_resnetv15stage3conv2fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3conv2fwd = fTensor_resnetv15stage3conv2fwd.data();
std::vector<float> fTensor_resnetv15stage3plus0 = std::vector<float>(50176);
float * tensor_resnetv15stage3plus0 = fTensor_resnetv15stage3plus0.data();
std::vector<float> fTensor_resnetv15stage3batchnorm3fwd = std::vector<float>(50176);
float * tensor_resnetv15stage3batchnorm3fwd = fTensor_resnetv15stage3batchnorm3fwd.data();
std::vector<float> fTensor_resnetv15stage2batchnorm1fwd = std::vector<float>(100352);
float * tensor_resnetv15stage2batchnorm1fwd = fTensor_resnetv15stage2batchnorm1fwd.data();
std::vector<float> fTensor_resnetv15stage4conv2fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4conv2fwd = fTensor_resnetv15stage4conv2fwd.data();
std::vector<float> fTensor_resnetv15stage4relu0fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4relu0fwd = fTensor_resnetv15stage4relu0fwd.data();
std::vector<float> fTensor_resnetv15dense0fwd = std::vector<float>(1000);
float * tensor_resnetv15dense0fwd = fTensor_resnetv15dense0fwd.data();
std::vector<float> fTensor_resnetv15stage4conv1fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4conv1fwd = fTensor_resnetv15stage4conv1fwd.data();
std::vector<float> fTensor_resnetv15stage4batchnorm1fwd = std::vector<float>(25088);
float * tensor_resnetv15stage4batchnorm1fwd = fTensor_resnetv15stage4batchnorm1fwd.data();
std::vector<float> fTensor_resnetv15stage1plus1 = std::vector<float>(200704);
float * tensor_resnetv15stage1plus1 = fTensor_resnetv15stage1plus1.data();
std::vector<float> fTensor_resnetv15stage4activation0 = std::vector<float>(25088);
float * tensor_resnetv15stage4activation0 = fTensor_resnetv15stage4activation0.data();

std::vector<float> fVec_op_0_f = std::vector<float>(9408);
std::vector<float> fVec_op_0_xpad = std::vector<float>(158700);
std::vector<float> fVec_op_0_xcol = std::vector<float>(1843968);

std::vector<float> fVec_op_3_xpad = std::vector<float>(831744);
std::vector<float> fVec_op_4_f = std::vector<float>(36864);
std::vector<float> fVec_op_4_xpad = std::vector<float>(215296);
std::vector<float> fVec_op_4_xcol = std::vector<float>(1806336);

std::vector<float> fVec_op_7_f = std::vector<float>(36864);
std::vector<float> fVec_op_7_xpad = std::vector<float>(215296);
std::vector<float> fVec_op_7_xcol = std::vector<float>(1806336);

std::vector<float> fVec_op_11_f = std::vector<float>(36864);
std::vector<float> fVec_op_11_xpad = std::vector<float>(215296);
std::vector<float> fVec_op_11_xcol = std::vector<float>(1806336);

std::vector<float> fVec_op_14_f = std::vector<float>(36864);
std::vector<float> fVec_op_14_xpad = std::vector<float>(215296);
std::vector<float> fVec_op_14_xcol = std::vector<float>(1806336);

std::vector<float> fVec_op_18_f = std::vector<float>(8192);
std::vector<float> fVec_op_18_xpad = std::vector<float>(200704);
std::vector<float> fVec_op_18_xcol = std::vector<float>(50176);

std::vector<float> fVec_op_20_f = std::vector<float>(73728);
std::vector<float> fVec_op_20_xpad = std::vector<float>(215296);
std::vector<float> fVec_op_20_xcol = std::vector<float>(451584);

std::vector<float> fVec_op_23_f = std::vector<float>(147456);
std::vector<float> fVec_op_23_xpad = std::vector<float>(115200);
std::vector<float> fVec_op_23_xcol = std::vector<float>(903168);

std::vector<float> fVec_op_27_f = std::vector<float>(147456);
std::vector<float> fVec_op_27_xpad = std::vector<float>(115200);
std::vector<float> fVec_op_27_xcol = std::vector<float>(903168);

std::vector<float> fVec_op_30_f = std::vector<float>(147456);
std::vector<float> fVec_op_30_xpad = std::vector<float>(115200);
std::vector<float> fVec_op_30_xcol = std::vector<float>(903168);

std::vector<float> fVec_op_34_f = std::vector<float>(32768);
std::vector<float> fVec_op_34_xpad = std::vector<float>(100352);
std::vector<float> fVec_op_34_xcol = std::vector<float>(25088);

std::vector<float> fVec_op_36_f = std::vector<float>(294912);
std::vector<float> fVec_op_36_xpad = std::vector<float>(115200);
std::vector<float> fVec_op_36_xcol = std::vector<float>(225792);

std::vector<float> fVec_op_39_f = std::vector<float>(589824);
std::vector<float> fVec_op_39_xpad = std::vector<float>(65536);
std::vector<float> fVec_op_39_xcol = std::vector<float>(451584);

std::vector<float> fVec_op_43_f = std::vector<float>(589824);
std::vector<float> fVec_op_43_xpad = std::vector<float>(65536);
std::vector<float> fVec_op_43_xcol = std::vector<float>(451584);

std::vector<float> fVec_op_46_f = std::vector<float>(589824);
std::vector<float> fVec_op_46_xpad = std::vector<float>(65536);
std::vector<float> fVec_op_46_xcol = std::vector<float>(451584);

std::vector<float> fVec_op_50_f = std::vector<float>(131072);
std::vector<float> fVec_op_50_xpad = std::vector<float>(50176);
std::vector<float> fVec_op_50_xcol = std::vector<float>(12544);

std::vector<float> fVec_op_52_f = std::vector<float>(1179648);
std::vector<float> fVec_op_52_xpad = std::vector<float>(65536);
std::vector<float> fVec_op_52_xcol = std::vector<float>(112896);

std::vector<float> fVec_op_55_f = std::vector<float>(2359296);
std::vector<float> fVec_op_55_xpad = std::vector<float>(41472);
std::vector<float> fVec_op_55_xcol = std::vector<float>(225792);

std::vector<float> fVec_op_59_f = std::vector<float>(2359296);
std::vector<float> fVec_op_59_xpad = std::vector<float>(41472);
std::vector<float> fVec_op_59_xcol = std::vector<float>(225792);

std::vector<float> fVec_op_62_f = std::vector<float>(2359296);
std::vector<float> fVec_op_62_xpad = std::vector<float>(41472);
std::vector<float> fVec_op_62_xcol = std::vector<float>(225792);

std::vector<float> fVec_op_66_xpad = std::vector<float>(41472);

Session(std::string filename ="") {
   if (filename.empty()) filename = "resnet18v1.dat";
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()){
      throw std::runtime_error("tmva-sofie failed to open file for input weights");
   }
   std::string tensor_name;
   int length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm4beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm4beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm4beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm3runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm3runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm3runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm3runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm3runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm3runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm1gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm1gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm1gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4conv1weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4conv1weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2359296) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2359296 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4conv1weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm0runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm0runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm0runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm0runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm0runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm0runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm0gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm0gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm0gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4conv0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4conv0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 1179648) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 1179648 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4conv0weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm2runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm2runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm2runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm1beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm1beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm1beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm2gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm2gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm2gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4conv2weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4conv2weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 131072) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 131072 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4conv2weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm4runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm4runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm4runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm4runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm4runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm4runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm2beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm2beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm2beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm4gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm4gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm4gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm3beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm3beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm3beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm3runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm3runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm3runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3conv3weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3conv3weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 589824) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 589824 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3conv3weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm1runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm1runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm1runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm1runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm1runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm1runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm1runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm1runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm1runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm1beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm1beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm1beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3conv1weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3conv1weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 589824) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 589824 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3conv1weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15dense0bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15dense0bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 1000) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 1000 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15dense0bias[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm0runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm0runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm0runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm2runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm2runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm2runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm2gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm2gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm2gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm3runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm3runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm3runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4conv3weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4conv3weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2359296) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2359296 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4conv3weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm3beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm3beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm3beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2conv0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2conv0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 73728) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 73728 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2conv0weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm4runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm4runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm4runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm3runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm3runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm3runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm2runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm2runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm2runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm4beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm4beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm4beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3conv0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3conv0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 294912) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 294912 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3conv0weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm1runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm1runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm1runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1conv2weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1conv2weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 36864) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 36864 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1conv2weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm2runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm2runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm2runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm3gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm3gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm3gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm4gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm4gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm4gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm2beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm2beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm2beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm2runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm2runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm2runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm2beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm2beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm2beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm1gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm1gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm1gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm0gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm0gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm0gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm0runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm0runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm0runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3conv4weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3conv4weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 589824) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 589824 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3conv4weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm2gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm2gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm2gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4conv4weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4conv4weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2359296) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2359296 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4conv4weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm2beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm2beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm2beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm1runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm1runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm1runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15batchnorm0gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15batchnorm0gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 802816) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 802816 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15batchnorm0gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2conv2weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2conv2weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 8192) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 8192 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2conv2weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1conv1weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1conv1weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 36864) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 36864 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1conv1weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm0gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm0gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm0gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15batchnorm0runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15batchnorm0runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 802816) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 802816 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15batchnorm0runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm3runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm3runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm3runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15conv0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15conv0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 9408) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 9408 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15conv0weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1conv0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1conv0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 36864) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 36864 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1conv0weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15batchnorm0beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15batchnorm0beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 802816) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 802816 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15batchnorm0beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm0gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm0gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm0gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm0beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm0beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm0beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15batchnorm0runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15batchnorm0runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 802816) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 802816 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15batchnorm0runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm0runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm0runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm0runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm4gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm4gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm4gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3conv2weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3conv2weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 32768) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 32768 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3conv2weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm3gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm3gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm3gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm4beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm4beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm4beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm1gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm1gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm1gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm2runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm2runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm2runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm3gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm3gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm3gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm3runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm3runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm3runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm0runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm0runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm0runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15dense0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15dense0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 512000) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 512000 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15dense0weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm1beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm1beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm1beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm2gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm2gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm2gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1conv3weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1conv3weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 36864) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 36864 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1conv3weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm3runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm3runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm3runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm0beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm0beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm0beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm0runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm0runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm0runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm3beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm3beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm3beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm1beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm1beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm1beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm0runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm0runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm0runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm1gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm1gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm1gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2conv1weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2conv1weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 147456) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 147456 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2conv1weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2conv3weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2conv3weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 147456) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 147456 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2conv3weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm1runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm1runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm1runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm1runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm1runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm1runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm4runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm4runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm4runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm0beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm0beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm0beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2conv4weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2conv4weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 147456) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 147456 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2conv4weight[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm0beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm0beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm0beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm3gamma" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm3gamma , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm3gamma[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm3beta" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm3beta , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm3beta[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage4batchnorm1runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage4batchnorm1runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 25088) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 25088 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage4batchnorm1runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage2batchnorm4runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage2batchnorm4runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 100352) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 100352 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage2batchnorm4runningvar[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm4runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm4runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm4runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage1batchnorm2runningmean" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage1batchnorm2runningmean , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 200704) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 200704 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage1batchnorm2runningmean[i];
   f >> tensor_name >> length;
   if (tensor_name != "tensor_resnetv15stage3batchnorm2runningvar" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_resnetv15stage3batchnorm2runningvar , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50176) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50176 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
    for (int i =0; i < length; ++i) 
       f >> tensor_resnetv15stage3batchnorm2runningvar[i];
   f.close();
}

std::vector<float> infer(float* tensor_data){

//----  operator Conv op_0
   float * op_0_f = fVec_op_0_f.data();
   for (std::size_t k = 0; k < 64; k++) {
      for (std::size_t d = 0; d < 3; d++) {
         for (std::size_t h = 0; h < 7; h++) {
            for (std::size_t w = 0; w < 7; w++) {
               op_0_f[k * 147 + d * 49 + h * 7 + w * 1  ] = tensor_resnetv15conv0weight[k * 147 + d * 49 + h * 7 + w ];
            }
         }
      }
   }
   char op_0_transA = 'N';
   char op_0_transB = 'N';
   int op_0_m = 12544;
   int op_0_n = 64;
   int op_0_k = 147;
   float op_0_alpha = 1.0;
   float op_0_beta = 0.0;
   float * op_0_xpad = fVec_op_0_xpad.data();
   float * op_0_xcol = fVec_op_0_xcol.data();
   size_t offset_tensor_resnetv15conv0fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 150528;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_data + x_offset,3,224,224,7,7,3,3,2,2,1,1,op_0_xcol);

       BLAS::sgemm_(&op_0_transA, &op_0_transB, &op_0_m, &op_0_n, &op_0_k, &op_0_alpha, op_0_xcol, &op_0_m,
         op_0_f, &op_0_k, &op_0_beta, tensor_resnetv15conv0fwd + offset_tensor_resnetv15conv0fwd, &op_0_m);
      offset_tensor_resnetv15conv0fwd += 802816;
   }
   constexpr int op_1_N =802816;
   constexpr int op_1_incx = 1;
   constexpr int op_1_incy = 1;
   BLAS::scopy_(&op_1_N, tensor_resnetv15conv0fwd, &op_1_incx,tensor_resnetv15batchnorm0fwd, &op_1_incy);

   float op_1_alpha = -1;
   BLAS::saxpy_(&op_1_N, &op_1_alpha, tensor_resnetv15batchnorm0runningmean, &op_1_incx,tensor_resnetv15batchnorm0fwd, &op_1_incy);

    for (size_t i = 0; i < 802816; i++) {
      tensor_resnetv15batchnorm0fwd[i] *= tensor_resnetv15batchnorm0gamma[i] * tensor_resnetv15batchnorm0runningvar[i]; 
   }
   op_1_alpha = 1;
   BLAS::saxpy_(&op_1_N, &op_1_alpha, tensor_resnetv15batchnorm0beta, &op_1_incx, tensor_resnetv15batchnorm0fwd, &op_1_incy);


//------ RELU
   for (int id = 0; id < 802816 ; id++){
      tensor_resnetv15relu0fwd[id] = ((tensor_resnetv15batchnorm0fwd[id] > 0 )? tensor_resnetv15batchnorm0fwd[id] : 0);
   }

//----  operator MaxPool  op_3
{
   constexpr int hsize = 112;
   constexpr int wsize = 112;
   constexpr int hmin = -1;
   constexpr int hmax = 111;
   constexpr int wmin = -1;
   constexpr int wmax = 111;
   constexpr int kh = 3;
   constexpr int kw = 3;
   size_t outIndex = 0;
   for (size_t n = 0; n < 64; n++) {
      size_t inputOffset = n*12544;
      for (int i = hmin; i < hmax; i+=2) {
         for (int j = wmin; j < wmax; j+=2) {
            float value = -INFINITY;
            for (int l = i;  l < i + kh; l++) {
               if (l < 0 || l >= hsize) continue;
               for (int k = j; k < j + kw; k++) {
                  if (k<0 || k>= wsize) continue;
                  int index = inputOffset + l*hsize + k;
                  auto xval = tensor_resnetv15relu0fwd[index];
                  if (xval > value) value = xval;
               }
            }
            tensor_resnetv15pool0fwd[outIndex++] = value;
         }
      }
   }
   }

//----  operator Conv op_4
   float * op_4_f = fVec_op_4_f.data();
   for (std::size_t k = 0; k < 64; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_4_f[k * 576 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage1conv0weight[k * 576 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_4_transA = 'N';
   char op_4_transB = 'N';
   int op_4_m = 3136;
   int op_4_n = 64;
   int op_4_k = 576;
   float op_4_alpha = 1.0;
   float op_4_beta = 0.0;
   float * op_4_xpad = fVec_op_4_xpad.data();
   float * op_4_xcol = fVec_op_4_xcol.data();
   size_t offset_tensor_resnetv15stage1conv0fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 200704;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15pool0fwd + x_offset,64,56,56,3,3,1,1,1,1,1,1,op_4_xcol);

       BLAS::sgemm_(&op_4_transA, &op_4_transB, &op_4_m, &op_4_n, &op_4_k, &op_4_alpha, op_4_xcol, &op_4_m,
         op_4_f, &op_4_k, &op_4_beta, tensor_resnetv15stage1conv0fwd + offset_tensor_resnetv15stage1conv0fwd, &op_4_m);
      offset_tensor_resnetv15stage1conv0fwd += 200704;
   }
   constexpr int op_5_N =200704;
   constexpr int op_5_incx = 1;
   constexpr int op_5_incy = 1;
   BLAS::scopy_(&op_5_N, tensor_resnetv15stage1conv0fwd, &op_5_incx,tensor_resnetv15stage1batchnorm0fwd, &op_5_incy);

   float op_5_alpha = -1;
   BLAS::saxpy_(&op_5_N, &op_5_alpha, tensor_resnetv15stage1batchnorm0runningmean, &op_5_incx,tensor_resnetv15stage1batchnorm0fwd, &op_5_incy);

    for (size_t i = 0; i < 200704; i++) {
      tensor_resnetv15stage1batchnorm0fwd[i] *= tensor_resnetv15stage1batchnorm0gamma[i] * tensor_resnetv15stage1batchnorm0runningvar[i]; 
   }
   op_5_alpha = 1;
   BLAS::saxpy_(&op_5_N, &op_5_alpha, tensor_resnetv15stage1batchnorm0beta, &op_5_incx, tensor_resnetv15stage1batchnorm0fwd, &op_5_incy);


//------ RELU
   for (int id = 0; id < 200704 ; id++){
      tensor_resnetv15stage1relu0fwd[id] = ((tensor_resnetv15stage1batchnorm0fwd[id] > 0 )? tensor_resnetv15stage1batchnorm0fwd[id] : 0);
   }

//----  operator Conv op_7
   float * op_7_f = fVec_op_7_f.data();
   for (std::size_t k = 0; k < 64; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_7_f[k * 576 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage1conv1weight[k * 576 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_7_transA = 'N';
   char op_7_transB = 'N';
   int op_7_m = 3136;
   int op_7_n = 64;
   int op_7_k = 576;
   float op_7_alpha = 1.0;
   float op_7_beta = 0.0;
   float * op_7_xpad = fVec_op_7_xpad.data();
   float * op_7_xcol = fVec_op_7_xcol.data();
   size_t offset_tensor_resnetv15stage1conv1fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 200704;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage1relu0fwd + x_offset,64,56,56,3,3,1,1,1,1,1,1,op_7_xcol);

       BLAS::sgemm_(&op_7_transA, &op_7_transB, &op_7_m, &op_7_n, &op_7_k, &op_7_alpha, op_7_xcol, &op_7_m,
         op_7_f, &op_7_k, &op_7_beta, tensor_resnetv15stage1conv1fwd + offset_tensor_resnetv15stage1conv1fwd, &op_7_m);
      offset_tensor_resnetv15stage1conv1fwd += 200704;
   }
   constexpr int op_8_N =200704;
   constexpr int op_8_incx = 1;
   constexpr int op_8_incy = 1;
   BLAS::scopy_(&op_8_N, tensor_resnetv15stage1conv1fwd, &op_8_incx,tensor_resnetv15stage1batchnorm1fwd, &op_8_incy);

   float op_8_alpha = -1;
   BLAS::saxpy_(&op_8_N, &op_8_alpha, tensor_resnetv15stage1batchnorm1runningmean, &op_8_incx,tensor_resnetv15stage1batchnorm1fwd, &op_8_incy);

    for (size_t i = 0; i < 200704; i++) {
      tensor_resnetv15stage1batchnorm1fwd[i] *= tensor_resnetv15stage1batchnorm1gamma[i] * tensor_resnetv15stage1batchnorm1runningvar[i]; 
   }
   op_8_alpha = 1;
   BLAS::saxpy_(&op_8_N, &op_8_alpha, tensor_resnetv15stage1batchnorm1beta, &op_8_incx, tensor_resnetv15stage1batchnorm1fwd, &op_8_incy);


//------ Add
   for (size_t id = 0; id < 200704 ; id++){
      tensor_resnetv15stage1plus0[id] = tensor_resnetv15pool0fwd[id] + tensor_resnetv15stage1batchnorm1fwd[id];
   }

//------ RELU
   for (int id = 0; id < 200704 ; id++){
      tensor_resnetv15stage1activation0[id] = ((tensor_resnetv15stage1plus0[id] > 0 )? tensor_resnetv15stage1plus0[id] : 0);
   }

//----  operator Conv op_11
   float * op_11_f = fVec_op_11_f.data();
   for (std::size_t k = 0; k < 64; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_11_f[k * 576 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage1conv2weight[k * 576 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_11_transA = 'N';
   char op_11_transB = 'N';
   int op_11_m = 3136;
   int op_11_n = 64;
   int op_11_k = 576;
   float op_11_alpha = 1.0;
   float op_11_beta = 0.0;
   float * op_11_xpad = fVec_op_11_xpad.data();
   float * op_11_xcol = fVec_op_11_xcol.data();
   size_t offset_tensor_resnetv15stage1conv2fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 200704;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage1activation0 + x_offset,64,56,56,3,3,1,1,1,1,1,1,op_11_xcol);

       BLAS::sgemm_(&op_11_transA, &op_11_transB, &op_11_m, &op_11_n, &op_11_k, &op_11_alpha, op_11_xcol, &op_11_m,
         op_11_f, &op_11_k, &op_11_beta, tensor_resnetv15stage1conv2fwd + offset_tensor_resnetv15stage1conv2fwd, &op_11_m);
      offset_tensor_resnetv15stage1conv2fwd += 200704;
   }
   constexpr int op_12_N =200704;
   constexpr int op_12_incx = 1;
   constexpr int op_12_incy = 1;
   BLAS::scopy_(&op_12_N, tensor_resnetv15stage1conv2fwd, &op_12_incx,tensor_resnetv15stage1batchnorm2fwd, &op_12_incy);

   float op_12_alpha = -1;
   BLAS::saxpy_(&op_12_N, &op_12_alpha, tensor_resnetv15stage1batchnorm2runningmean, &op_12_incx,tensor_resnetv15stage1batchnorm2fwd, &op_12_incy);

    for (size_t i = 0; i < 200704; i++) {
      tensor_resnetv15stage1batchnorm2fwd[i] *= tensor_resnetv15stage1batchnorm2gamma[i] * tensor_resnetv15stage1batchnorm2runningvar[i]; 
   }
   op_12_alpha = 1;
   BLAS::saxpy_(&op_12_N, &op_12_alpha, tensor_resnetv15stage1batchnorm2beta, &op_12_incx, tensor_resnetv15stage1batchnorm2fwd, &op_12_incy);


//------ RELU
   for (int id = 0; id < 200704 ; id++){
      tensor_resnetv15stage1relu1fwd[id] = ((tensor_resnetv15stage1batchnorm2fwd[id] > 0 )? tensor_resnetv15stage1batchnorm2fwd[id] : 0);
   }

//----  operator Conv op_14
   float * op_14_f = fVec_op_14_f.data();
   for (std::size_t k = 0; k < 64; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_14_f[k * 576 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage1conv3weight[k * 576 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_14_transA = 'N';
   char op_14_transB = 'N';
   int op_14_m = 3136;
   int op_14_n = 64;
   int op_14_k = 576;
   float op_14_alpha = 1.0;
   float op_14_beta = 0.0;
   float * op_14_xpad = fVec_op_14_xpad.data();
   float * op_14_xcol = fVec_op_14_xcol.data();
   size_t offset_tensor_resnetv15stage1conv3fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 200704;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage1relu1fwd + x_offset,64,56,56,3,3,1,1,1,1,1,1,op_14_xcol);

       BLAS::sgemm_(&op_14_transA, &op_14_transB, &op_14_m, &op_14_n, &op_14_k, &op_14_alpha, op_14_xcol, &op_14_m,
         op_14_f, &op_14_k, &op_14_beta, tensor_resnetv15stage1conv3fwd + offset_tensor_resnetv15stage1conv3fwd, &op_14_m);
      offset_tensor_resnetv15stage1conv3fwd += 200704;
   }
   constexpr int op_15_N =200704;
   constexpr int op_15_incx = 1;
   constexpr int op_15_incy = 1;
   BLAS::scopy_(&op_15_N, tensor_resnetv15stage1conv3fwd, &op_15_incx,tensor_resnetv15stage1batchnorm3fwd, &op_15_incy);

   float op_15_alpha = -1;
   BLAS::saxpy_(&op_15_N, &op_15_alpha, tensor_resnetv15stage1batchnorm3runningmean, &op_15_incx,tensor_resnetv15stage1batchnorm3fwd, &op_15_incy);

    for (size_t i = 0; i < 200704; i++) {
      tensor_resnetv15stage1batchnorm3fwd[i] *= tensor_resnetv15stage1batchnorm3gamma[i] * tensor_resnetv15stage1batchnorm3runningvar[i]; 
   }
   op_15_alpha = 1;
   BLAS::saxpy_(&op_15_N, &op_15_alpha, tensor_resnetv15stage1batchnorm3beta, &op_15_incx, tensor_resnetv15stage1batchnorm3fwd, &op_15_incy);


//------ Add
   for (size_t id = 0; id < 200704 ; id++){
      tensor_resnetv15stage1plus1[id] = tensor_resnetv15stage1activation0[id] + tensor_resnetv15stage1batchnorm3fwd[id];
   }

//------ RELU
   for (int id = 0; id < 200704 ; id++){
      tensor_resnetv15stage1activation1[id] = ((tensor_resnetv15stage1plus1[id] > 0 )? tensor_resnetv15stage1plus1[id] : 0);
   }

//----  operator Conv op_18
   float * op_18_f = fVec_op_18_f.data();
   for (std::size_t k = 0; k < 128; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 1; h++) {
            for (std::size_t w = 0; w < 1; w++) {
               op_18_f[k * 64 + d * 1 + h * 1 + w * 1  ] = tensor_resnetv15stage2conv2weight[k * 64 + d * 1 + h * 1 + w ];
            }
         }
      }
   }
   char op_18_transA = 'N';
   char op_18_transB = 'N';
   int op_18_m = 784;
   int op_18_n = 128;
   int op_18_k = 64;
   float op_18_alpha = 1.0;
   float op_18_beta = 0.0;
   float * op_18_xpad = fVec_op_18_xpad.data();
   float * op_18_xcol = fVec_op_18_xcol.data();
   size_t offset_tensor_resnetv15stage2conv2fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 200704;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage1activation1 + x_offset,64,56,56,1,1,0,0,2,2,1,1,op_18_xcol);

       BLAS::sgemm_(&op_18_transA, &op_18_transB, &op_18_m, &op_18_n, &op_18_k, &op_18_alpha, op_18_xcol, &op_18_m,
         op_18_f, &op_18_k, &op_18_beta, tensor_resnetv15stage2conv2fwd + offset_tensor_resnetv15stage2conv2fwd, &op_18_m);
      offset_tensor_resnetv15stage2conv2fwd += 100352;
   }
   constexpr int op_19_N =100352;
   constexpr int op_19_incx = 1;
   constexpr int op_19_incy = 1;
   BLAS::scopy_(&op_19_N, tensor_resnetv15stage2conv2fwd, &op_19_incx,tensor_resnetv15stage2batchnorm2fwd, &op_19_incy);

   float op_19_alpha = -1;
   BLAS::saxpy_(&op_19_N, &op_19_alpha, tensor_resnetv15stage2batchnorm2runningmean, &op_19_incx,tensor_resnetv15stage2batchnorm2fwd, &op_19_incy);

    for (size_t i = 0; i < 100352; i++) {
      tensor_resnetv15stage2batchnorm2fwd[i] *= tensor_resnetv15stage2batchnorm2gamma[i] * tensor_resnetv15stage2batchnorm2runningvar[i]; 
   }
   op_19_alpha = 1;
   BLAS::saxpy_(&op_19_N, &op_19_alpha, tensor_resnetv15stage2batchnorm2beta, &op_19_incx, tensor_resnetv15stage2batchnorm2fwd, &op_19_incy);


//----  operator Conv op_20
   float * op_20_f = fVec_op_20_f.data();
   for (std::size_t k = 0; k < 128; k++) {
      for (std::size_t d = 0; d < 64; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_20_f[k * 576 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage2conv0weight[k * 576 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_20_transA = 'N';
   char op_20_transB = 'N';
   int op_20_m = 784;
   int op_20_n = 128;
   int op_20_k = 576;
   float op_20_alpha = 1.0;
   float op_20_beta = 0.0;
   float * op_20_xpad = fVec_op_20_xpad.data();
   float * op_20_xcol = fVec_op_20_xcol.data();
   size_t offset_tensor_resnetv15stage2conv0fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 200704;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage1activation1 + x_offset,64,56,56,3,3,1,1,2,2,1,1,op_20_xcol);

       BLAS::sgemm_(&op_20_transA, &op_20_transB, &op_20_m, &op_20_n, &op_20_k, &op_20_alpha, op_20_xcol, &op_20_m,
         op_20_f, &op_20_k, &op_20_beta, tensor_resnetv15stage2conv0fwd + offset_tensor_resnetv15stage2conv0fwd, &op_20_m);
      offset_tensor_resnetv15stage2conv0fwd += 100352;
   }
   constexpr int op_21_N =100352;
   constexpr int op_21_incx = 1;
   constexpr int op_21_incy = 1;
   BLAS::scopy_(&op_21_N, tensor_resnetv15stage2conv0fwd, &op_21_incx,tensor_resnetv15stage2batchnorm0fwd, &op_21_incy);

   float op_21_alpha = -1;
   BLAS::saxpy_(&op_21_N, &op_21_alpha, tensor_resnetv15stage2batchnorm0runningmean, &op_21_incx,tensor_resnetv15stage2batchnorm0fwd, &op_21_incy);

    for (size_t i = 0; i < 100352; i++) {
      tensor_resnetv15stage2batchnorm0fwd[i] *= tensor_resnetv15stage2batchnorm0gamma[i] * tensor_resnetv15stage2batchnorm0runningvar[i]; 
   }
   op_21_alpha = 1;
   BLAS::saxpy_(&op_21_N, &op_21_alpha, tensor_resnetv15stage2batchnorm0beta, &op_21_incx, tensor_resnetv15stage2batchnorm0fwd, &op_21_incy);


//------ RELU
   for (int id = 0; id < 100352 ; id++){
      tensor_resnetv15stage2relu0fwd[id] = ((tensor_resnetv15stage2batchnorm0fwd[id] > 0 )? tensor_resnetv15stage2batchnorm0fwd[id] : 0);
   }

//----  operator Conv op_23
   float * op_23_f = fVec_op_23_f.data();
   for (std::size_t k = 0; k < 128; k++) {
      for (std::size_t d = 0; d < 128; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_23_f[k * 1152 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage2conv1weight[k * 1152 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_23_transA = 'N';
   char op_23_transB = 'N';
   int op_23_m = 784;
   int op_23_n = 128;
   int op_23_k = 1152;
   float op_23_alpha = 1.0;
   float op_23_beta = 0.0;
   float * op_23_xpad = fVec_op_23_xpad.data();
   float * op_23_xcol = fVec_op_23_xcol.data();
   size_t offset_tensor_resnetv15stage2conv1fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 100352;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage2relu0fwd + x_offset,128,28,28,3,3,1,1,1,1,1,1,op_23_xcol);

       BLAS::sgemm_(&op_23_transA, &op_23_transB, &op_23_m, &op_23_n, &op_23_k, &op_23_alpha, op_23_xcol, &op_23_m,
         op_23_f, &op_23_k, &op_23_beta, tensor_resnetv15stage2conv1fwd + offset_tensor_resnetv15stage2conv1fwd, &op_23_m);
      offset_tensor_resnetv15stage2conv1fwd += 100352;
   }
   constexpr int op_24_N =100352;
   constexpr int op_24_incx = 1;
   constexpr int op_24_incy = 1;
   BLAS::scopy_(&op_24_N, tensor_resnetv15stage2conv1fwd, &op_24_incx,tensor_resnetv15stage2batchnorm1fwd, &op_24_incy);

   float op_24_alpha = -1;
   BLAS::saxpy_(&op_24_N, &op_24_alpha, tensor_resnetv15stage2batchnorm1runningmean, &op_24_incx,tensor_resnetv15stage2batchnorm1fwd, &op_24_incy);

    for (size_t i = 0; i < 100352; i++) {
      tensor_resnetv15stage2batchnorm1fwd[i] *= tensor_resnetv15stage2batchnorm1gamma[i] * tensor_resnetv15stage2batchnorm1runningvar[i]; 
   }
   op_24_alpha = 1;
   BLAS::saxpy_(&op_24_N, &op_24_alpha, tensor_resnetv15stage2batchnorm1beta, &op_24_incx, tensor_resnetv15stage2batchnorm1fwd, &op_24_incy);


//------ Add
   for (size_t id = 0; id < 100352 ; id++){
      tensor_resnetv15stage2plus0[id] = tensor_resnetv15stage2batchnorm2fwd[id] + tensor_resnetv15stage2batchnorm1fwd[id];
   }

//------ RELU
   for (int id = 0; id < 100352 ; id++){
      tensor_resnetv15stage2activation0[id] = ((tensor_resnetv15stage2plus0[id] > 0 )? tensor_resnetv15stage2plus0[id] : 0);
   }

//----  operator Conv op_27
   float * op_27_f = fVec_op_27_f.data();
   for (std::size_t k = 0; k < 128; k++) {
      for (std::size_t d = 0; d < 128; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_27_f[k * 1152 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage2conv3weight[k * 1152 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_27_transA = 'N';
   char op_27_transB = 'N';
   int op_27_m = 784;
   int op_27_n = 128;
   int op_27_k = 1152;
   float op_27_alpha = 1.0;
   float op_27_beta = 0.0;
   float * op_27_xpad = fVec_op_27_xpad.data();
   float * op_27_xcol = fVec_op_27_xcol.data();
   size_t offset_tensor_resnetv15stage2conv3fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 100352;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage2activation0 + x_offset,128,28,28,3,3,1,1,1,1,1,1,op_27_xcol);

       BLAS::sgemm_(&op_27_transA, &op_27_transB, &op_27_m, &op_27_n, &op_27_k, &op_27_alpha, op_27_xcol, &op_27_m,
         op_27_f, &op_27_k, &op_27_beta, tensor_resnetv15stage2conv3fwd + offset_tensor_resnetv15stage2conv3fwd, &op_27_m);
      offset_tensor_resnetv15stage2conv3fwd += 100352;
   }
   constexpr int op_28_N =100352;
   constexpr int op_28_incx = 1;
   constexpr int op_28_incy = 1;
   BLAS::scopy_(&op_28_N, tensor_resnetv15stage2conv3fwd, &op_28_incx,tensor_resnetv15stage2batchnorm3fwd, &op_28_incy);

   float op_28_alpha = -1;
   BLAS::saxpy_(&op_28_N, &op_28_alpha, tensor_resnetv15stage2batchnorm3runningmean, &op_28_incx,tensor_resnetv15stage2batchnorm3fwd, &op_28_incy);

    for (size_t i = 0; i < 100352; i++) {
      tensor_resnetv15stage2batchnorm3fwd[i] *= tensor_resnetv15stage2batchnorm3gamma[i] * tensor_resnetv15stage2batchnorm3runningvar[i]; 
   }
   op_28_alpha = 1;
   BLAS::saxpy_(&op_28_N, &op_28_alpha, tensor_resnetv15stage2batchnorm3beta, &op_28_incx, tensor_resnetv15stage2batchnorm3fwd, &op_28_incy);


//------ RELU
   for (int id = 0; id < 100352 ; id++){
      tensor_resnetv15stage2relu1fwd[id] = ((tensor_resnetv15stage2batchnorm3fwd[id] > 0 )? tensor_resnetv15stage2batchnorm3fwd[id] : 0);
   }

//----  operator Conv op_30
   float * op_30_f = fVec_op_30_f.data();
   for (std::size_t k = 0; k < 128; k++) {
      for (std::size_t d = 0; d < 128; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_30_f[k * 1152 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage2conv4weight[k * 1152 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_30_transA = 'N';
   char op_30_transB = 'N';
   int op_30_m = 784;
   int op_30_n = 128;
   int op_30_k = 1152;
   float op_30_alpha = 1.0;
   float op_30_beta = 0.0;
   float * op_30_xpad = fVec_op_30_xpad.data();
   float * op_30_xcol = fVec_op_30_xcol.data();
   size_t offset_tensor_resnetv15stage2conv4fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 100352;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage2relu1fwd + x_offset,128,28,28,3,3,1,1,1,1,1,1,op_30_xcol);

       BLAS::sgemm_(&op_30_transA, &op_30_transB, &op_30_m, &op_30_n, &op_30_k, &op_30_alpha, op_30_xcol, &op_30_m,
         op_30_f, &op_30_k, &op_30_beta, tensor_resnetv15stage2conv4fwd + offset_tensor_resnetv15stage2conv4fwd, &op_30_m);
      offset_tensor_resnetv15stage2conv4fwd += 100352;
   }
   constexpr int op_31_N =100352;
   constexpr int op_31_incx = 1;
   constexpr int op_31_incy = 1;
   BLAS::scopy_(&op_31_N, tensor_resnetv15stage2conv4fwd, &op_31_incx,tensor_resnetv15stage2batchnorm4fwd, &op_31_incy);

   float op_31_alpha = -1;
   BLAS::saxpy_(&op_31_N, &op_31_alpha, tensor_resnetv15stage2batchnorm4runningmean, &op_31_incx,tensor_resnetv15stage2batchnorm4fwd, &op_31_incy);

    for (size_t i = 0; i < 100352; i++) {
      tensor_resnetv15stage2batchnorm4fwd[i] *= tensor_resnetv15stage2batchnorm4gamma[i] * tensor_resnetv15stage2batchnorm4runningvar[i]; 
   }
   op_31_alpha = 1;
   BLAS::saxpy_(&op_31_N, &op_31_alpha, tensor_resnetv15stage2batchnorm4beta, &op_31_incx, tensor_resnetv15stage2batchnorm4fwd, &op_31_incy);


//------ Add
   for (size_t id = 0; id < 100352 ; id++){
      tensor_resnetv15stage2plus1[id] = tensor_resnetv15stage2activation0[id] + tensor_resnetv15stage2batchnorm4fwd[id];
   }

//------ RELU
   for (int id = 0; id < 100352 ; id++){
      tensor_resnetv15stage2activation1[id] = ((tensor_resnetv15stage2plus1[id] > 0 )? tensor_resnetv15stage2plus1[id] : 0);
   }

//----  operator Conv op_34
   float * op_34_f = fVec_op_34_f.data();
   for (std::size_t k = 0; k < 256; k++) {
      for (std::size_t d = 0; d < 128; d++) {
         for (std::size_t h = 0; h < 1; h++) {
            for (std::size_t w = 0; w < 1; w++) {
               op_34_f[k * 128 + d * 1 + h * 1 + w * 1  ] = tensor_resnetv15stage3conv2weight[k * 128 + d * 1 + h * 1 + w ];
            }
         }
      }
   }
   char op_34_transA = 'N';
   char op_34_transB = 'N';
   int op_34_m = 196;
   int op_34_n = 256;
   int op_34_k = 128;
   float op_34_alpha = 1.0;
   float op_34_beta = 0.0;
   float * op_34_xpad = fVec_op_34_xpad.data();
   float * op_34_xcol = fVec_op_34_xcol.data();
   size_t offset_tensor_resnetv15stage3conv2fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 100352;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage2activation1 + x_offset,128,28,28,1,1,0,0,2,2,1,1,op_34_xcol);

       BLAS::sgemm_(&op_34_transA, &op_34_transB, &op_34_m, &op_34_n, &op_34_k, &op_34_alpha, op_34_xcol, &op_34_m,
         op_34_f, &op_34_k, &op_34_beta, tensor_resnetv15stage3conv2fwd + offset_tensor_resnetv15stage3conv2fwd, &op_34_m);
      offset_tensor_resnetv15stage3conv2fwd += 50176;
   }
   constexpr int op_35_N =50176;
   constexpr int op_35_incx = 1;
   constexpr int op_35_incy = 1;
   BLAS::scopy_(&op_35_N, tensor_resnetv15stage3conv2fwd, &op_35_incx,tensor_resnetv15stage3batchnorm2fwd, &op_35_incy);

   float op_35_alpha = -1;
   BLAS::saxpy_(&op_35_N, &op_35_alpha, tensor_resnetv15stage3batchnorm2runningmean, &op_35_incx,tensor_resnetv15stage3batchnorm2fwd, &op_35_incy);

    for (size_t i = 0; i < 50176; i++) {
      tensor_resnetv15stage3batchnorm2fwd[i] *= tensor_resnetv15stage3batchnorm2gamma[i] * tensor_resnetv15stage3batchnorm2runningvar[i]; 
   }
   op_35_alpha = 1;
   BLAS::saxpy_(&op_35_N, &op_35_alpha, tensor_resnetv15stage3batchnorm2beta, &op_35_incx, tensor_resnetv15stage3batchnorm2fwd, &op_35_incy);


//----  operator Conv op_36
   float * op_36_f = fVec_op_36_f.data();
   for (std::size_t k = 0; k < 256; k++) {
      for (std::size_t d = 0; d < 128; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_36_f[k * 1152 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage3conv0weight[k * 1152 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_36_transA = 'N';
   char op_36_transB = 'N';
   int op_36_m = 196;
   int op_36_n = 256;
   int op_36_k = 1152;
   float op_36_alpha = 1.0;
   float op_36_beta = 0.0;
   float * op_36_xpad = fVec_op_36_xpad.data();
   float * op_36_xcol = fVec_op_36_xcol.data();
   size_t offset_tensor_resnetv15stage3conv0fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 100352;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage2activation1 + x_offset,128,28,28,3,3,1,1,2,2,1,1,op_36_xcol);

       BLAS::sgemm_(&op_36_transA, &op_36_transB, &op_36_m, &op_36_n, &op_36_k, &op_36_alpha, op_36_xcol, &op_36_m,
         op_36_f, &op_36_k, &op_36_beta, tensor_resnetv15stage3conv0fwd + offset_tensor_resnetv15stage3conv0fwd, &op_36_m);
      offset_tensor_resnetv15stage3conv0fwd += 50176;
   }
   constexpr int op_37_N =50176;
   constexpr int op_37_incx = 1;
   constexpr int op_37_incy = 1;
   BLAS::scopy_(&op_37_N, tensor_resnetv15stage3conv0fwd, &op_37_incx,tensor_resnetv15stage3batchnorm0fwd, &op_37_incy);

   float op_37_alpha = -1;
   BLAS::saxpy_(&op_37_N, &op_37_alpha, tensor_resnetv15stage3batchnorm0runningmean, &op_37_incx,tensor_resnetv15stage3batchnorm0fwd, &op_37_incy);

    for (size_t i = 0; i < 50176; i++) {
      tensor_resnetv15stage3batchnorm0fwd[i] *= tensor_resnetv15stage3batchnorm0gamma[i] * tensor_resnetv15stage3batchnorm0runningvar[i]; 
   }
   op_37_alpha = 1;
   BLAS::saxpy_(&op_37_N, &op_37_alpha, tensor_resnetv15stage3batchnorm0beta, &op_37_incx, tensor_resnetv15stage3batchnorm0fwd, &op_37_incy);


//------ RELU
   for (int id = 0; id < 50176 ; id++){
      tensor_resnetv15stage3relu0fwd[id] = ((tensor_resnetv15stage3batchnorm0fwd[id] > 0 )? tensor_resnetv15stage3batchnorm0fwd[id] : 0);
   }

//----  operator Conv op_39
   float * op_39_f = fVec_op_39_f.data();
   for (std::size_t k = 0; k < 256; k++) {
      for (std::size_t d = 0; d < 256; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_39_f[k * 2304 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage3conv1weight[k * 2304 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_39_transA = 'N';
   char op_39_transB = 'N';
   int op_39_m = 196;
   int op_39_n = 256;
   int op_39_k = 2304;
   float op_39_alpha = 1.0;
   float op_39_beta = 0.0;
   float * op_39_xpad = fVec_op_39_xpad.data();
   float * op_39_xcol = fVec_op_39_xcol.data();
   size_t offset_tensor_resnetv15stage3conv1fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 50176;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage3relu0fwd + x_offset,256,14,14,3,3,1,1,1,1,1,1,op_39_xcol);

       BLAS::sgemm_(&op_39_transA, &op_39_transB, &op_39_m, &op_39_n, &op_39_k, &op_39_alpha, op_39_xcol, &op_39_m,
         op_39_f, &op_39_k, &op_39_beta, tensor_resnetv15stage3conv1fwd + offset_tensor_resnetv15stage3conv1fwd, &op_39_m);
      offset_tensor_resnetv15stage3conv1fwd += 50176;
   }
   constexpr int op_40_N =50176;
   constexpr int op_40_incx = 1;
   constexpr int op_40_incy = 1;
   BLAS::scopy_(&op_40_N, tensor_resnetv15stage3conv1fwd, &op_40_incx,tensor_resnetv15stage3batchnorm1fwd, &op_40_incy);

   float op_40_alpha = -1;
   BLAS::saxpy_(&op_40_N, &op_40_alpha, tensor_resnetv15stage3batchnorm1runningmean, &op_40_incx,tensor_resnetv15stage3batchnorm1fwd, &op_40_incy);

    for (size_t i = 0; i < 50176; i++) {
      tensor_resnetv15stage3batchnorm1fwd[i] *= tensor_resnetv15stage3batchnorm1gamma[i] * tensor_resnetv15stage3batchnorm1runningvar[i]; 
   }
   op_40_alpha = 1;
   BLAS::saxpy_(&op_40_N, &op_40_alpha, tensor_resnetv15stage3batchnorm1beta, &op_40_incx, tensor_resnetv15stage3batchnorm1fwd, &op_40_incy);


//------ Add
   for (size_t id = 0; id < 50176 ; id++){
      tensor_resnetv15stage3plus0[id] = tensor_resnetv15stage3batchnorm2fwd[id] + tensor_resnetv15stage3batchnorm1fwd[id];
   }

//------ RELU
   for (int id = 0; id < 50176 ; id++){
      tensor_resnetv15stage3activation0[id] = ((tensor_resnetv15stage3plus0[id] > 0 )? tensor_resnetv15stage3plus0[id] : 0);
   }

//----  operator Conv op_43
   float * op_43_f = fVec_op_43_f.data();
   for (std::size_t k = 0; k < 256; k++) {
      for (std::size_t d = 0; d < 256; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_43_f[k * 2304 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage3conv3weight[k * 2304 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_43_transA = 'N';
   char op_43_transB = 'N';
   int op_43_m = 196;
   int op_43_n = 256;
   int op_43_k = 2304;
   float op_43_alpha = 1.0;
   float op_43_beta = 0.0;
   float * op_43_xpad = fVec_op_43_xpad.data();
   float * op_43_xcol = fVec_op_43_xcol.data();
   size_t offset_tensor_resnetv15stage3conv3fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 50176;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage3activation0 + x_offset,256,14,14,3,3,1,1,1,1,1,1,op_43_xcol);

       BLAS::sgemm_(&op_43_transA, &op_43_transB, &op_43_m, &op_43_n, &op_43_k, &op_43_alpha, op_43_xcol, &op_43_m,
         op_43_f, &op_43_k, &op_43_beta, tensor_resnetv15stage3conv3fwd + offset_tensor_resnetv15stage3conv3fwd, &op_43_m);
      offset_tensor_resnetv15stage3conv3fwd += 50176;
   }
   constexpr int op_44_N =50176;
   constexpr int op_44_incx = 1;
   constexpr int op_44_incy = 1;
   BLAS::scopy_(&op_44_N, tensor_resnetv15stage3conv3fwd, &op_44_incx,tensor_resnetv15stage3batchnorm3fwd, &op_44_incy);

   float op_44_alpha = -1;
   BLAS::saxpy_(&op_44_N, &op_44_alpha, tensor_resnetv15stage3batchnorm3runningmean, &op_44_incx,tensor_resnetv15stage3batchnorm3fwd, &op_44_incy);

    for (size_t i = 0; i < 50176; i++) {
      tensor_resnetv15stage3batchnorm3fwd[i] *= tensor_resnetv15stage3batchnorm3gamma[i] * tensor_resnetv15stage3batchnorm3runningvar[i]; 
   }
   op_44_alpha = 1;
   BLAS::saxpy_(&op_44_N, &op_44_alpha, tensor_resnetv15stage3batchnorm3beta, &op_44_incx, tensor_resnetv15stage3batchnorm3fwd, &op_44_incy);


//------ RELU
   for (int id = 0; id < 50176 ; id++){
      tensor_resnetv15stage3relu1fwd[id] = ((tensor_resnetv15stage3batchnorm3fwd[id] > 0 )? tensor_resnetv15stage3batchnorm3fwd[id] : 0);
   }

//----  operator Conv op_46
   float * op_46_f = fVec_op_46_f.data();
   for (std::size_t k = 0; k < 256; k++) {
      for (std::size_t d = 0; d < 256; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_46_f[k * 2304 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage3conv4weight[k * 2304 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_46_transA = 'N';
   char op_46_transB = 'N';
   int op_46_m = 196;
   int op_46_n = 256;
   int op_46_k = 2304;
   float op_46_alpha = 1.0;
   float op_46_beta = 0.0;
   float * op_46_xpad = fVec_op_46_xpad.data();
   float * op_46_xcol = fVec_op_46_xcol.data();
   size_t offset_tensor_resnetv15stage3conv4fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 50176;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage3relu1fwd + x_offset,256,14,14,3,3,1,1,1,1,1,1,op_46_xcol);

       BLAS::sgemm_(&op_46_transA, &op_46_transB, &op_46_m, &op_46_n, &op_46_k, &op_46_alpha, op_46_xcol, &op_46_m,
         op_46_f, &op_46_k, &op_46_beta, tensor_resnetv15stage3conv4fwd + offset_tensor_resnetv15stage3conv4fwd, &op_46_m);
      offset_tensor_resnetv15stage3conv4fwd += 50176;
   }
   constexpr int op_47_N =50176;
   constexpr int op_47_incx = 1;
   constexpr int op_47_incy = 1;
   BLAS::scopy_(&op_47_N, tensor_resnetv15stage3conv4fwd, &op_47_incx,tensor_resnetv15stage3batchnorm4fwd, &op_47_incy);

   float op_47_alpha = -1;
   BLAS::saxpy_(&op_47_N, &op_47_alpha, tensor_resnetv15stage3batchnorm4runningmean, &op_47_incx,tensor_resnetv15stage3batchnorm4fwd, &op_47_incy);

    for (size_t i = 0; i < 50176; i++) {
      tensor_resnetv15stage3batchnorm4fwd[i] *= tensor_resnetv15stage3batchnorm4gamma[i] * tensor_resnetv15stage3batchnorm4runningvar[i]; 
   }
   op_47_alpha = 1;
   BLAS::saxpy_(&op_47_N, &op_47_alpha, tensor_resnetv15stage3batchnorm4beta, &op_47_incx, tensor_resnetv15stage3batchnorm4fwd, &op_47_incy);


//------ Add
   for (size_t id = 0; id < 50176 ; id++){
      tensor_resnetv15stage3plus1[id] = tensor_resnetv15stage3activation0[id] + tensor_resnetv15stage3batchnorm4fwd[id];
   }

//------ RELU
   for (int id = 0; id < 50176 ; id++){
      tensor_resnetv15stage3activation1[id] = ((tensor_resnetv15stage3plus1[id] > 0 )? tensor_resnetv15stage3plus1[id] : 0);
   }

//----  operator Conv op_50
   float * op_50_f = fVec_op_50_f.data();
   for (std::size_t k = 0; k < 512; k++) {
      for (std::size_t d = 0; d < 256; d++) {
         for (std::size_t h = 0; h < 1; h++) {
            for (std::size_t w = 0; w < 1; w++) {
               op_50_f[k * 256 + d * 1 + h * 1 + w * 1  ] = tensor_resnetv15stage4conv2weight[k * 256 + d * 1 + h * 1 + w ];
            }
         }
      }
   }
   char op_50_transA = 'N';
   char op_50_transB = 'N';
   int op_50_m = 49;
   int op_50_n = 512;
   int op_50_k = 256;
   float op_50_alpha = 1.0;
   float op_50_beta = 0.0;
   float * op_50_xpad = fVec_op_50_xpad.data();
   float * op_50_xcol = fVec_op_50_xcol.data();
   size_t offset_tensor_resnetv15stage4conv2fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 50176;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage3activation1 + x_offset,256,14,14,1,1,0,0,2,2,1,1,op_50_xcol);

       BLAS::sgemm_(&op_50_transA, &op_50_transB, &op_50_m, &op_50_n, &op_50_k, &op_50_alpha, op_50_xcol, &op_50_m,
         op_50_f, &op_50_k, &op_50_beta, tensor_resnetv15stage4conv2fwd + offset_tensor_resnetv15stage4conv2fwd, &op_50_m);
      offset_tensor_resnetv15stage4conv2fwd += 25088;
   }
   constexpr int op_51_N =25088;
   constexpr int op_51_incx = 1;
   constexpr int op_51_incy = 1;
   BLAS::scopy_(&op_51_N, tensor_resnetv15stage4conv2fwd, &op_51_incx,tensor_resnetv15stage4batchnorm2fwd, &op_51_incy);

   float op_51_alpha = -1;
   BLAS::saxpy_(&op_51_N, &op_51_alpha, tensor_resnetv15stage4batchnorm2runningmean, &op_51_incx,tensor_resnetv15stage4batchnorm2fwd, &op_51_incy);

    for (size_t i = 0; i < 25088; i++) {
      tensor_resnetv15stage4batchnorm2fwd[i] *= tensor_resnetv15stage4batchnorm2gamma[i] * tensor_resnetv15stage4batchnorm2runningvar[i]; 
   }
   op_51_alpha = 1;
   BLAS::saxpy_(&op_51_N, &op_51_alpha, tensor_resnetv15stage4batchnorm2beta, &op_51_incx, tensor_resnetv15stage4batchnorm2fwd, &op_51_incy);


//----  operator Conv op_52
   float * op_52_f = fVec_op_52_f.data();
   for (std::size_t k = 0; k < 512; k++) {
      for (std::size_t d = 0; d < 256; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_52_f[k * 2304 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage4conv0weight[k * 2304 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_52_transA = 'N';
   char op_52_transB = 'N';
   int op_52_m = 49;
   int op_52_n = 512;
   int op_52_k = 2304;
   float op_52_alpha = 1.0;
   float op_52_beta = 0.0;
   float * op_52_xpad = fVec_op_52_xpad.data();
   float * op_52_xcol = fVec_op_52_xcol.data();
   size_t offset_tensor_resnetv15stage4conv0fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 50176;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage3activation1 + x_offset,256,14,14,3,3,1,1,2,2,1,1,op_52_xcol);

       BLAS::sgemm_(&op_52_transA, &op_52_transB, &op_52_m, &op_52_n, &op_52_k, &op_52_alpha, op_52_xcol, &op_52_m,
         op_52_f, &op_52_k, &op_52_beta, tensor_resnetv15stage4conv0fwd + offset_tensor_resnetv15stage4conv0fwd, &op_52_m);
      offset_tensor_resnetv15stage4conv0fwd += 25088;
   }
   constexpr int op_53_N =25088;
   constexpr int op_53_incx = 1;
   constexpr int op_53_incy = 1;
   BLAS::scopy_(&op_53_N, tensor_resnetv15stage4conv0fwd, &op_53_incx,tensor_resnetv15stage4batchnorm0fwd, &op_53_incy);

   float op_53_alpha = -1;
   BLAS::saxpy_(&op_53_N, &op_53_alpha, tensor_resnetv15stage4batchnorm0runningmean, &op_53_incx,tensor_resnetv15stage4batchnorm0fwd, &op_53_incy);

    for (size_t i = 0; i < 25088; i++) {
      tensor_resnetv15stage4batchnorm0fwd[i] *= tensor_resnetv15stage4batchnorm0gamma[i] * tensor_resnetv15stage4batchnorm0runningvar[i]; 
   }
   op_53_alpha = 1;
   BLAS::saxpy_(&op_53_N, &op_53_alpha, tensor_resnetv15stage4batchnorm0beta, &op_53_incx, tensor_resnetv15stage4batchnorm0fwd, &op_53_incy);


//------ RELU
   for (int id = 0; id < 25088 ; id++){
      tensor_resnetv15stage4relu0fwd[id] = ((tensor_resnetv15stage4batchnorm0fwd[id] > 0 )? tensor_resnetv15stage4batchnorm0fwd[id] : 0);
   }

//----  operator Conv op_55
   float * op_55_f = fVec_op_55_f.data();
   for (std::size_t k = 0; k < 512; k++) {
      for (std::size_t d = 0; d < 512; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_55_f[k * 4608 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage4conv1weight[k * 4608 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_55_transA = 'N';
   char op_55_transB = 'N';
   int op_55_m = 49;
   int op_55_n = 512;
   int op_55_k = 4608;
   float op_55_alpha = 1.0;
   float op_55_beta = 0.0;
   float * op_55_xpad = fVec_op_55_xpad.data();
   float * op_55_xcol = fVec_op_55_xcol.data();
   size_t offset_tensor_resnetv15stage4conv1fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 25088;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage4relu0fwd + x_offset,512,7,7,3,3,1,1,1,1,1,1,op_55_xcol);

       BLAS::sgemm_(&op_55_transA, &op_55_transB, &op_55_m, &op_55_n, &op_55_k, &op_55_alpha, op_55_xcol, &op_55_m,
         op_55_f, &op_55_k, &op_55_beta, tensor_resnetv15stage4conv1fwd + offset_tensor_resnetv15stage4conv1fwd, &op_55_m);
      offset_tensor_resnetv15stage4conv1fwd += 25088;
   }
   constexpr int op_56_N =25088;
   constexpr int op_56_incx = 1;
   constexpr int op_56_incy = 1;
   BLAS::scopy_(&op_56_N, tensor_resnetv15stage4conv1fwd, &op_56_incx,tensor_resnetv15stage4batchnorm1fwd, &op_56_incy);

   float op_56_alpha = -1;
   BLAS::saxpy_(&op_56_N, &op_56_alpha, tensor_resnetv15stage4batchnorm1runningmean, &op_56_incx,tensor_resnetv15stage4batchnorm1fwd, &op_56_incy);

    for (size_t i = 0; i < 25088; i++) {
      tensor_resnetv15stage4batchnorm1fwd[i] *= tensor_resnetv15stage4batchnorm1gamma[i] * tensor_resnetv15stage4batchnorm1runningvar[i]; 
   }
   op_56_alpha = 1;
   BLAS::saxpy_(&op_56_N, &op_56_alpha, tensor_resnetv15stage4batchnorm1beta, &op_56_incx, tensor_resnetv15stage4batchnorm1fwd, &op_56_incy);


//------ Add
   for (size_t id = 0; id < 25088 ; id++){
      tensor_resnetv15stage4plus0[id] = tensor_resnetv15stage4batchnorm2fwd[id] + tensor_resnetv15stage4batchnorm1fwd[id];
   }

//------ RELU
   for (int id = 0; id < 25088 ; id++){
      tensor_resnetv15stage4activation0[id] = ((tensor_resnetv15stage4plus0[id] > 0 )? tensor_resnetv15stage4plus0[id] : 0);
   }

//----  operator Conv op_59
   float * op_59_f = fVec_op_59_f.data();
   for (std::size_t k = 0; k < 512; k++) {
      for (std::size_t d = 0; d < 512; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_59_f[k * 4608 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage4conv3weight[k * 4608 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_59_transA = 'N';
   char op_59_transB = 'N';
   int op_59_m = 49;
   int op_59_n = 512;
   int op_59_k = 4608;
   float op_59_alpha = 1.0;
   float op_59_beta = 0.0;
   float * op_59_xpad = fVec_op_59_xpad.data();
   float * op_59_xcol = fVec_op_59_xcol.data();
   size_t offset_tensor_resnetv15stage4conv3fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 25088;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage4activation0 + x_offset,512,7,7,3,3,1,1,1,1,1,1,op_59_xcol);

       BLAS::sgemm_(&op_59_transA, &op_59_transB, &op_59_m, &op_59_n, &op_59_k, &op_59_alpha, op_59_xcol, &op_59_m,
         op_59_f, &op_59_k, &op_59_beta, tensor_resnetv15stage4conv3fwd + offset_tensor_resnetv15stage4conv3fwd, &op_59_m);
      offset_tensor_resnetv15stage4conv3fwd += 25088;
   }
   constexpr int op_60_N =25088;
   constexpr int op_60_incx = 1;
   constexpr int op_60_incy = 1;
   BLAS::scopy_(&op_60_N, tensor_resnetv15stage4conv3fwd, &op_60_incx,tensor_resnetv15stage4batchnorm3fwd, &op_60_incy);

   float op_60_alpha = -1;
   BLAS::saxpy_(&op_60_N, &op_60_alpha, tensor_resnetv15stage4batchnorm3runningmean, &op_60_incx,tensor_resnetv15stage4batchnorm3fwd, &op_60_incy);

    for (size_t i = 0; i < 25088; i++) {
      tensor_resnetv15stage4batchnorm3fwd[i] *= tensor_resnetv15stage4batchnorm3gamma[i] * tensor_resnetv15stage4batchnorm3runningvar[i]; 
   }
   op_60_alpha = 1;
   BLAS::saxpy_(&op_60_N, &op_60_alpha, tensor_resnetv15stage4batchnorm3beta, &op_60_incx, tensor_resnetv15stage4batchnorm3fwd, &op_60_incy);


//------ RELU
   for (int id = 0; id < 25088 ; id++){
      tensor_resnetv15stage4relu1fwd[id] = ((tensor_resnetv15stage4batchnorm3fwd[id] > 0 )? tensor_resnetv15stage4batchnorm3fwd[id] : 0);
   }

//----  operator Conv op_62
   float * op_62_f = fVec_op_62_f.data();
   for (std::size_t k = 0; k < 512; k++) {
      for (std::size_t d = 0; d < 512; d++) {
         for (std::size_t h = 0; h < 3; h++) {
            for (std::size_t w = 0; w < 3; w++) {
               op_62_f[k * 4608 + d * 9 + h * 3 + w * 1  ] = tensor_resnetv15stage4conv4weight[k * 4608 + d * 9 + h * 3 + w ];
            }
         }
      }
   }
   char op_62_transA = 'N';
   char op_62_transB = 'N';
   int op_62_m = 49;
   int op_62_n = 512;
   int op_62_k = 4608;
   float op_62_alpha = 1.0;
   float op_62_beta = 0.0;
   float * op_62_xpad = fVec_op_62_xpad.data();
   float * op_62_xcol = fVec_op_62_xcol.data();
   size_t offset_tensor_resnetv15stage4conv4fwd = 0;
   for (size_t n = 0; n < 1; n++) {
      size_t x_offset = n * 25088;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_resnetv15stage4relu1fwd + x_offset,512,7,7,3,3,1,1,1,1,1,1,op_62_xcol);

       BLAS::sgemm_(&op_62_transA, &op_62_transB, &op_62_m, &op_62_n, &op_62_k, &op_62_alpha, op_62_xcol, &op_62_m,
         op_62_f, &op_62_k, &op_62_beta, tensor_resnetv15stage4conv4fwd + offset_tensor_resnetv15stage4conv4fwd, &op_62_m);
      offset_tensor_resnetv15stage4conv4fwd += 25088;
   }
   constexpr int op_63_N =25088;
   constexpr int op_63_incx = 1;
   constexpr int op_63_incy = 1;
   BLAS::scopy_(&op_63_N, tensor_resnetv15stage4conv4fwd, &op_63_incx,tensor_resnetv15stage4batchnorm4fwd, &op_63_incy);

   float op_63_alpha = -1;
   BLAS::saxpy_(&op_63_N, &op_63_alpha, tensor_resnetv15stage4batchnorm4runningmean, &op_63_incx,tensor_resnetv15stage4batchnorm4fwd, &op_63_incy);

    for (size_t i = 0; i < 25088; i++) {
      tensor_resnetv15stage4batchnorm4fwd[i] *= tensor_resnetv15stage4batchnorm4gamma[i] * tensor_resnetv15stage4batchnorm4runningvar[i]; 
   }
   op_63_alpha = 1;
   BLAS::saxpy_(&op_63_N, &op_63_alpha, tensor_resnetv15stage4batchnorm4beta, &op_63_incx, tensor_resnetv15stage4batchnorm4fwd, &op_63_incy);


//------ Add
   for (size_t id = 0; id < 25088 ; id++){
      tensor_resnetv15stage4plus1[id] = tensor_resnetv15stage4activation0[id] + tensor_resnetv15stage4batchnorm4fwd[id];
   }

//------ RELU
   for (int id = 0; id < 25088 ; id++){
      tensor_resnetv15stage4activation1[id] = ((tensor_resnetv15stage4plus1[id] > 0 )? tensor_resnetv15stage4plus1[id] : 0);
   }

//----  operator AveragePool  op_66
{
   constexpr int hsize = 7;
   constexpr int wsize = 7;
   constexpr int hmin = -1;
   constexpr int hmax = 2;
   constexpr int wmin = -1;
   constexpr int wmax = 2;
   constexpr int kh = 7;
   constexpr int kw = 7;
   size_t outIndex = 0;
   for (size_t n = 0; n < 512; n++) {
      size_t inputOffset = n*49;
      for (int i = hmin; i < hmax; i+=1) {
         for (int j = wmin; j < wmax; j+=1) {
            float value = 0;
            int nsum = 0;
            for (int l = i;  l < i + kh; l++) {
               if (l < 0 || l >= hsize) continue;
               for (int k = j; k < j + kw; k++) {
                  if (k<0 || k>= wsize) continue;
                  int index = inputOffset + l*hsize + k;
                  value += tensor_resnetv15stage4activation1[index];
                  nsum++;
               }
            }
            value /= float(nsum);
            tensor_resnetv15pool1fwd[outIndex++] = value;
         }
      }
   }
   }
	for (int id = 0; id < 4608 ; id++){
		tensor_flatten170[id] = tensor_resnetv15pool1fwd[id];
	}

//--------- Gemm
   char op_68_transA = 'n';
   char op_68_transB = 't';
   int op_68_m = 1;
   int op_68_n = 1000;
   int op_68_k = 4608;
   float op_68_alpha = 1;
   float op_68_beta = 1;
   int op_68_lda = 4608;
   int op_68_ldb = 4608;
   std::copy(tensor_resnetv15dense0bias, tensor_resnetv15dense0bias + 1000, tensor_resnetv15dense0fwd);
   BLAS::sgemm_(&op_68_transB, &op_68_transA, &op_68_n, &op_68_m, &op_68_k, &op_68_alpha, tensor_resnetv15dense0weight, &op_68_ldb, tensor_flatten170, &op_68_lda, &op_68_beta, tensor_resnetv15dense0fwd, &op_68_n);
	std::vector<float> ret (tensor_resnetv15dense0fwd, tensor_resnetv15dense0fwd + 1000);
	return ret;
}
};
} //TMVA_SOFIE_resnet18v1
