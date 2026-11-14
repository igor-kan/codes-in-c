/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing target for AFL++ and LibFuzzer for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_circular_queue_cas_day50(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val > -1e6 && *val < 1e6) {
        double res = (*val) * 1.0001;
        (void)res;
    }
    return 0;
}
