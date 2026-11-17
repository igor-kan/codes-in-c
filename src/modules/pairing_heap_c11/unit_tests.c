#include "interface.h"
#include <assert.h>

int main(void) {
    pairing_heap_t h;
    assert(ph_init(&h) == PAIRING_HEAP_C11_OK);
    int32_t id1 = 0, id2 = 0;
    assert(ph_push(&h, 40, 1, &id1) == PAIRING_HEAP_C11_OK);
    assert(ph_push(&h, 20, 2, &id2) == PAIRING_HEAP_C11_OK);
    assert(ph_push(&h, 30, 3, NULL) == PAIRING_HEAP_C11_OK);
    assert(ph_decrease_key(&h, id1, 10) == PAIRING_HEAP_C11_OK);
    assert(ph_verify_invariants(&h) == PAIRING_HEAP_C11_OK);
    int64_t k = 0;
    int32_t v = 0;
    assert(ph_pop_min(&h, &k, &v) == PAIRING_HEAP_C11_OK && k == 10 && v == 1);
    assert(ph_pop_min(&h, &k, &v) == PAIRING_HEAP_C11_OK && k == 20 && v == 2);
    assert(ph_pop_min(&h, &k, &v) == PAIRING_HEAP_C11_OK && k == 30 && v == 3);
    return 0;
}
