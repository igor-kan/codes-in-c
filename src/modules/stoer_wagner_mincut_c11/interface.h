#ifndef STOER_WAGNER_MINCUT_C11_INTERFACE_H
#define STOER_WAGNER_MINCUT_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

int64_t sw_mincut_c(int n, const int64_t adj[16][16]);

stoer_wagner_mincut_c11_err_t stoer_wagner_mincut_c11_validate_len(size_t n);
uint64_t stoer_wagner_mincut_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t stoer_wagner_mincut_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
stoer_wagner_mincut_c11_err_t stoer_wagner_mincut_c11_verify_guard(bool cond);

#endif /* STOER_WAGNER_MINCUT_C11_INTERFACE_H */
