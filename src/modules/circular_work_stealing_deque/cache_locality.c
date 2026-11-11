/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#define CIRCULAR_WORK_STEALING_DEQUE_CACHE_LINE 64
#define CIRCULAR_WORK_STEALING_DEQUE_TILE_DIM 32

void circular_work_stealing_deque_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += CIRCULAR_WORK_STEALING_DEQUE_TILE_DIM) {
        size_t r_end = (r + CIRCULAR_WORK_STEALING_DEQUE_TILE_DIM < rows) ? r + CIRCULAR_WORK_STEALING_DEQUE_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
