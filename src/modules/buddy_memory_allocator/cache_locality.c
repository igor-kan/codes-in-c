/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Power-of-Two Buddy Memory Pool Allocator.
 * Module: buddy_memory_allocator
 */

#define BUDDY_MEMORY_ALLOCATOR_CACHE_LINE 64
#define BUDDY_MEMORY_ALLOCATOR_TILE_DIM 32

void buddy_memory_allocator_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += BUDDY_MEMORY_ALLOCATOR_TILE_DIM) {
        size_t r_end = (r + BUDDY_MEMORY_ALLOCATOR_TILE_DIM < rows) ? r + BUDDY_MEMORY_ALLOCATOR_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
