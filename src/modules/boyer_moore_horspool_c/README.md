# Boyer-Moore-Horspool Sublinear Byte Pattern Scanner in C11 (`boyer_moore_horspool_c`)

> Category: **String Matching** | Language: **C11**

## Overview

Computes bad-character skip offsets for arbitrary byte needles and locates all exact pattern matches in sublinear average time.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N/M) average sublinear scan with 256-byte bad-char skip table` |
| **Space Complexity** | `O(256) shift table` |

## Mathematical & Safety Invariants

- Every reported match index satisfies memcmp(haystack + idx, needle, m) == 0.
- Match count agrees identically with brute-force O(N*M) scan.

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
