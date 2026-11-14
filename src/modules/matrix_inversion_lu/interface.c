/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for In-Place LU Decomposition Matrix Inversion with Solve.
 * Module: matrix_inversion_lu | Algorithm Family: linear_algebra
 */

#ifndef MATRIX_INVERSION_LU_INTERFACE_H
#define MATRIX_INVERSION_LU_INTERFACE_H

#include "types.c"

typedef int (*matrix_inversion_lu_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct matrix_inversion_lu_vtable {
    int (*init)(matrix_inversion_lu_state_t* state, const matrix_inversion_lu_config_t* cfg);
    int (*execute)(matrix_inversion_lu_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(matrix_inversion_lu_state_t* state);
    int (*destroy)(matrix_inversion_lu_state_t* state);
} matrix_inversion_lu_vtable_t;

#endif /* MATRIX_INVERSION_LU_INTERFACE_H */
