# Golomb-Rice Param-K Integer Bitstream Coder (`golomb_rice_c11_d59`)

> Category: **Entropy Compression** | Language: **C11**

## Overview

Compresses non-negative small geometric integers using unary-coded quotient q = n >> k and k-bit binary remainder cleanly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(Q + K) bits per symbol` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Encoded bits strictly decode back into original unsigned array across k=0..4.

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
