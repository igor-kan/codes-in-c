#include "interface.h"

binomial_heap_meld_c11_err_t binomial_heap_meld_c11_validate_len(size_t n) {
    if (n == 0) {
        return BINOMIAL_HEAP_MELD_C11_ERR_INVALID;
    }
    return BINOMIAL_HEAP_MELD_C11_OK;
}
