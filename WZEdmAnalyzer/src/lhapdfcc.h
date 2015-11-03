#ifndef _lhapdfcc_
#define _lhapdfcc_

extern "C" {
  void initpdfset_ (char *, int len);
  void initpdfsetm_(int &, char *);
  void initpdf_(int &);
  void evolvepdf_(double &, double &, double *);
  void numberpdf_(int &);
  void getxmin_(int &, double *);
  void getxmax_(int &, double *);
  void getq2max_(int &, double *);
  void getq2min_(int &, double *);

}



#endif
