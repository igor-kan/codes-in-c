#ifndef BINOMIAL_HEAP_MELD_C11_INTERFACE_H
#define BINOMIAL_HEAP_MELD_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void bh_init(binom_heap_t* h);
void bh_push(binom_heap_t* h, int64_t key);
int64_t bh_pop_min(binom_heap_t* h);

binomial_heap_meld_c11_err_t binomial_heap_meld_c11_validate_len(size_t n);
uint64_t binomial_heap_meld_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t binomial_heap_meld_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
binomial_heap_meld_c11_err_t binomial_heap_meld_c11_verify_guard(bool cond);

#endif /* BINOMIAL_HEAP_MELD_C11_INTERFACE_H */
