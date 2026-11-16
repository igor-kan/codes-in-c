#include "interface.h"
#include <math.h>

tridiagonal_thomas_c11_err_t tdma_validate(size_t n, const double* a, const double* b, const double* c, const double* d, const double* x) {
    if (!a || !b || !c || !d || !x) return TRIDIAGONAL_THOMAS_C11_ERR_NULL;
    if (n == 0) return TRIDIAGONAL_THOMAS_C11_ERR_BOUNDS;
    for (size_t i = 0; i < n; ++i) {
        if (!isfinite(b[i]) || !isfinite(d[i])) return TRIDIAGONAL_THOMAS_C11_ERR_OVERFLOW;
    }
    return TRIDIAGONAL_THOMAS_C11_OK;
}
