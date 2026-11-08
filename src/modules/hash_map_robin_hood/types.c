/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Robin Hood Open Addressing Cache-Friendly Hash Table.
 * Module: hash_map_robin_hood
 */

#ifndef HASH_MAP_ROBIN_HOOD_TYPES_H
#define HASH_MAP_ROBIN_HOOD_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HASH_MAP_ROBIN_HOOD_ALIGNMENT 64
#define HASH_MAP_ROBIN_HOOD_SUCCESS 0
#define HASH_MAP_ROBIN_HOOD_ERR_NULL_PTR -1
#define HASH_MAP_ROBIN_HOOD_ERR_INVALID_PARAM -2
#define HASH_MAP_ROBIN_HOOD_ERR_OUT_OF_BOUNDS -3

typedef struct hash_map_robin_hood_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} hash_map_robin_hood_config_t;

typedef struct hash_map_robin_hood_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    hash_map_robin_hood_config_t config;
} hash_map_robin_hood_context_t;

int hash_map_robin_hood_init(hash_map_robin_hood_context_t* ctx, const hash_map_robin_hood_config_t* cfg);
int hash_map_robin_hood_destroy(hash_map_robin_hood_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* HASH_MAP_ROBIN_HOOD_TYPES_H */
