#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    spsc_ring16_t b_q;
    spsc16_init(&b_q);
    uint64_t b_tmp = 0;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        spsc16_push(&b_q, (uint64_t)iter); spsc16_pop(&b_q, &b_tmp); sink += b_tmp;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("spsc_lockfree_ring_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
