/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

#ifndef SIMD_MATRIX_TRANSPOSE_INTERFACE_H
#define SIMD_MATRIX_TRANSPOSE_INTERFACE_H

#include "types.c"

typedef int (*simd_matrix_transpose_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_matrix_transpose_interface {
    int (*init)(simd_matrix_transpose_state_t* state, const simd_matrix_transpose_config_t* cfg);
    int (*execute)(simd_matrix_transpose_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(simd_matrix_transpose_state_t* state);
    int (*destroy)(simd_matrix_transpose_state_t* state);
} simd_matrix_transpose_interface_t;

#endif /* SIMD_MATRIX_TRANSPOSE_INTERFACE_H */
