#include "interface.h"

utf8_dfa_decoder_err_t utf8_dfa_decoder_check_invariants(const uint8_t* data, size_t len) {
    size_t count = 0;
    utf8_dfa_decoder_err_t e = utf8_dfa_decoder_count(data, len, &count);
    if (e == UTF8_DFA_DECODER_OK && count > len) return UTF8_DFA_DECODER_ERR_INVARIANT;
    return e;
}
