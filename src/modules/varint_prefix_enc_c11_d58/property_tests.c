#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(varint_prefix_enc_c11_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t buf[2];
    assert(pvar_encode(42ULL, buf) == 1);
    uint64_t o = 0; size_t u = 0;
    assert(pvar_decode(buf, 1, &o, &u) == 0 && o == 42ULL);
    return 0;
}
