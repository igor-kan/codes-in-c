# Musser Introsort Hybrid with Depth-Bounded Heapsort Guard (`introsort_heap_guard`)

> Category: **Comparison Sorting** | Language: **C11**

## Overview

Implements David Musser's introspective sort switching between median-of-three Hoare/Lomuto quicksort, 2*floor(log2(N)) depth-triggered max-heapsort fallback, and final insertion pass.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log N) worst-case` |
| **Space Complexity** | `O(log N)` |

## Mathematical & Safety Invariants

- Strictly O(N log N) worst-case time even on adversarial killer-pivot sequences.
- Auxiliary stack depth never exceeds 2*floor(log2(N)) frames.
- Multiset invariant and monotonic ordering verified after every run.

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
