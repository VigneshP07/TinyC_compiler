# TinyC Compiler – Part 2: Parser

## 1. Overview
This part of the project implements a **parser** for the tinyC language, using **Bison** (for grammar parsing) and **Flex** (for lexical analysis).  
The parser validates whether input programs written in tinyC follow the defined grammar rules and generates a **parse tree**.  

Together with Part 1 (lexer), this forms the core of the front-end for the tinyC compiler.

---

## 2. Features
- Uses **Flex** for lexical analysis and **Bison** for parsing.  
- Implements the phrase structure grammar of tinyC.  
- Handles expressions, declarations, statements, and function definitions.  
- Supports optional rules by introducing ε-productions in grammar.  
- Constructs and outputs a **parse tree** in a human-readable format.  

---

## 3. File Descriptions
- `tinyC2.l` → Flex specification for lexical analysis (reuses and extends Part 1).  
- `tinyC2.y` → Bison grammar specification for parsing tinyC.  
- `tinyC2.c` → Driver program with `main()` to invoke lexer and parser.  
- `Makefile` → Automates compilation and cleanup.  
- `input.c` → Sample input program to test the parser.  
- `output.txt` → Human-readable representation of the parse tree.  
- `lex.yy.c`, `y.tab.c`, `y.tab.h` → Auto-generated files from Flex and Bison.  
- `a.out` → Final executable parser.  

---

## 4. Build & Run Instructions
To build and test the parser:

```bash
# Move into the directory
cd Part2

# To build the necessary files
make all

# To test a input file named input.c
make test

# To test on custom input file
./a.out < <input_file_name> > output.txt

# Remove the generated files.
make clean
```