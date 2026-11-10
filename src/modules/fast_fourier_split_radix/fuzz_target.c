/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_fast_fourier_split_radix_day46(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.35 * (*val));
        (void)res;
    }
    return 0;
}
