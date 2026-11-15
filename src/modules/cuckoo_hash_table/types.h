#ifndef CUCKOO_HASH_TABLE_TYPES_H
#define CUCKOO_HASH_TABLE_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define CUCKOO_MAX_KICKS 64U
typedef struct {
    uint64_t key;
    int64_t value;
    uint8_t occupied;
} cuckoo_slot_t;

typedef struct {
    cuckoo_slot_t* t1;
    cuckoo_slot_t* t2;
    size_t cap;
    size_t count;
} cuckoo_map_t;

#endif /* CUCKOO_HASH_TABLE_TYPES_H */
