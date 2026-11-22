#ifndef UTF8_DFA_VALID_C11_D57_TYPES_H
#define UTF8_DFA_VALID_C11_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int valid;
    size_t codepoints;
} utf8_scan_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} utf8_dfa_valid_c11_d57_meta_t;

#endif /* UTF8_DFA_VALID_C11_D57_TYPES_H */
