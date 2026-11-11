/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

#define JEMALLOC_RUN_CACHE_CACHE_LINE 64
#define JEMALLOC_RUN_CACHE_TILE_DIM 32

void jemalloc_run_cache_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += JEMALLOC_RUN_CACHE_TILE_DIM) {
        size_t r_end = (r + JEMALLOC_RUN_CACHE_TILE_DIM < rows) ? r + JEMALLOC_RUN_CACHE_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
