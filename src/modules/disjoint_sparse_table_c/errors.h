#ifndef DISJOINT_SPARSE_TABLE_C_ERRORS_H
#define DISJOINT_SPARSE_TABLE_C_ERRORS_H

typedef enum disjoint_sparse_table_c_err {
    DISJOINT_SPARSE_TABLE_C_OK = 0,
    DISJOINT_SPARSE_TABLE_C_ERR_NULL = -1,
    DISJOINT_SPARSE_TABLE_C_ERR_BOUNDS = -2,
    DISJOINT_SPARSE_TABLE_C_ERR_INVALID = -3,
    DISJOINT_SPARSE_TABLE_C_ERR_OVERFLOW = -4,
    DISJOINT_SPARSE_TABLE_C_ERR_INVARIANT = -5
} disjoint_sparse_table_c_err_t;



static inline const char* disjoint_sparse_table_c_err_str(disjoint_sparse_table_c_err_t err) {
    switch (err) {
        case DISJOINT_SPARSE_TABLE_C_OK: return "ok";
        case DISJOINT_SPARSE_TABLE_C_ERR_NULL: return "null pointer supplied";
        case DISJOINT_SPARSE_TABLE_C_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case DISJOINT_SPARSE_TABLE_C_ERR_INVALID: return "domain precondition violated";
        case DISJOINT_SPARSE_TABLE_C_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case DISJOINT_SPARSE_TABLE_C_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* DISJOINT_SPARSE_TABLE_C_ERRORS_H */
