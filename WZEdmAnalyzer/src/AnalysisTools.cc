#include "AnalysisTools.h"
#include "lhapdfcc.h"

#include <iostream>
//#include <iomanip>
//#include "TVector3.h"
//#include "TLorentzVector.h"



// flavor numbering: d, u, s, c, b, t
// this is to follow LHAPDF convention
static double I3L_quark[6] = {-1.0/2, 1.0/2, -1.0/2, 1.0/2, -1.0/2, 1.0/2};
static double Q_quark[6] =   {-1.0/3, 2.0/3, -1.0/3, 2.0/3, -1.0/3, 2.0/3};


static double ckm[3][3] = {{0.9753, 0.221, 0.003},
		  {0.221, 0.9747, 0.040},
		  {0.009, 0.039, 0.9991}};


double calPtRel(TVector3 &muon, TVector3 &jet) {

  //  TVector3 tt(jet);  
  //tt+= muon;

  TVector3 mag= muon.Cross(jet);

  /*
  double angle = muon.Angle(jet);
  std::cout << setw(10) << sin(angle)*muon.Mag() 
	    << setw(10) << mag.Mag()/jet.Mag() 
	    << std::endl;
  */

  return mag.Mag()/jet.Mag();

}


/**************************************************************************
 *
 * for W analysis
 *
 **************************************************************************/
double solveWdy(TLorentzVector muon, TVector3 met, float Wmass) {


  // neutrino energy
  double Ev = (pow(Wmass, 2) + 2*muon.Vect().Dot(met)) / (2.0 * muon.Pt());
  double Wpz = 0;
  
  // w pz, is the same as neutrino pz this eta boost frame.
  if (Ev >= met.Pt()) Wpz = sqrt(pow(Ev, 2) - pow(met.Pt(), 2));


  //  w energy
  double Ew = muon.Pt() + Ev;
  if (Ev <=0) Ew = muon.Pt();

  return 0.5*log( (Ew + Wpz)/(Ew-Wpz) );
}



double solveNutrinoPz(TLorentzVector muon, TVector3 met, double *solutions, float Wmass) {

  //  float Wmass = 80.1; 

  double costh = muon.Pz()/muon.E();
  double sin2th = pow( costh, 2) - 1;


  // coefficient of x^2 + bb*x +cc = 0
  double bb = 2.0 * (pow(Wmass, 2)/2.0/muon.E() +  muon.Vect().Dot(met)/muon.E()) * costh;
  bb = bb/sin2th;

  double cc = pow(Wmass, 2)/2.0/muon.E() +  muon.Vect().Dot(met)/muon.E();
  cc = (pow(cc, 2) - pow(met.Mag(), 2)) / sin2th;


  double delta = pow(bb, 2) - 4 * cc;

  solutions[0] = (-bb + sqrt(fabs(delta)))/2.0;
  solutions[1] = (-bb - sqrt(fabs(delta)))/2.0;


  return delta;
}


/**************************************************************************
 *
 * for Z analysis
 *
 **************************************************************************/
// calculate the Colins-Soper variables;
// everything is in the lab frame
void calCSVariables(TLorentzVector mu, TLorentzVector mubar, double *res, bool swap) {

  // convention. beam direction is on the positive Z direction.
  // beam contains quark flux.
  TLorentzVector Pbeam  (0, 0,  CM_ENERGY/2.0, CM_ENERGY/2.0);
  TLorentzVector Ptarget(0, 0, -CM_ENERGY/2.0, CM_ENERGY/2.0);


  TLorentzVector Q(mu+mubar);
  /************************************************************************
   *
   * 1) cos(theta) = 2 Q^-1 (Q^2+Qt^2)^-1 (mu^+ mubar^- - mu^- mubar^+)
   * 
   *
   ************************************************************************/ 
  double muplus  = 1.0/sqrt(2.0) * (mu.E() + mu.Z());
  double muminus = 1.0/sqrt(2.0) * (mu.E() - mu.Z());

  double mubarplus  = 1.0/sqrt(2.0) * (mubar.E() + mubar.Z());
  double mubarminus = 1.0/sqrt(2.0) * (mubar.E() - mubar.Z());
  
  double costheta = 2.0 / Q.Mag() / sqrt(pow(Q.Mag(), 2) + pow(Q.Pt(), 2)) * (muplus * mubarminus - muminus * mubarplus);
  if (swap) costheta = -costheta;



  /************************************************************************
   *
   * 2) sin2(theta) = Q^-2 Dt^2 - Q^-2 (Q^2 + Qt^2)^-1 * (Dt dot Qt)^2 
   *
   ************************************************************************/
  TLorentzVector D(mu-mubar);
  double dt_qt = D.X()*Q.X() + D.Y()*Q.Y();
  double sin2theta = pow(D.Pt()/Q.Mag(), 2) 
    - 1.0/pow(Q.Mag(), 2)/(pow(Q.Mag(), 2) + pow(Q.Pt(), 2))*pow(dt_qt, 2);

  

  /************************************************************************
   *
   * 3) tanphi = (Q^2 + Qt^2)^1/2 / Q (Dt dot R unit) /(Dt dot Qt unit)
   *
   ************************************************************************/
  // unit vector on R direction
  TVector3 R = Pbeam.Vect().Cross(Q.Vect());
  TVector3 Runit = R.Unit();


  // unit vector on Qt
  TVector3 Qt = Q.Vect(); Qt.SetZ(0);
  TVector3 Qtunit = Qt.Unit();


  TVector3 Dt = D.Vect(); Dt.SetZ(0);
  double tanphi = sqrt(pow(Q.Mag(), 2) + pow(Q.Pt(), 2)) / Q.Mag() * Dt.Dot(Runit) / Dt.Dot(Qtunit);
  if (swap) tanphi = -tanphi;

  res[0] = costheta;
  res[1] = sin2theta;
  res[2] = tanphi;
}



