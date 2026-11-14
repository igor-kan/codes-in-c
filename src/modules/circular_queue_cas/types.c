/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas | Algorithm Family: queue
 */

#ifndef CIRCULAR_QUEUE_CAS_TYPES_H
#define CIRCULAR_QUEUE_CAS_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CIRCULAR_QUEUE_CAS_ALIGNMENT 64
#define CIRCULAR_QUEUE_CAS_CAPACITY 4096

typedef struct circular_queue_cas_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} circular_queue_cas_config_t;

typedef struct circular_queue_cas_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    circular_queue_cas_config_t config;
} circular_queue_cas_state_t;

#endif /* CIRCULAR_QUEUE_CAS_TYPES_H */
