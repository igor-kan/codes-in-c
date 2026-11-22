#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    pcg32_rng_t b_rng; pcg32_seed(&b_rng, 1ULL, 2ULL);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += pcg32_next(&b_rng);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("pcg32_lcg_prng_c11_d57 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
