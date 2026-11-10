/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

typedef enum hazard_pointer_domain_error_code {
    HAZARD_POINTER_DOMAIN_STATUS_OK = 0,
    HAZARD_POINTER_DOMAIN_ERR_NULL_PTR = -10,
    HAZARD_POINTER_DOMAIN_ERR_OUT_OF_BOUNDS = -11,
    HAZARD_POINTER_DOMAIN_ERR_DIVERGENCE = -12
} hazard_pointer_domain_error_code_t;

const char* hazard_pointer_domain_error_message(hazard_pointer_domain_error_code_t code) {
    switch (code) {
        case HAZARD_POINTER_DOMAIN_STATUS_OK: return "Operational success";
        case HAZARD_POINTER_DOMAIN_ERR_NULL_PTR: return "Null pointer argument";
        case HAZARD_POINTER_DOMAIN_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case HAZARD_POINTER_DOMAIN_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
