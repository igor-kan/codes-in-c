#include "interface.h"

lz77_sliding_match_c11_err_t lz77_sliding_match_c11_validate_len(size_t n) {
    if (n == 0) {
        return LZ77_SLIDING_MATCH_C11_ERR_INVALID;
    }
    return LZ77_SLIDING_MATCH_C11_OK;
}
