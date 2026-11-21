#include "interface.h"

lz77_sliding_match_c11_err_t lz77_sliding_match_c11_verify_guard(bool cond) {
    if (!cond) {
        return LZ77_SLIDING_MATCH_C11_ERR_INVARIANT;
    }
    return LZ77_SLIDING_MATCH_C11_OK;
}
