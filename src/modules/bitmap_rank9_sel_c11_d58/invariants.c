#include "interface.h"

bitmap_rank9_sel_c11_d58_err_t bitmap_rank9_sel_c11_d58_verify_guard(bool cond) {
    if (!cond) {
        return BITMAP_RANK9_SEL_C11_D58_ERR_INVARIANT;
    }
    return BITMAP_RANK9_SEL_C11_D58_OK;
}
