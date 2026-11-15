#include "interface.h"

cuckoo_hash_table_err_t cuckoo_hash_table_validate(const cuckoo_map_t* m) {
    if (!m || !m->t1 || !m->t2) return CUCKOO_HASH_TABLE_ERR_NULL;
    if ((m->cap & (m->cap - 1)) != 0 || m->count > 2 * m->cap) return CUCKOO_HASH_TABLE_ERR_INVALID;
    return CUCKOO_HASH_TABLE_OK;
}
