#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    binom_heap_t h; bh_init(&h); bh_push(&h, 10); bh_push(&h, 5);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        bh_push(&h, iter & 15); sink += bh_pop_min(&h);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("binomial_heap_meld_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
