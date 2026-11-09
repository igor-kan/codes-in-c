/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for 64-Bit Word Compact Bitset with Popcount.
 * Module: compact_bitset
 */

#define COMPACT_BITSET_CACHE_LINE 64
#define COMPACT_BITSET_TILE_DIM 32

void compact_bitset_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += COMPACT_BITSET_TILE_DIM) {
        size_t r_end = (r + COMPACT_BITSET_TILE_DIM < rows) ? r + COMPACT_BITSET_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
