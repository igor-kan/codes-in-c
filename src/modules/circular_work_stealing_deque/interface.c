/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#ifndef CIRCULAR_WORK_STEALING_DEQUE_INTERFACE_H
#define CIRCULAR_WORK_STEALING_DEQUE_INTERFACE_H

#include "types.c"

typedef int (*circular_work_stealing_deque_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct circular_work_stealing_deque_vtable {
    int (*init)(circular_work_stealing_deque_state_t* state, const circular_work_stealing_deque_config_t* cfg);
    int (*execute)(circular_work_stealing_deque_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(circular_work_stealing_deque_state_t* state);
    int (*destroy)(circular_work_stealing_deque_state_t* state);
} circular_work_stealing_deque_vtable_t;

#endif /* CIRCULAR_WORK_STEALING_DEQUE_INTERFACE_H */
