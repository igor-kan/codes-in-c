#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(robin_hood_hash_d60_validate_len(1) == ROBIN_HOOD_HASH_D60_OK);
    rh_map_t m; rh_init_d60(&m);
    assert(rh_put_d60(&m, 42ULL, 9001LL));
    assert(rh_put_d60(&m, 106ULL, -55LL));
    int64_t v = 0;
    assert(rh_get_d60(&m, 42ULL, &v) && v == 9001LL);
    assert(rh_get_d60(&m, 106ULL, &v) && v == -55LL);
    assert(robin_hood_hash_d60_verify_guard(true) == ROBIN_HOOD_HASH_D60_OK);
    return 0;
}
