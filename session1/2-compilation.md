# Under the Hood: What Happens When You Compile a C Program?

In this session, we'll explore what happens behind the scenes when you compile a C program, what the final output is, and the roles of tools like `gcc` and `make`.

---

## 1. What Happens When You Compile a C Program?

When you write a C program (for example, in `foo.c`), it is just plain text that computers can't execute directly. It needs to be translated into a form the computer understands. This process is called **compilation**.

### Compilation Steps

The compilation of a C program typically involves these main steps:

1. **Preprocessing**  
   All lines that start with `#` (like `#include <stdio.h>`) are processed. Header files are included, macros are expanded, and comments are removed.

2. **Compilation**  
   The preprocessed code is translated into **assembly language** (a low-level, human-readable language specific to the target CPU).

3. **Assembly**  
   The assembler converts the assembly code into **machine code** (binary instructions that the CPU can execute). The output is usually an **object file** (e.g., `foo.o`).

4. **Linking**  
   If your program uses functions from libraries (like `printf` from `stdio.h`), the linker combines your object file(s) with the required libraries to produce a final **executable** (e.g., `foo` or `foo.exe`).

### The Final Output

- **Executable File:**  
  The end result is a file (like `foo` on Linux/Mac or `foo.exe` on Windows) that contains machine code. This is what you run with `./foo`.

- **Machine Code vs. Assembly:**  
  - **Assembly** is an intermediate step; it's human-readable and close to what the CPU uses.
  - **Machine Code** is the actual binary instructions that are executed by your computer's processor.

---

## 2. What is `gcc`?

- **`gcc` stands for GNU Compiler Collection.**
- It is a popular, open-source compiler that can translate C (and other languages) into machine code.
- It handles all the compilation steps: preprocessing, compiling, assembling, and linking.

### Basic Usage

```sh
gcc foo.c -o foo
```

- `foo.c` is your source code.
- `-o foo` specifies the name of the output file (the executable).

You can also use gcc to see the intermediate steps (for learning purposes):

- **Stop after preprocessing:**  
  `gcc -E foo.c`
- **Stop after compilation (get assembly output):**  
  `gcc -S foo.c`
- **Stop after assembly (get object file):**  
  `gcc -c foo.c`
- **Full compile and link:**  
  `gcc foo.c -o foo`

---

## 3. What is `make`? How is it Different from `gcc`?

If you have a C file called `foo.c`, you can compile it to an executable by simply running:

```sh
make foo
```

- This creates an executable file named `foo`.
- **No Makefile is needed** for this simple case; `make` uses built-in rules to automatically compile single-file programs.

---

### 3.1. Using Makefiles: Customizing the Build

For more control or when your project grows, you can add a **Makefile**. This file tells `make` exactly how to build your program.

**Example Makefile:**

```makefile
foo: foo.c
	gcc foo.c -o foo
```

Now running `make foo` will use your specified build instructions.

---

### Key Differences

| gcc          | make                     |
| ------------ | ------------------------ |
| The actual compiler for C, C++, etc. | A build tool that automates compiling (calls `gcc` for you) |
| You run commands like `gcc foo.c -o foo` | You run `make foo`, and `make` runs the right `gcc` command |
| Good for compiling simple programs | Great for automating larger projects with many files |

---

## Summary

- When you compile C code, it’s transformed from source code → assembly → machine code → executable.
- `gcc` is the compiler that does the actual translation.
- `make` is a tool that automates compiling, especially helpful for larger projects.

---
