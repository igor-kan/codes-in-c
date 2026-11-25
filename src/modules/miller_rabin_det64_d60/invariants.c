#include "interface.h"

miller_rabin_det64_d60_err_t miller_rabin_det64_d60_verify_guard(bool cond) {
    if (!cond) {
        return MILLER_RABIN_DET64_D60_ERR_INVARIANT;
    }
    return MILLER_RABIN_DET64_D60_OK;
}
