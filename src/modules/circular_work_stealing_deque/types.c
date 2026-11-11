/**
 * @file types.c
 * @brief Core types and configuration for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#ifndef CIRCULAR_WORK_STEALING_DEQUE_TYPES_H
#define CIRCULAR_WORK_STEALING_DEQUE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CIRCULAR_WORK_STEALING_DEQUE_ALIGNMENT 64
#define CIRCULAR_WORK_STEALING_DEQUE_DEFAULT_SZ 8192

typedef struct circular_work_stealing_deque_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} circular_work_stealing_deque_config_t;

typedef struct circular_work_stealing_deque_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    circular_work_stealing_deque_config_t config;
} circular_work_stealing_deque_state_t;

#endif /* CIRCULAR_WORK_STEALING_DEQUE_TYPES_H */
