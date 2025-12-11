# Makefile for 3.SeparateWithInclude
# Note: This Makefile is designed to compile two separate programs (prog1 and prog2)
# that both use the same function defined in f.cpp. The object file f.o is shared
# between the two programs to reuse the func() function and to avoid redundant compilation.

# Define the object files for each of the two programs
OBJ1 = prog1.o f.o
OBJ2 = prog2.o f.o

# Default targets are the two programs
All: prog1 prog2

# Rule to link object files into the final executable
prog1: $(OBJ1)
	g++ -o $@ $(OBJ1)

prog2: $(OBJ2)
	g++ -o $@ $(OBJ2)

# Note: the power of using predefined symbosls like $@ and $<
# we are working with different source code file names, but the same rule applies
# and we do not need to repeat the same rule for each source code file
# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) prog1 prog2
