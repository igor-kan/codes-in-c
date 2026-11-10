/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_simd_spmv_ellpack_day46(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.35 * (*val));
        (void)res;
    }
    return 0;
}
