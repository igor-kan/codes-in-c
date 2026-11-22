#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(utf8_dfa_valid_c11_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t surr[3] = {0xEDu, 0xA0u, 0x80u};
    size_t cnt = 0;
    assert(utf8_count_codepoints(surr, 3, &cnt) == -1);
    return 0;
}
