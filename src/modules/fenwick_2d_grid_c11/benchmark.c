#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    fenwick2d_t fw; fw2d_init(&fw, 8, 8); fw2d_add(&fw, 2, 3, 10);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += fw2d_rect_sum(&fw, 0, 0, 7, 7);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("fenwick_2d_grid_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
