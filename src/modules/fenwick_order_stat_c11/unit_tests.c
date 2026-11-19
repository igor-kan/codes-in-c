#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(fenwick_order_stat_c11_validate_len(1) == FENWICK_ORDER_STAT_C11_OK);
    os_fenwick_t f; os_init(&f, 16);
    os_add(&f, 2, 3); os_add(&f, 5, 2); os_add(&f, 10, 4);
    assert(os_kth(&f, 1) == 2 && os_kth(&f, 3) == 2 && os_kth(&f, 4) == 5 && os_kth(&f, 7) == 10);
    assert(fenwick_order_stat_c11_verify_guard(true) == FENWICK_ORDER_STAT_C11_OK);
    return 0;
}
