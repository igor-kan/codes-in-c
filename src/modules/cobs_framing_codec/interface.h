#ifndef COBS_FRAMING_CODEC_INTERFACE_H
#define COBS_FRAMING_CODEC_INTERFACE_H

#include "types.h"
#include "errors.h"

cobs_framing_codec_err_t cobs_encode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len);
cobs_framing_codec_err_t cobs_decode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len);
cobs_framing_codec_err_t cobs_validate_buf(const uint8_t* src, size_t len, const uint8_t* dst, size_t cap);
size_t cobs_max_encoded_size(size_t src_len);
cobs_framing_codec_err_t cobs_encode_fast(const uint8_t* src, size_t len, uint8_t* dst, size_t* out_len);
cobs_framing_codec_err_t cobs_batch_roundtrip_mt(const uint8_t** srcs, const size_t* lens, size_t n_items, size_t num_threads);
cobs_framing_codec_err_t cobs_verify_invariants(const uint8_t* payload, size_t len);

#endif /* COBS_FRAMING_CODEC_INTERFACE_H */
