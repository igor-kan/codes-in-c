#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    bres_line_t ln;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink = sink + (int64_t)bresenham_line(0, 0, (int32_t)(iter % 40), (int32_t)(iter % 17), &ln);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("bresenham_line_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
