
// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// This shows that the func() function can be defined in a separate file,
// we can separately compile main.cpp and f.cpp (with -c options) and then
// link the .o files to create the executable program.

// The definition of func
float func(int x) {
    // A dummy function
    return (x + 1.0) / 0.3;
}
