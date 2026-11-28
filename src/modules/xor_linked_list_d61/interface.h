#ifndef XOR_LINKED_LIST_D61_INTERFACE_H
#define XOR_LINKED_LIST_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void xor_list_init(xor_list_t* l);
size_t xor_list_push_back(xor_list_t* l, int64_t v);
size_t xor_list_forward(const xor_list_t* l, int64_t* out, size_t cap);
size_t xor_list_size(const xor_list_t* l);

xor_linked_list_d61_err_t xor_linked_list_d61_validate_len(size_t n);
uint64_t xor_linked_list_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t xor_linked_list_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
xor_linked_list_d61_err_t xor_linked_list_d61_verify_guard(bool cond);

#endif /* XOR_LINKED_LIST_D61_INTERFACE_H */
