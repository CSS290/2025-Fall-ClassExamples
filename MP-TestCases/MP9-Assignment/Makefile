# Makefile for prog1 with shared function in f.cpp located in a separate folder

# Define the object files for each of the two programs
PROGRAM = mp9
OBJ = LinkedListClass_GivenCode.o LinkedListClass.o main.o

# Default target
All: $(PROGRAM) run

# Rule to link object files into the final executable
$(PROGRAM): $(OBJ)
	g++ -o $@ $(OBJ) 

run: $(PROGRAM)
	valgrind ./$(PROGRAM)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $(DEBUG) $< -o $@

clean:
	rm -rf $(OBJ) $(PROGRAM)
