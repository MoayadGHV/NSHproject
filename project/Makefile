#include <stdbool.h# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Executable name
TARGET = simulation

# Source files
SRC = Simulation.c ALU.c Deco.c extractBits.c Mux.c fetch.c instructionMemory.c

# Object files (replace .c with .o for each source file)
OBJ = $(SRC:.c=.o)

# Default target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

simulate : $(TARGET)
	./$(TARGET) $(FILENAME)

assemble : assembler.c
	$(CC) -o assemble assembler.c
	./assemble $(FILENAME)

# Compile each .c file into .o, with dependency on .h files
ALU.o: ALU.c ALU.h
Deco.o: Deco.c Deco.h
extractBits.o: extractBits.c extractBits.h
Mux.o: Mux.c Mux.h
fetch.o: fetch.c fetch.h
instructionMemory.o: instructionMemory.c instructionMemory.h

# Simulation.c does not have a header file
Simulation.o: Simulation.c

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)
