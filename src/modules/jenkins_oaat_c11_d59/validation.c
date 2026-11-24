#include "interface.h"

jenkins_oaat_c11_d59_err_t jenkins_oaat_c11_d59_validate_len(size_t n) {
    if (n == 0) {
        return JENKINS_OAAT_C11_D59_ERR_INVALID;
    }
    return JENKINS_OAAT_C11_D59_OK;
}
