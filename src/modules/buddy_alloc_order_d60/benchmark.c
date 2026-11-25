#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    buddy_pool_t bp; buddy_init_d60(&bp);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        int p = buddy_alloc_d60(&bp, 1);
    if (p >= 0) { sink = sink + p; buddy_free_d60(&bp, p, 1); }
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("buddy_alloc_order_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