// an more naive way to calculate the CS angle. 
double calCosThetaCS(TLorentzVector mu, TLorentzVector mubar) {

  // convention. beam direction is on the positive Z direction.
  // beam contains quark flux.
  TLorentzVector Pbeam(  0, 0,  CM_ENERGY/2.0, CM_ENERGY/2.0);
  TLorentzVector Ptarget(0, 0, -CM_ENERGY/2.0, CM_ENERGY/2.0);

  TLorentzVector Q(mu+mubar);
  TVector3 boost = Q.BoostVector();


  //  1) tag the beam direction with the dimuon Pz component
  if (Q.Pz() < 0) {

    TLorentzVector tmp(Pbeam);
    Pbeam = Ptarget;
    Ptarget = tmp;
  }
	
  Pbeam.Boost(-boost);
  Ptarget.Boost(-boost);

  // 2) take the reference line
  TVector3 beam   =  Pbeam.Vect();
  TVector3 target = -Ptarget.Vect();


  float mag = beam.Mag();
  TVector3 beamUnit(beam.X()/mag, beam.Y()/mag, beam.Z()/mag);

  mag = target.Mag();
  TVector3 targetUnit(target.X()/mag, target.Y()/mag, target.Z()/mag);

  // 3) bisec-direction of beam and target in dimuon rest frame.
  TVector3 z_axis = beamUnit + targetUnit; 

  // 4) boost muon into the rest frame of dimuon system. 
  TLorentzVector mmu=mu;
  mmu.Boost(-boost);
  

  return cos(mmu.Vect().Angle(z_axis));
}


double calCosTheta(TLorentzVector q, TLorentzVector mu, TLorentzVector mubar) {

  TLorentzVector dilepton(mu + mubar);
  TLorentzVector qq  = - q;  // q is the mother particle; opposite direction 
  // of mother flying direction. 
  TLorentzVector mmu = mu;


  TVector3 boost = dilepton.BoostVector();

  qq.Boost(-boost);
  mmu.Boost(-boost);

  return cos( mmu.Vect().Angle(qq.Vect()) );
}


double calMistag(double mass, double rapidity) {

  //  double xmin = 1e-5;
  // double xmax = 1;
  double xmin, xmax;
  int mem = 0; // always take the central PDF
  getxmin_(mem, &xmin);
  getxmax_(mem, &xmax);


  double q2min, q2max;
  getq2max_(mem, &q2max);
  getq2min_(mem, &q2min);



  double wx1 = pdf_x1(mass, rapidity);
  double wx2 = pdf_x2(mass, rapidity);

  double mistag_prob = 0.;
  if ((wx1 < xmax && wx1 >xmin) 
      && (wx2 < xmax && wx2 >xmin)
      && mass < sqrt(q2max) 
      && mass > sqrt(q2min)) {


    double qq  = qqbar(wx1, wx2, mass);
    double q_q = qqbar(wx2, wx1, mass);


    // the mistag probability
    if (wx1 > wx2) {

      mistag_prob = q_q/(qq + q_q); 
    } else {
      mistag_prob = qq/(qq + q_q); 
    }
  }

  return mistag_prob;
}


/**************************************************************************
 * calculate Sum(Q^2 * x1x2 *q(x1)qbar(x2)
 * be sure LHAPDF set has to be initialzed somewhere else before
 * using this function
 **************************************************************************/
//  return q(x1)*qbar(x2)*sigma(qqbar->ll)
double qqbar(double x1, double x2, double Q) {

  double      xfx1[NUM_FLAVORS], xfx2[NUM_FLAVORS];
  evolvepdf_( x1, Q, xfx1);
  evolvepdf_( x2, Q, xfx2);

  // xfx index:
  // tbar, bbar, cbar, sbar, ubar, dbar, g, d, u, s, c, b, t
  double value = 0;
  for (int ii = 1; ii < 6; ii++) {


    //    double charge = 1/3.0;
    //if (ii%2 ==0) charge = charge *2; // upper quarks are 2/3. 

    value += xfx1[6+ii] * xfx2[6-ii] * sigmaff2ll(ii, pow(Q, 2));
  }

  return value;
}


