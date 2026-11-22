# PCG32 Permuted Congruential 32-Bit PRNG (`pcg32_lcg_prng_c11_d57`)

> Category: **Pseudorandom Generators** | Language: **C11**

## Overview

Implements O'Neill PCG-XSH-RR with 64-bit LCG state transition, xorshift folding, variable bit rotation, and unbiased bounded Debiased-Lemire range output.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- PCG32 deterministic output sequences repeat identically across identical (seed, seq) initialization.

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
