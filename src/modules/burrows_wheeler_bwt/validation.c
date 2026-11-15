#include "interface.h"

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_validate(size_t n, size_t primary_idx) {
    if (n > 0 && primary_idx >= n) return BURROWS_WHEELER_BWT_ERR_BOUNDS;
    return BURROWS_WHEELER_BWT_OK;
}
