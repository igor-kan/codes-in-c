/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random
 */

#define PCG64_RANDOM_CACHELINE_SIZE 64
#define PCG64_RANDOM_BLOCK_SIZE 32

void pcg64_random_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += PCG64_RANDOM_BLOCK_SIZE) {
        size_t bi_end = (bi + PCG64_RANDOM_BLOCK_SIZE < n) ? (bi + PCG64_RANDOM_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += PCG64_RANDOM_BLOCK_SIZE) {
            size_t bj_end = (bj + PCG64_RANDOM_BLOCK_SIZE < n) ? (bj + PCG64_RANDOM_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
