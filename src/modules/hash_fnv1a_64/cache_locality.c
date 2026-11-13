/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#define HASH_FNV1A_64_LINE_SZ 64
#define HASH_FNV1A_64_TILE_SZ 32

void hash_fnv1a_64_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += HASH_FNV1A_64_TILE_SZ) {
        size_t r_max = (r + HASH_FNV1A_64_TILE_SZ < rows) ? (r + HASH_FNV1A_64_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
