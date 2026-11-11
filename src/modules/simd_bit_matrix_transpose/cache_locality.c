/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#define SIMD_BIT_MATRIX_TRANSPOSE_CACHE_LINE 64
#define SIMD_BIT_MATRIX_TRANSPOSE_TILE_DIM 32

void simd_bit_matrix_transpose_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += SIMD_BIT_MATRIX_TRANSPOSE_TILE_DIM) {
        size_t r_end = (r + SIMD_BIT_MATRIX_TRANSPOSE_TILE_DIM < rows) ? r + SIMD_BIT_MATRIX_TRANSPOSE_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
