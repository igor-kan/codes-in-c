#include "interface.h"
#include <assert.h>

int main(void) {
    int64_t edges[] = {0, 1, -1, 63, -64, 64, -65, 8191, -8192, 1LL << 31, -(1LL << 31), (1LL << 62), -(1LL << 62)};
    for (size_t i = 0; i < sizeof(edges)/sizeof(edges[0]); ++i) {
        assert(varint_leb128_codec_check_roundtrip(edges[i]) == VARINT_LEB128_CODEC_OK);
    }
    uint8_t over11[11] = {0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x01};
    uint64_t out = 0; size_t c = 0;
    assert(varint_leb128_codec_decode_u64(over11, 11, &out, &c) == VARINT_LEB128_CODEC_ERR_OVERFLOW);
    return 0;
}
