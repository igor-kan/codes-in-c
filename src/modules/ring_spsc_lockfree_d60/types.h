#ifndef RING_SPSC_LOCKFREE_D60_TYPES_H
#define RING_SPSC_LOCKFREE_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SPSC_CAP 64
typedef struct {
    int64_t buf[SPSC_CAP];
    size_t head;
    size_t tail;
} spsc_ring_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} ring_spsc_lockfree_d60_meta_t;

#endif /* RING_SPSC_LOCKFREE_D60_TYPES_H */
