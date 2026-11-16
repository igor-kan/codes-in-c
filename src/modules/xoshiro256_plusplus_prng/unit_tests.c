#include "interface.h"
#include <assert.h>

int main(void) {
    xoshiro256pp_state_t a, b;
    xoshiro_seed(&a, 0x1234ULL);
    xoshiro_seed(&b, 0x1234ULL);
    for (int i = 0; i < 64; ++i) assert(xoshiro_next(&a) == xoshiro_next(&b));
    xoshiro256pp_state_t c = a;
    xoshiro_jump(&c);
    assert(xoshiro_next(&a) != xoshiro_next(&c));
    assert(xoshiro_verify_invariants(&c) == XOSHIRO256_PLUSPLUS_PRNG_OK);
    return 0;
}
