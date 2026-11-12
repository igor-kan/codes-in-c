/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt | Algorithm Family: string_search
 */

#ifndef KNUTH_MORRIS_PRATT_INTERFACE_H
#define KNUTH_MORRIS_PRATT_INTERFACE_H

#include "types.c"

typedef int (*knuth_morris_pratt_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct knuth_morris_pratt_vtable {
    int (*init)(knuth_morris_pratt_state_t* state, const knuth_morris_pratt_config_t* cfg);
    int (*execute)(knuth_morris_pratt_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(knuth_morris_pratt_state_t* state);
    int (*destroy)(knuth_morris_pratt_state_t* state);
} knuth_morris_pratt_vtable_t;

#endif /* KNUTH_MORRIS_PRATT_INTERFACE_H */
