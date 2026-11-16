#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    double a[128], b[128], c[128], d[128], x[128], cp[128], dp[128]; for(int i=0;i<128;++i){a[i]=-1.0; b[i]=4.0; c[i]=-1.0; d[i]=1.0;}
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 200; ++iter) {
        tdma_solve(128, a, b, c, d, x, cp, dp); sink += (size_t)(x[0] * 1000.0);
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("tridiagonal_thomas_c11 ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 200.0, sink);
    return 0;
}
