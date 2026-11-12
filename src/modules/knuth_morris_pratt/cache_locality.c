/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt
 */

#define KNUTH_MORRIS_PRATT_CACHELINE_SIZE 64
#define KNUTH_MORRIS_PRATT_BLOCK_SIZE 32

void knuth_morris_pratt_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += KNUTH_MORRIS_PRATT_BLOCK_SIZE) {
        size_t bi_end = (bi + KNUTH_MORRIS_PRATT_BLOCK_SIZE < n) ? (bi + KNUTH_MORRIS_PRATT_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += KNUTH_MORRIS_PRATT_BLOCK_SIZE) {
            size_t bj_end = (bj + KNUTH_MORRIS_PRATT_BLOCK_SIZE < n) ? (bj + KNUTH_MORRIS_PRATT_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
