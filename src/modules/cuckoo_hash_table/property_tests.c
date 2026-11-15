#include "interface.h"
#include <assert.h>

int main(void) {
    cuckoo_map_t m;
    assert(cuckoo_hash_table_init(&m, 1024) == CUCKOO_HASH_TABLE_OK);
    for (uint64_t i = 0; i < 600; ++i) {
        assert(cuckoo_hash_table_insert(&m, i + 100000ULL, (int64_t)i) == CUCKOO_HASH_TABLE_OK);
    }
    for (uint64_t i = 0; i < 600; ++i) {
        int64_t val = -1;
        assert(cuckoo_hash_table_lookup_fast(&m, i + 100000ULL, &val) && val == (int64_t)i);
    }
    assert(cuckoo_hash_table_check_invariants(&m) == CUCKOO_HASH_TABLE_OK);
    cuckoo_hash_table_free(&m);
    return 0;
}
