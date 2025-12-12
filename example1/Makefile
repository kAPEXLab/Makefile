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