/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

#ifndef QUATERNION_SPHERICAL_SLERP_INTERFACE_H
#define QUATERNION_SPHERICAL_SLERP_INTERFACE_H

#include "types.c"

typedef int (*quaternion_spherical_slerp_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct quaternion_spherical_slerp_vtable {
    int (*init)(quaternion_spherical_slerp_state_t* state, const quaternion_spherical_slerp_config_t* cfg);
    int (*execute)(quaternion_spherical_slerp_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(quaternion_spherical_slerp_state_t* state);
    int (*destroy)(quaternion_spherical_slerp_state_t* state);
} quaternion_spherical_slerp_vtable_t;

#endif /* QUATERNION_SPHERICAL_SLERP_INTERFACE_H */
