#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    dary_heap_t h; dary_heap_init(&h);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        if (dary_heap_push(&h, (int64_t)(iter & 63))) {
        int64_t out = 0;
        if (dary_heap_pop(&h, &out)) sink = sink + out;
    }
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("dary_heap_c11_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
