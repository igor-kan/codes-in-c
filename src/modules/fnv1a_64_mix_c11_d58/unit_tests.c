#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(fnv1a_64_mix_c11_d58_validate_len(1) == FNV1A_64_MIX_C11_D58_OK);
    const uint8_t full[6] = {'f','o','o','b','a','r'};
    fnv1a_stream_t s1, s2;
    fnv1a_init(&s1); fnv1a_update(&s1, full, 6);
    fnv1a_init(&s2); fnv1a_update(&s2, full, 3); fnv1a_update(&s2, full + 3, 3);
    assert(s1.state == s2.state && s1.state == 0x85944171F73967E8ULL);
    assert(fnv1a_64_mix_c11_d58_verify_guard(true) == FNV1A_64_MIX_C11_D58_OK);
    return 0;
}
