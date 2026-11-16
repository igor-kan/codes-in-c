#ifndef RLE_PACKBITS_CODEC_INTERFACE_H
#define RLE_PACKBITS_CODEC_INTERFACE_H

#include "types.h"
#include "errors.h"

rle_packbits_codec_err_t packbits_encode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len);
rle_packbits_codec_err_t packbits_decode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len);
size_t packbits_worst_case_size(size_t src_len);
rle_packbits_codec_err_t packbits_encode_fast(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len);
rle_packbits_codec_err_t packbits_batch_mt(const uint8_t** srcs, const size_t* lens, size_t n_items, size_t num_threads);
rle_packbits_codec_err_t packbits_verify_roundtrip(const uint8_t* src, size_t len);

#endif /* RLE_PACKBITS_CODEC_INTERFACE_H */
