#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t ascii[256];
    for (size_t i = 0; i < 256; ++i) ascii[i] = (uint8_t)(' ' + (i % 90));
    assert(utf8_dfa_decoder_ascii_fast(ascii, 256) == 256);
    size_t cps = 0;
    assert(utf8_dfa_decoder_count(ascii, 256, &cps) == UTF8_DFA_DECODER_OK && cps == 256);
    // Truncated 3-byte sequence must reject
    const uint8_t trunc[2] = {0xE2, 0x82};
    assert(utf8_dfa_decoder_count(trunc, 2, &cps) == UTF8_DFA_DECODER_ERR_INVALID);
    return 0;
}
