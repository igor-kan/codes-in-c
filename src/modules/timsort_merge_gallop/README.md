# Adaptive Run-Merging TimSort with Exponential Gallop Search (`timsort_merge_gallop`)

> Category: **Adaptive Sorting** | Language: **C11**

## Overview

Implements Peter McIlroy / Tim Peters style natural run discovery, strict descending-run reversal, binary insertion extension up to minrun, and stack-invariant bottom-up gallop merge.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) best / O(N log N) worst` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Output array is monotonically non-decreasing: a[i] <= a[i+1].
- Multiset permutation of input elements is strictly preserved.
- Already sorted and strictly reversed inputs complete in O(N) comparisons.

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
