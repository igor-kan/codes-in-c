#include "interface.h"
#include <math.h>

tridiagonal_thomas_c11_err_t tdma_verify_residual(size_t n, const double* a, const double* b, const double* c, const double* d, const double* x, double tol) {
    if (tdma_validate(n, a, b, c, d, x) != TRIDIAGONAL_THOMAS_C11_OK) return TRIDIAGONAL_THOMAS_C11_ERR_INVARIANT;
    for (size_t i = 0; i < n; ++i) {
        double lhs = b[i] * x[i];
        if (i > 0) lhs += a[i] * x[i - 1];
        if (i + 1 < n) lhs += c[i] * x[i + 1];
        if (fabs(lhs - d[i]) > tol) return TRIDIAGONAL_THOMAS_C11_ERR_INVARIANT;
    }
    return TRIDIAGONAL_THOMAS_C11_OK;
}
