
// Date: 10/4/2025
// Author: K. Sung
// Purpose:
// Receives a float from the command line, calls func() with that number, and prints the result.
// If no number is presented as command line argument, this program prompts the user to enter a float number.
// To demonstrate that different programs can be linked to the same .o file
// to reuse the same function without redundant compilation.

#include "f.h"  // Include the header file that contains the prototype of func

int main(int argc, char* argv[])
{
	float f = 0;
    cout << "This is prog2!" << endl;
    if (argc > 1)
        f = atof(argv[1]);
    else
    {
        cout << "Please enter any float number: ";
        cin >> f;
    }
    
    cout << "This is from prog2 with func(" << f << ")=" << func(f) << endl;

    return 0;
}