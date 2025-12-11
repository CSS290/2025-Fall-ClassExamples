
// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// To bring out the point that function prototypes must be known 
// before you call the function.
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


// The defintion of func
float func(int x) {
    return (x + 1.0) / 0.3;
}
