#include "interface.h"

utf8_dfa_decoder_err_t utf8_dfa_decoder_batch_check(const uint8_t** strs, const size_t* lens, size_t* cp_counts, size_t k) {
    if (!strs || !lens || !cp_counts) return UTF8_DFA_DECODER_ERR_NULL;
    for (size_t i = 0; i < k; ++i) {
        utf8_dfa_decoder_err_t e = utf8_dfa_decoder_count(strs[i], lens[i], &cp_counts[i]);
        if (e != UTF8_DFA_DECODER_OK) return e;
    }
    return UTF8_DFA_DECODER_OK;
}
