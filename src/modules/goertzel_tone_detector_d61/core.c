#include "interface.h"
#include <math.h>
#include <string.h>

static const double goertzel_two_pi = 6.283185307179586476925286766559;

goertzel_complex_t goertzel_single_bin(const double* samples, size_t n, uint32_t k) {
    goertzel_complex_t out;
    out.real = 0.0;
    out.imag = 0.0;
    if (samples == NULL || n == 0) return out;
    double omega = goertzel_two_pi * (double)k / (double)n;
    double coeff = 2.0 * cos(omega);
    double prev = 0.0;
    double prev2 = 0.0;
    for (size_t i = 0; i < n; ++i) {
        double s = samples[i] + coeff * prev - prev2;
        prev2 = prev;
        prev = s;
    }
    out.real = prev - prev2 * cos(omega);
    out.imag = prev2 * sin(omega);
    return out;
}
double goertzel_bin_power(const double* samples, size_t n, uint32_t k) {
    goertzel_complex_t c = goertzel_single_bin(samples, n, k);
    return c.real * c.real + c.imag * c.imag;
}
size_t goertzel_dominant_bin(const double* samples, size_t n, size_t max_bin) {
    if (samples == NULL || n == 0 || max_bin == 0) return 0;
    size_t nyquist_limit = n / 2U + 1U;
    size_t limit = max_bin < nyquist_limit ? max_bin : nyquist_limit;
    size_t best = 0;
    double best_power = -1.0;
    for (size_t b = 0; b < limit; ++b) {
        double power = goertzel_bin_power(samples, n, (uint32_t)b);
        if (power > best_power) {
            best_power = power;
            best = b;
        }
    }
    return best;
}
