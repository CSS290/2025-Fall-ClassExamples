# Makefile for prog2 with shared function in f.cpp located in a separate folder
#
# NOTE: by defining the OBJ and PROGRAM variables, we can easily reuse this Makefile
#       for multiple programs (e.g., prog1, prog2) by just changing the OBJ and PROGRAM values.

# Define the object files for each of the two programs
LIB = ../Lib/f.a
OBJ = prog2.o 
PROGRAM = prog2

# Default target
All: $(PROGRAM)

# Rule to link object files into the final executable
$(PROGRAM): $(OBJ) $(LIB)
	cd ../Lib && make # Ensure the library is built	
	g++ -o $@ $(OBJ) $(LIB)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -rf $(OBJ) $(PROGRAM)
# Note: The shared library f.a is compiled separately and is not cleaned here
# to allow for reuse in both programs without needing to recompile it each time.