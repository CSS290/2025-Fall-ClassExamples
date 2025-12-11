// Date: 9/25/2025
// Author: K. Sung
// Purpose:
// Closer look at C++ include and complier options
// 
#include <iostream>
    // Where or what is "iostream"?
    // a File! 
    // Find it ...: I googled: "where is iostream located in Linux"
    //      find /usr/include -name iostream -type f -print
    // So what?
    //      importing a file to define what are: std, cin, cout, cerr

    // Try compuile with
    // g++ -E main.cpp
    //      -E: preprocess only (no compile, no assemble, no link)
    //      -S: compile and assemble only (no link)
    //      -c: compile only (no assemble, no link)
    //      (no option: compile, assemble, and link)
    //      -o <file>: specify output file name

// using the namespace defined in iostream so that
//      std::cout can be used as cout
//      std::cerr can be used as cerr
using namespace std;

int main()
{
	int a = 3;   // two ways to initialize: IDENTICAL!
    int b(3);    //    This inconsistency is NOT COOL!

    cout << "Hello World!" << endl;   // endl: end of line (flush the buffer)
    cout << "a=" << a << " b=" << b << endl;
}
