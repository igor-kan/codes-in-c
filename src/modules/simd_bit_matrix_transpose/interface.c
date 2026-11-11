/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#ifndef SIMD_BIT_MATRIX_TRANSPOSE_INTERFACE_H
#define SIMD_BIT_MATRIX_TRANSPOSE_INTERFACE_H

#include "types.c"

typedef int (*simd_bit_matrix_transpose_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_bit_matrix_transpose_vtable {
    int (*init)(simd_bit_matrix_transpose_state_t* state, const simd_bit_matrix_transpose_config_t* cfg);
    int (*execute)(simd_bit_matrix_transpose_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(simd_bit_matrix_transpose_state_t* state);
    int (*destroy)(simd_bit_matrix_transpose_state_t* state);
} simd_bit_matrix_transpose_vtable_t;

#endif /* SIMD_BIT_MATRIX_TRANSPOSE_INTERFACE_H */
