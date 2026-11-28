#ifndef SHELL_SORT_CIURA_D61_INTERFACE_H
#define SHELL_SORT_CIURA_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void shell_sort_ciura(int64_t* a, size_t n);

shell_sort_ciura_d61_err_t shell_sort_ciura_d61_validate_len(size_t n);
uint64_t shell_sort_ciura_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t shell_sort_ciura_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
shell_sort_ciura_d61_err_t shell_sort_ciura_d61_verify_guard(bool cond);

#endif /* SHELL_SORT_CIURA_D61_INTERFACE_H */
