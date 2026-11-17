#include "interface.h"

boyer_moore_horspool_c_err_t bmh_validate_inputs(const uint8_t* text, size_t n, const uint8_t* pat, size_t m) {
    if (!text || !pat) return BOYER_MOORE_HORSPOOL_C_ERR_NULL;
    if (m == 0 || n < m) return BOYER_MOORE_HORSPOOL_C_ERR_BOUNDS;
    return BOYER_MOORE_HORSPOOL_C_OK;
}
