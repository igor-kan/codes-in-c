#ifndef DARY_HEAP_C11_D61_INTERFACE_H
#define DARY_HEAP_C11_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void dary_heap_init(dary_heap_t* h);
bool dary_heap_push(dary_heap_t* h, int64_t v);
bool dary_heap_pop(dary_heap_t* h, int64_t* out);
bool dary_heap_peek(const dary_heap_t* h, int64_t* out);

dary_heap_c11_d61_err_t dary_heap_c11_d61_validate_len(size_t n);
uint64_t dary_heap_c11_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t dary_heap_c11_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
dary_heap_c11_d61_err_t dary_heap_c11_d61_verify_guard(bool cond);

#endif /* DARY_HEAP_C11_D61_INTERFACE_H */
