#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(utf8_dfa_valid_c11_d57_validate_len(1) == UTF8_DFA_VALID_C11_D57_OK);
    const uint8_t ok[7] = {'h','i', 0xC3u, 0xA9u, 0xE2u, 0x82u, 0xACu};
    size_t cnt = 0;
    assert(utf8_count_codepoints(ok, 7, &cnt) == 0 && cnt == 4);
    const uint8_t overlong[2] = {0xC0u, 0xAFu};
    assert(utf8_count_codepoints(overlong, 2, &cnt) == -1);
    assert(utf8_dfa_valid_c11_d57_verify_guard(true) == UTF8_DFA_VALID_C11_D57_OK);
    return 0;
}
