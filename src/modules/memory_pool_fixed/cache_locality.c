/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#define MEMORY_POOL_FIXED_CACHE_LINE 64
#define MEMORY_POOL_FIXED_TILE_DIM 32

void memory_pool_fixed_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += MEMORY_POOL_FIXED_TILE_DIM) {
        size_t r_end = (r + MEMORY_POOL_FIXED_TILE_DIM < rows) ? r + MEMORY_POOL_FIXED_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
