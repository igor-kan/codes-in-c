/**
 * @file types.c
 * @brief Core types and configuration for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#ifndef ATOMIC_MPMC_QUEUE_TYPES_H
#define ATOMIC_MPMC_QUEUE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ATOMIC_MPMC_QUEUE_ALIGNMENT 64
#define ATOMIC_MPMC_QUEUE_DEFAULT_CAPACITY 1024

typedef struct atomic_mpmc_queue_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} atomic_mpmc_queue_config_t;

typedef struct atomic_mpmc_queue_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    atomic_mpmc_queue_config_t config;
} atomic_mpmc_queue_state_t;

#endif /* ATOMIC_MPMC_QUEUE_TYPES_H */
