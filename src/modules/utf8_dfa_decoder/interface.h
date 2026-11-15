#ifndef UTF8_DFA_DECODER_INTERFACE_H
#define UTF8_DFA_DECODER_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t utf8_dfa_decoder_step(uint32_t* state, uint32_t* codep, uint8_t byte);
utf8_dfa_decoder_err_t utf8_dfa_decoder_count(const uint8_t* data, size_t len, size_t* out_codepoints);
utf8_dfa_decoder_err_t utf8_dfa_decoder_validate_range(uint32_t codep);
size_t utf8_dfa_decoder_ascii_fast(const uint8_t* data, size_t len);
utf8_dfa_decoder_err_t utf8_dfa_decoder_batch_check(const uint8_t** strs, const size_t* lens, size_t* cp_counts, size_t k);
utf8_dfa_decoder_err_t utf8_dfa_decoder_check_invariants(const uint8_t* data, size_t len);

#endif /* UTF8_DFA_DECODER_INTERFACE_H */
