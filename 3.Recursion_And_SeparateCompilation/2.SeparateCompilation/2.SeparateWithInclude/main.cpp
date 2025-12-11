
// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// Same example with defined .h file and included in main.cpp
// This is the preferred way to organize code

#include "f.h"  // Include the header file that contains the prototype of func
    // Very important: the include is with double quote, not angle bracket
    // This allows us to include our own header files 
    // "" means: look in the current directory first, then in the system directories
    // <> means: look in the system directories only

int main()
{
	float f = func(4);
    
    cout << "This is func(4)=" << f << endl;

    return 0;
}