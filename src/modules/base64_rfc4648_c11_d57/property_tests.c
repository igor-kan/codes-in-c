#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(base64_rfc4648_c11_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t one[1] = {'f'};
    uint8_t e1[4], d1[4];
    size_t dl = 0;
    assert(b64_encode(one, 1, e1) == 4 && e1[2] == '=' && e1[3] == '=');
    assert(b64_decode(e1, 4, d1, &dl) == 0 && dl == 1 && d1[0] == 'f');
    return 0;
}
