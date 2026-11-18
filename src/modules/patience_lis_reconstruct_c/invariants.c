#include "interface.h"

patience_lis_reconstruct_c_err_t patience_lis_reconstruct_c_verify_guard(bool cond) {
    if (!cond) {
        return PATIENCE_LIS_RECONSTRUCT_C_ERR_INVARIANT;
    }
    return PATIENCE_LIS_RECONSTRUCT_C_OK;
}
