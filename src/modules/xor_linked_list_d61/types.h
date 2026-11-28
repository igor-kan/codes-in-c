#ifndef XOR_LINKED_LIST_D61_TYPES_H
#define XOR_LINKED_LIST_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define XOR_LIST_CAP 64
typedef struct {
    int64_t val;
    uintptr_t both;
} xor_node_t;

typedef struct {
    xor_node_t pool[XOR_LIST_CAP];
    size_t used;
    uintptr_t head;
    uintptr_t tail;
} xor_list_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} xor_linked_list_d61_meta_t;

#endif /* XOR_LINKED_LIST_D61_TYPES_H */
