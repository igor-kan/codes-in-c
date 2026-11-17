#include "interface.h"

pairing_heap_c11_err_t ph_verify_invariants(const pairing_heap_t* h) {
    if (!h) return PAIRING_HEAP_C11_ERR_NULL;
    for (int32_t i = 0; i < h->cap; ++i) {
        if (!h->nodes[i].active) continue;
        int32_t c = h->nodes[i].child;
        while (c >= 0) {
            if (h->nodes[c].key < h->nodes[i].key) return PAIRING_HEAP_C11_ERR_INVARIANT;
            c = h->nodes[c].sibling;
        }
    }
    return PAIRING_HEAP_C11_OK;
}
