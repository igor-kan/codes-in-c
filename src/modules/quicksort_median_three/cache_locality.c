/**
 * @file cache_locality.c
 * @brief Memory hierarchy alignment and cacheline optimizations for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three
 */

#define QUICKSORT_MEDIAN_THREE_LINE_SZ 64
#define QUICKSORT_MEDIAN_THREE_TILE_SZ 32

void quicksort_median_three_cacheline_blocked_stride(const double* in_data, double* out_data, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += QUICKSORT_MEDIAN_THREE_TILE_SZ) {
        size_t r_max = (r + QUICKSORT_MEDIAN_THREE_TILE_SZ < rows) ? (r + QUICKSORT_MEDIAN_THREE_TILE_SZ) : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_max; ++i) {
                out_data[i * cols + c] = in_data[i * cols + c] * 1.000001;
            }
        }
    }
}
