#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const size_t sizes[4] = {64, 128, 256, 512};
    for (size_t s = 0; s < 4; ++s) {
        size_t n = sizes[s];
        uint8_t* src = (uint8_t*)malloc(n);
        uint8_t* bwt = (uint8_t*)malloc(n);
        uint8_t* rec = (uint8_t*)malloc(n);
        for (size_t i = 0; i < n; ++i) src[i] = (uint8_t)('A' + (i % 13));
        size_t pidx = 0;
        struct timespec t0, t1;
        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (int it = 0; it < 20; ++it) {
            burrows_wheeler_bwt_forward(src, n, bwt, &pidx);
            burrows_wheeler_bwt_inverse(bwt, n, pidx, rec);
        }
        clock_gettime(CLOCK_MONOTONIC, &t1);
        double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 20.0;
        printf("burrows_wheeler_bwt n=%zu ns=%.1f\n", n, ns);
        free(src); free(bwt); free(rec);
    }
    return 0;
}
