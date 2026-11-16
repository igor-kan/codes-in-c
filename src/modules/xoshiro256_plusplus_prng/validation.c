#include "interface.h"

xoshiro256_plusplus_prng_err_t xoshiro_validate_state(const xoshiro256pp_state_t* st) {
    if (!st) return XOSHIRO256_PLUSPLUS_PRNG_ERR_NULL;
    if ((st->s[0] | st->s[1] | st->s[2] | st->s[3]) == 0ULL) return XOSHIRO256_PLUSPLUS_PRNG_ERR_INVALID;
    return XOSHIRO256_PLUSPLUS_PRNG_OK;
}
