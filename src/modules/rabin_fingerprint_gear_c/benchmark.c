#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t data[64] = {1,2,3,4,5,6,7,8}; cdc_chunk_t ch[16];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (int64_t)gear_cdc_split(data, 64, 8, 32, 0x3ULL, ch, 16);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("rabin_fingerprint_gear_c us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
