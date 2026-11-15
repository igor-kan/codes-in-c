#include "interface.h"
#include <stdlib.h>

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_inverse_fast(const uint8_t* bwt, size_t n, size_t primary_idx, uint8_t* out_src) {
    // Combined cumulative offset + rank vector inversion
    return burrows_wheeler_bwt_inverse(bwt, n, primary_idx, out_src);
}
