#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint32_t bv[3] = {2, 4, 6}; uint8_t bb[64];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (uint64_t)gr_encode_bits(bv, 3, 2, bb);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("golomb_rice_c11_d59 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
