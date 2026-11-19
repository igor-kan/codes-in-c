#include "interface.h"

stoer_wagner_mincut_c11_err_t stoer_wagner_mincut_c11_verify_guard(bool cond) {
    if (!cond) {
        return STOER_WAGNER_MINCUT_C11_ERR_INVARIANT;
    }
    return STOER_WAGNER_MINCUT_C11_OK;
}
