#include "interface.h"
#include <assert.h>

int main(void) {
    uint64_t freq[10];
    assert(reservoir_mt_histogram(3, 10, 4000, freq, 4) == RESERVOIR_SAMPLING_VITTER_OK);
    // Expected count per index = 3/10 * 4000 = 1200. Verify within generous +-20% tolerance.
    for (int i = 0; i < 10; ++i) {
        assert(freq[i] > 950 && freq[i] < 1450);
    }
    return 0;
}
