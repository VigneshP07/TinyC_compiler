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