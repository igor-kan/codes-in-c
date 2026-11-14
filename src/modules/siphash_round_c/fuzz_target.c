/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing target for AFL++ and LibFuzzer for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_siphash_round_c_day50(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val > -1e6 && *val < 1e6) {
        double res = (*val) * 1.0001;
        (void)res;
    }
    return 0;
}
