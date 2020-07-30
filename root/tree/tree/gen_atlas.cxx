#include <ROOT/RField.hxx>
#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleModel.hxx>
#include <ROOT/RNTupleOptions.hxx>

#include <TBranch.h>
#include <TBranchElement.h>
#include <TBranchSTL.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1F.h>
#include <TLeaf.h>
#include <TTree.h>

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <unistd.h>

using RNTupleModel = ROOT::Experimental::RNTupleModel;
using RFieldBase = ROOT::Experimental::Detail::RFieldBase;
using RNTupleWriter = ROOT::Experimental::RNTupleWriter;
using RNTupleWriteOptions = ROOT::Experimental::RNTupleWriteOptions;

int GetCompressionSettings(std::string shorthand)
{
   if (shorthand == "zlib")
      return 101;
   if (shorthand == "lz4")
      return 404;
   if (shorthand == "lzma")
      return 207;
   if (shorthand == "zstd")
      return 505;
   if (shorthand == "none")
      return 0;
   abort();
}


static void SplitPath(const std::string &path, std::string *basename, std::string *suffix)
{
    size_t idx_dot = path.find_last_of(".");
    if (idx_dot == std::string::npos) {
        *basename = path;
        suffix->clear();
    } else {
        *basename = path.substr(0, idx_dot);
        *suffix = path.substr(idx_dot + 1);
    }
}


std::string StripSuffix(const std::string &path) {
    std::string basename;
    std::string suffix;
    SplitPath(path, &basename, &suffix);
    return basename;
}


std::string GetFileName(const std::string &path) {
    const std::string::size_type idx = path.find_last_of('/');
    if (idx != std::string::npos)
        return path.substr(idx+1);
    else
        return path;
}


void Usage(char *progname) {
   std::cout << "Usage: " << progname << " -i <gg_*.root> -o <ntuple-path> -c <compression>" << std::endl;
}


int main(int argc, char **argv) {
   std::string inputFile = "gg_data.root";
   std::string outputPath = ".";
   int compressionSettings = 0;
   std::string compressionShorthand = "none";

   int c;
   while ((c = getopt(argc, argv, "hvi:o:c:")) != -1) {
      switch (c) {
      case 'h':
      case 'v':
         Usage(argv[0]);
         return 0;
      case 'i':
         inputFile = optarg;
         break;
      case 'o':
         outputPath = optarg;
         break;
      case 'c':
         compressionSettings = GetCompressionSettings(optarg);
         compressionShorthand = optarg;
         break;
      default:
         fprintf(stderr, "Unknown option: -%c\n", c);
         Usage(argv[0]);
         return 1;
      }
   }
   std::string outputFile = outputPath + "/" + "atlas" + "-" + compressionShorthand + ".ntuple";

   std::unique_ptr<TFile> f(TFile::Open(inputFile.c_str()));
   assert(f && ! f->IsZombie());

   auto model = RNTupleModel::Create();

   auto tree = f->Get<TTree>("mini");
   for (auto b : TRangeDynCast<TBranch>(*tree->GetListOfBranches())) {
      assert(b);

      TLeaf *l = static_cast<TLeaf*>(b->GetListOfLeaves()->First());

      auto field = RFieldBase::Create(l->GetName(), l->GetTypeName());

      if (typeid(*b) == typeid(TBranchSTL) || typeid(*b) == typeid(TBranchElement)) {
         if (field->GetType() == "std::vector<bool>") {
            std::vector<bool> **v = new std::vector<bool> *();
            tree->SetBranchAddress(b->GetName(), v);
            model->GetDefaultEntry()->CaptureValue(field->CaptureValue(*v));
            model->GetRootField()->Attach(std::unique_ptr<RFieldBase>(field));
         } else if (field->GetType() == "std::vector<float>") {
            std::vector<float> **v = new std::vector<float> *();
            tree->SetBranchAddress(b->GetName(), v);
            model->GetDefaultEntry()->CaptureValue(field->CaptureValue(*v));
            model->GetRootField()->Attach(std::unique_ptr<RFieldBase>(field));
         } else if (field->GetType() == "std::vector<std::int32_t>") {
            std::vector<std::int32_t> **v = new std::vector<std::int32_t> *();
            tree->SetBranchAddress(b->GetName(), v);
            model->GetDefaultEntry()->CaptureValue(field->CaptureValue(*v));
            model->GetRootField()->Attach(std::unique_ptr<RFieldBase>(field));
         } else if (field->GetType() == "std::vector<std::uint32_t>") {
            std::vector<std::uint32_t> **v = new std::vector<std::uint32_t> *();
            tree->SetBranchAddress(b->GetName(), v);
            model->GetDefaultEntry()->CaptureValue(field->CaptureValue(*v));
            model->GetRootField()->Attach(std::unique_ptr<RFieldBase>(field));
         } else {
            assert(false);
         }
      } else {
         model->AddField(std::unique_ptr<RFieldBase>(field));
         void *fieldDataPtr = model->GetDefaultEntry()->GetValue(l->GetName()).GetRawPtr();
         tree->SetBranchAddress(b->GetName(), fieldDataPtr);
      }
   }

   RNTupleWriteOptions options;
   options.SetCompression(compressionSettings);
   auto ntuple = RNTupleWriter::Recreate(std::move(model), "mini", outputFile, options);

   auto nEntries = tree->GetEntries();
   for (decltype(nEntries) i = 0; i < nEntries; ++i) {
      tree->GetEntry(i);
      ntuple->Fill();
   }

   tree->ResetBranchAddresses();
} 