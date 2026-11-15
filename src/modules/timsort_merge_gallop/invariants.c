#include "interface.h"

timsort_merge_gallop_err_t timsort_merge_gallop_verify_sorted(const int64_t* arr, size_t n) {
    if (n > 0 && !arr) return TIMSORT_MERGE_GALLOP_ERR_NULL;
    for (size_t i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) return TIMSORT_MERGE_GALLOP_ERR_INVARIANT;
    }
    return TIMSORT_MERGE_GALLOP_OK;
}
