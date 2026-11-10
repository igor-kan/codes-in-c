/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

typedef enum fast_fourier_split_radix_error_code {
    FAST_FOURIER_SPLIT_RADIX_STATUS_OK = 0,
    FAST_FOURIER_SPLIT_RADIX_ERR_NULL_PTR = -10,
    FAST_FOURIER_SPLIT_RADIX_ERR_OUT_OF_BOUNDS = -11,
    FAST_FOURIER_SPLIT_RADIX_ERR_DIVERGENCE = -12
} fast_fourier_split_radix_error_code_t;

const char* fast_fourier_split_radix_error_message(fast_fourier_split_radix_error_code_t code) {
    switch (code) {
        case FAST_FOURIER_SPLIT_RADIX_STATUS_OK: return "Operational success";
        case FAST_FOURIER_SPLIT_RADIX_ERR_NULL_PTR: return "Null pointer argument";
        case FAST_FOURIER_SPLIT_RADIX_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case FAST_FOURIER_SPLIT_RADIX_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
