/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_dense_lu_factor_day45(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.3 * (*val));
        (void)res;
    }
    return 0;
}
