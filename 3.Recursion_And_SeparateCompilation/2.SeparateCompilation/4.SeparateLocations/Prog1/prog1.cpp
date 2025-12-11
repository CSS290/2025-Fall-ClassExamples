
// Date: 10/4/2025
// Author: K. Sung
// Purpose: 
// Same example to demonstrate that source code files of shared "library functions" can be located
// in separate folders. This is useful when multiple programs want
// to share the same function(s). In this way, we can compile the function(s) only once

#include "../Lib/f.h"  // Location of the header file is in a subfolder "Lib"

int main()
{
	float f = func(4);
    
    cout << "This is from prog1 with func(4)=" << f << endl;

    return 0;
}