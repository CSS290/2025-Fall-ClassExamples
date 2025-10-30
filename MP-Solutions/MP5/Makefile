# Makefile for prog1 with shared function in f.cpp located in a separate folder

# Define the object files for each of the two programs
LIB = KFSLib/KFS.a
PROGRAM = RemoveDuplicate
OBJ = $(PROGRAM).o


# Default target
All: $(PROGRAM) 

# Rule to link object files into the final executable
$(PROGRAM): $(OBJ) $(LIB)
	g++ -o $@ $(OBJ) $(LIB)


$(LIB): KFSLib/KFS.cpp KFSLib/KFS.h
	g++ -c KFSLib/KFS.cpp -o KFSLib/KFS.o
	ar rcs $@ KFSLib/KFS.o

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $(DEBUG) $< -o $@

clean:
	rm -rf $(OBJ) $(PROGRAM)
