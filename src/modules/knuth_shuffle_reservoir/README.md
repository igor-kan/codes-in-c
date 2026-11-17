# Fisher-Yates Unbiased Shuffle & Algorithm-L Reservoir Sampler (`knuth_shuffle_reservoir`)

> Category: **Randomized Algorithms** | Language: **C11**

## Overview

Implements deterministic SplitMix64-seeded Fisher-Yates permutation shuffling and Li's O(K log(N/K)) geometric-jump reservoir sampling (Algorithm L).

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) shuffle, O(K(1 + log(N/K))) Algorithm-L reservoir sampling` |
| **Space Complexity** | `O(K)` |

## Mathematical & Safety Invariants

- Fisher-Yates output forms an exact bijection over input elements.
- Reservoir of size K contains K distinct indices within [0, N).

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
