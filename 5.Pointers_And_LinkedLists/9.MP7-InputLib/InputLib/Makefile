# Makefile for Input Library

# Define the object files for the library
LIB = InputLib.a
OBJ = InputLib.o

# Default target
All: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -rf $(LIB) $(OBJ)