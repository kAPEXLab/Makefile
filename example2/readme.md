*Compile Without make*

```bash
gcc -c main.c
gcc -c hello.c
gcc -o myapp main.o hello.o
```
*Create a Basic Makefile*

# Makefile
# Build the final executable 'myapp' from object files
myapp: main.o hello.o
	gcc -o myapp main.o hello.o

# Compile main.c into main.o, depends on hello.h for declarations
main.o: main.c hello.h
	gcc -c main.c

# Compile hello.c into hello.o, depends on hello.h for declarations
hello.o: hello.c hello.h
	gcc -c hello.c

# Clean up generated files
clean:
	rm -f *.o myapp
````

Explanation:
* Target: myapp
* Dependencies: main.o hello.o
* Command: gcc -o myapp main.o hello.o
* Tabs are mandatory before commands.

*Run Make*

```bash
make
```

* Builds only what changed.
* If hello.c changes, only hello.o and myapp rebuild.

--------------
Here’s a **professional README.md** for the updated Makefile you shared:

***

# **README: Building `myapp` with Makefile (Enhanced Version)**

## **Overview**

This project demonstrates how to use a **Makefile** to automate the build process for a simple C application. The executable **`myapp`** is created by compiling and linking two source files: `main.c` and `hello.c`. The header file `hello.h` provides shared declarations.

This version introduces:

*   **Variables** (`CC`, `CFLAGS`) for flexibility.
*   **Compiler warnings** enabled via `-Wall`.
*   **Detailed dependency management** for incremental builds.

***

## **Concepts Explained**

*   **Makefile Targets & Dependencies**  
    Each target specifies:
    *   **What to build** (e.g., `myapp`, `main.o`).
    *   **What it depends on** (e.g., source files, headers).
    *   **How to build it** (commands executed by `make`).

*   **Variables in Makefile**
    *   `CC = gcc` → Sets the compiler.
    *   `CFLAGS = -Wall` → Enables warnings for safer code.

*   **Incremental Build**  
    Only files that changed (or their dependencies) are recompiled.

*   **Utility Targets**  
    `clean` removes build artifacts for a fresh start.

***

## **Project Structure**

    .
    ├── main.c       # Contains main() function
    ├── hello.c      # Implements helper functions
    ├── hello.h      # Header file with function declarations
    ├── Makefile     # Build automation script

***

## **Prerequisites**

*   **GCC Compiler** installed (`gcc --version`).
*   **Make Utility** installed (`make --version`).
*   Works on **Linux/MacOS** or **Windows with MinGW/MSYS**.

***

## **Execution Steps**

### **1. Build the Application**

Run:

```bash
make
```

This will:

*   Compile `main.c` → `main.o` (with `-Wall` warnings).
*   Compile `hello.c` → `hello.o`.
*   Link both object files into the executable `myapp`.

***

### **2. Run the Application**

```bash
./myapp
```

***

### **3. Clean Up**

Remove object files and executable:

```bash
make clean
```

***

## **How It Works**

*   **Target `myapp`**  
    Depends on `main.o` and `hello.o`. Links them:
    ```bash
    gcc -o myapp main.o hello.o
    ```
*   **Target `main.o`**  
    Recompiled if `main.c` or `hello.h` changes:
    ```bash
    gcc -Wall -c main.c
    ```
*   **Target `hello.o`**  
    Recompiled if `hello.c` or `hello.h` changes:
    ```bash
    gcc -Wall -c hello.c
    ```
*   **Target `clean`**  
    Removes build artifacts:
    ```bash
    rm -f *.o myapp
    ```

***

## **Best Practices**

*   Use `.PHONY` for non-file targets like `clean`:
    ```make
    .PHONY: clean
    ```
*   Add `-g` to `CFLAGS` for debugging:
    ```make
    CFLAGS = -Wall -g
    ```
*   For larger projects, consider **pattern rules** and **automatic variables**.

***
