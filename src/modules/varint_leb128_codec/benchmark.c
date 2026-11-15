#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    size_t n = 4096;
    uint64_t* vals = (uint64_t*)malloc(n * sizeof(uint64_t));
    uint8_t* enc = (uint8_t*)malloc(n * 10);
    for (size_t i = 0; i < n; ++i) vals[i] = i * 33ULL;
    size_t written = 0, dec_n = 0;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int it = 0; it < 100; ++it) {
        varint_leb128_codec_encode_batch_fast(vals, n, enc, n * 10, &written);
        varint_leb128_codec_decode_batch(enc, written, vals, n, &dec_n);
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 100.0;
    printf("varint_leb128_codec n=%zu bytes=%zu ns=%.1f\n", n, written, ns);
    free(vals); free(enc);
    return 0;
}
