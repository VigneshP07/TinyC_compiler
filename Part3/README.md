---
# TinyC Compiler – Part 3: Code Generation (TAC)

## 🔎 Overview

Generates **three-address code** (quadruples) for tinyC programs using Flex + Bison + semantic actions, along with nested symbol tables and backpatching.

---

## 📦 Contents

- `tinyC3.l` — lexer (Flex)
- `tinyC3.y` — parser and semantic actions (Bison)
- `translator.h` — symbol table, quad array, helpers (headers)
- `translator.cpp` — all implementations along with `main()`
- `input/` — sample programs for testing (`test1.c` … `test5.c`)
- `output/` — generated TAC as results of test files (`quads1.out` … `quads5.out`)
- `Makefile` — build/clean functionality

---

## ⚙️ Build
```bash
cd Part3
make
