/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c | Algorithm Family: hashing
 */

#ifndef SIPHASH_ROUND_C_INTERFACE_H
#define SIPHASH_ROUND_C_INTERFACE_H

#include "types.c"

typedef int (*siphash_round_c_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct siphash_round_c_vtable {
    int (*init)(siphash_round_c_state_t* state, const siphash_round_c_config_t* cfg);
    int (*execute)(siphash_round_c_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(siphash_round_c_state_t* state);
    int (*destroy)(siphash_round_c_state_t* state);
} siphash_round_c_vtable_t;

#endif /* SIPHASH_ROUND_C_INTERFACE_H */
