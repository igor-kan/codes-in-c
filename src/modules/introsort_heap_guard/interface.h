#ifndef INTROSORT_HEAP_GUARD_INTERFACE_H
#define INTROSORT_HEAP_GUARD_INTERFACE_H

#include "types.h"
#include "errors.h"

introsort_heap_guard_err_t introsort_heap_guard_sort(double* arr, size_t n, introsort_metrics_t* m);
introsort_heap_guard_err_t introsort_heap_guard_validate(const double* arr, size_t n);
void introsort_heap_guard_heapsort(double* arr, size_t lo, size_t hi);
introsort_heap_guard_err_t introsort_heap_guard_batch(double** ptrs, const size_t* lens, size_t k);
introsort_heap_guard_err_t introsort_heap_guard_verify(const double* arr, size_t n);

#endif /* INTROSORT_HEAP_GUARD_INTERFACE_H */
