#include "interface.h"
#include <math.h>

introsort_heap_guard_err_t introsort_heap_guard_validate(const double* arr, size_t n) {
    if (n > 0 && !arr) return INTROSORT_HEAP_GUARD_ERR_NULL;
    for (size_t i = 0; i < n; ++i) {
        if (isnan(arr[i])) return INTROSORT_HEAP_GUARD_ERR_INVALID;
    }
    return INTROSORT_HEAP_GUARD_OK;
}
