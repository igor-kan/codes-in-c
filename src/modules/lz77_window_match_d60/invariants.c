#include "interface.h"

lz77_window_match_d60_err_t lz77_window_match_d60_verify_guard(bool cond) {
    if (!cond) {
        return LZ77_WINDOW_MATCH_D60_ERR_INVARIANT;
    }
    return LZ77_WINDOW_MATCH_D60_OK;
}
