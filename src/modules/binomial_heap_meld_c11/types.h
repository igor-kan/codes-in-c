#ifndef BINOMIAL_HEAP_MELD_C11_TYPES_H
#define BINOMIAL_HEAP_MELD_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int64_t key;
    int32_t child;
    int32_t sibling;
    int32_t deg;
} bnode_t;

typedef struct {
    bnode_t pool[1024];
    int32_t trees[12];
    int32_t used;
    int32_t count;
} binom_heap_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} binomial_heap_meld_c11_meta_t;

#endif /* BINOMIAL_HEAP_MELD_C11_TYPES_H */
