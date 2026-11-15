#include "interface.h"

introsort_heap_guard_err_t introsort_heap_guard_verify(const double* arr, size_t n) {
    if (n > 0 && !arr) return INTROSORT_HEAP_GUARD_ERR_NULL;
    for (size_t i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) return INTROSORT_HEAP_GUARD_ERR_INVARIANT;
    }
    return INTROSORT_HEAP_GUARD_OK;
}
