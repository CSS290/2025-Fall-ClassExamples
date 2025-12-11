// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//Demonstrate scoping issues with pointers and references
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw
#include <string>

int* bad_return_address() {
    int x = 10; // x is a local variable
    return &x; // returning address of local variable is bad
               // because x will be destroyed when function returns
}

int& bad_return_reference() {
    int y = 20; // y is a local variable
    return y;  // returning reference to local variable is bad
               // because y will be destroyed when function returns
}

int main(int argc, const char* argv[])
{
    int *p = bad_return_address(); // p is now a dangling pointer
    cerr << *p << endl;    // undefined behavior

    int &r = bad_return_reference(); // r is now a dangling reference
    cerr << r << endl;               // undefined behavior

    {
        int a(100);
        p = &a; // p points to a
        cerr << "Inside block: a = " << a << ", *p = " << *p << endl;
    }
    // a is out of scope here, p is now a dangling pointer
    cerr << "Outside block: *p = " << *p << endl; // undefined
    return 0;
}