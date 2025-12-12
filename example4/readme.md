# README: Advanced Makefile for Multi-Source C Project

## Overview

This project demonstrates an efficient Makefile for building a C application from multiple source files. The final executable `myapp` is created by compiling and linking:

*   `main.c` → Contains `main()` function.
*   `hello.c` → Implements greeting-related functions.
*   `add.c` → Implements addition-related functions.
*   `hello.h` and `add.h` → Header files for declarations.

```makefile
CC      := gcc
CFLAGS  := -Wall
SRC     := main.c hello.c add.c
OBJ     := $(SRC:.c=.o)
TARGET  := myapp
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
    rm -f $(OBJ) $(TARGET)        
```


The Makefile uses:

*   Variables for compiler and flags.
*   Pattern rules for generic compilation.
*   Automatic variables for cleaner commands.
*   .PHONY targets for utility actions.


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
    *   Declares `all` and `clean` as non-file targets.

*

## Project Structure


```
├── main.c       # Entry point
├── hello.c      # Greeting functions
├── add.c        # Addition functions
├── hello.h      # Header for hello.c
├── add.h        # Header for add.c
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
    .PHONY: all
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
    .PHONY: clean
    clean:
        rm -f $(OBJ) $(TARGET)
    ```