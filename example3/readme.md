# Advanced Makefile for Building `myapp`

## Overview

This project demonstrates an optimized Makefile for compiling and linking a simple C program. The executable `myapp` is built from multiple source files using:

*   Variables for compiler and flags.
*   Pattern rules for generic compilation.
*   Automatic variables (`$@`, `$^`, `$<`) for cleaner commands.
*   .PHONY targets for utility actions.

**Makefile**
```make
CC      := gcc
CFLAGS  := -Wall
SRC     := main.c hello.c
OBJ     := $(SRC:.c=.o)
TARGET  := myapp
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: all clean    
clean:
    rm -f *.o myapp
```

## Concepts Explained

*   Variables:
    *   `CC := gcc` → Compiler.
    *   `CFLAGS := -Wall` → Enables warnings.
*   Pattern Rule:
    *   `%.o: %.c` → Generic rule to compile any `.c` into `.o`.
*   Automatic Variables:
    *   `$@` → Target name.
    *   `$^` → All prerequisites.
    *   `$<` → First prerequisite.
*   .PHONY:
    *   Declares targets like `clean` and `all` as non-file targets.



## Project Structure

```
├── main.c       # Contains main() function
├── hello.c      # Implements helper functions
├── hello.h      # Header file with declarations
├── Makefile     # Build automation script
```

## Execution Steps

### 1. Build the Application

Run:

```bash
make
```

This will:

*   Compile all `.c` files into `.o` using the pattern rule.
*   Link them into the executable `myapp`.

### 2. Run the Application

```bash
./myapp
```

### 3. Clean Up

Remove object files and executable:

```bash
make clean
```

## How It Works

*   Default Target (`all`):
    ```make
    all: myapp
    ```
*   Linking Rule:
    ```make
    $(TARGET): $(OBJ)
        $(CC) -o $@ $^
    ```
*   Pattern Rule for Compilation:
    ```make
    %.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@
    ```
*   Clean Target:
    ```make
    .PHONY: all clean
    clean:
        rm -f *.o myapp
    ```
