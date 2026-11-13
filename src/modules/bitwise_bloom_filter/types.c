/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter | Algorithm Family: bloom
 */

#ifndef BITWISE_BLOOM_FILTER_TYPES_H
#define BITWISE_BLOOM_FILTER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BITWISE_BLOOM_FILTER_ALIGNMENT 64
#define BITWISE_BLOOM_FILTER_CAPACITY 2048

typedef struct bitwise_bloom_filter_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} bitwise_bloom_filter_config_t;

typedef struct bitwise_bloom_filter_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    bitwise_bloom_filter_config_t config;
} bitwise_bloom_filter_state_t;

#endif /* BITWISE_BLOOM_FILTER_TYPES_H */
