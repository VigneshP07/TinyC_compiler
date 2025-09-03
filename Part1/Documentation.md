# TinyC Compiler – Part 1: Lexer

## 1. Overview
This project implements a **lexer** for a simplified subset of the C programming language, called **tinyC**.  
The lexer scans source code, identifies tokens such as **keywords, identifiers, constants, string literals, punctuators, and comments**, and builds a **symbol table**.  

This forms the first step in building a full compiler for tinyC.

---

## 2. Features
- Recognizes keywords, identifiers, constants (integer, float, character), string literals, punctuators, and comments.
- Supports both **single-line** (`// ...`) and **multi-line** (`/* ... */`) comments.
- Maintains a **symbol table** for identifiers and constants.
- Outputs a stream of tokens in the form `<token_name, lexeme>`.

---

## 3. File Descriptions
- `tinyC1.l` → Flex lexer specification.  
- `tinyC2.c` → Driver program containing `main()` to run the lexer.  
- `Makefile` → Automates build and execution.  
- `test.c` → Example input program to test all token types.  
- `lex.yy.c` → Auto-generated file from Flex.  
- `a.out` → Executable generated after compilation.  

---

## 4. Build & Run Instructions
To build and test the lexer:

```bash
# Move into Part1 directory
cd Part1

# to test a code present in test.c
make test

# or to test a custom test file
lex tinyC1.l
gcc tinyC2.c -o a.out
./a.out < <test_file_name>
```