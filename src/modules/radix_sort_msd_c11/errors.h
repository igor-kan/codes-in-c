#ifndef RADIX_SORT_MSD_C11_ERRORS_H
#define RADIX_SORT_MSD_C11_ERRORS_H

typedef enum radix_sort_msd_c11_err {
    RADIX_SORT_MSD_C11_OK = 0,
    RADIX_SORT_MSD_C11_ERR_NULL = -1,
    RADIX_SORT_MSD_C11_ERR_BOUNDS = -2,
    RADIX_SORT_MSD_C11_ERR_INVALID = -3,
    RADIX_SORT_MSD_C11_ERR_OVERFLOW = -4,
    RADIX_SORT_MSD_C11_ERR_INVARIANT = -5
} radix_sort_msd_c11_err_t;



static inline const char* radix_sort_msd_c11_err_str(radix_sort_msd_c11_err_t err) {
    switch (err) {
        case RADIX_SORT_MSD_C11_OK: return "ok";
        case RADIX_SORT_MSD_C11_ERR_NULL: return "null pointer supplied";
        case RADIX_SORT_MSD_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RADIX_SORT_MSD_C11_ERR_INVALID: return "domain precondition violated";
        case RADIX_SORT_MSD_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RADIX_SORT_MSD_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RADIX_SORT_MSD_C11_ERRORS_H */
