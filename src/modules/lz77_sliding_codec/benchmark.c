#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const size_t sizes[4] = {64, 256, 1024, 2048};
    for (size_t s = 0; s < 4; ++s) {
        size_t n = sizes[s];
        uint8_t* src = (uint8_t*)malloc(n);
        lz77_token_t* toks = (lz77_token_t*)malloc((n + 1) * sizeof(lz77_token_t));
        for (size_t i = 0; i < n; ++i) src[i] = (uint8_t)('A' + (i % 7));
        size_t cnt = 0;
        struct timespec t0, t1;
        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (int it = 0; it < 30; ++it) lz77_sliding_codec_encode_fast(src, n, toks, n + 1, &cnt);
        clock_gettime(CLOCK_MONOTONIC, &t1);
        double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 30.0;
        printf("lz77_sliding_codec n=%zu tokens=%zu ns=%.1f\n", n, cnt, ns);
        free(src); free(toks);
    }
    return 0;
}
