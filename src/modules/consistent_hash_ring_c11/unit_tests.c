#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(consistent_hash_ring_c11_validate_len(1) == CONSISTENT_HASH_RING_C11_OK);
    hash_ring_t ring; hring_init(&ring);
    hring_add_node(&ring, 10, 16);
    hring_add_node(&ring, 20, 16);
    int32_t owner = hring_locate(&ring, 123456ULL);
    assert(owner == 10 || owner == 20);
    assert(consistent_hash_ring_c11_verify_guard(true) == CONSISTENT_HASH_RING_C11_OK);
    return 0;
}
