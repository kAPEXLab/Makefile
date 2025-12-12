# Set the C compiler. 'gcc' is the GNU C Compiler.
CC = gcc

# Compiler flags:
#  -Wall enables most compiler warning messages to help catch potential issues.
CFLAGS = -Wall

# ------------------------------
# Target: 'myapp'
# ------------------------------
# 'myapp' depends on the object files 'main.o' and 'hello.o'.
# If either 'main.o' or 'hello.o' is newer than 'myapp', or if 'myapp' doesn't exist,
# this rule will run to (re)link the final executable.
# Link the object files into the executable 'myapp' using $(CC).
# Note: Linking typically uses the compiler driver as the linker front-end.
myapp: main.o hello.o
	$(CC) -o myapp main.o hello.o

# ------------------------------
# Target: 'main.o'
# ------------------------------
# 'main.o' must be recompiled if 'main.c' or 'hello.h' changes.
# Header dependencies ensure that changes in 'hello.h' trigger recompilation of 'main.o'.
# Compile 'main.c' into an object file 'main.o' with compiler warnings enabled.
main.o: main.c hello.h
	$(CC) $(CFLAGS) -c main.c

# ------------------------------
# Target: 'hello.o'
# ------------------------------
# 'hello.o' depends on 'hello.c' and the header 'hello.h'.
# If either of these files changes, 'hello.o' will be recompiled.
    # Compile 'hello.c' into 'hello.o' with compiler warnings enabled.
hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c

# ------------------------------
# Utility target: 'clean'
# ------------------------------
# This target removes build artifacts so you can start fresh.
# It's common to mark such utility targets as .PHONY (see improved version below).
clean:
    # Remove all object files (*.o) and the output executable 'myapp'.
    # -f suppresses errors if files don't exist.
	rm -f *.o myapp