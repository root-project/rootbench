#include <RooCategory.h>
#include <RooWorkspace.h>
#include <RooRealVar.h>
#include <RooRandom.h>
#include <RooSimultaneous.h>
#include <RooUniform.h>
#include <RooMinimizer.h>
#include <RooStats/ModelConfig.h>
#include <Minuit2/GradientCalculator.h>

#include <TFile.h>
#include <TRandom.h>
#include <TError.h>

// Driven once per evaluation backend by run_atlasHiggsBackendComparison.sh:
//
//     sh -c "{ time root -q -b 'atlasHiggsBackendComparison.C(\"codegen\")'; }" &> atlas/codegen.log
//
// The resulting atlas/*.log are what atlasHiggsBackendComparison_make_plot.py
// parses.
// It looks for exactly these lines, so anything that changes them changes the plot:
//
//     Creation of NLL object took ...           (all backends)
//     Function JIT time: ...                    (codegen only)
//     Gradient generation time: ...             (codegen only)
//     Gradient IR to machine code time: ...     (codegen only)
//     MnSeedGenerator Evaluated function and gradient in ...
//     NegativeG2LineSearch Done after ...
//     VariableMetricBuilder Stop iterating after ...
//     user<TAB>...                              (from the `time` around root)
//
// The "user" total is the bar height, and every step above is subtracted from it
// to get the "Other" slice. So doHessian and writeDebugMacros default to off:
// both are codegen-only side studies whose minutes would otherwise land in "Other".
void atlasHiggsBackendComparison(const char *evalBackend = "cpu", bool doHessian = false, bool writeDebugMacros = false)
{
   using namespace RooFit;

   const bool isCodegen = std::string{evalBackend} == "codegen";

   std::cout << "EvalBackend: " << evalBackend << std::endl;

   gErrorIgnoreLevel = kInfo;
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Minimization);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::NumIntegration);
   RooMsgService::instance().getStream(1).removeTopic(RooFit::Eval);

   // Fetched by download_workspaces.sh into the working directory.
   std::string workspaceFile = "WS-VHbb-STXS_mu_toy_new.root";
   std::string workspaceName = "combined";

   std::unique_ptr<TFile> tfile{TFile::Open(workspaceFile.c_str())};
   RooWorkspace *ws = tfile->Get<RooWorkspace>(workspaceName.c_str());
   auto mc = static_cast<RooStats::ModelConfig *>(ws->obj("ModelConfig"));

   RooAbsPdf *pdf = mc->GetPdf();

   RooArgSet const *globObs = mc->GetGlobalObservables();
   RooAbsData *data = ws->data("toyData");

   //ROOT::Minuit2::GradientCalculator::DoParallelOMP(false);
   //ROOT::Minuit2::GradientCalculator::DoParallelOMP(true);

   std::unique_ptr<RooAbsReal> nll{pdf->createNLL(
         *data, GlobalObservables(*globObs), Offset(true), Optimize(2), EvalBackend(evalBackend))};

   // Only the codegen NLL is a RooEvaluatorWrapper, so this cast is not valid
   // for the legacy and cpu backends.
   if (isCodegen && doHessian) {
      static_cast<RooFit::Experimental::RooEvaluatorWrapper &>(*nll).generateHessian();
   }

   double val = nll->getVal();

   std::cout << "Initial value: " << val << std::endl;

   if (isCodegen && writeDebugMacros) {
      RooFit::Experimental::writeCodegenDebugMacro(*nll, "debug_macro");
   }

   RooMinimizer::Config cfg;
   cfg.useGradient = true;
   cfg.useHessian = isCodegen && doHessian;

   RooMinimizer minim{*nll, cfg};
   minim.setStrategy(0);

   minim.minimize("Minuit2", "MIGRAD");

   if (doHessian) {
      minim.setStrategy(3);
      minim.hesse();
   }
}
