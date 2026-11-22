#include "interface.h"

pcg32_lcg_prng_c11_d57_err_t pcg32_lcg_prng_c11_d57_validate_len(size_t n) {
    if (n == 0) {
        return PCG32_LCG_PRNG_C11_D57_ERR_INVALID;
    }
    return PCG32_LCG_PRNG_C11_D57_OK;
}
