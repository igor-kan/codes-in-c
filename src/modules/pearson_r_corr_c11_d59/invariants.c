#include "interface.h"

pearson_r_corr_c11_d59_err_t pearson_r_corr_c11_d59_verify_guard(bool cond) {
    if (!cond) {
        return PEARSON_R_CORR_C11_D59_ERR_INVARIANT;
    }
    return PEARSON_R_CORR_C11_D59_OK;
}
