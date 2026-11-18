#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(hermite_cubic_spline_c11_validate_len(1) == HERMITE_CUBIC_SPLINE_C11_OK);
    double xs[4] = {0.0, 1.0, 2.0, 3.0}, ys[4] = {0.0, 1.0, 4.0, 9.0};
    pchip_spline_t sp; pchip_build(&sp, xs, ys, 4);
    assert(fabs(pchip_eval(&sp, 1.0) - 1.0) < 1e-12);
    double mid = pchip_eval(&sp, 1.5);
    assert(mid > 1.0 && mid < 4.0);
    assert(hermite_cubic_spline_c11_verify_guard(true) == HERMITE_CUBIC_SPLINE_C11_OK);
    return 0;
}
