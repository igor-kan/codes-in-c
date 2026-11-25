#ifndef ROBIN_HOOD_HASH_D60_TYPES_H
#define ROBIN_HOOD_HASH_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RH_CAP 64
typedef struct {
    uint64_t keys[RH_CAP];
    int64_t vals[RH_CAP];
    uint8_t used[RH_CAP];
    size_t count;
} rh_map_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} robin_hood_hash_d60_meta_t;

#endif /* ROBIN_HOOD_HASH_D60_TYPES_H */
