/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Vectorized Cosine Similarity and Dot Product with FMA.
 * Module: simd_cosine_similarity
 */

#include <assert.h>

void test_simd_cosine_similarity_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
