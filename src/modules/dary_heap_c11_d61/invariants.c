#include "interface.h"

dary_heap_c11_d61_err_t dary_heap_c11_d61_verify_guard(bool cond) {
    if (!cond) {
        return DARY_HEAP_C11_D61_ERR_INVARIANT;
    }
    return DARY_HEAP_C11_D61_OK;
}
