#ifndef CONSISTENT_HASH_RING_C11_TYPES_H
#define CONSISTENT_HASH_RING_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t token;
    int32_t node_id;
} vnode_t;

typedef struct {
    vnode_t ring[256];
    size_t count;
} hash_ring_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} consistent_hash_ring_c11_meta_t;

#endif /* CONSISTENT_HASH_RING_C11_TYPES_H */
