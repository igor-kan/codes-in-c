#include "interface.h"
#include <assert.h>

int main(void) {
    assert(kfifo_mt_test_batches(300) == KFIFO_POWER2_RING_OK);
    return 0;
}
