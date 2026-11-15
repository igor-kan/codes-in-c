#include "interface.h"

utf8_dfa_decoder_err_t utf8_dfa_decoder_validate_range(uint32_t codep) {
    if (codep > 0x10FFFFU || (codep >= 0xD800U && codep <= 0xDFFFU)) return UTF8_DFA_DECODER_ERR_INVALID;
    return UTF8_DFA_DECODER_OK;
}
