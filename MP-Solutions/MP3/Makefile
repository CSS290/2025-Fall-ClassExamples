# Makefile for prog1 with shared function in f.cpp located in a separate folder

# Define the object files for each of the two programs
LIB = KFSLib/KFS.o
OBJ = DirList.o
PROGRAM = DirList

# Default target
All: $(PROGRAM) 

# Rule to link object files into the final executable
$(PROGRAM): $(OBJ) $(LIB)
	g++ -o $@ $(OBJ) $(LIB)

debug: $(PROGRAM)
	make clean
	make DEBUG="-DDEBUG"

$(LIB): KFSLib/KFS.cpp KFSLib/KFS.h
	g++ -c $< -o $@

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $(DEBUG) $< -o $@

clean:
	rm -rf $(OBJ) $(PROGRAM)
