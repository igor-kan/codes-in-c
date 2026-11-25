#ifndef BUDDY_ALLOC_ORDER_D60_TYPES_H
#define BUDDY_ALLOC_ORDER_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BUDDY_MAX_ORDER 4
#define BUDDY_LEAVES (1U << BUDDY_MAX_ORDER)
typedef struct {
    uint8_t used[1U << (BUDDY_MAX_ORDER + 1)];
} buddy_pool_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} buddy_alloc_order_d60_meta_t;

#endif /* BUDDY_ALLOC_ORDER_D60_TYPES_H */
