#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    size_t n = 4096;
    uint8_t* buf = (uint8_t*)malloc(n);
    for (size_t i = 0; i < n; ++i) buf[i] = (uint8_t)('a' + (i % 26));
    size_t cps = 0;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int it = 0; it < 200; ++it) utf8_dfa_decoder_count(buf, n, &cps);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 200.0;
    printf("utf8_dfa_decoder n=%zu cps=%zu ns=%.1f\n", n, cps, ns);
    free(buf);
    return 0;
}
