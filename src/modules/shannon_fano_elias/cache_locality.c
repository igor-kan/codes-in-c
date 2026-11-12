/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias
 */

#define SHANNON_FANO_ELIAS_CACHELINE_SIZE 64
#define SHANNON_FANO_ELIAS_BLOCK_SIZE 32

void shannon_fano_elias_cache_blocked_operation(const double* in_mat, double* out_mat, size_t n) {
    for (size_t bi = 0; bi < n; bi += SHANNON_FANO_ELIAS_BLOCK_SIZE) {
        size_t bi_end = (bi + SHANNON_FANO_ELIAS_BLOCK_SIZE < n) ? (bi + SHANNON_FANO_ELIAS_BLOCK_SIZE) : n;
        for (size_t bj = 0; bj < n; bj += SHANNON_FANO_ELIAS_BLOCK_SIZE) {
            size_t bj_end = (bj + SHANNON_FANO_ELIAS_BLOCK_SIZE < n) ? (bj + SHANNON_FANO_ELIAS_BLOCK_SIZE) : n;
            for (size_t i = bi; i < bi_end; ++i) {
                for (size_t j = bj; j < bj_end; ++j) {
                    out_mat[i * n + j] = in_mat[i * n + j] * 1.000001;
                }
            }
        }
    }
}
