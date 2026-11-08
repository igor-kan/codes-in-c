/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Kernel-Style Slab Cache Memory Pool Allocator.
 * Module: slab_cache_allocator
 */

#ifndef SLAB_CACHE_ALLOCATOR_INTERFACE_H
#define SLAB_CACHE_ALLOCATOR_INTERFACE_H

#include "types.c"

typedef int (*slab_cache_allocator_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct slab_cache_allocator_interface {
    int (*init)(slab_cache_allocator_state_t* state, const slab_cache_allocator_config_t* cfg);
    int (*execute)(slab_cache_allocator_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(slab_cache_allocator_state_t* state);
    int (*destroy)(slab_cache_allocator_state_t* state);
} slab_cache_allocator_interface_t;

#endif /* SLAB_CACHE_ALLOCATOR_INTERFACE_H */
