#ifndef SPLAY_TREE_INTRUSIVE_INTERFACE_H
#define SPLAY_TREE_INTRUSIVE_INTERFACE_H

#include "types.h"
#include "errors.h"

void splay_init(splay_tree_t* t);
splay_tree_intrusive_err_t splay_insert(splay_tree_t* t, int64_t key, int64_t val);
bool splay_find(splay_tree_t* t, int64_t key, int64_t* out_val);
bool splay_erase(splay_tree_t* t, int64_t key);
splay_tree_intrusive_err_t splay_validate_tree(const splay_tree_t* t);
int64_t splay_fast_range_sum(splay_tree_t* t, int64_t lo, int64_t hi);
void splay_parallel_queries(const int64_t* keys, size_t n, int64_t* out_sums);
splay_tree_intrusive_err_t splay_verify_bst(const splay_tree_t* t);

#endif /* SPLAY_TREE_INTRUSIVE_INTERFACE_H */
