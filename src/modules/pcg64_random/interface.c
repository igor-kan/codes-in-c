/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random | Algorithm Family: random_gen
 */

#ifndef PCG64_RANDOM_INTERFACE_H
#define PCG64_RANDOM_INTERFACE_H

#include "types.c"

typedef int (*pcg64_random_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct pcg64_random_vtable {
    int (*init)(pcg64_random_state_t* state, const pcg64_random_config_t* cfg);
    int (*execute)(pcg64_random_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(pcg64_random_state_t* state);
    int (*destroy)(pcg64_random_state_t* state);
} pcg64_random_vtable_t;

#endif /* PCG64_RANDOM_INTERFACE_H */
