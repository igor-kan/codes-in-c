#include "interface.h"

utf8_dfa_valid_c11_d57_err_t utf8_dfa_valid_c11_d57_validate_len(size_t n) {
    if (n == 0) {
        return UTF8_DFA_VALID_C11_D57_ERR_INVALID;
    }
    return UTF8_DFA_VALID_C11_D57_OK;
}
