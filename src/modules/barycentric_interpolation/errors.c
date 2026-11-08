/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for High-Order Barycentric Rational Interpolator.
 * Module: barycentric_interpolation
 */

typedef enum barycentric_interpolation_error {
    BARYCENTRIC_INTERPOLATION_OK = 0,
    BARYCENTRIC_INTERPOLATION_ERR_NULL = -100,
    BARYCENTRIC_INTERPOLATION_ERR_CAPACITY = -101,
    BARYCENTRIC_INTERPOLATION_ERR_CONVERGENCE = -102
} barycentric_interpolation_error_t;

const char* barycentric_interpolation_strerror(barycentric_interpolation_error_t err) {
    switch (err) {
        case BARYCENTRIC_INTERPOLATION_OK: return "Success";
        case BARYCENTRIC_INTERPOLATION_ERR_NULL: return "Encountered null pointer argument";
        case BARYCENTRIC_INTERPOLATION_ERR_CAPACITY: return "Capacity limit exceeded";
        case BARYCENTRIC_INTERPOLATION_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
