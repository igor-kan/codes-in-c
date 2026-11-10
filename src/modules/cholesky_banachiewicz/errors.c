/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

typedef enum cholesky_banachiewicz_error_code {
    CHOLESKY_BANACHIEWICZ_STATUS_OK = 0,
    CHOLESKY_BANACHIEWICZ_ERR_NULL_PTR = -10,
    CHOLESKY_BANACHIEWICZ_ERR_OUT_OF_BOUNDS = -11,
    CHOLESKY_BANACHIEWICZ_ERR_DIVERGENCE = -12
} cholesky_banachiewicz_error_code_t;

const char* cholesky_banachiewicz_error_message(cholesky_banachiewicz_error_code_t code) {
    switch (code) {
        case CHOLESKY_BANACHIEWICZ_STATUS_OK: return "Operational success";
        case CHOLESKY_BANACHIEWICZ_ERR_NULL_PTR: return "Null pointer argument";
        case CHOLESKY_BANACHIEWICZ_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case CHOLESKY_BANACHIEWICZ_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
