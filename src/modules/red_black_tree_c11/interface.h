#ifndef RED_BLACK_TREE_C11_INTERFACE_H
#define RED_BLACK_TREE_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void llrb_init(llrb_tree_t* t);
red_black_tree_c11_err_t llrb_put(llrb_tree_t* t, int64_t key, int64_t val);
bool llrb_get(const llrb_tree_t* t, int64_t key, int64_t* out_val);
red_black_tree_c11_err_t llrb_validate(const llrb_tree_t* t);
int32_t llrb_fast_rank(const llrb_tree_t* t, int64_t key);
int32_t llrb_parallel_count_present(const llrb_tree_t* t, const int64_t* probes, size_t n);
red_black_tree_c11_err_t llrb_verify_properties(const llrb_tree_t* t);

#endif /* RED_BLACK_TREE_C11_INTERFACE_H */
