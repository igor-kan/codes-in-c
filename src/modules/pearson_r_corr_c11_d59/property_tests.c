#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(pearson_r_corr_c11_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    welford_t w; welford_init(&w);
    welford_add(&w, 5.0); welford_add(&w, 5.0);
    assert(welford_var(&w) == 0.0);
    return 0;
}
