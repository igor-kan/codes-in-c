#include "interface.h"
#include <assert.h>

int main(void) {
    // "Hi € 🚀" -> 2 + 1 + 1 + 1 + 1 = 6 codepoints in UTF-8 (11 bytes)
    const uint8_t valid[] = {'H','i',' ',0xE2,0x82,0xAC,' ',0xF0,0x9F,0x9A,0x80};
    size_t cps = 0;
    assert(utf8_dfa_decoder_count(valid, sizeof(valid), &cps) == UTF8_DFA_DECODER_OK);
    assert(cps == 6);
    assert(utf8_dfa_decoder_ascii_fast(valid, sizeof(valid)) == 3);

    // Surrogate U+D800: ED A0 80 must reject
    const uint8_t bad_surr[] = {0xED, 0xA0, 0x80};
    assert(utf8_dfa_decoder_count(bad_surr, 3, &cps) == UTF8_DFA_DECODER_ERR_INVALID);
    // Overlong '/': C0 AF must reject
    const uint8_t bad_over[] = {0xC0, 0xAF};
    assert(utf8_dfa_decoder_count(bad_over, 2, &cps) == UTF8_DFA_DECODER_ERR_INVALID);
    return 0;
}
