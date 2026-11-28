#include "interface.h"

base58_btc_d61_err_t base58_btc_d61_verify_guard(bool cond) {
    if (!cond) {
        return BASE58_BTC_D61_ERR_INVARIANT;
    }
    return BASE58_BTC_D61_OK;
}
