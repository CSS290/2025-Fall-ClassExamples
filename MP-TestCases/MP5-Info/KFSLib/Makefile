# Makefile for KFS Library

# Define the object files for the library
LIB = KFS.a

# Default target
All: $(LIB)

$(LIB): KFS.o
	ar rcs $@ KFS.o

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -rf $(LIB)