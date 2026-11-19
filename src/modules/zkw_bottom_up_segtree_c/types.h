#ifndef ZKW_BOTTOM_UP_SEGTREE_C_TYPES_H
#define ZKW_BOTTOM_UP_SEGTREE_C_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define ZKW_BASE 64
typedef struct {
    int64_t t[2 * ZKW_BASE];
} zkw_tree_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} zkw_bottom_up_segtree_c_meta_t;

#endif /* ZKW_BOTTOM_UP_SEGTREE_C_TYPES_H */
