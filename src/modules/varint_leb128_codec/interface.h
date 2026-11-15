#ifndef VARINT_LEB128_CODEC_INTERFACE_H
#define VARINT_LEB128_CODEC_INTERFACE_H

#include "types.h"
#include "errors.h"

varint_leb128_codec_err_t varint_leb128_codec_encode_u64(uint64_t val, uint8_t* out, size_t cap, size_t* written);
varint_leb128_codec_err_t varint_leb128_codec_decode_u64(const uint8_t* in, size_t len, uint64_t* out_val, size_t* consumed);
uint64_t varint_leb128_codec_zigzag_encode(int64_t v);
int64_t varint_leb128_codec_zigzag_decode(uint64_t u);
varint_leb128_codec_err_t varint_leb128_codec_encode_batch_fast(const uint64_t* vals, size_t n, uint8_t* out, size_t cap, size_t* total_written);
varint_leb128_codec_err_t varint_leb128_codec_decode_batch(const uint8_t* buf, size_t len, uint64_t* vals, size_t max_n, size_t* decoded_n);
varint_leb128_codec_err_t varint_leb128_codec_check_roundtrip(int64_t signed_val);

#endif /* VARINT_LEB128_CODEC_INTERFACE_H */