//  s is partonic center of energy, 
double sfLRL(double Q, double I3, double s) {

  double z_coeff = (I3 - Q * xMSbar) * ( -0.5 +  xMSbar)/(xMSbar * (1.0 -xMSbar )  ); 

  double bw = s/( pow( s - pow(PDG_Z_MASS , 2), 2) + pow(PDG_Z_MASS* PDG_Z_WIDTH, 2)  );





  return pow(-Q + (z_coeff * bw)*(s- pow(PDG_Z_MASS, 2)), 2) + 
    pow(z_coeff*bw*PDG_Z_MASS*PDG_Z_WIDTH, 2);   
}
double sfLRR(double Q, double I3, double s) {



  double z_coeff = (I3 - Q * xMSbar) / (1.0 -xMSbar ); 

  double bw = s/( pow( s - pow(PDG_Z_MASS , 2), 2) + pow(PDG_Z_MASS* PDG_Z_WIDTH, 2)  );





  return pow(-Q + (z_coeff * bw)*(s- pow(PDG_Z_MASS, 2)), 2) + 
    pow(z_coeff*bw*PDG_Z_MASS*PDG_Z_WIDTH, 2);  

}

//static I3L_quark[6] = {1/2, -1/2, 1/2, -1/2, 1/2, -1/2};
//static Q_quark[6] =   {2/3, -1/3, 2/3, -1/3, 2/3, -1/3};

double sigmaff2ll(int flavor, double s) {


  double Q = Q_quark[flavor-1];
  double I3L = I3L_quark[flavor-1];
  double I3R = 0;


  return M_PI * pow(ALPHA, 2)/3.0/s*( sfLRL(Q, I3L, s) + sfLRL(Q, I3R, s) + sfLRR(Q, I3L, s) + sfLRR(Q, I3R, s));

}



/**************************************************************************
 * calculate the W+ Vqq^2 * q(x1)qbar(x2)
 * or W- Vqq^2 qbar(x1) *q(x2)
 * be sure LHAPDF set has to be initialzed somewhere else before
 * using this function
 **************************************************************************/
double qqbar(double x1, double x2, int charge) {

  double Q = 80.4; // W mass 
  double      xfx1[NUM_FLAVORS], xfx2[NUM_FLAVORS];
  evolvepdf_( x1, Q, xfx1);
  evolvepdf_( x2, Q, xfx2);

  // xfx index:
  // tbar, bbar, cbar, sbar, ubar, dbar, g, d, u, s, c, b, t
  double value = 0;
  int g_index = 6;
  if (charge > 0) {
    value =  pow(ckm[0][0], 2) * xfx1[g_index+2] * xfx2[g_index-1]; // u dbar 
    value += pow(ckm[0][1], 2) * xfx1[g_index+2] * xfx2[g_index-3]; // u sbar 
    value += pow(ckm[1][0], 2) * xfx1[g_index+4] * xfx2[g_index-1]; // c dbar 
    value += pow(ckm[1][1], 2) * xfx1[g_index+4] * xfx2[g_index-3]; // c sbar 
  } else {
    value =  pow(ckm[0][0], 2) * xfx1[g_index-2] * xfx2[g_index+1]; // ubar d 
    value += pow(ckm[0][1], 2) * xfx1[g_index-2] * xfx2[g_index+3]; // ubar s 
    value += pow(ckm[1][0], 2) * xfx1[g_index-4] * xfx2[g_index+1]; // cbar d 
    value += pow(ckm[1][1], 2) * xfx1[g_index-4] * xfx2[g_index+3]; // cbar s 
  }

  //  std::cout << ckm[0][0] << ", "<<ckm[0][1] << std::endl;
  // std::cout << ckm[1][0] << ", "<<ckm[1][1] << std::endl;


  return value;
}


double pdf_x1(double Q, double y) {return Q/CM_ENERGY * exp(y);}
double pdf_x2(double Q, double y) {return Q/CM_ENERGY * exp(-y);}

//  return xfx(x) for given flavor quark. 
double evolved_xfx(   double Q,  double x, int flav) {

  double      xfx[NUM_FLAVORS];
  evolvepdf_( x, Q, xfx);
  return xfx[flav+6];
}


void   initPdf(const char *pdf_set, int subset) {

  const char *lhaPDFPath = getenv("LHAPATH");
  std::string pdfSet(lhaPDFPath);
  pdfSet.append("/");   pdfSet.append(pdf_set);
  std::cout << "PDF set - " << pdfSet.data() << " subset - " << subset << std::endl;
  initpdfset_((char *)pdfSet.data(), pdfSet.size());
  initpdf_(subset);

  std::cout << "        PDF initialized" << std::endl;
  std::cout << "**************************************" << std::endl;

}
