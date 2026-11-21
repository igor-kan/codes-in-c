#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(spsc_lockfree_ring_c11_validate_len(1) == SPSC_LOCKFREE_RING_C11_OK);
    spsc_ring16_t q;
    spsc16_init(&q);
    for (uint64_t i = 0; i < 16; ++i) assert(spsc16_push(&q, i + 100) == 0);
    assert(spsc16_push(&q, 999) == -1 && spsc16_len(&q) == 16);
    uint64_t out = 0;
    assert(spsc16_pop(&q, &out) == 0 && out == 100);
    assert(spsc_lockfree_ring_c11_verify_guard(true) == SPSC_LOCKFREE_RING_C11_OK);
    return 0;
}
