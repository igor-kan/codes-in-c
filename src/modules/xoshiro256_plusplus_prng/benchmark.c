#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    xoshiro256pp_state_t st; xoshiro_seed(&st, 1ULL); uint64_t out[256];
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 200; ++iter) {
        xoshiro_fill_batch(&st, out, 256); sink += (size_t)out[0];
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("xoshiro256_plusplus_prng ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 200.0, sink);
    return 0;
}
