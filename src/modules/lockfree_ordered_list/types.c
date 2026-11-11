/**
 * @file types.c
 * @brief Core types and configuration for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#ifndef LOCKFREE_ORDERED_LIST_TYPES_H
#define LOCKFREE_ORDERED_LIST_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define LOCKFREE_ORDERED_LIST_ALIGNMENT 64
#define LOCKFREE_ORDERED_LIST_DEFAULT_SZ 8192

typedef struct lockfree_ordered_list_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} lockfree_ordered_list_config_t;

typedef struct lockfree_ordered_list_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    lockfree_ordered_list_config_t config;
} lockfree_ordered_list_state_t;

#endif /* LOCKFREE_ORDERED_LIST_TYPES_H */
