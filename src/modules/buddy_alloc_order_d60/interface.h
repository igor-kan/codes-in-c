#ifndef BUDDY_ALLOC_ORDER_D60_INTERFACE_H
#define BUDDY_ALLOC_ORDER_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

void buddy_init_d60(buddy_pool_t* bp);
int buddy_alloc_d60(buddy_pool_t* bp, int order);
void buddy_free_d60(buddy_pool_t* bp, int offset, int order);

buddy_alloc_order_d60_err_t buddy_alloc_order_d60_validate_len(size_t n);
uint64_t buddy_alloc_order_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t buddy_alloc_order_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
buddy_alloc_order_d60_err_t buddy_alloc_order_d60_verify_guard(bool cond);

#endif /* BUDDY_ALLOC_ORDER_D60_INTERFACE_H */
