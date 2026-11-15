#include "interface.h"
#include <assert.h>
#include <stdint.h>

int main(void) {
    uint8_t buf[16]; size_t w = 0, c = 0; uint64_t val = 0;
    // Standard DWARF ULEB128 test vector: 624485 -> E5 8E 26
    assert(varint_leb128_codec_encode_u64(624485ULL, buf, 16, &w) == VARINT_LEB128_CODEC_OK);
    assert(w == 3 && buf[0] == 0xE5 && buf[1] == 0x8E && buf[2] == 0x26);
    assert(varint_leb128_codec_decode_u64(buf, w, &val, &c) == VARINT_LEB128_CODEC_OK);
    assert(val == 624485ULL && c == 3);

    // ZigZag boundaries
    assert(varint_leb128_codec_zigzag_encode(0) == 0);
    assert(varint_leb128_codec_zigzag_encode(-1) == 1);
    assert(varint_leb128_codec_zigzag_encode(1) == 2);
    assert(varint_leb128_codec_check_roundtrip(INT64_MIN) == VARINT_LEB128_CODEC_OK);
    assert(varint_leb128_codec_check_roundtrip(INT64_MAX) == VARINT_LEB128_CODEC_OK);
    return 0;
}
