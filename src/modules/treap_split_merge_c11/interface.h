#ifndef TREAP_SPLIT_MERGE_C11_INTERFACE_H
#define TREAP_SPLIT_MERGE_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void treap_c_init(treap_arena_t* t);
int32_t treap_c_new(treap_arena_t* t, int64_t val, uint32_t prio);
void treap_c_split(treap_arena_t* t, int32_t u, int32_t k, int32_t* out_l, int32_t* out_r);
int32_t treap_c_merge(treap_arena_t* t, int32_t a, int32_t b);

treap_split_merge_c11_err_t treap_split_merge_c11_validate_len(size_t n);
uint64_t treap_split_merge_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t treap_split_merge_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
treap_split_merge_c11_err_t treap_split_merge_c11_verify_guard(bool cond);

#endif /* TREAP_SPLIT_MERGE_C11_INTERFACE_H */
