/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Power-of-Two Buddy Memory Pool Allocator.
 * Module: buddy_memory_allocator
 */

#ifndef BUDDY_MEMORY_ALLOCATOR_INTERFACE_H
#define BUDDY_MEMORY_ALLOCATOR_INTERFACE_H

#include "types.c"

typedef int (*buddy_memory_allocator_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct buddy_memory_allocator_vtable {
    int (*init)(buddy_memory_allocator_state_t* state, const buddy_memory_allocator_config_t* cfg);
    int (*execute)(buddy_memory_allocator_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(buddy_memory_allocator_state_t* state);
} buddy_memory_allocator_vtable_t;

#endif /* BUDDY_MEMORY_ALLOCATOR_INTERFACE_H */
