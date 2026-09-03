#include <ROOT/RNTupleImporter.hxx>
#include <ROOT/RNTupleWriteOptions.hxx>

#include <TSystem.h>

#include <iostream>
#include <string>

#include <unistd.h>

using ROOT::Experimental::RNTupleImporter;

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

void Usage(char *progname)
{
   std::cout << "Usage: " << progname << " -i <gg_*.root> -o <ntuple-path> -c <compression>" << std::endl;
}

int main(int argc, char **argv)
{
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
   std::string outputFile = outputPath + "/atlas-" + compressionShorthand + ".ntuple";
   if (!gSystem->AccessPathName(outputFile.c_str())) {
      std::cout << "Output file " << outputFile << " already exists, nothing to do" << std::endl;
      return 0;
   }
   std::cout << "Converting " << inputFile << " --> " << outputFile << std::endl;

   auto importer = RNTupleImporter::Create(inputFile, "mini", outputFile);
   ROOT::RNTupleWriteOptions options;
   options.SetCompression(compressionSettings);
   importer->SetWriteOptions(options);
   importer->Import();
}
