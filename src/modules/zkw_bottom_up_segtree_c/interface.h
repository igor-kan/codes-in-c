#ifndef ZKW_BOTTOM_UP_SEGTREE_C_INTERFACE_H
#define ZKW_BOTTOM_UP_SEGTREE_C_INTERFACE_H

#include "types.h"
#include "errors.h"

void zkw_init(zkw_tree_t* z);
void zkw_set(zkw_tree_t* z, int idx, int64_t val);
int64_t zkw_sum(const zkw_tree_t* z, int l, int r);

zkw_bottom_up_segtree_c_err_t zkw_bottom_up_segtree_c_validate_len(size_t n);
uint64_t zkw_bottom_up_segtree_c_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t zkw_bottom_up_segtree_c_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
zkw_bottom_up_segtree_c_err_t zkw_bottom_up_segtree_c_verify_guard(bool cond);

#endif /* ZKW_BOTTOM_UP_SEGTREE_C_INTERFACE_H */
