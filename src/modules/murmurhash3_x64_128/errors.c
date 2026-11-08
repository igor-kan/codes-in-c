/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

typedef enum murmurhash3_x64_128_error {
    MURMURHASH3_X64_128_OK = 0,
    MURMURHASH3_X64_128_ERR_NULL = -100,
    MURMURHASH3_X64_128_ERR_CAPACITY = -101,
    MURMURHASH3_X64_128_ERR_CONVERGENCE = -102
} murmurhash3_x64_128_error_t;

const char* murmurhash3_x64_128_strerror(murmurhash3_x64_128_error_t err) {
    switch (err) {
        case MURMURHASH3_X64_128_OK: return "Success";
        case MURMURHASH3_X64_128_ERR_NULL: return "Encountered null pointer argument";
        case MURMURHASH3_X64_128_ERR_CAPACITY: return "Capacity limit exceeded";
        case MURMURHASH3_X64_128_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
