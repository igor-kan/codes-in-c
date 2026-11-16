#include "interface.h"

xoshiro256_plusplus_prng_err_t xoshiro_verify_invariants(const xoshiro256pp_state_t* st) {
    if (!st || (st->s[0] | st->s[1] | st->s[2] | st->s[3]) == 0ULL) {
        return XOSHIRO256_PLUSPLUS_PRNG_ERR_INVARIANT;
    }
    return XOSHIRO256_PLUSPLUS_PRNG_OK;
}
