#include "interface.h"
#include <math.h>
#include <string.h>

size_t floyd_steinberg_dither(const uint8_t* gray, size_t width, size_t height, uint8_t* out) {
    if (gray == NULL || out == NULL || width == 0 || height == 0) return 0;
    if (width > (size_t)FLOYD_MAX_PIXELS) return 0;
    if (height > (size_t)FLOYD_MAX_PIXELS / width) return 0;
    size_t n = width * height;
    int32_t err[FLOYD_MAX_PIXELS];
    memset(err, 0, n * sizeof(int32_t));
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            size_t idx = y * width + x;
            int32_t v = (int32_t)gray[idx] + err[idx];
            if (v < 0) v = 0;
            if (v > 255) v = 255;
            uint8_t q = (v < 128) ? (uint8_t)0 : (uint8_t)255;
            out[idx] = q;
            int32_t e = v - (int32_t)q;
            if (x + 1 < width) err[idx + 1] += (e * 7) / 16;
            if (y + 1 < height) {
                size_t below = idx + width;
                if (x > 0) err[below - 1] += (e * 3) / 16;
                err[below] += (e * 5) / 16;
                if (x + 1 < width) err[below + 1] += e / 16;
            }
        }
    }
    return n;
}
uint64_t floyd_steinberg_quantization_error(const uint8_t* gray, size_t n, const uint8_t* out) {
    if (gray == NULL || out == NULL) return 0;
    uint64_t acc = 0;
    for (size_t i = 0; i < n; ++i) {
        int32_t diff = (int32_t)gray[i] - (int32_t)out[i];
        if (diff < 0) diff = -diff;
        acc += (uint64_t)diff;
    }
    return acc;
}
