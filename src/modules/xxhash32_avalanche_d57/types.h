#ifndef XXHASH32_AVALANCHE_D57_TYPES_H
#define XXHASH32_AVALANCHE_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t seed;
    uint32_t digest;
} xx32_state_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} xxhash32_avalanche_d57_meta_t;

#endif /* XXHASH32_AVALANCHE_D57_TYPES_H */
