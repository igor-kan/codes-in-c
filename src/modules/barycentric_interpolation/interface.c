/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for High-Order Barycentric Rational Interpolator.
 * Module: barycentric_interpolation
 */

#ifndef BARYCENTRIC_INTERPOLATION_INTERFACE_H
#define BARYCENTRIC_INTERPOLATION_INTERFACE_H

#include "types.c"

typedef int (*barycentric_interpolation_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct barycentric_interpolation_interface {
    int (*init)(barycentric_interpolation_state_t* state, const barycentric_interpolation_config_t* cfg);
    int (*execute)(barycentric_interpolation_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(barycentric_interpolation_state_t* state);
    int (*destroy)(barycentric_interpolation_state_t* state);
} barycentric_interpolation_interface_t;

#endif /* BARYCENTRIC_INTERPOLATION_INTERFACE_H */
