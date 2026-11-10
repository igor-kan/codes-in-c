/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

#ifndef LOCKFREE_FREELIST_INTERFACE_H
#define LOCKFREE_FREELIST_INTERFACE_H

#include "types.c"

typedef int (*lockfree_freelist_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct lockfree_freelist_vtable {
    int (*init)(lockfree_freelist_state_t* state, const lockfree_freelist_config_t* cfg);
    int (*execute)(lockfree_freelist_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(lockfree_freelist_state_t* state);
    int (*destroy)(lockfree_freelist_state_t* state);
} lockfree_freelist_vtable_t;

#endif /* LOCKFREE_FREELIST_INTERFACE_H */
