#include "interface.h"

shell_sort_ciura_d61_err_t shell_sort_ciura_d61_verify_guard(bool cond) {
    if (!cond) {
        return SHELL_SORT_CIURA_D61_ERR_INVARIANT;
    }
    return SHELL_SORT_CIURA_D61_OK;
}
