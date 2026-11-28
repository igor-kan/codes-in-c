#include "interface.h"

shell_sort_ciura_d61_err_t shell_sort_ciura_d61_validate_len(size_t n) {
    if (n == 0) {
        return SHELL_SORT_CIURA_D61_ERR_INVALID;
    }
    return SHELL_SORT_CIURA_D61_OK;
}
