#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(hermite_cubic_spline_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    double xs[3] = {0.0, 2.0, 4.0}, ys[3] = {1.0, 3.0, 5.0};
    pchip_spline_t sp; pchip_build(&sp, xs, ys, 3);
    assert(fabs(pchip_eval(&sp, 1.0) - 2.0) < 1e-12);
    return 0;
}
