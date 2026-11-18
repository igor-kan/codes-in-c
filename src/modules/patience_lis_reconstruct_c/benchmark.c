#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    int64_t a[8] = {10, 9, 2, 5, 3, 7, 101, 18}; lis_result_t r;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (int64_t)patience_lis(a, 8, &r);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("patience_lis_reconstruct_c us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
