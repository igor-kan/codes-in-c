#include "interface.h"

pcg32_lcg_prng_c11_d57_err_t pcg32_lcg_prng_c11_d57_verify_guard(bool cond) {
    if (!cond) {
        return PCG32_LCG_PRNG_C11_D57_ERR_INVARIANT;
    }
    return PCG32_LCG_PRNG_C11_D57_OK;
}
