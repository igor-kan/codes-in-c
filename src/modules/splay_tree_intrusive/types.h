#ifndef SPLAY_TREE_INTRUSIVE_TYPES_H
#define SPLAY_TREE_INTRUSIVE_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SPLAY_MAX 512
typedef struct {
    int64_t key;
    int64_t val;
    int32_t ch[2];
    int32_t parent;
    bool active;
} splay_node_t;

typedef struct {
    splay_node_t nodes[SPLAY_MAX];
    int32_t root;
    int32_t cap;
    int32_t count;
} splay_tree_t;

#endif /* SPLAY_TREE_INTRUSIVE_TYPES_H */
