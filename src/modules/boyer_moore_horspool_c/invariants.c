#include "interface.h"
#include <string.h>

boyer_moore_horspool_c_err_t bmh_verify_hits(const uint8_t* text, const uint8_t* pat, size_t m, const size_t* pos, size_t cnt) {
    for (size_t i = 0; i < cnt; ++i) {
        if (memcmp(text + pos[i], pat, m) != 0) return BOYER_MOORE_HORSPOOL_C_ERR_INVARIANT;
    }
    return BOYER_MOORE_HORSPOOL_C_OK;
}
