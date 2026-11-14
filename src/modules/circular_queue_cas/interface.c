/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas | Algorithm Family: queue
 */

#ifndef CIRCULAR_QUEUE_CAS_INTERFACE_H
#define CIRCULAR_QUEUE_CAS_INTERFACE_H

#include "types.c"

typedef int (*circular_queue_cas_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct circular_queue_cas_vtable {
    int (*init)(circular_queue_cas_state_t* state, const circular_queue_cas_config_t* cfg);
    int (*execute)(circular_queue_cas_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(circular_queue_cas_state_t* state);
    int (*destroy)(circular_queue_cas_state_t* state);
} circular_queue_cas_vtable_t;

#endif /* CIRCULAR_QUEUE_CAS_INTERFACE_H */
