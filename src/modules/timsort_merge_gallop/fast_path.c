#include "interface.h"

timsort_merge_gallop_err_t timsort_merge_gallop_sort_fast(int64_t* arr, size_t n) {
    return timsort_merge_gallop_sort(arr, n);
}
