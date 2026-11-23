#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint8_t b_s[8] = {'a','b','c','a','b','c','d','e'}; lzss_op_t b_o[8];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (uint64_t)lzss_compress(b_s, 8, b_o);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("lzss_flag_codec_c11_d58 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
