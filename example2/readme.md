# README: Building `myapp` with Makefile (Enhanced Version)

### Overview

This project demonstrates how to use a Makefile to automate the build process for a simple C application. The executable `myapp` is created by compiling and linking two source files: `main.c` and `hello.c`. The header file `hello.h` provides shared declarations.

This version introduces:

*   Variables (`CC`, `CFLAGS`) for flexibility.
*   Compiler warnings enabled via `-Wall`.
*   Detailed dependency management for incremental builds.

### Concepts Explained

*   Makefile Targets & Dependencies  
    Each target specifies:
    *   What to build (e.g., `myapp`, `main.o`).
    *   What it depends on (e.g., source files, headers).
    *   How to build it (commands executed by `make`).

*   Variables in Makefile
    *   `CC = gcc` → Sets the compiler.
    *   `CFLAGS = -Wall` → Enables warnings for safer code.

*   Incremental Build  
    Only files that changed (or their dependencies) are recompiled.

*   Utility Targets  
    `clean` removes build artifacts for a fresh start.


### Project Structure

````bash
├── main.c       # Contains main() function
├── hello.c      # Implements helper functions
├── hello.h      # Header file with function declarations
├── Makefile     # Build automation script

````

### Execution Steps

**1. Build the Application**

Run:

```bash
make
```

This will:

*   Compile `main.c` → `main.o` (with `-Wall` warnings).
*   Compile `hello.c` → `hello.o`.
*   Link both object files into the executable `myapp`.


**2. Run the Application**

```bash
./myapp
```

**3. Clean Up**

Remove object files and executable:

```bash
make clean
```

*

### How It Works

*   Target `myapp`  
    Depends on `main.o` and `hello.o`. Links them:
    ```bash
    gcc -o myapp main.o hello.o
    ```
*   Target `main.o`  
    Recompiled if `main.c` or `hello.h` changes:
    ```bash
    gcc -Wall -c main.c
    ```
*   Target `hello.o`  
    Recompiled if `hello.c` or `hello.h` changes:
    ```bash
    gcc -Wall -c hello.c
    ```
*   Target `clean`  
    Removes build artifacts:
    ```bash
    rm -f *.o myapp
    ```

*

### Best Practices

*   Use `.PHONY` for non-file targets like `clean`:
    ```make
    .PHONY: clean
    ```
*   Add `-g` to `CFLAGS` for debugging:
    ```make
    CFLAGS = -Wall -g
    ```
*   For larger projects, consider pattern rules and automatic variables.
