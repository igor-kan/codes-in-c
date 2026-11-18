#include "interface.h"

patience_lis_reconstruct_c_err_t patience_lis_reconstruct_c_validate_len(size_t n) {
    if (n == 0) {
        return PATIENCE_LIS_RECONSTRUCT_C_ERR_INVALID;
    }
    return PATIENCE_LIS_RECONSTRUCT_C_OK;
}
