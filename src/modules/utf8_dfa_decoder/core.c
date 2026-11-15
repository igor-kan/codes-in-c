#include "interface.h"

static const uint8_t UTF8D[] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
  8,8,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
  10,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,11,6,6,6,5,8,8,8,8,8,8,8,8,8,8,8,

  0,12,24,36,60,96,84,12,12,12,48,72, 12,12,12,12,12,12,12,12,12,12,12,12,
  12, 0,12,12,12,12,12, 0,12, 0,12,12, 12,24,12,12,12,12,12,24,12,24,12,12,
  12,12,12,12,12,12,12,24,12,12,12,12, 12,24,12,12,12,12,12,12,12,24,12,12,
  12,12,12,12,12,12,12,36,12,36,12,12, 12,36,12,12,12,12,12,36,12,36,12,12,
  12,36,12,12,12,12,12,12,12,12,12,12,
};

uint32_t utf8_dfa_decoder_step(uint32_t* state, uint32_t* codep, uint8_t byte) {
    uint32_t type = UTF8D[byte];
    *codep = (*state != UTF8_DFA_ACCEPT) ? ((byte & 0x3fU) | (*codep << 6)) : ((0xffU >> type) & byte);
    *state = UTF8D[256U + *state + type];
    return *state;
}

utf8_dfa_decoder_err_t utf8_dfa_decoder_count(const uint8_t* data, size_t len, size_t* out_codepoints) {
    if (!out_codepoints || (len > 0 && !data)) return UTF8_DFA_DECODER_ERR_NULL;
    uint32_t state = 0, cp = 0;
    size_t count = 0;
    for (size_t i = 0; i < len; ++i) {
        if (utf8_dfa_decoder_step(&state, &cp, data[i]) == UTF8_DFA_ACCEPT) count++;
        else if (state == UTF8_DFA_REJECT) return UTF8_DFA_DECODER_ERR_INVALID;
    }
    if (state != UTF8_DFA_ACCEPT) return UTF8_DFA_DECODER_ERR_INVALID;
    *out_codepoints = count;
    return UTF8_DFA_DECODER_OK;
}
