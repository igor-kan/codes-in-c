#include "interface.h"

pearson_r_corr_c11_d59_err_t pearson_r_corr_c11_d59_validate_len(size_t n) {
    if (n == 0) {
        return PEARSON_R_CORR_C11_D59_ERR_INVALID;
    }
    return PEARSON_R_CORR_C11_D59_OK;
}
