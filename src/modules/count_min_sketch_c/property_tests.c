#include "interface.h"
#include <assert.h>

int main(void) {
    cms_sketch_t cm, cu;
    assert(count_min_sketch_c_init(&cm, 4, 128) == COUNT_MIN_SKETCH_C_OK);
    assert(count_min_sketch_c_init(&cu, 4, 128) == COUNT_MIN_SKETCH_C_OK);
    for (uint64_t k = 0; k < 400; ++k) {
        uint64_t item = k % 50;
        count_min_sketch_c_add_standard(&cm, item, 1);
        count_min_sketch_c_add_conservative(&cu, item, 1);
    }
    for (uint64_t item = 0; item < 50; ++item) {
        uint64_t q_cm = count_min_sketch_c_query(&cm, item);
        uint64_t q_cu = count_min_sketch_c_query(&cu, item);
        assert(q_cu >= 8 && q_cu <= q_cm); // Conservative never exceeds standard and never underestimates
    }
    count_min_sketch_c_free(&cm);
    count_min_sketch_c_free(&cu);
    return 0;
}
