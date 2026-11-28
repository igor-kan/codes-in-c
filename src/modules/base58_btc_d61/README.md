# Base58 Bitcoin-Alphabet Big-Integer Encoder and Decoder (`base58_btc_d61`)

> Category: **Encodings** | Language: **C11**

## Overview

Transcodes byte strings to and from the Bitcoin Base58 alphabet by repeated multiply-and-carry base conversion with explicit preservation of leading zero bytes.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^2) radix-58 big-integer conversion` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Decoding an encoding reproduces the exact input bytes.
- Each leading zero byte maps to exactly one leading '1' character.

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
