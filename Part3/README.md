---

# TinyC Compiler – Part 3: Code Generation (TAC)

## 🔎 Overview

Generates **three-address code** (quadruples) for tinyC programs using Flex + Bison + semantic actions, along with nested symbol tables and backpatching.

---

## 📦 Project Structure

- `tinyC3.l` — lexer (Flex)
- `tinyC3.y` — parser and semantic actions (Bison)
- `translator.h` — symbol table, quad array, helpers (headers)
- `translator.cpp` — all implementations along with `main()`
- `input/` — sample programs for testing (`test1.c` … `test5.c`)
- `output/` — generated TAC as results of input test files (`quads1.out` … `quads5.out`)
- `Makefile` — build/clean functionality

---

## ⚙️ How to Build & Run

- Move into the directory
    ```bash
    cd Part3
    ```

- To build all the necessary files
    ```bash
    make
    ```

- To test all the test files present in input/
    ```bash
    make test
    ```

- To test a custom test file
    ```bash
    ./a.out < <test_file_path> > <output_file_path>
    ```

- Remove the generated files
    ```bash
    make clean
    ```