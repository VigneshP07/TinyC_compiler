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
    ```

- Remove the generated files.
    ```bash
    make clean
    ```