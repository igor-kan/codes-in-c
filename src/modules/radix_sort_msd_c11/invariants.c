#include "interface.h"

radix_sort_msd_c11_err_t msd_verify_sorted(const uint32_t* arr, size_t n) {
    if (n > 0 && !arr) return RADIX_SORT_MSD_C11_ERR_NULL;
    for (size_t i = 1; i < n; ++i) {
        if (arr[i - 1] > arr[i]) return RADIX_SORT_MSD_C11_ERR_INVARIANT;
    }
    return RADIX_SORT_MSD_C11_OK;
}
