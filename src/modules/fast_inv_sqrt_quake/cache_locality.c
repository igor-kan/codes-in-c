/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

#define FAST_INV_SQRT_QUAKE_LINE_SZ 64
#define FAST_INV_SQRT_QUAKE_TILE_SZ 32

void fast_inv_sqrt_quake_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += FAST_INV_SQRT_QUAKE_TILE_SZ) {
        size_t r_max = (r + FAST_INV_SQRT_QUAKE_TILE_SZ < rows) ? (r + FAST_INV_SQRT_QUAKE_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
