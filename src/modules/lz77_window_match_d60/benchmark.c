#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint8_t src[16] = {1,2,3,1,2,3,1,2,3,4,1,2,3,4,5,6};
    lz77_tok_t toks[16];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        size_t nt = lz77_encode_d60(src, 16, toks, 16);
    sink = sink + (int64_t)nt;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("lz77_window_match_d60 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
