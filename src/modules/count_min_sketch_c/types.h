#ifndef COUNT_MIN_SKETCH_C_TYPES_H
#define COUNT_MIN_SKETCH_C_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t depth;
    size_t width;
    uint64_t* table;
    uint64_t total_weight;
} cms_sketch_t;

#endif /* COUNT_MIN_SKETCH_C_TYPES_H */
