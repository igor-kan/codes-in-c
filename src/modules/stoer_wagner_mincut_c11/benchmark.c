#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    int64_t g[16][16] = {0}; g[0][1]=g[1][0]=3; g[1][2]=g[2][1]=2; g[0][2]=g[2][0]=1;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += sw_mincut_c(3, g);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("stoer_wagner_mincut_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
