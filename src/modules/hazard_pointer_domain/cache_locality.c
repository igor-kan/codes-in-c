/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#define HAZARD_POINTER_DOMAIN_CACHE_LINE 64
#define HAZARD_POINTER_DOMAIN_TILE_DIM 32

void hazard_pointer_domain_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += HAZARD_POINTER_DOMAIN_TILE_DIM) {
        size_t r_end = (r + HAZARD_POINTER_DOMAIN_TILE_DIM < rows) ? r + HAZARD_POINTER_DOMAIN_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00003;
            }
        }
    }
}
