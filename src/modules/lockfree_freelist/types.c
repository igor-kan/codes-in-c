/**
 * @file types.c
 * @brief Core types and configuration for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

#ifndef LOCKFREE_FREELIST_TYPES_H
#define LOCKFREE_FREELIST_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define LOCKFREE_FREELIST_ALIGNMENT 64
#define LOCKFREE_FREELIST_CAPACITY 4096

typedef struct lockfree_freelist_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} lockfree_freelist_config_t;

typedef struct lockfree_freelist_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    lockfree_freelist_config_t config;
} lockfree_freelist_state_t;

#endif /* LOCKFREE_FREELIST_TYPES_H */
