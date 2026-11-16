#ifndef RESERVOIR_SAMPLING_VITTER_TYPES_H
#define RESERVOIR_SAMPLING_VITTER_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int64_t* items;
    size_t capacity;
    size_t filled;
    uint64_t seen;
    uint64_t rng_state;
} reservoir_t;

#endif /* RESERVOIR_SAMPLING_VITTER_TYPES_H */
