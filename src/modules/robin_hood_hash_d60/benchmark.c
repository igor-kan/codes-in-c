#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    rh_map_t m; rh_init_d60(&m);
    for (uint64_t k = 1; k <= 24; ++k) rh_put_d60(&m, k, (int64_t)k);
    int64_t out = 0;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        if (rh_get_d60(&m, (uint64_t)((iter % 24) + 1), &out)) sink = sink + out;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("robin_hood_hash_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
