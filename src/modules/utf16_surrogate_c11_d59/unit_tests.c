#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(utf16_surrogate_c11_d59_validate_len(1) == UTF16_SURROGATE_C11_D59_OK);
    uint16_t u[2]; size_t nu = 0; uint32_t rec = 0;
    assert(cp_to_utf16(0x1F680u, u, &nu) == 0 && nu == 2 && u[0] == 0xD83Du && u[1] == 0xDE80u);
    assert(utf16_to_cp(u, 2, &rec) == 0 && rec == 0x1F680u);
    assert(utf16_surrogate_c11_d59_verify_guard(true) == UTF16_SURROGATE_C11_D59_OK);
    return 0;
}
