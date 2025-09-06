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

# Remove the generated files.
make clean
```

---

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

---

# TinyC Compiler – Part 3: Machine-Independent Code Generator

## 1) Overview
This stage implements a **machine-independent translator** for tinyC that produces **three-address code (TAC)** in the form of **quadruples**, along with a supporting **symbol table** and helper data structures. It builds on the lexer (Part 1) and parser (Part 2).

The translator:
- Generates TAC for expressions, declarations, statements, and function definitions.
- Manages scopes with nested symbol tables (global + per-function + block).
- Gives human-readable output files for quads.

---

## 2) Supported Language Subset (high level)
- **Types:** `void`, `char`, `int`, `float` (treat `char`/`int` as signed).
- **Declarations:** scalars, pointers, arrays, functions (no enum/qualifiers/specifiers beyond the above).
- **Statements:** blocks, if/else, while, do…while, for (no declaration in `for`), return.
- **Expressions:** arithmetic, shift, relational, bitwise, logical, unary, and simple assignment `=`.
  - **Not implemented:** `sizeof`, comma operator, compound assignments `+=, -=, …`, struct member `.`/`->` for aggregates in semantic translation (may still be tokenized/parsed as they are present in Part 1/2).
- **External definitions:** function definitions (skip extern declarations and storage class specifiers).

---

## 3) Three-Address Code (TAC)
### 3.1 Address kinds
- **name:** user identifiers (variables, arrays, functions)
- **const:** numeric/char constants
- **temp:** compiler-generated temporaries (`t1`, `t2`, …)

### 3.2 Quad format
Each TAC instruction is stored as a quadruple:
(op, arg1, arg2, result) // arg2 may be empty for unary/copy ops
Representative forms:
- `x = y op z` → `(op, y, z, x)`  
- `x = op y` (unary) → `(op, y, -, x)`
- `x = y` (copy) → `('=', y, -, x)`
- `if x relop y goto Lk` → `(relop, x, y, Lk)`
- `goto Lk` → `('goto', -, -, Lk)`
- `param xi` → `('param', xi, -, -)`
- `y = call p, N` → `('call', p, N, y)`
- `x = y[z]` → `('=[]', y, z, x)`  
- `x[z] = y` → `('[]=', x, z, y)`  
- `x = &y`, `x = *y`, `*x = y`

---

## 4) Data Structures

### 4.1 Symbol Table (ST)
- **Fields (illustrative):** `name, type, init, size, offset, nested(ST*)`
- **Operations:**  
  - `lookup(name)` → find or create entry in current scope  
  - `gentemp(type)` → create temporary, insert into current ST  
  - `update(entry, fields...)` → mutate metadata (type, init, size, etc.)  
  - `print()` → pretty print (with nesting)

**Storage sizes used (for machine-independent design, configured as constants):**
- `char:1`, `int:4`, `float:8`, `pointer:4`.  
`void` is not storable. A derived, non-storable `bool` may be inferred internally.

### 4.2 Quad Array (QA)
- Vector/array of quads, each with `op, arg1, arg2, result`.
- **Operations:**  
  - `emit(op, arg1, arg2, result)`  
  - `print()` → human-readable listing with labels `L<i>`.

### 4.3 Backpatching Helpers
- `makelist(i)` → returns new list containing index `i`  
- `merge(p, q)` → concatenates two lists  
- `backpatch(p, i)` → set target of pending jumps in list `p` to label `i`

### 4.4 Type Checking & Conversions
- `typecheck(E1, E2)` → ensure compatible types; insert conversions if needed  
- `conv<T1_2_T2>(E)` → convert expression `E` to target type `T2`

---

## 5) Directory & Files (this repo)
- `tinyC3.l` — lexer (Flex)
- `tinyC3.y` — parser and semantic actions (Bison)
- `translator.h` — symbol table, quad array, helpers (headers)
- `translator.cpp` — all implementations along with `main()`
- `input/` — sample programs for testing (`test1.c` … `test5.c`)
- `output/` — generated TAC as results of input test files (`quads1.out` … `quads5.out`)
- `Makefile` — build/clean functionality

> Generated files (by tools): `lex.yy.c`, `tinyC3.tab.c`, `tinyC3.tab.h`, `a.out` etc.

---

## 6) Build & Run

```bash
# Move into the directory
cd Part3

# To build all the necessary files
make

# To test all the test files present in input/
make test

# To test a custom test file
./a.out < <test_file_path> > <output_file_path>

# Remove the generated files
make clean
```