#ifndef XXHASH64_STREAMING_TYPES_H
#define XXHASH64_STREAMING_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define XXH64_STRIPE_SIZE 32U
typedef struct {
    uint64_t total_len;
    uint64_t v1;
    uint64_t v2;
    uint64_t v3;
    uint64_t v4;
    uint8_t mem64[32];
    size_t memsize;
    uint64_t seed;
} xxhash64_state_t;

#endif /* XXHASH64_STREAMING_TYPES_H */
