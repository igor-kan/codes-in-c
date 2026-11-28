#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    floyd_image_t dims = {16U, 16U, 256U};
    uint8_t image[256];
    uint8_t output[256];
    for (size_t i = 0; i < dims.pixels; ++i) image[i] = (uint8_t)((i * 37U) % 256U);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink = sink + (int64_t)floyd_steinberg_dither(image, dims.width, dims.height, output);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("floyd_steinberg_dither_d61 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
