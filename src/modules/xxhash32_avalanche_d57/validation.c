#include "interface.h"

xxhash32_avalanche_d57_err_t xxhash32_avalanche_d57_validate_len(size_t n) {
    if (n == 0) {
        return XXHASH32_AVALANCHE_D57_ERR_INVALID;
    }
    return XXHASH32_AVALANCHE_D57_OK;
}
