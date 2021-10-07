#include "RooAbsPdf.h"
#include "RooRealProxy.h"

class RooRealVar;
class RooAbsReal;

/// A slow implementation of RooExponential that doesn't support batch evaluation.
class SlowRooExponential : public RooAbsPdf {
public:
  SlowRooExponential() {}
  SlowRooExponential(const char *name, const char *title, RooAbsReal& _x, RooAbsReal& _c) :
    RooAbsPdf(name, title),
    x("x","Dependent",this,_x),
    c("c","Exponent",this,_c) { }

  SlowRooExponential(const SlowRooExponential& other, const char* name) :
    RooAbsPdf(other, name), x("x",this,other.x), c("c",this,other.c) { }

  virtual TObject* clone(const char* newname) const override { return new SlowRooExponential(*this,newname); }
  inline virtual ~SlowRooExponential() { }

  Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const override;
  Double_t analyticalIntegral(Int_t code, const char* rangeName=0) const override;

protected:
  RooRealProxy x;
  RooRealProxy c;

  Double_t evaluate() const override;
};

#include "RooRealVar.h"
#include "rbc.h"

#include <cmath>
using namespace std;

Double_t SlowRooExponential::evaluate() const{
  return exp(c*x);
}

Int_t SlowRooExponential::getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* /*rangeName*/) const
{
  if (matchArgs(allVars,analVars,x)) return 1;
  if (matchArgs(allVars,analVars,c)) return 2;
  return 0 ;
}

Double_t SlowRooExponential::analyticalIntegral(Int_t code, const char* rangeName) const
{
  assert(code == 1 || code ==2);

  auto& constant  = code == 1 ? c : x;
  auto& integrand = code == 1 ? x : c;

  if (constant == 0.0) {
    return integrand.max(rangeName) - integrand.min(rangeName);
  }

  return (exp(constant*integrand.max(rangeName)) - exp(constant*integrand.min(rangeName)))
      / constant;
}
