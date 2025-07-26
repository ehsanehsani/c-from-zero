# Getting Started with C

Welcome to the first session of learning C programming from scratch! This document will guide you through the basics, including essential libraries, the structure of a C program, and how to write and run your very first C program.

---

## 1. What Are C Libraries?

C libraries are collections of pre-written code that provide useful functions to help with your programming tasks. They let you perform tasks such as input/output operations, math calculations, string manipulations, and more without having to write everything from scratch.

### Essential C Libraries:

- **`stdio.h`**  
  Stands for "Standard Input/Output Header". This library provides functions for input and output, like `printf()` (to print text to the screen) and `scanf()` (to get input from the user).

- **Other Common Libraries** (will be explored in future sessions):
  - `stdlib.h`: Standard library, includes functions for memory allocation, process control, conversions, etc.
  - `string.h`: Functions for manipulating strings.
  - `math.h`: Mathematical functions.

---

## 2. The Structure of a C Program

A basic C program has the following structure:

```c
#include <stdio.h>   // Include standard input/output library

int main() {         // Main function - program execution starts here
    // Your code goes here
    return 0;        // Return statement
}
```

- **`#include <stdio.h>`**: This line includes the Standard Input/Output library.
- **`int main() { ... }`**: The main function where your program starts executing.
- **`return 0;`**: Ends the main function and returns 0 to the operating system (indicates success).

---

## 3. Your First C Program: "Hello, World!"

Let's write a simple program that prints "Hello, World!" to the screen.

### The Code

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

- **`printf("Hello, World!\n");`**: Prints the text to the screen. The `\n` adds a new line at the end.

---

## 4. Compiling and Running Your Program

### Steps

1. **Save your code in a file**  
   For example: `foo.c`

2. **Compile the code using `make`**  
   If you have a Makefile, run:
   ```
   make foo
   ```
   This will compile `foo.c` and create an executable named `foo`.

   Alternatively, you can use `gcc` directly:
   ```
   gcc foo.c -o foo
   ```

3. **Run your program**
   ```
   ./foo
   ```

   You should see:
   ```
   Hello, World!
   ```

---

## Summary

- C uses libraries like `stdio.h` for input/output.
- Every C program has a `main` function as its entry point.
- You write, compile, and run your C code using tools like `make` and `gcc`.

---

**Next Steps:**  
In the following sessions, we'll explore more libraries and start working with variables, data types, and user input.

Happy Coding!
