#include "interface.h"

kuhn_bipartite_match_c11_err_t kuhn_bipartite_match_c11_validate_len(size_t n) {
    if (n == 0) {
        return KUHN_BIPARTITE_MATCH_C11_ERR_INVALID;
    }
    return KUHN_BIPARTITE_MATCH_C11_OK;
}
