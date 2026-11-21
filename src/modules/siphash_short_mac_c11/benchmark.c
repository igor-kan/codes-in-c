#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint8_t b_m[8] = {1,2,3,4,5,6,7,8};
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += siphash24(0x11ULL, 0x22ULL, b_m, 8);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("siphash_short_mac_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
