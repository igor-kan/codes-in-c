#include "interface.h"

uint16_t qf_fast_fingerprint(uint64_t key, uint32_t* out_quotient) {
    uint64_t x = key ^ (key >> 33);
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    *out_quotient = (uint32_t)((x >> QF_R_BITS) & (QF_SLOTS - 1U));
    return (uint16_t)(x & ((1U << QF_R_BITS) - 1U));
}
