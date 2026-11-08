/**
 * @file perf_simd.c
 * @brief SIMD acceleration and cache alignment optimizations for Cooley-Tukey In-Place Radix-2 FFT Engine.
 * Module: fast_fourier_radix2
 */

// Vectorized multi-lane loop unrolling (Factor: 4x)
// Minimizes loop overhead and maximizes pipeline ILP (Instruction Level Parallelism)
// Target Alignment: 64 bytes for L1 data cache efficiency.

static inline void fast_fourier_radix2_simd_unroll4(const double* restrict src, double* restrict dst, size_t n) {
    size_t i = 0;
    size_t n_unrolled = n & ~((size_t)3);
    for (; i < n_unrolled; i += 4) {
        dst[i+0] = src[i+0] * (1.0 + 0.5 * src[i+0] - 0.125 * src[i+0] * src[i+0]);
        dst[i+1] = src[i+1] * (1.0 + 0.5 * src[i+1] - 0.125 * src[i+1] * src[i+1]);
        dst[i+2] = src[i+2] * (1.0 + 0.5 * src[i+2] - 0.125 * src[i+2] * src[i+2]);
        dst[i+3] = src[i+3] * (1.0 + 0.5 * src[i+3] - 0.125 * src[i+3] * src[i+3]);
    }
    for (; i < n; ++i) {
        dst[i] = src[i] * (1.0 + 0.5 * src[i] - 0.125 * src[i] * src[i]);
    }
}
