#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(xxhash32_avalanche_d57_validate_len(1) == XXHASH32_AVALANCHE_D57_OK);
    const uint8_t d[3] = {'a','b','c'};
    assert(xxhash32_compute(d, 0, 0u) == 0x02CC5D05u);
    assert(xxhash32_compute(d, 3, 0u) == 0x32D153FFu);
    assert(xxhash32_avalanche_d57_verify_guard(true) == XXHASH32_AVALANCHE_D57_OK);
    return 0;
}
