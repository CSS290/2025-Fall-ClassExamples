// Date: 10/14/2025
// Author: K. Sung
// Purpose:
//     
//
#include <iostream>
using namespace std;
#include <iomanip> // Required for std::setw
#include <string>


int main(int argc, const char* argv[])
{
    int c(100);
    int a[5] {10, 20, 30, 40, 50};

    int *p = &c;
    cout << "p points to c: " << *p << endl;

    cout << endl << "Begin doing evil things" << endl;
    // increment p to point to the next integer location
    p = p + 1;
    cout << "p incremented (do not know what is this): " << *p << endl;
    cout << "p[-1] (should be c): " << p[-1] << endl; // This is very bad
    cout << "p[-2] (do not know what is this): " << p[-2] << endl; 

    // this is even more evil!
    cout << endl << "Begin doing even more evil things" << endl;
    char *ptr = (char*)&c; // treat the address of c as a char pointer
    ptr[0] = 0xA0;  // write something intp the memory location of c
    // now print c
    cout << "c after modifying its memory directly (was 100): " << c << endl;

    cout << endl << "End of evil things: I hope this will crash the program" << endl;
    p = &c - 100;
    cout << "*p (do not know what is this): " << *p << endl; // undefined behavior

    return 0;
}