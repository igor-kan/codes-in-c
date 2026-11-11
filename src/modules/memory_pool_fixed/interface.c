/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#ifndef MEMORY_POOL_FIXED_INTERFACE_H
#define MEMORY_POOL_FIXED_INTERFACE_H

#include "types.c"

typedef int (*memory_pool_fixed_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct memory_pool_fixed_vtable {
    int (*init)(memory_pool_fixed_state_t* state, const memory_pool_fixed_config_t* cfg);
    int (*execute)(memory_pool_fixed_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(memory_pool_fixed_state_t* state);
    int (*destroy)(memory_pool_fixed_state_t* state);
} memory_pool_fixed_vtable_t;

#endif /* MEMORY_POOL_FIXED_INTERFACE_H */
