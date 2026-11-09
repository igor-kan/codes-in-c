/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Sequential Lock for High-Frequency Concurrent Reads.
 * Module: atomic_seqlock
 */

#ifndef ATOMIC_SEQLOCK_INTERFACE_H
#define ATOMIC_SEQLOCK_INTERFACE_H

#include "types.c"

typedef int (*atomic_seqlock_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct atomic_seqlock_vtable {
    int (*init)(atomic_seqlock_state_t* state, const atomic_seqlock_config_t* cfg);
    int (*execute)(atomic_seqlock_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(atomic_seqlock_state_t* state);
} atomic_seqlock_vtable_t;

#endif /* ATOMIC_SEQLOCK_INTERFACE_H */
