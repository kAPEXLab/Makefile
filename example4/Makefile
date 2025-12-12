# -----------------------------------------------------------
# Compiler and flags
# -----------------------------------------------------------
# CC: The C compiler to use. You can override it at the CLI: `make CC=clang`
CC      := gcc

# CFLAGS: Compiler flags passed to CC during compilation.
# -Wall : enable common warnings to help catch issues early.
CFLAGS  := -Wall

# -----------------------------------------------------------
# Sources, objects, and final target
# -----------------------------------------------------------
# SRC: List of C source files in the current directory.
# Keep this explicit for clarity and control.
SRC     := main.c hello.c add.c

# OBJ: Derive the corresponding object files from SRC.
# e.g., main.c -> main.o, hello.c -> hello.o
OBJ     := $(SRC:.c=.o)

# TARGET: The name of the final executable to produce.
TARGET  := myapp

# -----------------------------------------------------------
# Default target
# -----------------------------------------------------------
# `all` is the conventional default target: it builds the final program.
# Running plain `make` will build $(TARGET).
.PHONY: all
all: $(TARGET)

# -----------------------------------------------------------
# Link step: produce the final executable
# -----------------------------------------------------------
# Rule: $(TARGET) depends on all object files in $(OBJ).
# $@ : the name of the target being generated (here, `myapp`)
# $^ : all prerequisites (here, all the .o files)
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# -----------------------------------------------------------
# Pattern rule: compile any .c into a .o
# -----------------------------------------------------------
# This single generic rule replaces individual compile rules for each source.
# $< : the first prerequisite (the .c file being compiled)
# -c : compile to an object file, don't link
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# -----------------------------------------------------------
# Clean target: remove build artifacts
# -----------------------------------------------------------
# .PHONY marks `clean` as a special target that does not create a file named 'clean'.
.PHONY: clean
clean:
	# Remove all object files and the final executable.
	# -f suppresses errors if files do not exist.
	rm -f $(OBJ) $(TARGET)
