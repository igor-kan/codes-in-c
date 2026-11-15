#include "interface.h"
#include <pthread.h>

cuckoo_hash_table_err_t cuckoo_hash_table_batch_lookup(const cuckoo_map_t* m, const uint64_t* keys, int64_t* vals, uint8_t* found, size_t n) {
    if (!m || !keys || !vals || !found) return CUCKOO_HASH_TABLE_ERR_NULL;
    for (size_t i = 0; i < n; ++i) {
        found[i] = cuckoo_hash_table_lookup(m, keys[i], &vals[i]) ? 1 : 0;
    }
    return CUCKOO_HASH_TABLE_OK;
}
