/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Bit-Parallel Myers Levenshtein Edit Distance.
 * Module: simd_levenshtein
 */

#ifndef SIMD_LEVENSHTEIN_INTERFACE_H
#define SIMD_LEVENSHTEIN_INTERFACE_H

#include "types.c"

typedef int (*simd_levenshtein_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_levenshtein_vtable {
    int (*init)(simd_levenshtein_state_t* state, const simd_levenshtein_config_t* cfg);
    int (*execute)(simd_levenshtein_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(simd_levenshtein_state_t* state);
} simd_levenshtein_vtable_t;

#endif /* SIMD_LEVENSHTEIN_INTERFACE_H */
