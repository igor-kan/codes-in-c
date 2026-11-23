#ifndef CRC32_IEEE8023_C11_D58_ERRORS_H
#define CRC32_IEEE8023_C11_D58_ERRORS_H

typedef enum crc32_ieee8023_c11_d58_err {
    CRC32_IEEE8023_C11_D58_OK = 0,
    CRC32_IEEE8023_C11_D58_ERR_NULL = -1,
    CRC32_IEEE8023_C11_D58_ERR_BOUNDS = -2,
    CRC32_IEEE8023_C11_D58_ERR_INVALID = -3,
    CRC32_IEEE8023_C11_D58_ERR_OVERFLOW = -4,
    CRC32_IEEE8023_C11_D58_ERR_INVARIANT = -5
} crc32_ieee8023_c11_d58_err_t;



static inline const char* crc32_ieee8023_c11_d58_err_str(crc32_ieee8023_c11_d58_err_t err) {
    switch (err) {
        case CRC32_IEEE8023_C11_D58_OK: return "ok";
        case CRC32_IEEE8023_C11_D58_ERR_NULL: return "null pointer supplied";
        case CRC32_IEEE8023_C11_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CRC32_IEEE8023_C11_D58_ERR_INVALID: return "domain precondition violated";
        case CRC32_IEEE8023_C11_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CRC32_IEEE8023_C11_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CRC32_IEEE8023_C11_D58_ERRORS_H */
