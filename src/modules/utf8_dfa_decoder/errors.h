#ifndef UTF8_DFA_DECODER_ERRORS_H
#define UTF8_DFA_DECODER_ERRORS_H

typedef enum utf8_dfa_decoder_err {
    UTF8_DFA_DECODER_OK = 0,
    UTF8_DFA_DECODER_ERR_NULL = -1,
    UTF8_DFA_DECODER_ERR_BOUNDS = -2,
    UTF8_DFA_DECODER_ERR_INVALID = -3,
    UTF8_DFA_DECODER_ERR_OVERFLOW = -4,
    UTF8_DFA_DECODER_ERR_INVARIANT = -5
} utf8_dfa_decoder_err_t;



static inline const char* utf8_dfa_decoder_err_str(utf8_dfa_decoder_err_t err) {
    switch (err) {
        case UTF8_DFA_DECODER_OK: return "ok";
        case UTF8_DFA_DECODER_ERR_NULL: return "null pointer supplied";
        case UTF8_DFA_DECODER_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case UTF8_DFA_DECODER_ERR_INVALID: return "domain precondition violated";
        case UTF8_DFA_DECODER_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case UTF8_DFA_DECODER_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* UTF8_DFA_DECODER_ERRORS_H */
