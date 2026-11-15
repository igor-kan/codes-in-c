#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const size_t sizes[4] = {64, 256, 1024, 4096};
    for (size_t s = 0; s < 4; ++s) {
        size_t n = sizes[s];
        double* a = (double*)malloc(n * sizeof(double));
        struct timespec t0, t1;
        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (int it = 0; it < 20; ++it) {
            for (size_t i = 0; i < n; ++i) a[i] = (double)((i * 997U) % n);
            introsort_heap_guard_sort(a, n, NULL);
        }
        clock_gettime(CLOCK_MONOTONIC, &t1);
        double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 20.0;
        printf("introsort_heap_guard n=%zu ns=%.1f\n", n, ns);
        free(a);
    }
    return 0;
}
