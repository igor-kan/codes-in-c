/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc | Algorithm Family: statistics
 */

#ifndef SHANNON_ENTROPY_CALC_INTERFACE_H
#define SHANNON_ENTROPY_CALC_INTERFACE_H

#include "types.c"

typedef int (*shannon_entropy_calc_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct shannon_entropy_calc_vtable {
    int (*init)(shannon_entropy_calc_state_t* state, const shannon_entropy_calc_config_t* cfg);
    int (*execute)(shannon_entropy_calc_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(shannon_entropy_calc_state_t* state);
    int (*destroy)(shannon_entropy_calc_state_t* state);
} shannon_entropy_calc_vtable_t;

#endif /* SHANNON_ENTROPY_CALC_INTERFACE_H */
