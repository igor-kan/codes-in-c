#include "interface.h"

xxhash32_avalanche_d57_err_t xxhash32_avalanche_d57_verify_guard(bool cond) {
    if (!cond) {
        return XXHASH32_AVALANCHE_D57_ERR_INVARIANT;
    }
    return XXHASH32_AVALANCHE_D57_OK;
}
