#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(jenkins_oaat_c11_d59_validate_len(1) == JENKINS_OAAT_C11_D59_OK);
    const uint8_t a[1] = {'a'};
    assert(jenkins_oaat32(a, 1) == 0xCA2E9442u);
    assert(jenkins_oaat_c11_d59_verify_guard(true) == JENKINS_OAAT_C11_D59_OK);
    return 0;
}
