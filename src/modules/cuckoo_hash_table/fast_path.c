#include "interface.h"

bool cuckoo_hash_table_lookup_fast(const cuckoo_map_t* m, uint64_t key, int64_t* out_val) {
    return cuckoo_hash_table_lookup(m, key, out_val);
}
