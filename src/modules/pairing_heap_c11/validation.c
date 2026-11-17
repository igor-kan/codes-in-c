#include "interface.h"

pairing_heap_c11_err_t ph_validate_handle(const pairing_heap_t* h, int32_t id) {
    if (!h) return PAIRING_HEAP_C11_ERR_NULL;
    if (id < 0 || id >= h->cap || !h->nodes[id].active) return PAIRING_HEAP_C11_ERR_BOUNDS;
    return PAIRING_HEAP_C11_OK;
}
