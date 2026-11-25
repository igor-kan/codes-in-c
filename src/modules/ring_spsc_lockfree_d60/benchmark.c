#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    spsc_ring_t q; spsc_init_d60(&q);
    int64_t v = 0;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        spsc_push_d60(&q, (int64_t)iter);
    if (spsc_pop_d60(&q, &v)) sink = sink + v;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("ring_spsc_lockfree_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
