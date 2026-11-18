#include "interface.h"

binomial_heap_meld_c11_err_t binomial_heap_meld_c11_verify_guard(bool cond) {
    if (!cond) {
        return BINOMIAL_HEAP_MELD_C11_ERR_INVARIANT;
    }
    return BINOMIAL_HEAP_MELD_C11_OK;
}
