/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#define SHANNON_ENTROPY_CALC_LINE_SZ 64
#define SHANNON_ENTROPY_CALC_TILE_SZ 32

void shannon_entropy_calc_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += SHANNON_ENTROPY_CALC_TILE_SZ) {
        size_t r_max = (r + SHANNON_ENTROPY_CALC_TILE_SZ < rows) ? (r + SHANNON_ENTROPY_CALC_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
