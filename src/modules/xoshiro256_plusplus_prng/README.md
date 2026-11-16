# xoshiro256++ 256-Bit State PRNG with Jump Streams (`xoshiro256_plusplus_prng`)

> Category: **Pseudorandom Generators** | Language: **C11**

## Overview

Implements Blackman & Vigna's xoshiro256++ general-purpose 64-bit PRNG seeded through SplitMix64, including the exact 2^128 jump polynomial for disjoint parallel streams.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) next() / O(1) 2^128 jump` |
| **Space Complexity** | `O(1) (32 bytes state)` |

## Mathematical & Safety Invariants

- Non-zero seed always produces non-zero 256-bit state.
- jump() advances deterministically without colliding across adjacent worker streams.
- Bit balance across generated 64-bit streams approximates 50% Hamming weight.

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
