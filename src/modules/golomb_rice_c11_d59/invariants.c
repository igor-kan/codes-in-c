#include "interface.h"

golomb_rice_c11_d59_err_t golomb_rice_c11_d59_verify_guard(bool cond) {
    if (!cond) {
        return GOLOMB_RICE_C11_D59_ERR_INVARIANT;
    }
    return GOLOMB_RICE_C11_D59_OK;
}
