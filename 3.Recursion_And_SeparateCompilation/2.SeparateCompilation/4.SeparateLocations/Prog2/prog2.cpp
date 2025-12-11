
// Date: 10/4/2025
// Author: K. Sung
// Purpose:
// Same example to demonstrate that source code files of shared "library functions" can be located
// in separate folders. This is useful when multiple programs want
// to share the same function(s). In this way, we can compile the function(s) only once

#include "../Lib/f.h"  // Include the header file that contains the prototype of func

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