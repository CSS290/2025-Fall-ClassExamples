# Makefile for prog1 with shared function in f.cpp located in a separate folder

# Define the object files for each of the two programs
LIB = InputLib/InputLib.a
PROGRAM = TestInputLib
OBJ = $(PROGRAM).o


# Default target
All: $(PROGRAM) 

# Rule to link object files into the final executable
$(PROGRAM): $(OBJ) $(LIB)
	g++ -o $@ $(OBJ) $(LIB)


$(LIB): InputLib/InputLib.cpp InputLib/InputLib.h
	g++ -c InputLib/InputLib.cpp -o InputLib/InputLib.o
	ar rcs $@ InputLib/InputLib.o

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $(DEBUG) $< -o $@

clean:
	rm -rf $(OBJ) $(PROGRAM)
