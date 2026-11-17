#ifndef PAIRING_HEAP_C11_INTERFACE_H
#define PAIRING_HEAP_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

pairing_heap_c11_err_t ph_init(pairing_heap_t* h);
pairing_heap_c11_err_t ph_push(pairing_heap_t* h, int64_t key, int32_t val, int32_t* out_id);
pairing_heap_c11_err_t ph_decrease_key(pairing_heap_t* h, int32_t id, int64_t new_key);
pairing_heap_c11_err_t ph_pop_min(pairing_heap_t* h, int64_t* out_key, int32_t* out_val);
pairing_heap_c11_err_t ph_validate_handle(const pairing_heap_t* h, int32_t id);
void ph_fast_sort(int64_t* arr, size_t n);
void ph_parallel_sort_pair(int64_t* a, size_t na, int64_t* b, size_t nb);
pairing_heap_c11_err_t ph_verify_invariants(const pairing_heap_t* h);

#endif /* PAIRING_HEAP_C11_INTERFACE_H */
