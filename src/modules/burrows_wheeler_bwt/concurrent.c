#include "interface.h"

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_batch(const uint8_t** blocks, const size_t* lens, size_t count) {
    if (!blocks || !lens) return BURROWS_WHEELER_BWT_ERR_NULL;
    for (size_t i = 0; i < count; ++i) {
        burrows_wheeler_bwt_err_t e = burrows_wheeler_bwt_verify_bijection(blocks[i], lens[i]);
        if (e != BURROWS_WHEELER_BWT_OK) return e;
    }
    return BURROWS_WHEELER_BWT_OK;
}
