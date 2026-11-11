/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

typedef enum quaternion_spherical_slerp_error_code {
    QUATERNION_SPHERICAL_SLERP_STATUS_OK = 0,
    QUATERNION_SPHERICAL_SLERP_ERR_NULL_PTR = -20,
    QUATERNION_SPHERICAL_SLERP_ERR_OUT_OF_BOUNDS = -21,
    QUATERNION_SPHERICAL_SLERP_ERR_DIVERGENCE = -22
} quaternion_spherical_slerp_error_code_t;

const char* quaternion_spherical_slerp_error_message(quaternion_spherical_slerp_error_code_t code) {
    switch (code) {
        case QUATERNION_SPHERICAL_SLERP_STATUS_OK: return "Operational success";
        case QUATERNION_SPHERICAL_SLERP_ERR_NULL_PTR: return "Null pointer argument";
        case QUATERNION_SPHERICAL_SLERP_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case QUATERNION_SPHERICAL_SLERP_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
