/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#ifndef SIMD_SPMV_ELLPACK_INTERFACE_H
#define SIMD_SPMV_ELLPACK_INTERFACE_H

#include "types.c"

typedef int (*simd_spmv_ellpack_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_spmv_ellpack_vtable {
    int (*init)(simd_spmv_ellpack_state_t* state, const simd_spmv_ellpack_config_t* cfg);
    int (*execute)(simd_spmv_ellpack_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(simd_spmv_ellpack_state_t* state);
    int (*destroy)(simd_spmv_ellpack_state_t* state);
} simd_spmv_ellpack_vtable_t;

#endif /* SIMD_SPMV_ELLPACK_INTERFACE_H */
