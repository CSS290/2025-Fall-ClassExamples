
// Date: 10/4/2025
// Author: K. Sung
// Purpose: 
// To demonstrate that different programs can be linked to the same .o file
// This program is the same as the previous example

#include "f.h"  // Include the header file that contains the prototype of func
    

int main()
{
	float f = func(4);
    
    cout << "This is from prog1 with func(4)=" << f << endl;

    return 0;
}