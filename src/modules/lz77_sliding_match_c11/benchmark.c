#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint8_t b_src[8] = {'a','b','a','b','a','b','c','d'};
    lz77_token_t b_tok[8];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (uint64_t)lz77_compress(b_src, 8, 4, b_tok, 8);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("lz77_sliding_match_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
