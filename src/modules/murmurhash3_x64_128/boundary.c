/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool murmurhash3_x64_128_is_valid_float(double x) {
    return isfinite(x);
}

static inline double murmurhash3_x64_128_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
