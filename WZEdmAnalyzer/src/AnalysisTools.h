#ifndef _AnalysisTools_h_
#define _AnalysisTools_h_

//#include "lhapdfcc.h"

#include "TVector3.h"
#include "TLorentzVector.h"

//#include "math.h"

#define NUM_FLAVORS 13
#define ALPHA       1.0/137
#define xMSbar      0.23120
#define PDG_Z_MASS  91.19
#define PDG_Z_WIDTH 2.4952
#define PDG_W_MASS  80.40
#define PDG_W_WIDTH 2.118
#define CM_ENERGY   13000.0

double calPtRel(TVector3 &muon, TVector3 &jet); 

double solveNutrinoPz(TLorentzVector muon, TVector3 met, double *solutions, float Wmass =PDG_W_MASS);
double solveWdy(TLorentzVector muon, TVector3 met, float Wmass =PDG_W_MASS);


double calCosThetaCS(TLorentzVector mu, TLorentzVector mubar);
double calCosTheta(TLorentzVector q, TLorentzVector mu, TLorentzVector mubar);
void   calCSVariables(TLorentzVector mu, TLorentzVector mubar, double *res, bool swap);
double calMistag(double mass, double rapidity);


double pdf_x1(double Q,  double y);
double pdf_x2(double Q,  double y);
double qqbar( double x1, double x2, double Q); 
double qqbar( double x1, double x2, int charge);
double evolved_xfx(double Q,  double x,  int flav);
void   initPdf(const char *pdf_set, int subset);


double sfLRL(double Q, double I3, double s);
double sfLRR(double Q, double I3, double s);
double sigmaff2ll(int flavor, double s);

#endif
