
// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// This shows that the func() function can be defined in a separate file.
//
// Note that main.cpp does not include f.cpp, but it has a prototype of func().
// This is referred to as forward declaration of the function.
// If you do not have the prototype, the compiler will complain that it does not know
// what func() is when it sees the call to func() in main().
//
// You can also put the prototype in a separate header file and include that header file
// in both main.cpp and f.cpp. This is a better practice. (as shown in the next example).
//
//
#include <iostream>
using namespace std;

float func(int);  // What is this?

int main()
{
	float f = func(4);
    
    cout << "This is func(4)=" << f << endl;

    return 0;
}