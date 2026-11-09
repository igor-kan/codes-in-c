/**
 * @file types.c
 * @brief Core types and configuration for Power-of-Two Buddy Memory Pool Allocator.
 * Module: buddy_memory_allocator
 */

#ifndef BUDDY_MEMORY_ALLOCATOR_TYPES_H
#define BUDDY_MEMORY_ALLOCATOR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BUDDY_MEMORY_ALLOCATOR_ALIGNMENT 64
#define BUDDY_MEMORY_ALLOCATOR_CAPACITY 2048

typedef struct buddy_memory_allocator_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} buddy_memory_allocator_config_t;

typedef struct buddy_memory_allocator_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    buddy_memory_allocator_config_t config;
} buddy_memory_allocator_state_t;

#endif /* BUDDY_MEMORY_ALLOCATOR_TYPES_H */
