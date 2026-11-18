#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(brent_pollard_factor_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t n = 1000003ULL * 1000033ULL;
    uint64_t f = brent_pollard_rho(n, 3);
    assert(f > 1 && f < n && n % f == 0);
    return 0;
}
