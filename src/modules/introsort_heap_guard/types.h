#ifndef INTROSORT_HEAP_GUARD_TYPES_H
#define INTROSORT_HEAP_GUARD_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define INTRO_INSERT_THRESH 16U
typedef struct {
    size_t comparisons;
    size_t swaps;
    uint32_t heap_fallbacks;
} introsort_metrics_t;

#endif /* INTROSORT_HEAP_GUARD_TYPES_H */
