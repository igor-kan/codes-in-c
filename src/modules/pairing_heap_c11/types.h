#ifndef PAIRING_HEAP_C11_TYPES_H
#define PAIRING_HEAP_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define PH_MAX_NODES 1024
typedef struct {
    int64_t key;
    int32_t value;
    int32_t child;
    int32_t sibling;
    int32_t prev;
    bool active;
} ph_node_t;

typedef struct {
    ph_node_t nodes[PH_MAX_NODES];
    int32_t size;
    int32_t cap;
    int32_t root;
} pairing_heap_t;

#endif /* PAIRING_HEAP_C11_TYPES_H */
