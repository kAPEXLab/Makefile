# -----------------------------------------------------------
# Compiler and flags
# -----------------------------------------------------------

# Set the C compiler. 'gcc' is the GNU C Compiler.
CC      := gcc

# Compiler flags:
#  -Wall enables most compiler warning messages to help catch potential issues.
CFLAGS  := -Wall

# -----------------------------------------------------------
# Sources, objects, and target
# -----------------------------------------------------------

# Explicitly list your source files (keeps control & readability)
SRC     := main.c hello.c

# Derive object file names from source files using substitution
# e.g., main.c -> main.o, hello.c -> hello.o
OBJ     := $(SRC:.c=.o)

# Name of the final executable
TARGET  := myapp

# -----------------------------------------------------------
# Default target: build the program
# -----------------------------------------------------------
# 'myapp' depends on the object files listed in $(OBJ).
# If any object is newer than the executable, or the executable doesn't exist,
# the link step runs to (re)create it.
all: $(TARGET)

# Link the object files into the executable 'myapp'.
# $@ expands to the target name (myapp).
# $^ expands to all prerequisites (the list of .o files).
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# -----------------------------------------------------------
# Pattern rule: compile any .c into a .o
# -----------------------------------------------------------
# This single rule replaces per-file compile rules like:
#   main.o: main.c hello.h
#   hello.o: hello.c hello.h
#
# Explanation:
#  - The target pattern '%.o' matches any object file.
#  - The prerequisite '%.c' matches the corresponding C source file.
#  - $< is the first prerequisite (the .c file).
#  - -c tells the compiler to compile to an object file.
#
# Note on header dependencies:
#  This simple pattern rule doesn't list headers (e.g., hello.h) explicitly.
#  If you change headers, 'make' won't know to rebuild unless you enable
#  auto-dependency generation (shown below in an optional section).
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# -----------------------------------------------------------
# Utility targets
# -----------------------------------------------------------

# Declares targets that don’t produce files; avoids confusion if files named
# 'clean' or 'all' exist in the directory.
.PHONY: all clean

clean:
    # Remove all object files (*.o) and the output executable 'myapp'.
    # -f suppresses errors if files don't exist.
	rm -f *.o myapp