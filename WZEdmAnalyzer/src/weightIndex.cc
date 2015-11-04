#include "weightIndex.h"


double sthw2_variation[] = {
  0.2312,
  0.2200, 0.2230, 0.2250, 0.2270, 0.2275, 0.2280, 0.2282, 0.2284, 0.2286, 0.2288, 
  0.2290, 0.2291, 0.2292, 0.2293, 0.2294, 0.2295, 0.2296, 0.2297, 0.2298, 0.2299,
  0.2300, 0.2301, 0.2302, 0.2303, 0.2304, 0.2305, 0.2306, 0.2307, 0.2308, 0.2309,
  0.2310, 0.2311,         0.2313, 0.2314, 0.2315, 0.2316, 0.2317, 0.2318, 0.2319,
  0.2320, 0.2321, 0.2322, 0.2323, 0.2324, 0.2325, 0.2326, 0.2327, 0.2328, 0.2329,
  0.2330, 0.2331, 0.2332, 0.2333, 0.2334, 0.2335, 0.2336, 0.2337, 0.2338, 0.2339,
  0.2340, 0.2342, 0.2344, 0.2346, 0.2348, 0.2350, 0.2355, 0.2360, 0.2370, 0.2400};

unsigned int nnpdf3VariationsStartIndex(void)       {return scaleVariationsStartIndex()  + SCALE_VARIATIONS;}
unsigned int nnpdf3AlphasVariationsStartIndex(void) {return nnpdf3VariationsStartIndex() + NNPDF3_VARIATIONS ;}




unsigned int ct10VariationsStartIndex(void)       {return nnpdf3AlphasVariationsStartIndex()  + NNPDF3_ALPHAS_VARIATIONS;}
unsigned int ct10AlphasVariationsStartIndex(void) {return ct10VariationsStartIndex() + CT10_VARIATIONS ;}


unsigned int mmht2014VariationsStartIndex(void)       {return ct10AlphasVariationsStartIndex()  + CT10_ALPHAS_VARIATIONS;}
unsigned int mmht2014AlphasVariationsStartIndex(void) {return mmht2014VariationsStartIndex() + MMHT2014_VARIATIONS ;}


unsigned int ct14VariationsStartIndex(void)       {return mmht2014AlphasVariationsStartIndex()  + MMHT2014_ALPHAS_VARIATIONS;}
unsigned int ct14AlphasVariationsStartIndex(void) {return ct14VariationsStartIndex() + CT14_VARIATIONS ;}

unsigned int sthw2VariationsStartIndex(void) {return ct14AlphasVariationsStartIndex() + CT14_ALPHAS_VARIATIONS; }

