#include "interface.h"

lz77_window_match_d60_err_t lz77_window_match_d60_validate_len(size_t n) {
    if (n == 0) {
        return LZ77_WINDOW_MATCH_D60_ERR_INVALID;
    }
    return LZ77_WINDOW_MATCH_D60_OK;
}
