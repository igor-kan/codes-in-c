#include "interface.h"

miller_rabin_det64_d60_err_t miller_rabin_det64_d60_validate_len(size_t n) {
    if (n == 0) {
        return MILLER_RABIN_DET64_D60_ERR_INVALID;
    }
    return MILLER_RABIN_DET64_D60_OK;
}
