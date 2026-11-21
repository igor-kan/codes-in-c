#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(reservoir_r_skip_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    size_t a[4], b[4];
    assert(reservoir_sample_u64(50, 4, 7ULL, a) == 4);
    assert(reservoir_sample_u64(50, 4, 7ULL, b) == 4);
    assert(memcmp(a, b, sizeof(a)) == 0);
    return 0;
}
