#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(floyd_steinberg_dither_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    floyd_image_t dims = {16U, 16U, 256U};
    uint8_t grad[256];
    uint8_t out[256];
    uint8_t out_repeat[256];
    for (size_t i = 0; i < dims.pixels; ++i) grad[i] = (uint8_t)(i % 256U);
    assert(floyd_steinberg_dither(grad, dims.width, dims.height, out) == dims.pixels);
    assert(floyd_steinberg_dither(grad, dims.width, dims.height, out_repeat) == dims.pixels);
    assert(memcmp(out, out_repeat, dims.pixels) == 0);
    double sum_in = 0.0;
    double sum_out = 0.0;
    for (size_t i = 0; i < dims.pixels; ++i) {
        assert(out[i] == 0U || out[i] == 255U);
        sum_in += (double)grad[i];
        sum_out += (double)out[i];
    }
    double mean_in = sum_in / (double)dims.pixels;
    double mean_out = sum_out / (double)dims.pixels;
    assert(fabs(mean_in - mean_out) < 8.0);
    uint8_t checker[256];
    uint8_t checker_out[256];
    for (size_t i = 0; i < dims.pixels; ++i) {
        size_t row = i / dims.width;
        size_t col = i % dims.width;
        checker[i] = ((row + col) % 2U == 0U) ? (uint8_t)0 : (uint8_t)255;
    }
    assert(floyd_steinberg_dither(checker, dims.width, dims.height, checker_out) == dims.pixels);
    assert(memcmp(checker, checker_out, dims.pixels) == 0);
    assert(floyd_steinberg_quantization_error(checker, dims.pixels, checker_out) == 0U);
    return 0;
}
