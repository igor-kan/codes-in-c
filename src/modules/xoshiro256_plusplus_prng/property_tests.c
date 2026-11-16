#include "interface.h"
#include <assert.h>

int main(void) {
    xoshiro256pp_state_t st;
    xoshiro_seed(&st, 0xDEADBEEFULL);
    uint64_t buf[256];
    xoshiro_fill_batch(&st, buf, 256);
    int ones = 0;
    for (int i = 0; i < 256; ++i) ones += __builtin_popcountll(buf[i]);
    // 256 * 64 = 16384 bits -> expect ~8192 ones
    assert(ones > 7600 && ones < 8800);
    uint64_t x1 = 0, x2 = 0;
    assert(xoshiro_parallel_reduce_mt(777ULL, 500, &x1, 4) == XOSHIRO256_PLUSPLUS_PRNG_OK);
    assert(xoshiro_parallel_reduce_mt(777ULL, 500, &x2, 4) == XOSHIRO256_PLUSPLUS_PRNG_OK);
    assert(x1 == x2 && x1 != 0);
    return 0;
}
