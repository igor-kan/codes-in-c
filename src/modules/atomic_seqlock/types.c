/**
 * @file types.c
 * @brief Core types and configuration for Sequential Lock for High-Frequency Concurrent Reads.
 * Module: atomic_seqlock
 */

#ifndef ATOMIC_SEQLOCK_TYPES_H
#define ATOMIC_SEQLOCK_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ATOMIC_SEQLOCK_ALIGNMENT 64
#define ATOMIC_SEQLOCK_CAPACITY 2048

typedef struct atomic_seqlock_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} atomic_seqlock_config_t;

typedef struct atomic_seqlock_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    atomic_seqlock_config_t config;
} atomic_seqlock_state_t;

#endif /* ATOMIC_SEQLOCK_TYPES_H */
