# Makefile for creating f.o
# Note: This Makefile only compiles f.o and do not create any executable files

# note the .a file, is an archive file, a library file
LIB = f.a
OBJ = f.o

# Default targets are the two programs
$(LIB): $(OBJ)
	ar rcs $@ $(OBJ)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -f $(OBJ)
