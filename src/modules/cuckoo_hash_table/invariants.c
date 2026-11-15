#include "interface.h"

cuckoo_hash_table_err_t cuckoo_hash_table_check_invariants(const cuckoo_map_t* m) {
    if (!m || !m->t1 || !m->t2) return CUCKOO_HASH_TABLE_ERR_NULL;
    size_t active = 0;
    for (size_t i = 0; i < m->cap; ++i) {
        if (m->t1[i].occupied) active++;
        if (m->t2[i].occupied) active++;
    }
    return (active == m->count) ? CUCKOO_HASH_TABLE_OK : CUCKOO_HASH_TABLE_ERR_INVARIANT;
}
