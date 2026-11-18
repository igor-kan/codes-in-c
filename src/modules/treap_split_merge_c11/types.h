#ifndef TREAP_SPLIT_MERGE_C11_TYPES_H
#define TREAP_SPLIT_MERGE_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int64_t val;
    int64_t sum;
    uint32_t prio;
    int32_t sz;
    int32_t l;
    int32_t r;
} treap_node_c_t;

typedef struct {
    treap_node_c_t pool[256];
    int32_t used;
    int32_t root;
} treap_arena_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} treap_split_merge_c11_meta_t;

#endif /* TREAP_SPLIT_MERGE_C11_TYPES_H */
