#include "interface.h"
#include <assert.h>

int main(void) {
    double a[4] = {0.0, -1.0, -1.0, -1.0};
    double b[4] = {4.0, 4.0, 4.0, 4.0};
    double c[4] = {-1.0, -1.0, -1.0, 0.0};
    double d[4] = {3.0, 2.0, 2.0, 3.0};
    double x[4], cp[4], dp[4], xf[4];
    assert(tdma_solve(4, a, b, c, d, x, cp, dp) == TRIDIAGONAL_THOMAS_C11_OK);
    assert(tdma_verify_residual(4, a, b, c, d, x, 1e-11) == TRIDIAGONAL_THOMAS_C11_OK);
    assert(tdma_solve_constant_coeff(4, -1.0, 4.0, -1.0, d, xf) == TRIDIAGONAL_THOMAS_C11_OK);
    assert(tdma_verify_residual(4, a, b, c, d, xf, 1e-11) == TRIDIAGONAL_THOMAS_C11_OK);
    return 0;
}
