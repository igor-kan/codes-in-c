/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

typedef enum fast_fourier_bluestein_error_code {
    FAST_FOURIER_BLUESTEIN_STATUS_OK = 0,
    FAST_FOURIER_BLUESTEIN_ERR_NULL_PTR = -20,
    FAST_FOURIER_BLUESTEIN_ERR_OUT_OF_BOUNDS = -21,
    FAST_FOURIER_BLUESTEIN_ERR_DIVERGENCE = -22
} fast_fourier_bluestein_error_code_t;

const char* fast_fourier_bluestein_error_message(fast_fourier_bluestein_error_code_t code) {
    switch (code) {
        case FAST_FOURIER_BLUESTEIN_STATUS_OK: return "Operational success";
        case FAST_FOURIER_BLUESTEIN_ERR_NULL_PTR: return "Null pointer argument";
        case FAST_FOURIER_BLUESTEIN_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case FAST_FOURIER_BLUESTEIN_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
