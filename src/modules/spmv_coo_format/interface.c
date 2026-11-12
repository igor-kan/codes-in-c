/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Coordinate List (COO) Sparse Matrix-Vector Multiply.
 * Module: spmv_coo_format | Algorithm Family: sparse_math
 */

#ifndef SPMV_COO_FORMAT_INTERFACE_H
#define SPMV_COO_FORMAT_INTERFACE_H

#include "types.c"

typedef int (*spmv_coo_format_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct spmv_coo_format_vtable {
    int (*init)(spmv_coo_format_state_t* state, const spmv_coo_format_config_t* cfg);
    int (*execute)(spmv_coo_format_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(spmv_coo_format_state_t* state);
    int (*destroy)(spmv_coo_format_state_t* state);
} spmv_coo_format_vtable_t;

#endif /* SPMV_COO_FORMAT_INTERFACE_H */
