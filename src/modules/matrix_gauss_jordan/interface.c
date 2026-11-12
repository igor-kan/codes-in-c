/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan | Algorithm Family: linear_algebra
 */

#ifndef MATRIX_GAUSS_JORDAN_INTERFACE_H
#define MATRIX_GAUSS_JORDAN_INTERFACE_H

#include "types.c"

typedef int (*matrix_gauss_jordan_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct matrix_gauss_jordan_vtable {
    int (*init)(matrix_gauss_jordan_state_t* state, const matrix_gauss_jordan_config_t* cfg);
    int (*execute)(matrix_gauss_jordan_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(matrix_gauss_jordan_state_t* state);
    int (*destroy)(matrix_gauss_jordan_state_t* state);
} matrix_gauss_jordan_vtable_t;

#endif /* MATRIX_GAUSS_JORDAN_INTERFACE_H */
