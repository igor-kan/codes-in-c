#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(floyd_steinberg_dither_d61_validate_len(1) == FLOYD_STEINBERG_DITHER_D61_OK);
    floyd_image_t dims = {8U, 8U, 64U};
    uint8_t gray[64];
    for (size_t i = 0; i < dims.pixels; ++i) gray[i] = 100U;
    uint8_t out[64];
    assert(floyd_steinberg_dither(gray, dims.width, dims.height, out) == dims.pixels);
    size_t whites = 0;
    for (size_t i = 0; i < dims.pixels; ++i) {
        assert(out[i] == 0U || out[i] == 255U);
        if (out[i] == 255U) ++whites;
    }
    assert(whites > 0 && whites < dims.pixels);
    uint8_t black[16];
    memset(black, 0, sizeof(black));
    uint8_t bin[16];
    assert(floyd_steinberg_dither(black, 4U, 4U, bin) == 16U);
    for (size_t i = 0; i < 16U; ++i) assert(bin[i] == 0U);
    assert(floyd_steinberg_quantization_error(black, 16U, bin) == 0U);
    uint8_t white[16];
    memset(white, 255, sizeof(white));
    assert(floyd_steinberg_dither(white, 4U, 4U, bin) == 16U);
    for (size_t i = 0; i < 16U; ++i) assert(bin[i] == 255U);
    assert(floyd_steinberg_quantization_error(white, 16U, bin) == 0U);
    uint8_t tiny[1] = {100U};
    uint8_t tiny_out[1];
    assert(floyd_steinberg_dither(tiny, 1U, 1U, tiny_out) == 1U && tiny_out[0] == 0U);
    tiny[0] = 200U;
    assert(floyd_steinberg_dither(tiny, 1U, 1U, tiny_out) == 1U && tiny_out[0] == 255U);
    assert(floyd_steinberg_dither(NULL, 4U, 4U, bin) == 0U);
    assert(floyd_steinberg_dither(black, 4U, 4U, NULL) == 0U);
    assert(floyd_steinberg_dither(black, 100U, 100U, bin) == 0U);
    assert(floyd_steinberg_dither_d61_verify_guard(true) == FLOYD_STEINBERG_DITHER_D61_OK);
    return 0;
}
