#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint8_t b_raw[3] = {'a','b','c'};
    uint8_t b_enc[8];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += (uint64_t)b64_encode(b_raw, 3, b_enc);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("base64_rfc4648_c11_d57 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
