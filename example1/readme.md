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

*README: Building and Running myapp Using Makefile*

*Overview*
This project demonstrates how to compile and link multiple C source files using a Makefile. The final executable is named myapp, which is built from two source files: main.c and hello.c. The header file hello.h provides declarations used in both source files.

*Concepts Covered*
* Makefile Basics: Automating compilation using targets and dependencies.
* Object Files: Intermediate files (.o) generated from source files.
* Dependency Management: Ensuring files are recompiled only when necessary.
* Clean Target: Removing generated files to reset the build environment.

*Project Structure*
├── main.c       # Contains the main() function
├── hello.c      # Contains implementation of helper functions
├── hello.h      # Header file with function declarations
├── Makefile     # Build automation script

Execution Steps
1. Build the Application

make

This will:
* Compile main.c → main.o
* Compile hello.c → hello.o
* Link both object files into the executable myapp.

2. Run the Application
After successful build:

./myapp

3. Clean Up Build Files
To remove object files and the executable:

make clean

How It Works

Target myapp depends on main.o and hello.o.
Command: gcc -o myapp main.o hello.o
Target main.o depends on main.c and hello.h.
Command: gcc -c main.c
Target hello.o depends on hello.c and hello.h.
Command: gcc -c hello.c
Target clean removes all generated files.