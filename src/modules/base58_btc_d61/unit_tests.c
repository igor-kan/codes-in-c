#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(base58_btc_d61_validate_len(1) == BASE58_BTC_D61_OK);
    uint8_t zeros[2] = {0, 0};
    base58_string_t enc;
    assert(base58_encode(zeros, 2, &enc) == 2);
    assert(enc.length == 2 && enc.text[0] == '1' && enc.text[1] == '1');
    uint8_t one[1] = {1};
    assert(base58_encode(one, 1, &enc) == 1);
    assert(enc.length == 1 && enc.text[0] == '2');
    assert(base58_btc_d61_verify_guard(true) == BASE58_BTC_D61_OK);
    return 0;
}
