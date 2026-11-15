#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const size_t sizes[4] = {64, 256, 1024, 4096};
    for (size_t s = 0; s < 4; ++s) {
        size_t n = sizes[s];
        uint8_t* buf = (uint8_t*)malloc(n);
        for (size_t i = 0; i < n; ++i) buf[i] = (uint8_t)(i & 0xFF);
        volatile uint64_t sink = 0;
        struct timespec t0, t1;
        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (int iter = 0; iter < 500; ++iter) {
            sink ^= xxhash64_streaming_oneshot(buf, n, (uint64_t)iter);
        }
        clock_gettime(CLOCK_MONOTONIC, &t1);
        double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 500.0;
        printf("xxhash64_streaming n=%zu ns=%.1f sink=%llu\n", n, ns, (unsigned long long)sink);
        free(buf);
    }
    return 0;
}
