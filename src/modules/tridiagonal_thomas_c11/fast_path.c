#include "interface.h"
#include <math.h>
#include <stdlib.h>

tridiagonal_thomas_c11_err_t tdma_solve_constant_coeff(size_t n, double sub, double diag, double sup, const double* d, double* x) {
    if (!d || !x || n == 0 || fabs(diag) < 1e-15) return TRIDIAGONAL_THOMAS_C11_ERR_INVALID;
    double* cp = (double*)malloc(n * sizeof(double));
    double* dp = (double*)malloc(n * sizeof(double));
    if (!cp || !dp) { free(cp); free(dp); return TRIDIAGONAL_THOMAS_C11_ERR_NULL; }
    cp[0] = (n > 1) ? (sup / diag) : 0.0;
    dp[0] = d[0] / diag;
    for (size_t i = 1; i < n; ++i) {
        double inv = 1.0 / (diag - sub * cp[i - 1]);
        cp[i] = sup * inv;
        dp[i] = (d[i] - sub * dp[i - 1]) * inv;
    }
    x[n - 1] = dp[n - 1];
    for (size_t k = n - 1; k > 0; --k) x[k - 1] = dp[k - 1] - cp[k - 1] * x[k];
    free(cp);
    free(dp);
    return TRIDIAGONAL_THOMAS_C11_OK;
}
