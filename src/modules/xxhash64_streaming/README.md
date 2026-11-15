# xxHash64 Streaming Non-Cryptographic Block Hasher (`xxhash64_streaming`)

> Category: **High-Speed Hashing** | Language: **C11**

## Overview

Implements full 64-bit xxHash64 streaming digest computation with four-lane 32-byte stripe accumulators, prime multiplications, 31/27-bit lane rotations, and final avalanche mixing.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Streaming chunked updates produce byte-for-byte identical digests to one-shot hashing.
- Avalanche finality guarantees single-bit input changes flip roughly 50% of output bits.
- Zero heap allocation during streaming update or finalize.

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
