/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Vectorized Cosine Similarity and Dot Product with FMA.
 * Module: simd_cosine_similarity
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool simd_cosine_similarity_is_valid_float(double x) {
    return isfinite(x);
}

static inline double simd_cosine_similarity_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
