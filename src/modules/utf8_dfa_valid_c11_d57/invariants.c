#include "interface.h"

utf8_dfa_valid_c11_d57_err_t utf8_dfa_valid_c11_d57_verify_guard(bool cond) {
    if (!cond) {
        return UTF8_DFA_VALID_C11_D57_ERR_INVARIANT;
    }
    return UTF8_DFA_VALID_C11_D57_OK;
}
