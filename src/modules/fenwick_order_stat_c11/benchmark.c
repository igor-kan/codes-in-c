#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    os_fenwick_t f; os_init(&f, 16); os_add(&f, 3, 2); os_add(&f, 9, 3);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += os_kth(&f, 4);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("fenwick_order_stat_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
