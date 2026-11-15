#include "interface.h"
#include <assert.h>
#include <stdlib.h>

int main(void) {
    int64_t buf[300], copy[300];
    uint32_t rng = 0x55AA3311U;
    for (int t = 0; t < 15; ++t) {
        size_t n = (size_t)(t * 19 + 5);
        int64_t sum_before = 0, sum_after = 0;
        for (size_t i = 0; i < n; ++i) {
            rng = rng * 1664525U + 1013904223U;
            buf[i] = (int64_t)(int32_t)rng;
            copy[i] = buf[i];
            sum_before += buf[i];
        }
        assert(timsort_merge_gallop_sort(buf, n) == TIMSORT_MERGE_GALLOP_OK);
        assert(timsort_merge_gallop_verify_sorted(buf, n) == TIMSORT_MERGE_GALLOP_OK);
        for (size_t i = 0; i < n; ++i) sum_after += buf[i];
        assert(sum_before == sum_after);
        // Reversed input test
        for (size_t i = 0; i < n; ++i) copy[i] = (int64_t)(n - i);
        assert(timsort_merge_gallop_sort_fast(copy, n) == TIMSORT_MERGE_GALLOP_OK);
        assert(timsort_merge_gallop_verify_sorted(copy, n) == TIMSORT_MERGE_GALLOP_OK);
    }
    return 0;
}
