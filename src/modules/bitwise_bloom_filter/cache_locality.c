/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter
 */

#define BITWISE_BLOOM_FILTER_LINE_SZ 64
#define BITWISE_BLOOM_FILTER_TILE_SZ 32

void bitwise_bloom_filter_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += BITWISE_BLOOM_FILTER_TILE_SZ) {
        size_t r_max = (r + BITWISE_BLOOM_FILTER_TILE_SZ < rows) ? (r + BITWISE_BLOOM_FILTER_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
