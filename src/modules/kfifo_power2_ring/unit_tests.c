#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t backing[16], tmp[16], out[16];
    kfifo_t q;
    assert(kfifo_init(&q, backing, 16) == KFIFO_POWER2_RING_OK);
    q.in = UINT32_MAX - 3U;
    q.out = q.in;
    for (size_t i = 0; i < 12; ++i) tmp[i] = (uint8_t)(0x40 + i);
    assert(kfifo_in(&q, tmp, 12) == 12);
    assert(kfifo_len(&q) == 12 && kfifo_avail(&q) == 4);
    assert(kfifo_peek(&q, out, 12) == 12 && memcmp(tmp, out, 12) == 0);
    assert(kfifo_out(&q, out, 12) == 12 && kfifo_len(&q) == 0);
    assert(kfifo_verify_invariants(&q) == KFIFO_POWER2_RING_OK);
    return 0;
}
