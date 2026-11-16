#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

static double elapsed_ns(struct timespec a, struct timespec b) {
    return (double)(b.tv_sec - a.tv_sec) * 1e9 + (double)(b.tv_nsec - a.tv_nsec);
}

int main(void) {
    size_t sink = 0;
    uint8_t s[512], d[540]; for(size_t i=0;i<512;++i) s[i]=(uint8_t)(i/8U); size_t ol=0;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int iter = 0; iter < 200; ++iter) {
        packbits_encode(s, 512, d, sizeof(d), &ol); sink += ol;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("rle_packbits_codec ns=%.1f sink=%zu\n", elapsed_ns(t0, t1) / 200.0, sink);
    return 0;
}
