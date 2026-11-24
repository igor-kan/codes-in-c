#include "interface.h"

jenkins_oaat_c11_d59_err_t jenkins_oaat_c11_d59_verify_guard(bool cond) {
    if (!cond) {
        return JENKINS_OAAT_C11_D59_ERR_INVARIANT;
    }
    return JENKINS_OAAT_C11_D59_OK;
}
