#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    uint8_t b[256], src[64], dst[64]; kfifo_t q; kfifo_init(&q, b, 256); for(int i=0;i<64;++i) src[i]=(uint8_t)i;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 200; ++iter) {
        kfifo_in(&q, src, 64); sink += kfifo_out(&q, dst, 64);
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("kfifo_power2_ring ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 200.0, sink);
    return 0;
}
