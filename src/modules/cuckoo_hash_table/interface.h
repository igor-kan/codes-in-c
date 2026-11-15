#ifndef CUCKOO_HASH_TABLE_INTERFACE_H
#define CUCKOO_HASH_TABLE_INTERFACE_H

#include "types.h"
#include "errors.h"

cuckoo_hash_table_err_t cuckoo_hash_table_init(cuckoo_map_t* m, size_t half_cap);
void cuckoo_hash_table_free(cuckoo_map_t* m);
cuckoo_hash_table_err_t cuckoo_hash_table_insert(cuckoo_map_t* m, uint64_t key, int64_t val);
bool cuckoo_hash_table_lookup(const cuckoo_map_t* m, uint64_t key, int64_t* out_val);
bool cuckoo_hash_table_remove(cuckoo_map_t* m, uint64_t key);
cuckoo_hash_table_err_t cuckoo_hash_table_validate(const cuckoo_map_t* m);
bool cuckoo_hash_table_lookup_fast(const cuckoo_map_t* m, uint64_t key, int64_t* out_val);
cuckoo_hash_table_err_t cuckoo_hash_table_batch_lookup(const cuckoo_map_t* m, const uint64_t* keys, int64_t* vals, uint8_t* found, size_t n);
cuckoo_hash_table_err_t cuckoo_hash_table_check_invariants(const cuckoo_map_t* m);

#endif /* CUCKOO_HASH_TABLE_INTERFACE_H */
