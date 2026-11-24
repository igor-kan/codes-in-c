#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(utf16_surrogate_c11_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint16_t bad[2] = {0xD800u, 0u}; uint32_t cp = 0; size_t tmp_nu = 0;
    assert(utf16_to_cp(bad, 1, &cp) == -1);
    assert(cp_to_utf16(0xD800u, bad, &tmp_nu) == -1);
    return 0;
}
