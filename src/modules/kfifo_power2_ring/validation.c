#include "interface.h"

kfifo_power2_ring_err_t kfifo_validate(const kfifo_t* q) {
    if (!q || !q->data) return KFIFO_POWER2_RING_ERR_NULL;
    size_t cap = (size_t)q->mask + 1U;
    if (cap < 2 || (cap & (cap - 1U)) != 0 || kfifo_len(q) > cap) return KFIFO_POWER2_RING_ERR_BOUNDS;
    return KFIFO_POWER2_RING_OK;
}
