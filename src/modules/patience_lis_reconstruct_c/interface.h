#ifndef PATIENCE_LIS_RECONSTRUCT_C_INTERFACE_H
#define PATIENCE_LIS_RECONSTRUCT_C_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t patience_lis(const int64_t* arr, size_t n, lis_result_t* out);

patience_lis_reconstruct_c_err_t patience_lis_reconstruct_c_validate_len(size_t n);
uint64_t patience_lis_reconstruct_c_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t patience_lis_reconstruct_c_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
patience_lis_reconstruct_c_err_t patience_lis_reconstruct_c_verify_guard(bool cond);

#endif /* PATIENCE_LIS_RECONSTRUCT_C_INTERFACE_H */
