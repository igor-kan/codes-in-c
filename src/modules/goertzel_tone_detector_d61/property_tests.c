#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(goertzel_tone_detector_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    double x[32];
    for (size_t i = 0; i < 32; ++i) {
        x[i] = (double)((int)((i * 37U + 11U) % 21U) - 10) / 7.0;
    }
    double energy = 0.0;
    for (size_t i = 0; i < 32; ++i) energy += x[i] * x[i];
    double spectral = 0.0;
    for (uint32_t k = 0; k < 32U; ++k) spectral += goertzel_bin_power(x, 32, k);
    assert(fabs(spectral - 32.0 * energy) < 1e-6 * (1.0 + spectral));
    for (uint32_t k = 1; k < 32U; ++k) {
        double left = goertzel_bin_power(x, 32, k);
        double right = goertzel_bin_power(x, 32, 32U - k);
        assert(fabs(left - right) < 1e-6 * (1.0 + left + right));
    }
    return 0;
}
