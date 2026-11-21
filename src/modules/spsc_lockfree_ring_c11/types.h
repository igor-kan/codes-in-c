#ifndef SPSC_LOCKFREE_RING_C11_TYPES_H
#define SPSC_LOCKFREE_RING_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t data[16];
    uint32_t head;
    uint32_t tail;
} spsc_ring16_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} spsc_lockfree_ring_c11_meta_t;

#endif /* SPSC_LOCKFREE_RING_C11_TYPES_H */
