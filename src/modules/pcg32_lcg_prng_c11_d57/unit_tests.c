#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(pcg32_lcg_prng_c11_d57_validate_len(1) == PCG32_LCG_PRNG_C11_D57_OK);
    pcg32_rng_t r1, r2;
    pcg32_seed(&r1, 42ULL, 54ULL);
    pcg32_seed(&r2, 42ULL, 54ULL);
    for (int i = 0; i < 16; ++i) {
        uint32_t v = pcg32_next(&r1);
        assert(v == pcg32_next(&r2));
    }
    assert(pcg32_lcg_prng_c11_d57_verify_guard(true) == PCG32_LCG_PRNG_C11_D57_OK);
    return 0;
}
