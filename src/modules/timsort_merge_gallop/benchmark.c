#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const size_t sizes[4] = {64, 256, 1024, 4096};
    for (size_t s = 0; s < 4; ++s) {
        size_t n = sizes[s];
        int64_t* arr = (int64_t*)malloc(n * sizeof(int64_t));
        struct timespec t0, t1;
        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (int it = 0; it < 20; ++it) {
            for (size_t i = 0; i < n; ++i) arr[i] = (int64_t)((i * 2654435761U) & 0xFFFFU);
            timsort_merge_gallop_sort(arr, n);
        }
        clock_gettime(CLOCK_MONOTONIC, &t1);
        double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 20.0;
        printf("timsort_merge_gallop n=%zu ns=%.1f\n", n, ns);
        free(arr);
    }
    return 0;
}
