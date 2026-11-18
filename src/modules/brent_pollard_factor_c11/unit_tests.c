#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(brent_pollard_factor_c11_validate_len(1) == BRENT_POLLARD_FACTOR_C11_OK);
    uint64_t n = 10403ULL; /* 101 * 103 */
    uint64_t f = brent_pollard_rho(n, 1);
    assert((f == 101ULL || f == 103ULL) && n % f == 0);
    assert(brent_pollard_factor_c11_verify_guard(true) == BRENT_POLLARD_FACTOR_C11_OK);
    return 0;
}
