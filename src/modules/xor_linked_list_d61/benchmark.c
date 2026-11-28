#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    xor_list_t xl; xor_list_init(&xl);
    int64_t vals[64];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        xor_list_push_back(&xl, (int64_t)(iter & 63));
    sink = sink + (int64_t)xor_list_forward(&xl, vals, 64);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("xor_linked_list_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
