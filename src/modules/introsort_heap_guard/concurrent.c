#include "interface.h"

introsort_heap_guard_err_t introsort_heap_guard_batch(double** ptrs, const size_t* lens, size_t k) {
    if (!ptrs || !lens) return INTROSORT_HEAP_GUARD_ERR_NULL;
    for (size_t i = 0; i < k; ++i) {
        introsort_heap_guard_err_t e = introsort_heap_guard_sort(ptrs[i], lens[i], NULL);
        if (e != INTROSORT_HEAP_GUARD_OK) return e;
    }
    return INTROSORT_HEAP_GUARD_OK;
}
