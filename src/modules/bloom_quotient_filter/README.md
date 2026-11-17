# Open-Addressed Quotient Filter (Insert, Lookup & Delete) (`bloom_quotient_filter`)

> Category: **Probabilistic Structures** | Language: **C11**

## Overview

Implements a compact quotient filter with q=8 quotient bits and r=8 remainder bits in a fixed 256-slot table, storing remainder fingerprints and cluster metadata to support false-positive-bounded membership and deletion.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) expected linear cluster probe` |
| **Space Complexity** | `O(2^Q) fixed fingerprint slots` |

## Mathematical & Safety Invariants

- Zero false negatives: any inserted and undeleted key always returns true on lookup.
- Deleting an inserted key removes it cleanly without corrupting later cluster entries.

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
