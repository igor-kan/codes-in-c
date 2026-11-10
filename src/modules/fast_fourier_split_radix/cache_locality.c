/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#define FAST_FOURIER_SPLIT_RADIX_CACHE_LINE 64
#define FAST_FOURIER_SPLIT_RADIX_TILE_DIM 32

void fast_fourier_split_radix_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += FAST_FOURIER_SPLIT_RADIX_TILE_DIM) {
        size_t r_end = (r + FAST_FOURIER_SPLIT_RADIX_TILE_DIM < rows) ? r + FAST_FOURIER_SPLIT_RADIX_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
