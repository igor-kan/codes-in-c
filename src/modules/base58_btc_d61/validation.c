#include "interface.h"

base58_btc_d61_err_t base58_btc_d61_validate_len(size_t n) {
    if (n == 0) {
        return BASE58_BTC_D61_ERR_INVALID;
    }
    return BASE58_BTC_D61_OK;
}
