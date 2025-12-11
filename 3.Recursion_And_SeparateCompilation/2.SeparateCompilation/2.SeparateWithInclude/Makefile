# Makefile for SeparateWithInclude example
# This Makefile compiles main.cpp and f.cpp into an executable named prog

# Define the object files
# 	Left side: is the variable name
# 	Right side: is the value of the variable
OBJS = main.o f.o

All: prog

# Rule to link object files into the final executable
# $(OBJS) expands to main.o f.o, this is like using the variable
#         note the "$" and the "()"
# $@ is the target (prog)
prog: $(OBJS)
	g++ -o $@ $(OBJS)

# Rule to compile .cpp files into .o files
#     The pattern rule %.o: %.cpp means any .o file depends on its corresponding .cpp file
# $< is the first prerequisite (the .cpp file)
# $@ is the target (the .o file)
%.o: %.cpp
	g++ -c $< -o $@

# Rule to clean up the directory by removing object files and the executable
# "make clean" will execute this rule
# -f means "force", it won't complain if the files don't exist
clean:
	rm -f $(OBJS) prog


