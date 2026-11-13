/**
 * @file core.c
 * @brief FNV-1a 64-bit non-cryptographic hash algorithm for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#include "types.c"
#include <stdint.h>

#define FNV_OFFSET_BASIS_64 14695981039346656037ULL
#define FNV_PRIME_64 1099511628211ULL

uint64_t hash_fnv1a_64_hash(const void* data, size_t len) {
    if (!data || len == 0) return 0;
    const uint8_t* ptr = (const uint8_t*)data;
    uint64_t hash = FNV_OFFSET_BASIS_64;
    for (size_t i = 0; i < len; ++i) {
        hash ^= (uint64_t)ptr[i];
        hash *= FNV_PRIME_64;
    }
    return hash;
}
