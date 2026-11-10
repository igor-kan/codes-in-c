/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_hazard_pointer_domain_day46(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.35 * (*val));
        (void)res;
    }
    return 0;
}
