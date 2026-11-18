#ifndef DISJOINT_SPARSE_TABLE_C_INTERFACE_H
#define DISJOINT_SPARSE_TABLE_C_INTERFACE_H

#include "types.h"
#include "errors.h"

void dst_build(dst_sum_t* d, const int64_t* arr, int32_t n);
int64_t dst_query(const dst_sum_t* d, int32_t l, int32_t r);

disjoint_sparse_table_c_err_t disjoint_sparse_table_c_validate_len(size_t n);
uint64_t disjoint_sparse_table_c_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t disjoint_sparse_table_c_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
disjoint_sparse_table_c_err_t disjoint_sparse_table_c_verify_guard(bool cond);

#endif /* DISJOINT_SPARSE_TABLE_C_INTERFACE_H */
