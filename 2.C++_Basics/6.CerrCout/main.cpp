
// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// Examine the subtle difference between cout and cerr
// 
#include <iostream>

// Two things to note:
//     1. the use of #define and #ifdef
//     2. Where is the COUT message?
using namespace std;

// Uncomment to see CERR message
// Alternatively, you can use -DCERR when compiling to switch on the flag
// #define CERR

int main()
{
	int a = 3;   // two ways to initialize: IDENTICAL!
    int b(3);    //

#ifdef CERR
    cerr << "CERR message: a=" << a << " b=" << b;
#endif

    cout << "COUT message   a=" << a << " b=" << b;
    //      Do you know you can "flush" cout?
    //      Without flushing, the message is not showing?
    // cout.flush();

    char *p = nullptr;
    *p = 'c';
}
