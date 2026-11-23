#include "interface.h"

bitmap_rank9_sel_c11_d58_err_t bitmap_rank9_sel_c11_d58_validate_len(size_t n) {
    if (n == 0) {
        return BITMAP_RANK9_SEL_C11_D58_ERR_INVALID;
    }
    return BITMAP_RANK9_SEL_C11_D58_OK;
}
