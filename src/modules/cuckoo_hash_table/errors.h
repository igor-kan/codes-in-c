#ifndef CUCKOO_HASH_TABLE_ERRORS_H
#define CUCKOO_HASH_TABLE_ERRORS_H

typedef enum cuckoo_hash_table_err {
    CUCKOO_HASH_TABLE_OK = 0,
    CUCKOO_HASH_TABLE_ERR_NULL = -1,
    CUCKOO_HASH_TABLE_ERR_BOUNDS = -2,
    CUCKOO_HASH_TABLE_ERR_INVALID = -3,
    CUCKOO_HASH_TABLE_ERR_OVERFLOW = -4,
    CUCKOO_HASH_TABLE_ERR_INVARIANT = -5
} cuckoo_hash_table_err_t;



static inline const char* cuckoo_hash_table_err_str(cuckoo_hash_table_err_t err) {
    switch (err) {
        case CUCKOO_HASH_TABLE_OK: return "ok";
        case CUCKOO_HASH_TABLE_ERR_NULL: return "null pointer supplied";
        case CUCKOO_HASH_TABLE_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CUCKOO_HASH_TABLE_ERR_INVALID: return "domain precondition violated";
        case CUCKOO_HASH_TABLE_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CUCKOO_HASH_TABLE_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CUCKOO_HASH_TABLE_ERRORS_H */
