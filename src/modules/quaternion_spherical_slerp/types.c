/**
 * @file types.c
 * @brief Core types and configuration for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

#ifndef QUATERNION_SPHERICAL_SLERP_TYPES_H
#define QUATERNION_SPHERICAL_SLERP_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define QUATERNION_SPHERICAL_SLERP_ALIGNMENT 64
#define QUATERNION_SPHERICAL_SLERP_DEFAULT_SZ 8192

typedef struct quaternion_spherical_slerp_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} quaternion_spherical_slerp_config_t;

typedef struct quaternion_spherical_slerp_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    quaternion_spherical_slerp_config_t config;
} quaternion_spherical_slerp_state_t;

#endif /* QUATERNION_SPHERICAL_SLERP_TYPES_H */
