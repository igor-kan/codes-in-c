#ifndef FENWICK_ORDER_STAT_C11_TYPES_H
#define FENWICK_ORDER_STAT_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define OS_MAX 64
typedef struct {
    int64_t bit[OS_MAX + 1];
    int n;
} os_fenwick_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} fenwick_order_stat_c11_meta_t;

#endif /* FENWICK_ORDER_STAT_C11_TYPES_H */
