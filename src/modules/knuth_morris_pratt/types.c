/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt | Algorithm Family: string_search
 */

#ifndef KNUTH_MORRIS_PRATT_TYPES_H
#define KNUTH_MORRIS_PRATT_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KNUTH_MORRIS_PRATT_ALIGNMENT 64
#define KNUTH_MORRIS_PRATT_BASE_CAPACITY 1024

typedef struct knuth_morris_pratt_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} knuth_morris_pratt_config_t;

typedef struct knuth_morris_pratt_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    knuth_morris_pratt_config_t config;
} knuth_morris_pratt_state_t;

#endif /* KNUTH_MORRIS_PRATT_TYPES_H */
