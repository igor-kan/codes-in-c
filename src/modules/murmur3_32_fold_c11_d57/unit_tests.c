#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(murmur3_32_fold_c11_d57_validate_len(1) == MURMUR3_32_FOLD_C11_D57_OK);
    assert(murmur3_32(NULL, 0, 0u) == 0u);
    const uint8_t k[4] = {1, 2, 3, 4};
    assert(murmur3_32(k, 4, 42u) != murmur3_32(k, 4, 43u));
    assert(murmur3_32_fold_c11_d57_verify_guard(true) == MURMUR3_32_FOLD_C11_D57_OK);
    return 0;
}
