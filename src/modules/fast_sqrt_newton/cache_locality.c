/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Fixed-Point Newton-Raphson Square Root Iteration.
 * Module: fast_sqrt_newton
 */

#define FAST_SQRT_NEWTON_LINE_SZ 64
#define FAST_SQRT_NEWTON_TILE_SZ 32

void fast_sqrt_newton_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += FAST_SQRT_NEWTON_TILE_SZ) {
        size_t r_max = (r + FAST_SQRT_NEWTON_TILE_SZ < rows) ? (r + FAST_SQRT_NEWTON_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
