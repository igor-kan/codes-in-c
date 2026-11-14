/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for Diagonal (DIA) Sparse Matrix-Vector Multiply for Banded.
 * Module: spmv_dia_format
 */

#define SPMV_DIA_FORMAT_LINE_SZ 64
#define SPMV_DIA_FORMAT_TILE_SZ 32

void spmv_dia_format_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += SPMV_DIA_FORMAT_TILE_SZ) {
        size_t r_max = (r + SPMV_DIA_FORMAT_TILE_SZ < rows) ? (r + SPMV_DIA_FORMAT_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
