#include "interface.h"
#include <math.h>

brent_root_c11_err_t validate_bracket(double fa, double fb, double tol, int max_iter) {
    if (!isfinite(fa) || !isfinite(fb) || tol <= 0.0 || max_iter <= 0) return BRENT_ROOT_C11_ERR_INVALID;
    if (fa * fb > 0.0) return BRENT_ROOT_C11_ERR_INVALID;
    return BRENT_ROOT_C11_OK;
}
