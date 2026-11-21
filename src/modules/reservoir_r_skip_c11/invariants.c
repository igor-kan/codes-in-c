#include "interface.h"

reservoir_r_skip_c11_err_t reservoir_r_skip_c11_verify_guard(bool cond) {
    if (!cond) {
        return RESERVOIR_R_SKIP_C11_ERR_INVARIANT;
    }
    return RESERVOIR_R_SKIP_C11_OK;
}
