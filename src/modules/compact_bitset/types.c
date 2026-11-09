/**
 * @file types.c
 * @brief Core types and configuration for 64-Bit Word Compact Bitset with Popcount.
 * Module: compact_bitset
 */

#ifndef COMPACT_BITSET_TYPES_H
#define COMPACT_BITSET_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define COMPACT_BITSET_ALIGNMENT 64
#define COMPACT_BITSET_CAPACITY 2048

typedef struct compact_bitset_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} compact_bitset_config_t;

typedef struct compact_bitset_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    compact_bitset_config_t config;
} compact_bitset_state_t;

#endif /* COMPACT_BITSET_TYPES_H */
