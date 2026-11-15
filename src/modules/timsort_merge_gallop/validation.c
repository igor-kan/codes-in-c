#include "interface.h"

timsort_merge_gallop_err_t timsort_merge_gallop_validate(const int64_t* arr, size_t n) {
    if (n > 0 && !arr) return TIMSORT_MERGE_GALLOP_ERR_NULL;
    return TIMSORT_MERGE_GALLOP_OK;
}
