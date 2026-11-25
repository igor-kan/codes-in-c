#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(ring_spsc_lockfree_d60_validate_len(1) == RING_SPSC_LOCKFREE_D60_OK);
    spsc_ring_t q; spsc_init_d60(&q);
    assert(spsc_push_d60(&q, 11) && spsc_push_d60(&q, 22));
    int64_t x = 0;
    assert(spsc_pop_d60(&q, &x) && x == 11);
    assert(spsc_pop_d60(&q, &x) && x == 22);
    assert(!spsc_pop_d60(&q, &x));
    assert(ring_spsc_lockfree_d60_verify_guard(true) == RING_SPSC_LOCKFREE_D60_OK);
    return 0;
}
