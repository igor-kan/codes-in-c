#include "interface.h"

dary_heap_c11_d61_err_t dary_heap_c11_d61_validate_len(size_t n) {
    if (n == 0) {
        return DARY_HEAP_C11_D61_ERR_INVALID;
    }
    return DARY_HEAP_C11_D61_OK;
}
