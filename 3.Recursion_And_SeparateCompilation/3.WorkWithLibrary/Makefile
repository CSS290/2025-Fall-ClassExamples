# Makefile for the KFS Example program

# Define the object files for each of the two programs
LIB = ./KFSLib/KFS.a
OBJ = KFSExample.o
PROGRAM = kfs

# Default target
All: $(PROGRAM)

# Rule to link object files into the final executable
$(PROGRAM): $(OBJ) $(LIB)
	g++ -o $@ $(OBJ) $(LIB)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -rf $(OBJ) $(PROGRAM)
# Note: MUST NOT and cannot rm the files in the lib, not the KFS.h and certainly not the KFS.o