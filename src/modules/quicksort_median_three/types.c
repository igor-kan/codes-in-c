/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three | Algorithm Family: sorting
 */

#ifndef QUICKSORT_MEDIAN_THREE_TYPES_H
#define QUICKSORT_MEDIAN_THREE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define QUICKSORT_MEDIAN_THREE_ALIGNMENT 64
#define QUICKSORT_MEDIAN_THREE_CAPACITY 2048

typedef struct quicksort_median_three_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} quicksort_median_three_config_t;

typedef struct quicksort_median_three_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    quicksort_median_three_config_t config;
} quicksort_median_three_state_t;

#endif /* QUICKSORT_MEDIAN_THREE_TYPES_H */
