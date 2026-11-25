#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(buddy_alloc_order_d60_validate_len(1) == BUDDY_ALLOC_ORDER_D60_OK);
    buddy_pool_t bp; buddy_init_d60(&bp);
    int a = buddy_alloc_d60(&bp, 2);
    int b = buddy_alloc_d60(&bp, 2);
    assert(a == 0 && b == 4);
    buddy_free_d60(&bp, a, 2);
    int c = buddy_alloc_d60(&bp, 2);
    assert(c == 0);
    assert(buddy_alloc_order_d60_verify_guard(true) == BUDDY_ALLOC_ORDER_D60_OK);
    return 0;
}
