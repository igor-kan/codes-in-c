/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#define LOCKFREE_ORDERED_LIST_CACHE_LINE 64
#define LOCKFREE_ORDERED_LIST_TILE_DIM 32

void lockfree_ordered_list_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += LOCKFREE_ORDERED_LIST_TILE_DIM) {
        size_t r_end = (r + LOCKFREE_ORDERED_LIST_TILE_DIM < rows) ? r + LOCKFREE_ORDERED_LIST_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
