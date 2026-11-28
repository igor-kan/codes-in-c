#ifndef BASE58_BTC_D61_ERRORS_H
#define BASE58_BTC_D61_ERRORS_H

typedef enum base58_btc_d61_err {
    BASE58_BTC_D61_OK = 0,
    BASE58_BTC_D61_ERR_NULL = -1,
    BASE58_BTC_D61_ERR_BOUNDS = -2,
    BASE58_BTC_D61_ERR_INVALID = -3,
    BASE58_BTC_D61_ERR_OVERFLOW = -4,
    BASE58_BTC_D61_ERR_INVARIANT = -5
} base58_btc_d61_err_t;



static inline const char* base58_btc_d61_err_str(base58_btc_d61_err_t err) {
    switch (err) {
        case BASE58_BTC_D61_OK: return "ok";
        case BASE58_BTC_D61_ERR_NULL: return "null pointer supplied";
        case BASE58_BTC_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BASE58_BTC_D61_ERR_INVALID: return "domain precondition violated";
        case BASE58_BTC_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BASE58_BTC_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BASE58_BTC_D61_ERRORS_H */
