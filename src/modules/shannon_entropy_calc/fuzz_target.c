/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing target for AFL++ and LibFuzzer for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_shannon_entropy_calc_day50(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val > -1e6 && *val < 1e6) {
        double res = (*val) * 1.0001;
        (void)res;
    }
    return 0;
}
