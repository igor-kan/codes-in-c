#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    // Sorted cyclic rotations of "BANANA": ABANAN(N), ANABAN(N), ANANAB(B), BANANA(A), NABANA(A), NANABA(A)
    const char* s = "BANANA";
    uint8_t bwt[6], rec[6], mtf[6], unmtf[6];
    size_t pidx = 999;
    assert(burrows_wheeler_bwt_forward((const uint8_t*)s, 6, bwt, &pidx) == BURROWS_WHEELER_BWT_OK);
    assert(memcmp(bwt, "NNBAAA", 6) == 0);
    assert(pidx == 3);
    assert(burrows_wheeler_bwt_inverse(bwt, 6, pidx, rec) == BURROWS_WHEELER_BWT_OK);
    assert(memcmp(rec, s, 6) == 0);

    assert(burrows_wheeler_bwt_mtf_encode(bwt, 6, mtf) == BURROWS_WHEELER_BWT_OK);
    assert(burrows_wheeler_bwt_mtf_decode(mtf, 6, unmtf) == BURROWS_WHEELER_BWT_OK);
    assert(memcmp(unmtf, bwt, 6) == 0);
    return 0;
}
