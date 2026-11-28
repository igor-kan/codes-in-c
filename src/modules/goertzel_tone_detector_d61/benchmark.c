#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    double signal[64];
    for (size_t i = 0; i < 64; ++i) signal[i] = (double)((i * 37U) % 64U) - 32.0;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink = sink + (int64_t)goertzel_dominant_bin(signal, 64, 64);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("goertzel_tone_detector_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
