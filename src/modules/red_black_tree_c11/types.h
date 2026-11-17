#ifndef RED_BLACK_TREE_C11_TYPES_H
#define RED_BLACK_TREE_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define LLRB_MAX 512
typedef struct {
    int64_t key;
    int64_t val;
    int32_t left;
    int32_t right;
    bool red;
} llrb_node_t;

typedef struct {
    llrb_node_t nodes[LLRB_MAX];
    int32_t root;
    int32_t cap;
} llrb_tree_t;

#endif /* RED_BLACK_TREE_C11_TYPES_H */
