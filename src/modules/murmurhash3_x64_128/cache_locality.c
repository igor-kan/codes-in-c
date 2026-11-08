/**
 * @file cache_locality.c
 * @brief Cache tiling and memory hierarchy optimizations for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#define MURMURHASH3_X64_128_CACHE_LINE_SIZE 64
#define MURMURHASH3_X64_128_L1_TILE_SIZE 32

void murmurhash3_x64_128_cache_tiled_transform(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += MURMURHASH3_X64_128_L1_TILE_SIZE) {
        size_t r_end = (r + MURMURHASH3_X64_128_L1_TILE_SIZE < rows) ? r + MURMURHASH3_X64_128_L1_TILE_SIZE : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.0001;
            }
        }
    }
}
