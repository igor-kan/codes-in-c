#ifndef TIMSORT_MERGE_GALLOP_INTERFACE_H
#define TIMSORT_MERGE_GALLOP_INTERFACE_H

#include "types.h"
#include "errors.h"

timsort_merge_gallop_err_t timsort_merge_gallop_sort(int64_t* arr, size_t n);
size_t timsort_merge_gallop_right(int64_t key, const int64_t* a, size_t len);
timsort_merge_gallop_err_t timsort_merge_gallop_validate(const int64_t* arr, size_t n);
timsort_merge_gallop_err_t timsort_merge_gallop_sort_fast(int64_t* arr, size_t n);
timsort_merge_gallop_err_t timsort_merge_gallop_batch_mt(int64_t** arrays, const size_t* lens, size_t k);
timsort_merge_gallop_err_t timsort_merge_gallop_verify_sorted(const int64_t* arr, size_t n);

#endif /* TIMSORT_MERGE_GALLOP_INTERFACE_H */
