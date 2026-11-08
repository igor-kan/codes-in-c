/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for 64-Byte Aligned Bump Arena Memory Allocator.
 * Module: arena_allocator
 */

#ifndef ARENA_ALLOCATOR_TYPES_H
#define ARENA_ALLOCATOR_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ARENA_ALLOCATOR_ALIGNMENT 64
#define ARENA_ALLOCATOR_SUCCESS 0
#define ARENA_ALLOCATOR_ERR_NULL_PTR -1
#define ARENA_ALLOCATOR_ERR_INVALID_PARAM -2
#define ARENA_ALLOCATOR_ERR_OUT_OF_BOUNDS -3

typedef struct arena_allocator_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} arena_allocator_config_t;

typedef struct arena_allocator_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    arena_allocator_config_t config;
} arena_allocator_context_t;

int arena_allocator_init(arena_allocator_context_t* ctx, const arena_allocator_config_t* cfg);
int arena_allocator_destroy(arena_allocator_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* ARENA_ALLOCATOR_TYPES_H */
