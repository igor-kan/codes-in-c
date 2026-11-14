/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Diagonal (DIA) Sparse Matrix-Vector Multiply for Banded.
 * Module: spmv_dia_format | Algorithm Family: sparse_math
 */

#ifndef SPMV_DIA_FORMAT_INTERFACE_H
#define SPMV_DIA_FORMAT_INTERFACE_H

#include "types.c"

typedef int (*spmv_dia_format_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct spmv_dia_format_vtable {
    int (*init)(spmv_dia_format_state_t* state, const spmv_dia_format_config_t* cfg);
    int (*execute)(spmv_dia_format_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(spmv_dia_format_state_t* state);
    int (*destroy)(spmv_dia_format_state_t* state);
} spmv_dia_format_vtable_t;

#endif /* SPMV_DIA_FORMAT_INTERFACE_H */
