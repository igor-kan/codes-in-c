#ifndef SKIP_LIST_PROBABILISTIC_TYPES_H
#define SKIP_LIST_PROBABILISTIC_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SKIPLIST_MAX_LEVEL 16
typedef struct sl_node {
    int64_t key;
    int64_t value;
    int level;
    struct sl_node* next[SKIPLIST_MAX_LEVEL];
} sl_node_t;

typedef struct {
    sl_node_t* head;
    int max_level;
    size_t count;
    uint32_t rng;
} skiplist_t;

#endif /* SKIP_LIST_PROBABILISTIC_TYPES_H */
