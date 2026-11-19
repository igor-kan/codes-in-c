#include "interface.h"

stoer_wagner_mincut_c11_err_t stoer_wagner_mincut_c11_validate_len(size_t n) {
    if (n == 0) {
        return STOER_WAGNER_MINCUT_C11_ERR_INVALID;
    }
    return STOER_WAGNER_MINCUT_C11_OK;
}
