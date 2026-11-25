#ifndef CRC32C_CASTAGNOLI_D60_ERRORS_H
#define CRC32C_CASTAGNOLI_D60_ERRORS_H

typedef enum crc32c_castagnoli_d60_err {
    CRC32C_CASTAGNOLI_D60_OK = 0,
    CRC32C_CASTAGNOLI_D60_ERR_NULL = -1,
    CRC32C_CASTAGNOLI_D60_ERR_BOUNDS = -2,
    CRC32C_CASTAGNOLI_D60_ERR_INVALID = -3,
    CRC32C_CASTAGNOLI_D60_ERR_OVERFLOW = -4,
    CRC32C_CASTAGNOLI_D60_ERR_INVARIANT = -5
} crc32c_castagnoli_d60_err_t;



static inline const char* crc32c_castagnoli_d60_err_str(crc32c_castagnoli_d60_err_t err) {
    switch (err) {
        case CRC32C_CASTAGNOLI_D60_OK: return "ok";
        case CRC32C_CASTAGNOLI_D60_ERR_NULL: return "null pointer supplied";
        case CRC32C_CASTAGNOLI_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CRC32C_CASTAGNOLI_D60_ERR_INVALID: return "domain precondition violated";
        case CRC32C_CASTAGNOLI_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CRC32C_CASTAGNOLI_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CRC32C_CASTAGNOLI_D60_ERRORS_H */
