# Consistent Overhead Byte Stuffing (COBS) Packet Framing Codec (`cobs_framing_codec`)

> Category: **Framing & Serial Protocols** | Language: **C11**

## Overview

Encodes arbitrary byte payloads into zero-free framed packets via forward code-byte run jumps and decodes them with strict malformed-hop validation.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1) extra overhead (<= ceil(N/254) + 1 bytes)` |

## Mathematical & Safety Invariants

- Encoded output contains zero 0x00 bytes prior to packet delimiter.
- decode(encode(payload)) recovers payload byte-for-byte across zero-dense and 254+ nonzero runs.
- Corrupted or truncated hop bytes cleanly return ERR_INVALID without buffer overread.

## Module Architecture

| File | Lifecycle Role |
| :--- | :--- |
| `types.h` | Stage 01 |
| `errors.h` | Stage 02 |
| `interface.h` | Stage 03 |
| `core.c` | Stage 04 |
| `validation.c` | Stage 05 |
| `fast_path.c` | Stage 06 |
| `concurrent.c` | Stage 07 |
| `invariants.c` | Stage 08 |
| `unit_tests.c` | Stage 09 |
| `property_tests.c` | Stage 10 |
| `benchmark.c` | Stage 11 |
| `README.md` | Stage 12 |

## Verification & Execution Example

```text
gcc -std=c11 -O2 -Wall -Wextra -Werror -pthread core.c validation.c fast_path.c concurrent.c invariants.c unit_tests.c -lm -o test_bin && ./test_bin
```

---
© 2026 Igor Kan
