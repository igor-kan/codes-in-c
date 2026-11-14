/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c
 */

#define SIPHASH_ROUND_C_LINE_SZ 64
#define SIPHASH_ROUND_C_TILE_SZ 32

void siphash_round_c_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += SIPHASH_ROUND_C_TILE_SZ) {
        size_t r_max = (r + SIPHASH_ROUND_C_TILE_SZ < rows) ? (r + SIPHASH_ROUND_C_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
