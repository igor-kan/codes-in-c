/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Sequential Lock for High-Frequency Concurrent Reads.
 * Module: atomic_seqlock
 */

#define ATOMIC_SEQLOCK_CACHE_LINE 64
#define ATOMIC_SEQLOCK_TILE_DIM 32

void atomic_seqlock_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += ATOMIC_SEQLOCK_TILE_DIM) {
        size_t r_end = (r + ATOMIC_SEQLOCK_TILE_DIM < rows) ? r + ATOMIC_SEQLOCK_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
