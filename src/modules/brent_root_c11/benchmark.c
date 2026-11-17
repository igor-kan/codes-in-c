#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    brent_result_t res; (void)res;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (int64_t)(fast_secant_step(1.0, 2.0, -2.0, 4.0) * 1000.0 + iter);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("brent_root_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
