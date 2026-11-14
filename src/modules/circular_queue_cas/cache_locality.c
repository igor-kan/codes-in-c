/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas
 */

#define CIRCULAR_QUEUE_CAS_LINE_SZ 64
#define CIRCULAR_QUEUE_CAS_TILE_SZ 32

void circular_queue_cas_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += CIRCULAR_QUEUE_CAS_TILE_SZ) {
        size_t r_max = (r + CIRCULAR_QUEUE_CAS_TILE_SZ < rows) ? (r + CIRCULAR_QUEUE_CAS_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
