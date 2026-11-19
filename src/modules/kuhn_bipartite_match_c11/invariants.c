#include "interface.h"

kuhn_bipartite_match_c11_err_t kuhn_bipartite_match_c11_verify_guard(bool cond) {
    if (!cond) {
        return KUHN_BIPARTITE_MATCH_C11_ERR_INVARIANT;
    }
    return KUHN_BIPARTITE_MATCH_C11_OK;
}
