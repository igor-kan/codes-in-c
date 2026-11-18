# Virtual-Node Consistent Hash Ring with Binary Search Lookup (`consistent_hash_ring_c11`)

> Category: **Distributed Systems** | Language: **C11**

## Overview

Maps cluster nodes onto a 64-bit circular hash continuum with R virtual tokens per physical server and resolves keys via binary search wrap-around.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(V log V) ring sort + O(log V) clockwise node lookup` |
| **Space Complexity** | `O(V) virtual tokens` |

## Mathematical & Safety Invariants

- Every key deterministically maps to the first token >= hash(key) or wraps to index 0.

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
