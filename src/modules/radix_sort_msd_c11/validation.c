#include "interface.h"

radix_sort_msd_c11_err_t msd_validate_slice(const uint32_t* arr, size_t n) {
    if (n > 0 && !arr) return RADIX_SORT_MSD_C11_ERR_NULL;
    return RADIX_SORT_MSD_C11_OK;
}
