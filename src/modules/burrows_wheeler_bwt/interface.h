#ifndef BURROWS_WHEELER_BWT_INTERFACE_H
#define BURROWS_WHEELER_BWT_INTERFACE_H

#include "types.h"
#include "errors.h"

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_forward(const uint8_t* src, size_t n, uint8_t* out_bwt, size_t* primary_idx);
burrows_wheeler_bwt_err_t burrows_wheeler_bwt_inverse(const uint8_t* bwt, size_t n, size_t primary_idx, uint8_t* out_src);
burrows_wheeler_bwt_err_t burrows_wheeler_bwt_mtf_encode(const uint8_t* src, size_t n, uint8_t* out);
burrows_wheeler_bwt_err_t burrows_wheeler_bwt_mtf_decode(const uint8_t* src, size_t n, uint8_t* out);
burrows_wheeler_bwt_err_t burrows_wheeler_bwt_validate(size_t n, size_t primary_idx);
burrows_wheeler_bwt_err_t burrows_wheeler_bwt_inverse_fast(const uint8_t* bwt, size_t n, size_t primary_idx, uint8_t* out_src);
burrows_wheeler_bwt_err_t burrows_wheeler_bwt_batch(const uint8_t** blocks, const size_t* lens, size_t count);
burrows_wheeler_bwt_err_t burrows_wheeler_bwt_verify_bijection(const uint8_t* src, size_t n);

#endif /* BURROWS_WHEELER_BWT_INTERFACE_H */
