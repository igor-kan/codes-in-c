#include "interface.h"
#include <assert.h>

int main(void) {
    cuckoo_map_t m;
    assert(cuckoo_hash_table_init(&m, 256) == CUCKOO_HASH_TABLE_OK);
    for (uint64_t i = 1; i <= 150; ++i) {
        assert(cuckoo_hash_table_insert(&m, i * 1009ULL, (int64_t)(i * 7)) == CUCKOO_HASH_TABLE_OK);
    }
    assert(m.count == 150);
    int64_t v = 0;
    assert(cuckoo_hash_table_lookup(&m, 42 * 1009ULL, &v) && v == 294);
    assert(cuckoo_hash_table_remove(&m, 42 * 1009ULL));
    assert(!cuckoo_hash_table_lookup(&m, 42 * 1009ULL, &v));
    assert(cuckoo_hash_table_check_invariants(&m) == CUCKOO_HASH_TABLE_OK);
    cuckoo_hash_table_free(&m);
    return 0;
}
