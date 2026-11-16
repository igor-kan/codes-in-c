#include "interface.h"
#include <math.h>

tridiagonal_thomas_c11_err_t tdma_solve(size_t n, const double* a, const double* b, const double* c, const double* d, double* x, double* c_prime, double* d_prime) {
    if (tdma_validate(n, a, b, c, d, x) != TRIDIAGONAL_THOMAS_C11_OK || !c_prime || !d_prime) {
        return TRIDIAGONAL_THOMAS_C11_ERR_NULL;
    }
    if (fabs(b[0]) < 1e-15) return TRIDIAGONAL_THOMAS_C11_ERR_INVALID;
    c_prime[0] = (n > 1) ? (c[0] / b[0]) : 0.0;
    d_prime[0] = d[0] / b[0];
    for (size_t i = 1; i < n; ++i) {
        double denom = b[i] - a[i] * c_prime[i - 1];
        if (fabs(denom) < 1e-15) return TRIDIAGONAL_THOMAS_C11_ERR_INVALID;
        c_prime[i] = (i + 1 < n) ? (c[i] / denom) : 0.0;
        d_prime[i] = (d[i] - a[i] * d_prime[i - 1]) / denom;
    }
    x[n - 1] = d_prime[n - 1];
    for (size_t idx = n - 1; idx > 0; --idx) {
        size_t i = idx - 1;
        x[i] = d_prime[i] - c_prime[i] * x[i + 1];
    }
    return TRIDIAGONAL_THOMAS_C11_OK;
}
