// Author: Federico Sossai, 2021
// Description:
//    SOFIE command line compiler.
//    Usage example: $./EmitFromONNX in_dir/mymodel.onnx out_dir/mymodel
//    Will produce:  out_dir/mymodel_FromONNX.hxx

#include <iostream>

#include "TMVA/RModel.hxx"
#include "TMVA/RModelParser_ONNX.hxx"

using namespace TMVA::Experimental::SOFIE;

int main(int argc, char *argv[])
{
   if (argc < 2) {
      std::cerr << "ERROR: missing input file\n";
      return -1;
   }

   std::string outname = argv[2];
   RModelParser_ONNX parser;
   RModel model = parser.Parse(argv[1]);
   model.Generate();
   model.OutputGenerated(outname + "_FromONNX.hxx");

   return 0;
}
