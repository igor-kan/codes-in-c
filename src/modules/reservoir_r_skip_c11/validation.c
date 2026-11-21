#include "interface.h"

reservoir_r_skip_c11_err_t reservoir_r_skip_c11_validate_len(size_t n) {
    if (n == 0) {
        return RESERVOIR_R_SKIP_C11_ERR_INVALID;
    }
    return RESERVOIR_R_SKIP_C11_OK;
}
