#ifndef KUHN_BIPARTITE_MATCH_C11_ERRORS_H
#define KUHN_BIPARTITE_MATCH_C11_ERRORS_H

typedef enum kuhn_bipartite_match_c11_err {
    KUHN_BIPARTITE_MATCH_C11_OK = 0,
    KUHN_BIPARTITE_MATCH_C11_ERR_NULL = -1,
    KUHN_BIPARTITE_MATCH_C11_ERR_BOUNDS = -2,
    KUHN_BIPARTITE_MATCH_C11_ERR_INVALID = -3,
    KUHN_BIPARTITE_MATCH_C11_ERR_OVERFLOW = -4,
    KUHN_BIPARTITE_MATCH_C11_ERR_INVARIANT = -5
} kuhn_bipartite_match_c11_err_t;



static inline const char* kuhn_bipartite_match_c11_err_str(kuhn_bipartite_match_c11_err_t err) {
    switch (err) {
        case KUHN_BIPARTITE_MATCH_C11_OK: return "ok";
        case KUHN_BIPARTITE_MATCH_C11_ERR_NULL: return "null pointer supplied";
        case KUHN_BIPARTITE_MATCH_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case KUHN_BIPARTITE_MATCH_C11_ERR_INVALID: return "domain precondition violated";
        case KUHN_BIPARTITE_MATCH_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case KUHN_BIPARTITE_MATCH_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* KUHN_BIPARTITE_MATCH_C11_ERRORS_H */
