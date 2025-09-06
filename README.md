---

# TinyC Compiler – Part 1: Lexer

## 🔎 Overview

A **lexer** for the tinyC language implemented using **Flex**.  
It converts source code into a stream of tokens and maintains a symbol table.

---

## 📂 Project Structure

- `tinyC1.l` → Flex lexer specification.  
- `tinyC2.c` → Driver program (contains `main()`).  
- `Makefile` → Build automation.  
- `test.c` → Example input source code.  

---

## ⚙️ How to Build & Run

- Move into the directory
    ```bash
    cd Part1
    ```

- To test a code present in test.c
    ```bash
    make test
    ```

- To test a custom test file
    ```bash
    lex tinyC1.l
    gcc tinyC2.c -o a.out
    ./a.out < <test_file_name>
    ```

- Remove the generated files.
    ```bash
    make clean
    ```

---

# TinyC Compiler – Part 2: Parser

## 🔎 Overview

This project implements a **parser** for the tinyC language using **Bison** and **Flex**.  
It validates tinyC programs against the grammar and generates a **parse tree**.

---

## 📂 Project Structure

- `tinyC2.l` → Flex specification.  
- `tinyC2.y` → Bison grammar specification.  
- `tinyC2.c` → Driver program.  
- `Makefile` → Build automation.  
- `input.c` → Example test program.  
- `output.txt` → Parse actions ans parse tree output.  

---

## ⚙️ How to Build & Run

- Move into the directory
    ```bash
    cd Part2
    ```
- To build the necessary files
    ```bash
    make all
    ```
- To test a input file named input.c
    ```bash
    make test
    ```
- To test on custom input file
    ```bash
    ./a.out < <input_file_name> > output.txt

- Remove the generated files.
    ```bash
    make clean
    ```

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
