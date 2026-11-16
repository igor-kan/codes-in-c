#include "interface.h"
#include <assert.h>

int main(void) {
    enum { N = 32, S = 8 };
    double a[N], b[N], c[N], rhs[S * N], x[S * N];
    for (size_t i = 0; i < N; ++i) {
        a[i] = (i > 0) ? -0.5 - 0.01 * (double)(i % 5) : 0.0;
        b[i] = 4.0 + 0.1 * (double)(i % 7);
        c[i] = (i + 1 < N) ? -0.4 - 0.01 * (double)(i % 4) : 0.0;
    }
    for (size_t k = 0; k < S; ++k) {
        for (size_t i = 0; i < N; ++i) rhs[k * N + i] = (double)(k + 1) * (double)(i + 1);
    }
    assert(tdma_batch_solve_mt(S, N, a, b, c, rhs, x, 4) == TRIDIAGONAL_THOMAS_C11_OK);
    for (size_t k = 0; k < S; ++k) {
        assert(tdma_verify_residual(N, a, b, c, rhs + k * N, x + k * N, 1e-10) == TRIDIAGONAL_THOMAS_C11_OK);
    }
    return 0;
}
