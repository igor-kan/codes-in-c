#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const int64_t b_ts[4] = {10, 20, 30, 40};
    int64_t b_e[4];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        delta_encode(b_ts, 4, b_e); sink += b_e[2];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("delta_zig_frame_c11_d57 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
