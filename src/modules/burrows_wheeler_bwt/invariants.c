#include "interface.h"
#include <stdlib.h>
#include <string.h>

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_verify_bijection(const uint8_t* src, size_t n) {
    if (n == 0) return BURROWS_WHEELER_BWT_OK;
    if (!src) return BURROWS_WHEELER_BWT_ERR_NULL;
    uint8_t* bwt = (uint8_t*)malloc(n);
    uint8_t* rec = (uint8_t*)malloc(n);
    size_t pidx = 0;
    if (!bwt || !rec) { free(bwt); free(rec); return BURROWS_WHEELER_BWT_ERR_BOUNDS; }
    burrows_wheeler_bwt_err_t e = burrows_wheeler_bwt_forward(src, n, bwt, &pidx);
    if (e == BURROWS_WHEELER_BWT_OK) e = burrows_wheeler_bwt_inverse(bwt, n, pidx, rec);
    if (e == BURROWS_WHEELER_BWT_OK && memcmp(src, rec, n) != 0) e = BURROWS_WHEELER_BWT_ERR_INVARIANT;
    free(bwt);
    free(rec);
    return e;
}
