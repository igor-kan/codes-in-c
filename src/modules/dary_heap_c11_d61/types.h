#ifndef DARY_HEAP_C11_D61_TYPES_H
#define DARY_HEAP_C11_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define DARY_HEAP_CAP 256
typedef struct {
    int64_t data[DARY_HEAP_CAP];
    size_t size;
} dary_heap_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} dary_heap_c11_d61_meta_t;

#endif /* DARY_HEAP_C11_D61_TYPES_H */
