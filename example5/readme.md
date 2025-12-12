# README: Scalable C Project with Directory-Structured Makefile

## Overview

This repository uses a robust Makefile to build a C application named `myapp`. It supports:

*   Structured directories: `src/` for sources, `include/` for headers, `build/` for objects & dependencies.
*   Release & Debug build modes via `make release` and `make debug`.
*   Auto-generated header dependencies with `-MMD -MP`.
*   Convenience utilities: `make run` to execute, `make clean` to reset, `make print-vars` to inspect variables.

The Makefile is designed to be portable, extensible, and fast (works well with `make -j` for parallel builds).

## Makefile

```makefile
# Compiler and flags
CC        := gcc
CFLAGS    ?= -Wall -Wextra -O2 -MMD -MP
CPPFLAGS  := -Iinclude
LDFLAGS   :=
LDLIBS    :=

# Project directories
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build
TARGET    := myapp

# Sources / objects / deps
SRC       := $(wildcard $(SRC_DIR)/*.c)
OBJ       := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEPS      := $(OBJ:.o=.d)

# Phony targets
.PHONY: all clean debug release run print-vars
all: release

# Build modes
release: CFLAGS += -DNDEBUG
release: $(TARGET)

debug:   CFLAGS += -g -O0 -DDEBUG
debug:   $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Compile pattern
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Ensure build dir exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Auto header deps
-include $(DEPS)

# Utilities
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

print-vars:
	@echo "CC        = $(CC)"
	@echo "CFLAGS    = $(CFLAGS)"
	@echo "CPPFLAGS  = $(CPPFLAGS)"
	@echo "LDFLAGS   = $(LDFLAGS)"
	@echo "LDLIBS    = $(LDLIBS)"
	@echo "SRC_DIR   = $(SRC_DIR)"
	@echo "INC_DIR   = $(INC_DIR)"
	@echo "BUILD_DIR = $(BUILD_DIR)"
	@echo "SRC       = $(SRC)"
	@echo "OBJ       = $(OBJ)"
```

## Project Layout

```
├── include/            # Header files (*.h)
│   └── ...             # e.g., hello.h, add.h
├── src/                # Source files (*.c)
│   └── ...             # e.g., main.c, hello.c, add.c
├── build/              # Auto-created: object & dependency files (*.o, *.d)
├── Makefile            # Build script
└── README.md
```


## Makefile Concepts

### Key Variables

*   `CC` — C compiler (default: `gcc`). Override per-invocation:
    ```bash
    make CC=clang
    ```
*   `CFLAGS` — Compiler flags. Defaults:
    *   `-Wall -Wextra`: warnings
    *   `-O2`: optimization for release
    *   `-MMD -MP`: generate `.d` dependency files automatically
*   `CPPFLAGS` — Preprocessor flags; includes header search path:
    *   `-Iinclude`: look for headers under `include/`
*   `LDFLAGS`, `LDLIBS` — Linker flags & libraries (empty by default; override as needed).

### Directories

*   `SRC_DIR = src`
*   `INC_DIR = include`
*   `BUILD_DIR = build`

### Source → Object Mapping

*   Collect all C sources:
    ```make
    SRC := $(wildcard $(SRC_DIR)/*.c)
    ```
*   Map `src/foo.c` → `build/foo.o`:
    ```make
    OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
    ```
*   Auto-generated header dependency files:
    ```make
    DEPS := $(OBJ:.o=.d)
    ```

### Pattern Rule (Generic Compilation)

```make
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
```

*   `$<`: first prerequisite (the `.c` file)
*   `| $(BUILD_DIR)`: order-only prerequisite ensuring `build/` exists without forcing rebuilds if its timestamp changes.

### Auto Header Dependencies

```make
-include $(DEPS)
```

*   Includes the generated `.d` files so changes in headers trigger the correct recompilation.
*   Leading `-` ignores missing `.d` files during the first build (when they don’t exist yet).

### Build Modes

*   Release (default via `make all` → `make release`):
    ```make
    release: CFLAGS += -DNDEBUG
    release: $(TARGET)
    ```
    Adds `-DNDEBUG` to disable assertions.
*   Debug:
    ```make
    debug:   CFLAGS += -g -O0 -DDEBUG
    debug:   $(TARGET)
    ```
    Adds symbols, disables optimization, defines `DEBUG`.

### Linking

```make
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
```

*   `$@` — target (`myapp`)
*   `$^` — all object prerequisites

*

## Prerequisites

*   Compiler: GCC or Clang  
    Check with:
    ```bash
    gcc --version
    clang --version
    ```
*   Make:
    ```bash
    make --version
    ```
*   OS: Linux/macOS, or Windows via MSYS2/MinGW or WSL.


## How to Build and Run

### 1) Build (Release mode, default)

```bash
make            # same as: make all → make release
```

### 2) Build (Debug mode)

```bash
make debug
```

### 3) Run the program

```bash
make run        # ensures myapp is built, then runs it
# or:
./myapp
```

### 4) Print current Make variables (for debugging/learning)

```bash
make print-vars
```

### 5) Clean build artifacts

```bash
make clean      # removes build/ and myapp
```

### 6) Faster compilation (parallel builds)

```bash
make -j         # choose a number, e.g., -j4
```

### 7) Override compiler or flags ad-hoc

```bash
make CC=clang CFLAGS="-Wall -Wextra -O3 -MMD -MP"
```

*

## Extending the Build

### Linking libraries

If your code uses `math.h` functions (e.g., `sin`, `pow`), add the math library:

```bash
make LDLIBS="-lm"
```

If you need custom library directories or rpaths:

```bash
make LDFLAGS="-L/path/to/libs -Wl,-rpath,/path/to/libs" LDLIBS="-lmylib"
```

### Adding new source files

Just drop `.c` files into `src/` and `.h` into `include/`. The wildcard and pattern rule will pick them up automatically.

*

## Troubleshooting

*   “header file not found”  
    Ensure headers are under `include/` and referenced as:
    ```c
    #include "hello.h"
    ```
    The `-Iinclude` in `CPPFLAGS` enables this.

*   Stale builds or odd errors after renaming files  
    Run:
    ```bash
    make clean && make
    ```

*   Auto-dependency doesn’t trigger rebuild  
    Confirm `CFLAGS` includes `-MMD -MP`. Also check that the header is indeed included in a `.c` file.

*   Windows path issues  
    Prefer MSYS2/MinGW or WSL; PowerShell/CMD may require quoting paths carefully. Use forward slashes in the Makefile.