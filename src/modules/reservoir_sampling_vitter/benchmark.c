#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    int64_t buf[32], vals[512]; for(int i=0;i<512;++i) vals[i]=i; reservoir_t r;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 200; ++iter) {
        reservoir_init(&r, buf, 32, 99ULL); reservoir_observe_batch(&r, vals, 512); sink += (size_t)buf[0];
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("reservoir_sampling_vitter ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 200.0, sink);
    return 0;
}
