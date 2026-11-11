/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#ifndef LOCKFREE_ORDERED_LIST_INTERFACE_H
#define LOCKFREE_ORDERED_LIST_INTERFACE_H

#include "types.c"

typedef int (*lockfree_ordered_list_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct lockfree_ordered_list_vtable {
    int (*init)(lockfree_ordered_list_state_t* state, const lockfree_ordered_list_config_t* cfg);
    int (*execute)(lockfree_ordered_list_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(lockfree_ordered_list_state_t* state);
    int (*destroy)(lockfree_ordered_list_state_t* state);
} lockfree_ordered_list_vtable_t;

#endif /* LOCKFREE_ORDERED_LIST_INTERFACE_H */
