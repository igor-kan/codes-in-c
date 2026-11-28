#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    int64_t a[128];
    for (size_t i = 0; i < 128; ++i) a[i] = (int64_t)((i * 37) % 101);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        shell_sort_ciura(a, 128);
    sink = sink + a[0] + a[127];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("shell_sort_ciura_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
