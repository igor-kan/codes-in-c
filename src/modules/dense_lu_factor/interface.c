/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#ifndef DENSE_LU_FACTOR_INTERFACE_H
#define DENSE_LU_FACTOR_INTERFACE_H

#include "types.c"

typedef int (*dense_lu_factor_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct dense_lu_factor_vtable {
    int (*init)(dense_lu_factor_state_t* state, const dense_lu_factor_config_t* cfg);
    int (*execute)(dense_lu_factor_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(dense_lu_factor_state_t* state);
} dense_lu_factor_vtable_t;

#endif /* DENSE_LU_FACTOR_INTERFACE_H */
