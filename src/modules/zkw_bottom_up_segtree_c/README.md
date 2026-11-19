# Iterative Power-of-Two Bottom-Up Range Sum Segment Tree (`zkw_bottom_up_segtree_c`)

> Category: **Range Structures** | Language: **C11**

## Overview

Constructs an iterative ZKW segment tree anchored at base M = next_pow2(N) for branch-minimal range sums.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) iterative bit-level segment update and query` |
| **Space Complexity** | `O(2 * N) flat array` |

## Mathematical & Safety Invariants

- Iterative range sum equals exact slice total over [l, r].

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
