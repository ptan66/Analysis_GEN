#ifndef _weightIndex_h_
#define _weightIndex_h_


#define SCALE_VARIATIONS           9

#define NNPDF3_VARIATIONS          100
#define NNPDF3_ALPHAS_VARIATIONS   2

#define CT10_VARIATIONS            53
#define CT10_ALPHAS_VARIATIONS     2
#define MMHT2014_VARIATIONS        51
#define MMHT2014_ALPHAS_VARIATIONS 5

#define CT14_VARIATIONS            57
#define CT14_ALPHAS_VARIATIONS     2
#define STHW2_VARIATIONS           70



extern double sthw2_variation[];

inline unsigned int scaleVariationsStartIndex(void)  {return 0;}

unsigned int nnpdf3VariationsStartIndex(void);
unsigned int nnpdf3AlphasVariationsStartIndex(void);


unsigned int ct10VariationsStartIndex(void);
unsigned int ct10AlphasVariationsStartIndex(void);



unsigned int mmht2014VariationsStartIndex(void);
unsigned int mmht2014AlphasVariationsStartIndex(void);



unsigned int ct14VariationsStartIndex(void);
unsigned int ct14AlphasVariationsStartIndex(void);

unsigned int sthw2VariationsStartIndex(void);


#endif
