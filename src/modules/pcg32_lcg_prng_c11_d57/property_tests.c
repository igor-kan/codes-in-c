#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(pcg32_lcg_prng_c11_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    pcg32_rng_t rng;
    pcg32_seed(&rng, 7ULL, 9ULL);
    for (int i = 0; i < 64; ++i) assert(pcg32_bounded(&rng, 13u) < 13u);
    return 0;
}
