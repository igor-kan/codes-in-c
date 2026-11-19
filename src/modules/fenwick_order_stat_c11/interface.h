#ifndef FENWICK_ORDER_STAT_C11_INTERFACE_H
#define FENWICK_ORDER_STAT_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void os_init(os_fenwick_t* f, int n);
void os_add(os_fenwick_t* f, int idx, int64_t delta);
int os_kth(const os_fenwick_t* f, int64_t k);

fenwick_order_stat_c11_err_t fenwick_order_stat_c11_validate_len(size_t n);
uint64_t fenwick_order_stat_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t fenwick_order_stat_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
fenwick_order_stat_c11_err_t fenwick_order_stat_c11_verify_guard(bool cond);

#endif /* FENWICK_ORDER_STAT_C11_INTERFACE_H */
