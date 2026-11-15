#ifndef UTF8_DFA_DECODER_TYPES_H
#define UTF8_DFA_DECODER_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define UTF8_DFA_ACCEPT 0U
#define UTF8_DFA_REJECT 12U
typedef struct {
    uint32_t state;
    uint32_t codepoint;
    size_t codepoint_count;
} utf8_dfa_cursor_t;

#endif /* UTF8_DFA_DECODER_TYPES_H */
