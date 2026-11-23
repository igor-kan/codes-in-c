#ifndef BITMAP_RANK9_SEL_C11_D58_INTERFACE_H
#define BITMAP_RANK9_SEL_C11_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

int word_popcount64(uint64_t x);
int word_rank64(uint64_t w, int pos);
int word_select64(uint64_t w, int k);

bitmap_rank9_sel_c11_d58_err_t bitmap_rank9_sel_c11_d58_validate_len(size_t n);
uint64_t bitmap_rank9_sel_c11_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t bitmap_rank9_sel_c11_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
bitmap_rank9_sel_c11_d58_err_t bitmap_rank9_sel_c11_d58_verify_guard(bool cond);

#endif /* BITMAP_RANK9_SEL_C11_D58_INTERFACE_H */
