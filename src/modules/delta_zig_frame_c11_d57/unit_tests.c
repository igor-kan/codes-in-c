#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(delta_zig_frame_c11_d57_validate_len(1) == DELTA_ZIG_FRAME_C11_D57_OK);
    const int64_t ts[6] = {1000, 1060, 1120, 1185, 1245, 1305};
    int64_t enc[6], dec[6];
    delta_encode(ts, 6, enc);
    assert(enc[2] == 0 && enc[3] == 5);
    delta_decode(enc, 6, dec);
    assert(memcmp(ts, dec, sizeof(ts)) == 0);
    assert(delta_zig_frame_c11_d57_verify_guard(true) == DELTA_ZIG_FRAME_C11_D57_OK);
    return 0;
}
