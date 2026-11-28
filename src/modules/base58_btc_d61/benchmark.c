#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint8_t payload[16];
    for (size_t i = 0; i < 16; ++i) payload[i] = (uint8_t)(i * 13 + 7);
    base58_string_t enc;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        if (base58_encode(payload, 16, &enc) > 0) sink = sink + (int64_t)enc.length;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("base58_btc_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
