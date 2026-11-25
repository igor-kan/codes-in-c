#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(miller_rabin_det64_d60_validate_len(1) == MILLER_RABIN_DET64_D60_OK);
    assert(is_prime_u64_d60(2ULL));
    assert(is_prime_u64_d60(2147483647ULL));
    assert(!is_prime_u64_d60(341550071728321ULL));
    assert(miller_rabin_det64_d60_verify_guard(true) == MILLER_RABIN_DET64_D60_OK);
    return 0;
}
