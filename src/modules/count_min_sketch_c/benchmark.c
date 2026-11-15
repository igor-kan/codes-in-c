#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    cms_sketch_t sk;
    count_min_sketch_c_init(&sk, 4, 2048);
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (uint64_t i = 0; i < 10000; ++i) count_min_sketch_c_add_conservative(&sk, i * 17ULL, 1);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 10000.0;
    printf("count_min_sketch_c update_ns=%.2f\n", ns);
    count_min_sketch_c_free(&sk);
    return 0;
}
