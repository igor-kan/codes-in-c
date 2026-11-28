#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(goertzel_tone_detector_d61_validate_len(1) == GOERTZEL_TONE_DETECTOR_D61_OK);
    const double pi = 3.14159265358979323846;
    double sig[64];
    for (size_t i = 0; i < 64; ++i) {
        sig[i] = cos(2.0 * pi * 5.0 * (double)i / 64.0);
    }
    double p5 = goertzel_bin_power(sig, 64, 5);
    assert(p5 > 900.0 && p5 < 1100.0);
    goertzel_complex_t c = goertzel_single_bin(sig, 64, 5);
    assert(fabs(c.real) > 1.0);
    assert(goertzel_dominant_bin(sig, 64, 64) == 5);
    double dc[16];
    for (size_t i = 0; i < 16; ++i) dc[i] = 1.0;
    assert(goertzel_dominant_bin(dc, 16, 16) == 0);
    assert(goertzel_bin_power(dc, 16, 0) > 255.0);
    assert(fabs(goertzel_single_bin(dc, 16, 0).imag) < 1e-9);
    assert(goertzel_tone_detector_d61_verify_guard(true) == GOERTZEL_TONE_DETECTOR_D61_OK);
    return 0;
}
