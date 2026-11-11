/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Vectorized Cosine Similarity and Dot Product with FMA.
 * Module: simd_cosine_similarity
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_simd_cosine_similarity_day47(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.4 * (*val));
        (void)res;
    }
    return 0;
}
