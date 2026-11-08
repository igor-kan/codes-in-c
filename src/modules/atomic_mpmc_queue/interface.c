/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#ifndef ATOMIC_MPMC_QUEUE_INTERFACE_H
#define ATOMIC_MPMC_QUEUE_INTERFACE_H

#include "types.c"

typedef int (*atomic_mpmc_queue_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct atomic_mpmc_queue_interface {
    int (*init)(atomic_mpmc_queue_state_t* state, const atomic_mpmc_queue_config_t* cfg);
    int (*execute)(atomic_mpmc_queue_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(atomic_mpmc_queue_state_t* state);
    int (*destroy)(atomic_mpmc_queue_state_t* state);
} atomic_mpmc_queue_interface_t;

#endif /* ATOMIC_MPMC_QUEUE_INTERFACE_H */
