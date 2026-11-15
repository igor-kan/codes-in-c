# Deterministic Finite Automaton UTF-8 Validator & Decoder (`utf8_dfa_decoder`)

> Category: **Text & Encoding** | Language: **C11**

## Overview

Implements Bjoern Hoehrmann's branch-minimal UTF-8 state machine mapping byte classes cleanly to DFA states, rejecting surrogates, overlong forms, and codepoints above U+10FFFF.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Returns ACCEPT (0) only on structurally valid RFC 3629 UTF-8 byte sequences.
- Surrogates U+D800..U+DFFF and values > U+10FFFF deterministically enter REJECT.
- ASCII-only prefixes process identically via 8-byte SWAR fast-scan.

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
